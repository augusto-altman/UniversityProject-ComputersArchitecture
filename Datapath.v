`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:21:42 01/18/2014 
// Design Name: 
// Module Name:    Datapath 
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
module Datapath(
    input [1:0] SelA,
    input SelB,
    input [10:0] Addr,
    input WrAcc,
    input Op,
	 input Clock,
    output [15:0] In_Data,
    input [15:0] Out_Data
    );
	 
wire [15:0] SEAB, AluA, AccA, AccMemAlu, BAlu;

assign In_Data = AccMemAlu;
//assign Out_Data = MemAB;

SignalExtension Sig(
	.eleven(Addr),
	.sixteen(SEAB)
	);

MuxA MultiplexorA(
	.Memory(Out_Data),
	.Immediate(SEAB),
	.Alu(AluA),
	.SelA(SelA),
	.Acc(AccA)
	);

MuxB MultiplexorB(
	.Memory(Out_Data),
	.Immediate(SEAB),
	.SelB(SelB),
	.Alu(BAlu)
	);

Acc Accumulator(
	.SelA(AccA),
	.WrAcc(WrAcc),
	.Clock(Clock),
	.AccOut(AccMemAlu)
	);
	
ALU Alunit(
	.A(AccMemAlu),
	.B(BAlu),
	.Out(AluA),
	.Op(Op)
	);
endmodule
