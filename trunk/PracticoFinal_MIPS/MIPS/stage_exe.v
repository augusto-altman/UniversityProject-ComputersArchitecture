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
    input [31:0] data_imm, //data_imm[5:0] -> function
    input [3:0] control_oper,
    input control_use_b,
	 input control_Reg_DST,
	 input [31:0] npc,
	 //Signals from forwarding_exe unit
	 input [1:0] for_a,
	 input [1:0] for_b,
	 input [31:0] result_from_exe,
	 input [31:0] result_from_mem,
	 //Signals for stage_if
    input control_is_jump,
	 input control_branch_eq,
	 input control_branch_inc,
    output reg is_jump_o,
	 output reg branch_eq_o,
	 output reg branch_inc_o,
	 output reg zero,
    output reg [31:0] jump_address,
	 //end -- Signals for stage_if
	 //Signals for stage_mem
	 input [1:0] wbi,
	 input M,
	 input [4:0] regaddr1,
	 input [4:0] regaddr2,
	 output reg [4:0] rt_id,
	 output reg [1:0] wbi_o,
    output reg M_o,
	 output reg [4:0] regaddr_o,
	 output reg [31:0] data_b_o,
    output reg [31:0] out
	 //end -- Signals for stage_mem
    );

	wire [31:0] t_out, b_entry, t_jump_address;
	wire [3:0] alu_op;
	wire t_zero;
	reg [31:0] a_processed_entry, b_processed_entry;
	
	assign b_entry = (!control_use_b) ? b_processed_entry : data_imm;
	
	always @ (*)
	begin
		if(for_a == 2'b01)
			a_processed_entry = result_from_exe;
		else if(for_a == 2'b10)
			a_processed_entry = result_from_mem;
		else
			a_processed_entry = data_a;
			
		if(for_b == 2'b01)
			b_processed_entry = result_from_exe;
		else if(for_b == 2'b10)
			b_processed_entry = result_from_mem;
		else
			b_processed_entry = data_b;
	end
	
	//assign t_jump_address = npc + data_imm;
	
	adder_32b instance_name (
    .a(npc), 
    .b(data_imm), 
    .c(t_jump_address)
    );
	
	alu arith_log_unit (
		 .a(a_processed_entry),
		 .b(b_entry),
		 .aluop(alu_op),
		 .out(t_out),
		 .zero(t_zero)
		 );
		 
	alu_control ac (
		 .funct(data_imm[5:0]), 
		 .oper(control_oper), 
		 .alu_op(alu_op)
		 );
		
	always @ (posedge clock)
	begin
		if (reset)
		begin
			out = 32'b0;
			jump_address = 32'b0;
			is_jump_o = 0;
			branch_eq_o = 1'b0;
			branch_inc_o = 1'b0;
			zero = 1'b0;
			wbi_o = 2'b0;
			M_o = 1'b0;
			data_b_o = 32'b0;
			regaddr_o = 0;
		end
		else
		begin
			out = t_out;
			zero = t_zero;
			jump_address = t_jump_address;
			is_jump_o = control_is_jump;
			branch_eq_o = control_branch_eq;
			branch_inc_o = control_branch_inc;
			wbi_o = wbi;
			M_o = M;
			data_b_o = b_processed_entry;
			if(control_Reg_DST)
				regaddr_o = regaddr1; //1
			else
				regaddr_o = regaddr2; //0
			rt_id = regaddr2;
		end
	end

endmodule
