`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:11:43 01/15/2014 
// Design Name: 
// Module Name:    Control 
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
module Control(
    input Clk,
    input [15:0] Instruction,
	 input Reset,
    output [10:0] Addr,
    output [1:0] SelA,
    output SelB,
    output WrAcc,
    output Op,
    output WrRam,
    output RdRam,
    output [10:0] Operand
    );
	 
	assign Operand = Instruction[10:0];

	PC ProgramCounter (
		.Clk(Clk), 
		.Reset(Reset), 
		.Addr(Addr)
	);
	
	Instruction_Decoder ID (
		.Opcode(Instruction[15:11]), 
		.SelA(SelA), 
		.SelB(SelB), 
		.WrAcc(WrAcc), 
		.Op(Op), 
		.WrRam(WrRam), 
		.RdRam(RdRam)
	);

endmodule
