`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:39:34 01/20/2014
// Design Name:   BIPI
// Module Name:   D:/Estudio/facu/arquitectura de computadoras/final/workspace/BIPTEST1.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: BIPI
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module BIPTEST1;

	// Inputs
	reg Clock;
	reg Reset;

	// Instantiate the Unit Under Test (UUT)
	BIPI uut (
		.Clock(Clock), 
		.Reset(Reset)
	);

	initial begin
		// Initialize Inputs
		Clock = 0;
		Reset = 0;

		// Wait 100 ns for global reset to finish
		#50;
		Reset = 1;
		#100
		Reset = 0;        
		// Add stimulus here
	end
      
	always
	begin
		#100 
		Clock = ~Clock;
	end
      
endmodule

