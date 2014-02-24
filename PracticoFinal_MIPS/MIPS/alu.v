`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:09:44 02/15/2014 
// Design Name: 
// Module Name:    alu 
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
module alu(
    input [31:0] a,
    input [31:0] b,
    output reg [31:0] out,
    output zero,
    input [3:0] aluop
    );
	 
	assign zero = ~(out && 32'b11111111111111111111111111111111);

	always @ (*)
	begin
		case (aluop)
			4'b0000 : out = a + b;
			4'b0001 : out = a - b;
			4'b0010 : out = a | b;
			4'b0011 : out = ~(a | b);
			4'b0100 : out = a & b;
			4'b0101 : out = ~(a & b);
			4'b0110 : out = a ^ b;
			4'b0111 : out = b << a;
			4'b1000 : out = b >> a;
			4'b1001 : out = b >>> a;
			default : out = 32'b0;
		endcase
	end

endmodule
