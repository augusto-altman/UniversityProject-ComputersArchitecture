`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:36:07 02/15/2014 
// Design Name: 
// Module Name:    pc 
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
module pc(
    input clock,
    input reset,
    input control_use_npc,
    input [31:0] data_jump_address,
	 output [31:0] instruction_address
    );

	reg [31:0] pc;
	assign instruction_address = pc;
	
	always @ (negedge clock)
	begin
		if (reset)
			pc = 32'b0;
		else
		begin
			if(control_use_npc)
				pc = pc + 4;
			else
				pc = data_jump_address;
		end
	end

endmodule
