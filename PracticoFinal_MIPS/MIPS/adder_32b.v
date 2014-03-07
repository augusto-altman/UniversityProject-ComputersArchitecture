`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:46:45 03/05/2014 
// Design Name: 
// Module Name:    adder_32b 
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
module adder_32b(
    input [31:0] a,
    input [31:0] b,
    output reg [31:0] c
    );

	//assign c = a + b;
	always @ (*)
		c = a + b;
endmodule
