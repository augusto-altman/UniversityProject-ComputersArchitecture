`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:32:19 02/15/2014 
// Design Name: 
// Module Name:    stage_if 
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
module stage_if(
    input clock,
    input reset,
    input control_use_npc,
    input [31:0] data_jump_address,
    output reg [31:0] instruction
    );

	wire [31:0] iadd;
	wire instr;

	pc pc_reg (
		 .clock(clock), 
		 .reset(reset), 
		 .control_use_npc(control_use_npc), 
		 .data_jump_address(data_jump_address), 
		 .instruction_address(iadd)
		 );
	 
	program_memory mem (
		 .dir(iadd), 
		 .instr(instr)
		 );
		 
	always @ (posedge clock)
		instruction = instr;
	 
endmodule
