`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   04:14:41 03/05/2014
// Design Name:   stage_if
// Module Name:   D:/Estudio/facu/arquitectura de computadoras/final/workspace - trunk/PracticoFinal_MIPS/MIPS/Test_stage_if.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: stage_if
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Test_stage_if;

	// Inputs
	reg clock;
	reg reset;
	reg control_is_jump;
	reg control_branch_eq;
	reg control_branch_inc;
	reg control_is_zero;
	reg [31:0] data_jump_address;

	// Outputs
	wire [31:0] instruction;

	// Instantiate the Unit Under Test (UUT)
	stage_if uut (
		.clock(clock), 
		.reset(reset), 
		.control_is_jump(control_is_jump), 
		.control_branch_eq(control_branch_eq), 
		.control_branch_inc(control_branch_inc), 
		.control_is_zero(control_is_zero), 
		.data_jump_address(data_jump_address), 
		.instruction(instruction)
	);

	initial begin
		// Initialize Inputs
		clock = 0;
		reset = 0;
		control_is_jump = 0;
		control_branch_eq = 0;
		control_branch_inc = 0;
		control_is_zero = 0;
		data_jump_address = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here

	end
      
endmodule

