`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:57:00 01/20/2014
// Design Name:   ClockTree
// Module Name:   D:/Estudio/facu/arquitectura de computadoras/final/workspace/ClockTreeTest.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ClockTree
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ClockTreeTest;

	// Inputs
	reg Clock;

	// Outputs
	wire ClockPc;
	wire ClockWrRd;

	// Instantiate the Unit Under Test (UUT)
	ClockTree uut (
		.Clock(Clock), 
		.ClockPc(ClockPc), 
		.ClockWrRd(ClockWrRd)
	);

	initial begin
		// Initialize Inputs
		Clock = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
	
	end
      
		
		always
	begin
		#5
		Clock = ~Clock;
	end 
endmodule

