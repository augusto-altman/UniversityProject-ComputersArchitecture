`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:49:46 01/19/2014 
// Design Name: 
// Module Name:    CPU 
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
module CPU(
    output [10:0] InsAddr,
    input [15:0] Instruction,
    output Rd,
    output Wr,
    output [10:0] DataAddr,
    output [15:0] In_Data,
    input [15:0] Out_Data,
	 input Clock,
	 input Reset
    );
wire [1:0] SelA;
wire SelB, WrAcc, Op;
wire [10:0] OpAddrSE;

assign DataAddr = OpAddrSE;

Control ctrl (
    .Clk(Clock), 
    .Instruction(Instruction), 
    .Reset(Reset), 
    .Addr(InsAddr), 
    .SelA(SelA), 
    .SelB(SelB), 
    .WrAcc(WrAcc), 
    .Op(Op), 
    .WrRam(Wr), 
    .RdRam(Rd), 
    .Operand(OpAddrSE)
    );

Datapath dp (
    .SelA(SelA), 
    .SelB(SelB), 
    .Addr(OpAddrSE), 
    .WrAcc(WrAcc), 
    .Op(Op), 
    .Clock(Clock), 
    .In_Data(In_Data), 
    .Out_Data(Out_Data)
    );



endmodule
