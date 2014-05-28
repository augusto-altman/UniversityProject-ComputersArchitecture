`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:42:15 05/27/2014
// Design Name:   ControlHazzardHandler
// Module Name:   D:/Estudio/facu/arquitectura de computadoras/final/workspace - trunk/PracticoFinal_MIPS/MIPS/ControlHazarHandler_test1.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ControlHazzardHandler
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ControlHazarHandler_test1;

	// Inputs
	reg isJump;
	reg clock;
	reg reset;

	// Outputs
	wire stall_exe;
	wire stall_id;

	// Instantiate the Unit Under Test (UUT)
	ControlHazzardHandler uut (
		.isJump(isJump), 
		.clock(clock), 
		.reset(reset), 
		.stall_exe(stall_exe), 
		.stall_id(stall_id)
	);

	initial begin
		// Initialize Inputs
		isJump = 0;
		clock = 0;
		reset = 0;

		// Wait 100 ns for global reset to finish
		#4;
		reset = 1;
		#4;
		reset = 0;
        
		// Add stimulus here
		#39;
		
		isJump = 1 ;
			
		#20;
		isJump =0;
		#23;
		isJump=1;
		#30;
		isJump=0;
		

	end
	
	always
	begin
		#2;
		clock = ~clock;
	end
      
endmodule

