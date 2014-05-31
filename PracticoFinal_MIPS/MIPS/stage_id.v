`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:35:00 02/21/2014 
// Design Name: 
// Module Name:    stage_id 
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
module stage_id(
	// inputs
	input clock,
	input reset,
	input [31:0] 	instr,
	input [31:0] 	writeData,
	input [4:0] 	writeAddr,
	input 			regWrite,
	input [31:0]   pc_id,
	input 			isJumped,
	input 			nop_if,
	// outputs
	output reg [31:0]  pc_ex,
	output reg [3:0] 	aluOp,
	output reg			isJump,
	output reg			isNotConditional,
	output reg			isEq,
	output reg			memWrite,  
	output reg [1:0] 	wbi,
	output reg			memRead, 
	output reg			aluSrc, 
	output [31:0]	reg1,
	output [31:0]	reg2,
	output reg [31:0]	extendedInstr,
	output reg [4:0] 	regAddr1,
	output reg [4:0] 	regAddr2,
	output reg [4:0] 	rs,
	output reg 			regDst,
	output reg 			nop
    );

wire [3:0] 	_aluOp;
wire			_isJump;
wire 			_isNotConditional;
wire 			_isEq;
wire 			_memWrite;
wire [1:0] 	_wbi;
wire 			_memRead;
wire 			_aluSrc;
//wire [31:0] _reg1;
//wire [31:0] _reg2;
wire [31:0]	_extendedInstr;
wire [4:0] 	_regAddr1;
wire [4:0] 	_regAddr2 ;
wire 			_regDst;
wire [4:0]  _rs;


ControlModule control (
    .instr(instr[31:26]), 
    .aluOp(_aluOp), 
    .isJump(_isJump), 
    .isNotConditional(_isNotConditional), 
    .isEq(_isEq), 
    .memWrite(_memWrite), 
    .wbi(_wbi), 
    .memRead(_memRead), 
    .aluSrc(_aluSrc), 
    .regDst(_regDst)
    );
	 
RegisterBank registerBank (
    .clock(clock),
	 .reset(reset),
    .addr1(instr[25:21]), 
    .addr2(instr[20:16]), 
    .writeAddr(writeAddr), // mux de esta etapa con instr[20:16] y instr[16:11] -> no es seguro, consultar tito
    .writeData(writeData), // input de etapa ex
    .regWrite(regWrite), // De control
    .reg1(reg1), 
    .reg2(reg2)
    );
	 
signExtension signExtension (
    .instr(instr[15:0]), 
    .extendedInstr(_extendedInstr)
    );
	 
//mux5bits muxWriteAddr (
//    .input1(instr[20:16]), 
//	 .input2(instr[15:11]),
//    .condition(regDist), 
//    .out(_writeAddr)
//    );

GetRegAddr getRegAddr (
    .instr(instr), 
    .regAddr1(_regAddr1), 
    .regAddr2(_regAddr2),
	 .rs(_rs)
    );



always@(posedge clock)
begin
  if(reset || isJumped)
	  begin
			aluOp					= 4'b0010;
			extendedInstr 		= 32'b000000;
			wbi 					= 2'b0;
			memWrite 			= 1'b0;
			aluSrc 				= 1'b1;
			regDst				= 1'b0;
			regAddr1 			= 5'b0;
			regAddr2 			= 5'b0;
			rs						= 5'b0;
			pc_ex 				= 32'b0;
			isJump 				= 1'b0;
			isNotConditional 	= 1'b0;
			isEq 					= 1'b0;
			memRead 				= 1'b0;
			nop 					= 1;
	  end
	else
		begin
			aluOp 				= _aluOp;
			isJump 				= _isJump;
			isNotConditional 	= _isNotConditional;
			isEq 					= _isEq;
			memWrite 			= _memWrite;
			wbi 					= _wbi;
			memRead 				= _memRead;
			aluSrc 				= _aluSrc;
			extendedInstr 		= _extendedInstr;
			regDst				= _regDst;
			regAddr1 			= _regAddr1;
			regAddr2 			= _regAddr2;
			rs						= _rs;
			pc_ex 				= pc_id;
			nop 					= nop_if;
		end

end	
	
endmodule
