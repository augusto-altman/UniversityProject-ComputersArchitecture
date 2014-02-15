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
    input signed [31:0] a,
    input signed [31:0] b,
    output reg signed [31:0] out,
    output zero,
    input [2:0] aluop
    );
	 
	assign zero = ~(out && 32'b11111111111111111111111111111111);

	always @ (*)
	begin
		case (aluop)
			3'b000 : out = a + b;
			3'b001 : out = a - b;
			3'b010 : out = a | b;
			3'b011 : out = a & b;
			3'b100 : out = ~a;
			default : out = 32'b0;
		endcase
	end

endmodule
