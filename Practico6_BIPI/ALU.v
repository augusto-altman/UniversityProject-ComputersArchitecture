`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:19:22 01/18/2014 
// Design Name: 
// Module Name:    ALU 
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
module ALU(
    input [15:0] A,
    input [15:0] B,
    output [15:0] Out,
    input Op
    );
reg [15:0] Result;
assign Out = Result;

always @ (A or B or Op)
if (Op == 0)
	Result = A + B;
else
	Result = A - B;
endmodule
