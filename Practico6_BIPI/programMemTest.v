`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:47:00 01/19/2014
// Design Name:   u_program_memory
// Module Name:   D:/Estudio/facu/arquitectura de computadoras/final/memorias/programMemTest.v
// Project Name:  memorias
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: u_program_memory
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module programMemTest;

	// Inputs
	reg clock;
	reg [0:15] address;

	// Outputs
	wire [0:15] out;

	// Instantiate the Unit Under Test (UUT)
	u_program_memory uut (
		.clock(clock), 
		.address(address), 
		.out(out)
	);

	initial begin
		// Initialize Inputs
		clock = 0;
		address = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		
		//1st round
		address = 0;
		clock =~ clock;
		#100;
		clock =~ clock;
		#100;
		//2nd round
		address = 1;
		clock =~ clock;
		#100;
		clock =~ clock;
		#100;
		//3er round
		address = 16'b0000_0000_0000_0010;
		clock =~ clock;
		#100;
		clock =~ clock;
		#100;
		//4to round
		address = 16'b0000_0000_0000_0011;
		clock =~ clock;
		#100;
		clock =~ clock;
		#100;

	end
      
endmodule

