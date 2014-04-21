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
    input [7:0] code,
	 input reset,
    output reg [31:0] result,
	 output reg [1:0] size
    );
reg clk;
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

mem stage_mem (
    .clk(clk),
    .wbi(wb_mem), 
    .regaddr(regaddr_mem), 
    .wbo(wb), 
    .M(M), 
    .data(data), 
    .dataaddr(dataaddr), 
    .datafrommem(datafrommem), 
    .datafromimm(datafromimm), 
    .regaddrout(writeAddr),
	 .reset(reset)
    );
	 
wb write_back (
    .datafrommem(datafrommem), 
    .datafromimm(datafromimm), 
    .wb(wb), 
    .datatoregfile(writeData), 
    .weregfile(regWrite)
    );



always @ (*)
begin
	case (code[5:0])
		6'b100000: clk = 1;
		6'b100001: clk = 0;
		default: clk = 0;
	endcase

	case (code[5:0])
		/*IF*/ 
		6'b000001: result = instr; //instruction
		6'b100010: result = pc_id; //iadd
		/*ID*/
		6'b000010: result = control_oper; //aluOp
		6'b000011: result = control_is_jump; //isJump
		6'b000100: result = control_branch_inc; //isNotConditional
		6'b000101: result = control_branch_eq; //isEq
		6'b000110: result = M_exe; //memWrite
		6'b000111: result = wb_exe; //wbi
		//6'b001000: result = //memRead
		6'b001001: result = control_use_b; //aluSrc
		6'b001010: result = data_a; //reg1
		6'b001011: result = data_b; //reg2
		6'b001100: result = data_imm; //extendedInstr
		6'b001101: result = regaddr1; //regAddr1
		6'b001110: result = regaddr2; //regAddr2
		6'b001111: result = control_Reg_DST; //regDst
		/*EXE*/
		6'b010000: result = control_is_jump_if; //is_jump_o
		6'b010001: result = control_branch_eq_if; //branch_eq_o
		6'b010010: result = control_branch_inc_if; //branch_inc_o
		6'b010011: result = control_is_zero_if; //zero
		6'b010100: result = data_jump_address; //jump_address
		6'b010101: result = wb_mem; //wbi_o
		6'b010110: result = M; //M_o
		6'b010111: result = regaddr_mem; //regaddr_o
		6'b011000: result = data;//data_b_o
		6'b011001: result = dataaddr;//out
		/*MEM*/
		6'b011010: result = datafrommem; //datafrommem
		6'b011011: result = datafromimm; //datafromimm
		6'b011100: result = writeAddr; //regaddrout
		6'b011101: result = wb; //wbo
		/*WB*/
		6'b011110: result = writeData; //datatoregfile
		6'b011111: result = regWrite; //weregfile
		default: result = 0;
	endcase
	
	size = code[7:6];
	
end

endmodule
