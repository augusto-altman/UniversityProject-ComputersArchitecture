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
//		input clk,
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
//FOR REGBANK
wire [4:0] addr1_frb;
wire [4:0] addr2_frb;
wire [4:0] writeAddr_frb;
wire [31:0] writeData_frb;
wire regWrite_frb;
wire [31:0] reg1_frb;
wire [31:0] reg2_frb;

/*EX*/
wire [31:0] data_a, data_b, data_imm, npc;
wire [3:0] control_oper;
wire control_use_b, control_Reg_DST, control_is_jump, control_branch_eq, control_branch_inc;
wire [4:0] regaddr1, regaddr2;

wire [1:0] wb_exe;
wire M_exe;
wire [4:0] rs;

/*MEM*/
wire M;
wire [31:0] data, dataaddr;
wire [1:0] wb_mem;
wire [4:0] regaddr_mem;
wire [4:0] rt_id;

/*WB*/
wire [31:0] datafrommem, datafromimm;
wire [1:0] wb;

/*Forwarding*/
wire [1:0] forw_exe_a, forw_exe_b;
wire forw_mem;

// control hazzard
wire isJumped;

// wire NOP
wire nop_if, nop_id, nop_exe, nop_mem;
//wire stall
wire stall;

assign processed_clock = clk && ~stall;


StallHandler staller (
    .clock(clk), 
	 .reset(reset),
    .isFromAlu(wb_mem[0]),
	 //.isFromAlu(wb_exe[0]), 
    .nop_exe(nop_exe), 
    .reg_Dst(control_Reg_DST), 
    .regAddrOutAlu(regaddr_mem), 
    .regAddrInRs(rs), 
    .regAddrInRt(regaddr2), 
    .regAddrInRd(regaddr1), 
    .stall(stall)
    );

	 
forwarding_exe fe (
    .rs_id(rs), 
    .rd_id(regaddr1), 
    .rt_id(regaddr2), 
	 .nop_exe(nop_exe),
	 .nop_mem(nop_mem),
	 .wb_exe(wb_mem[1]),
	 .wb_mem(wb[1]),
    .regDst(control_Reg_DST), 
    .outReg_exe(regaddr_mem), 
    .outReg_mem(writeAddr), 
    .selector_salida_a(forw_exe_a), 
    .selector_salida_b(forw_exe_b)
    );
	 
forwarding_mem fm (
    .rt_id(rt_id), 
    .outReg_mem(writeAddr), 
	 .nop_mem(nop_mem),
	 .wb_mem(wb[1]),
    .selector_salida(forw_mem)
    );

stage_if instr_fetch (
    .clock(processed_clock), 
    .reset(reset), 
    .control_is_jump(control_is_jump_if), 
	 .nop_exe(nop_exe),
    .control_branch_eq(control_branch_eq_if), 
    .control_branch_inc(control_branch_inc_if), 
    .control_is_zero(control_is_zero_if), 
    .data_jump_address(data_jump_address),
	 .iadd(pc_id),
    .instruction(instr),
	 .isJumped(isJumped),
	 .nop(nop_if)
    );
	 
stage_id ins_decoder (
    .clock(processed_clock),
	 .reset(reset),
	 .nop_if(nop_if),
    .instr(instr), 
	 .isJumped(isJumped),
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
	 .rs(rs),
    .regDst(control_Reg_DST),
	 .nop(nop_id),
    //FOR REGBANK
    .addr1_frb(addr1_frb), 
    .addr2_frb(addr2_frb), 
    .writeAddr_frb(writeAddr_frb), // mux de esta etapa con instr[20:16] y instr[16:11] -> no es seguro, consultar tito
    .writeData_frb(writeData_frb), // input de etapa ex
    .regWrite_frb(regWrite_frb), // De control
    .reg1_frb(reg1_frb), 
    .reg2_frb(reg2_frb)
    );
	 
RegisterBank registerBank (
    .clock(clk),
	 .reset(reset),
    .addr1(addr1_frb), 
    .addr2(addr2_frb), 
    .writeAddr(writeAddr_frb), // mux de esta etapa con instr[20:16] y instr[16:11] -> no es seguro, consultar tito
    .writeData(writeData_frb), // input de etapa ex
    .regWrite(regWrite_frb), // De control
    .reg1(reg1_frb), 
    .reg2(reg2_frb)
    );

stage_exe exe(
    //.clock(processed_clock),
	 .clock(clk), 
    .reset(reset), 
	 .nop_id(nop_id),
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
    .out(dataaddr),
	 .for_a(forw_exe_a),
	 .for_b(forw_exe_b),
	 .rt_id(rt_id),
	 .result_from_exe(dataaddr),
	 .result_from_mem(writeData),
	 .isJumped(isJumped),
	 .stall(stall),
	 .nop(nop_exe)
    );

mem stage_mem (
    .clk(clk),
	 .nop_exe(nop_exe),
    .wbi(wb_mem), 
    .regaddr(regaddr_mem), 
    .wbo(wb), 
    .M(M), 
    .data(data), 
    .dataaddr(dataaddr), 
    .datafrommem(datafrommem), 
    .datafromimm(datafromimm), 
    .regaddrout(writeAddr),
	 .forw(forw_mem),
	 .result_from_mem(writeData),
	 .reset(reset),
	 .nop(nop_mem)
    );
	 
wb write_back (
	 .nop_mem(nop_mem),
    .datafrommem(datafrommem), 
    .datafromimm(datafromimm), 
    .wb(wb), 
    .datatoregfile(writeData), 
    .weregfile(regWrite)
    );



always @ (*)
begin
	case (code[5:0])
		6'b111000: clk = 0;
		6'b111111: clk = 1;
		default: clk = 0;
	endcase
	case (code[5:0])
		/*IF*/ 
		6'b000001: result = 32'b0 + instr; //instruction
		6'b100010: result = 32'b0 + pc_id; //iadd
		/*ID*/
		6'b000010: result = 32'b0 + control_oper; //aluOp
		6'b000011: result = 32'b0 + control_is_jump; //isJump
		6'b000100: result = 32'b0 + control_branch_inc; //isNotConditional
		6'b000101: result = 32'b0 + control_branch_eq; //isEq
		6'b000110: result = 32'b0 + M_exe; //memWrite
		6'b000111: result = 32'b0 + wb_exe; //wbi
		//6'b001000: result = //memRead
		6'b001001: result = 32'b0 + control_use_b; //aluSrc
		6'b001010: result = 32'b0 + data_a; //reg1
		6'b001011: result = 32'b0 + data_b; //reg2
		6'b001100: result = 32'b0 + data_imm; //extendedInstr
		6'b001101: result = 32'b0 + regaddr1; //regAddr1
		6'b001110: result = 32'b0 + regaddr2; //regAddr2
		6'b001111: result = 32'b0 + control_Reg_DST; //regDst
		/*EXE*/
		6'b010000: result = 32'b0 + control_is_jump_if; //is_jump_o
		6'b010001: result = 32'b0 + control_branch_eq_if; //branch_eq_o
		6'b010010: result = 32'b0 + control_branch_inc_if; //branch_inc_o
		6'b010011: result = 32'b0 + control_is_zero_if; //zero
		6'b010100: result = 32'b0 + data_jump_address; //jump_address
		6'b010101: result = 32'b0 + wb_mem; //wbi_o
		6'b010110: result = 32'b0 + M; //M_o
		6'b010111: result = 32'b0 + regaddr_mem; //regaddr_o
		6'b011000: result = 32'b0 + data;//data_b_o
		6'b011001: result = 32'b0 + dataaddr;//out
		/*MEM*/
		6'b011010: result = 32'b0 + datafrommem; //datafrommem
		6'b011011: result = 32'b0 + datafromimm; //datafromimm
		6'b011100: result = 32'b0 + writeAddr; //regaddrout
		6'b011111: result = 32'b0 + wb; //wbo
		/*WB*/
		6'b011101: result = 32'b0 + writeData; //datatoregfile
		6'b011110: result = 32'b0 + regWrite; //weregfile
      6'b111000: result = 32'b0 + 8'b01010101;
		6'b111111: result = 32'b0 + 8'b11111111;
		default: result = 0;
	endcase
	
	size = code[7:6];
	
end

endmodule
