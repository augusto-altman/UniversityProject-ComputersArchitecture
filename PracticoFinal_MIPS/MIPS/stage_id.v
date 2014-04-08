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
	output [31:0]	reg1, //rs
	output [31:0]	reg2,
	output reg [31:0]	extendedInstr,
	output reg [4:0] 	regAddr1,
	output reg [4:0] 	regAddr2,
	output reg 			regDst
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
    .regAddr2(_regAddr2)
    );



always@(posedge clock)
begin
	aluOp 				= _aluOp;
	isJump 				= _isJump;
	isNotConditional 	= _isNotConditional;
	isEq 					= _isEq;
	memWrite 			= _memWrite;
	wbi 					= _wbi;
	memRead 				= _memRead;
	aluSrc 				= _aluSrc;
	//reg1 					= _reg1;
	//reg2 					= _reg2;
	extendedInstr 		= _extendedInstr;
	regDst				= _regDst;
	regAddr1 			= _regAddr1;
	regAddr2 			= _regAddr2;
	pc_ex 				= pc_id;

end	
	
endmodule
