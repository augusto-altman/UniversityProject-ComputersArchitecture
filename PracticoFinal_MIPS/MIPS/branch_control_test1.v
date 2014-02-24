`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:00:36 02/24/2014
// Design Name:   branch_control
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/PracticoFinal_MIPS/MIPS/branch_control_test1.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: branch_control
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module branch_control_test1;

	// Inputs
	reg control_is_jump;
	reg control_zero;
	reg control_branch_eq;
	reg control_branch_inc;

	// Outputs
	wire use_npc;

	// Instantiate the Unit Under Test (UUT)
	branch_control uut (
		.control_is_jump(control_is_jump), 
		.control_zero(control_zero), 
		.control_branch_eq(control_branch_eq), 
		.control_branch_inc(control_branch_inc), 
		.use_npc(use_npc)
	);

	initial begin
		// Initialize Inputs
		control_is_jump = 0;
		control_zero = 0;
		control_branch_eq = 0;
		control_branch_inc = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		//Expected result: use_npc = 1
		control_is_jump = 0;
		control_zero = 1;
		control_branch_eq = 0;
		control_branch_inc = 1;
		#10;
		
		//Expected result: use_npc = 1
		control_is_jump = 1;
		control_zero = 0;
		control_branch_eq = 1;
		control_branch_inc = 0;
		#10;
		
		//Expected result: use_npc = 0
		control_is_jump = 1;
		control_zero = 1;
		control_branch_eq = 1;
		control_branch_inc = 0;
		#10;
		
		//Expected result: use_npc = 0
		control_is_jump = 1;
		control_zero = 0;
		control_branch_eq = 1;
		control_branch_inc = 1;
		#10;
		
		//Expected result: use_npc = 0
		control_is_jump = 1;
		control_zero = 1;
		control_branch_eq = 1;
		control_branch_inc = 1;
		#10;
		
		//Expected result: use_npc = 1
		control_is_jump = 1;
		control_zero = 1;
		control_branch_eq = 0;
		control_branch_inc = 0;
		#10;
		
		//Expected result: use_npc = 1
		control_is_jump = 1;
		control_zero = 0;
		control_branch_eq = 1;
		control_branch_inc = 0;
		#10;
		
		//Expected result: use_npc = 0
		control_is_jump = 1;
		control_zero = 0;
		control_branch_eq = 0;
		control_branch_inc = 1;

	end
      
endmodule

