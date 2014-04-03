`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:57:10 03/14/2014 
// Design Name: 
// Module Name:    debuger_decoder 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module debuger_decoder(
    //input [7:0] code,
	 input clk,
	 input reset
    //output reg [31:0] result,
	 //output reg [1:0] size
    );
/*reg [3:0] clkdiv;

always @(posedge clk)
begin
	if (reset)
		clkdiv = 0;
	else
		clkdiv = clkdiv + 1;
end*/

/*IF*/
wire control_is_jump_if, control_branch_eq_if, control_branch_inc_if, control_is_zero_if;
wire [31:0] data_jump_address;

/*ID*/
wire [31:0] instr, writeData, pc_id;
wire [4:0] 	writeAddr;
wire 			regWrite;

/*EX*/
wire [31:0] data_a, data_b, data_imm, npc;
wire [3:0] control_oper;
wire control_use_b, control_Reg_DST, control_is_jump, control_branch_eq, control_branch_inc;
wire [4:0] regaddr1, regaddr2;

wire [1:0] wb_exe;
wire M_exe;

/*MEM*/
wire M;
wire [31:0] data, dataaddr;
wire [1:0] wb_mem;
wire [4:0] regaddr_mem;

/*WB*/
wire [31:0] datafrommem, datafromimm;
wire [1:0] wb;

stage_if instr_fetch (
    .clock(clk), 
    .reset(reset), 
    .control_is_jump(control_is_jump_if), 
    .control_branch_eq(control_branch_eq_if), 
    .control_branch_inc(control_branch_inc_if), 
    .control_is_zero(control_is_zero_if), 
    .data_jump_address(data_jump_address),
	 .iadd(pc_id),
    .instruction(instr)
    );
	 
stage_id ins_decoder (
    .clock(clk),
	 .reset(reset),
    .instr(instr), 
    .writeData(writeData), 
    .writeAddr(writeAddr), 
    .regWrite(regWrite), 
    .pc_id(pc_id), 
    .pc_ex(npc), 
    .aluOp(control_oper), 
    .isJump(control_is_jump), 
    .isNotConditional(control_branch_inc), 
    .isEq(control_branch_eq), 
    .memWrite(M_exe), 
    .wbi(wb_exe), 
    .memRead(), 
    .aluSrc(control_use_b), 
    .reg1(data_a), 
    .reg2(data_b), 
    .extendedInstr(data_imm), 
    .regAddr1(regaddr1), 
    .regAddr2(regaddr2), 
    .regDst(control_Reg_DST)
    );


stage_exe exe(
    .clock(clk), 
    .reset(reset), 
    .data_a(data_a), 
    .data_b(data_b), 
    .data_imm(data_imm), 
    .control_oper(control_oper), 
    .control_use_b(control_use_b), 
    .control_Reg_DST(control_Reg_DST), 
    .npc(npc), 
    .control_is_jump(control_is_jump), 
    .control_branch_eq(control_branch_eq), 
    .control_branch_inc(control_branch_inc), 
    .is_jump_o(control_is_jump_if), 
    .branch_eq_o(control_branch_eq_if), 
    .branch_inc_o(control_branch_inc_if), 
    .zero(control_is_zero_if), 
    .jump_address(data_jump_address), 
    .wbi(wb_exe), 
    .M(M_exe), 
    .regaddr1(regaddr1), 
    .regaddr2(regaddr2), 
    .wbi_o(wb_mem), 
    .M_o(M), 
    .regaddr_o(regaddr_mem), 
    .data_b_o(data), 
    .out(dataaddr)
    );

mem module_tested (
    .clk(clk),
    .wbi(wb_mem), 
    .regaddr(regaddr_mem), 
    .wbo(wb), 
    .M(M), 
    .data(data), 
    .dataaddr(dataaddr), 
    .datafrommem(datafrommem), 
    .datafromimm(datafromimm), 
    .regaddrout(writeAddr)
    );
	 
wb write_back (
    .datafrommem(datafrommem), 
    .datafromimm(datafromimm), 
    .wb(wb), 
    .datatoregfile(writeData), 
    .weregfile(regWrite)
    );

/*always @ (*)
begin
	case (code[5:0])
	6'b100001: result = datafrommem;
	6'b100010: result = datafromimm;
	6'b100011: result = regaddrout;
	default: result = 0;
	endcase
	
	size = code[7:5];
end*/

endmodule
