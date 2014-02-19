`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:55:48 02/17/2014
// Design Name:   stage_if
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/PracticoFinal_MIPS/MIPS/stage_if_test1.v
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

module stage_if_test1;

	// Inputs
	reg clock;
	reg reset;
	reg control_use_npc;
	reg [31:0] data_jump_address;

	// Outputs
	wire [31:0] instruction;

	// Instantiate the Unit Under Test (UUT)
	stage_if uut (
		.clock(clock), 
		.reset(reset), 
		.control_use_npc(control_use_npc), 
		.data_jump_address(data_jump_address), 
		.instruction(instruction)
	);

	initial begin
		// Initialize Inputs
		clock = 0;
		reset = 1;
		control_use_npc = 1;
		data_jump_address = 0;


      
endmodule

