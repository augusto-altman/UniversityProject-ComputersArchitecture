`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:53:43 02/24/2014 
// Design Name: 
// Module Name:    branch_control 
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
module branch_control(
    input control_is_jump,
    input control_zero,
	 input nop_exe,
    input control_branch_eq,
    input control_branch_inc,
    output reg use_npc
    );

	always @ *
	begin
		if(~nop_exe)
		begin
			if(control_is_jump)
				use_npc = (control_zero ^ control_branch_eq) && ~control_branch_inc;
			else
				use_npc = 1;
		end
		else
			use_npc = 1;
	end

endmodule
