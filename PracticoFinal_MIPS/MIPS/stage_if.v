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
    input control_is_jump,
	 input control_branch_eq,
	 input control_branch_inc,
	 input control_is_zero,
    input [31:0] data_jump_address,
    output [31:0] instruction,
	 output reg [31:0] iadd,
	 output isJumped
	 
    );

	wire use_npc;
	wire [31:0] iadd_out;


	assign isJumped = ~use_npc;
	
	always @ (posedge clock)
		iadd = iadd_out;

	pc pc_reg (
		 .clock(clock), 
		 .reset(reset), 
		 .control_use_npc(use_npc), 
		 .data_jump_address(data_jump_address), 
		 .instruction_address(iadd_out)
		 );
	 
	pmem pmemory (
	  .clka(clock),
	  .addra(iadd_out),
	  .douta(instruction)
	);
	
	branch_control bc (
		 .control_is_jump(control_is_jump), 
		 .control_zero(control_is_zero), 
		 .control_branch_eq(control_branch_eq), 
		 .control_branch_inc(control_branch_inc), 
		 .use_npc(use_npc)
	 );
	 
endmodule
