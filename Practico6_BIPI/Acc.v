`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:50:31 01/18/2014 
// Design Name: 
// Module Name:    Acc 
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
module Acc(
    input [15:0] SelA,
    input WrAcc,
    input Clock,
    output [15:0] AccOut
    );
reg [15:0] Accumulator;
assign AccOut = Accumulator;

always @ (negedge Clock)
 if (WrAcc == 1)
	Accumulator = SelA;

endmodule
