`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:24:48 01/18/2014
// Design Name:   ALU
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/bipI/AluTest.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ALU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module AluTest;

	// Inputs
	reg [15:0] A;
	reg [15:0] B;
	reg Op;

	// Outputs
	wire [15:0] Out;

	// Instantiate the Unit Under Test (UUT)
	ALU uut (
		.A(A), 
		.B(B), 
		.Out(Out), 
		.Op(Op)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
		Op = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		A = 12;
		B = 7;
		
		#100;
		
		Op = 1;
		
		#100;
		
		B = 15;
	end
      
endmodule

