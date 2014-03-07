`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:27:25 03/05/2014
// Design Name:   stage_if
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/PracticoFinal_MIPS/MIPS/stage_if_test3.v
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

module stage_if_test3;

	// Inputs
	reg clock;
	reg reset;
	reg control_is_jump;
	reg control_branch_eq;
	reg control_branch_inc;
	reg control_is_zero;
	reg [31:0] data_jump_address;
	reg pass;

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
		pass = 0;
		clock = 1;
		reset = 1;
		control_is_jump = 0;
		control_branch_eq = 0;
		control_branch_inc = 0;
		control_is_zero = 0;
		data_jump_address = 0;

		// Wait 110 ns for global reset to finish
		#60;
      
		// Add stimulus here
		reset = 0;
		#40
		//Expected: Instruction = 0 -> Pass
		#1;
		if(instruction == 0) pass = 1; else pass = 0;

		//Progam simulation start
		//Expected: Instruction = 4 -> Pass
		control_is_jump = 0;
		#100;
		#1;
		if(instruction == 4) pass = 1; else pass = 0;
		
		//Expected: Instruction = 8 -> Pass
		control_is_jump = 0;
		#100;
		#1;
		if(instruction == 8) pass = 1; else pass = 0;
		
		//Expected: Instruction = 12 -> Pass
		control_is_jump = 0;
		#100;
		#1;
		if(instruction == 12) pass = 1; else pass = 0;
		
		//Expected: Instruction = 4 -> Pass
		control_is_jump = 1;
		control_branch_eq = 1;
		control_branch_inc = 0;
		control_is_zero = 1;
		data_jump_address = 4;
		#100;
		#1;
		if(instruction == 4) pass = 1; else pass = 0;
		
		//Expected: Instruction = 8 -> Pass
		control_is_jump = 0;
		control_branch_eq = 0;
		control_branch_inc = 1;
		control_is_zero = 0;
		data_jump_address = 16;
		#100;
		#1;
		if(instruction == 8) pass = 1; else pass = 0;
		
		//Expected: Instruction = 12 -> Pass
		control_is_jump = 0;
		#100;
		#1;
		if(instruction == 12) pass = 1; else pass = 0;
		
		//Expected: Instruction = 0 -> Pass
		control_is_jump = 1;
		control_branch_eq = 0;
		control_branch_inc = 1;
		control_is_zero = 0;
		data_jump_address = 0;
		#100;
		#1;
		if(instruction == 0) pass = 1; else pass = 0;
		
		//Expected: Instruction = 4 -> Pass
		control_is_jump = 0;
		#100;
		if(instruction == 4) pass = 1; else pass = 0;
		
		//Expected: Instruction = 8 -> Pass
		control_is_jump = 1;
		control_branch_eq = 1;
		control_branch_inc = 0;
		control_is_zero = 0;
		data_jump_address = 0;
		#100;
		#1;
		if(instruction == 8) pass = 1; else pass = 0;
	
		//Expected: Instruction = 4 -> Pass
		control_is_jump = 1;
		control_branch_eq = 1;
		control_branch_inc = 0;
		control_is_zero = 1;
		data_jump_address = 4;
		#100;
		#1;
		if(instruction == 4) pass = 1; else pass = 0;
		
		//Expected: Instruction = 8 -> Pass
		control_is_jump = 0;
		control_branch_eq = 1;
		control_branch_inc = 0;
		control_is_zero = 1;
		data_jump_address = 4;
		#100;
		#1;
		if(instruction == 8) pass = 1; else pass = 0;
		
	end
	
	always
	begin
		#50;
		clock = ~clock;
	end
      
endmodule

