`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    17:50:01 02/15/2014 
// Design Name: 
// Module Name:    stage_exe 
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
module stage_exe(
	 input clock,
	 input reset,
    input [31:0] data_a,
    input [31:0] data_b,
    input [31:0] data_imm,
    input [2:0] control_alu_op,
    input control_use_b,
    input control_is_branch,
	 input [31:0] npc,
	 //Signals for stage_mem
	 input [1:0] wbi,
    input M,
	 input [3:0] regaddr,
	 //data_b
	 //out
	 //end -- Signals for stage_mem
    output reg [31:0] out,
    output reg use_npc,
    output reg [31:0] jump_address,
	 //Signals for stage_mem
	 output reg [1:0] wbi_o,
    output reg M_o,
	 output reg [3:0] regaddr_o,
	 output reg [31:0] data_b_o
	 //out
	 //end -- Signals for stage_mem
    );

	wire [31:0] t_out, b_entry;
	wire t_zero;
	
	assign b_entry = (control_use_b) ? data_b : data_imm;
	
	alu arith_log_unit (
		 .a(data_a),
		 .b(b_entry),
		 .out(t_out),
		 .zero(t_zero),
		 .aluop(control_alu_op)
		 );
		
	always @ (posedge clock)
	begin
		if (reset)
		begin
			out = 32'd0;
			use_npc = 1;
			jump_address = 32'b0;
		end
		else
		begin
			out = t_out;
			use_npc = ~(control_is_branch && t_zero);
			jump_address = npc + data_imm;
		end
		wbi_o = wbi;
		M_o = M;
		regaddr_o = regaddr;
		data_b_o = data_b;
	end

endmodule
