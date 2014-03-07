`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:58:04 02/25/2014
// Design Name:   stage_exe
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/PracticoFinal_MIPS/MIPS/stage_exe_test2.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: stage_exe
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module stage_exe_test2;

	// Inputs
	reg clock;
	reg reset;
	reg [31:0] data_a;
	reg [31:0] data_b;
	reg [31:0] data_imm;
	reg [3:0] control_oper;
	reg control_use_b;
	reg control_Reg_DST;
	reg [31:0] npc;
	reg control_is_jump;
	reg control_branch_eq;
	reg control_branch_inc;
	reg [1:0] wbi;
	reg M;
	reg [4:0] regaddr1;
	reg [4:0] regaddr2;

	// Outputs
	wire is_jump_o;
	wire branch_eq_o;
	wire branch_inc_o;
	wire zero;
	wire [31:0] jump_address;
	wire [1:0] wbi_o;
	wire M_o;
	wire [4:0] regaddr_o;
	wire [31:0] data_b_o;
	wire [31:0] out;

	// Instantiate the Unit Under Test (UUT)
	stage_exe uut (
		.clock(clock), 
		.reset(reset), 
		.data_a(data_a), 
		.data_b(data_b), 
		.data_imm(data_imm), 
		.control_oper(control_oper), 
		.control_use_b(control_use_b), 
		.control_Reg_DST(control_Reg_DST), 
		.npc(npc), 
		.control_is_jump(control_is_jump), 
		.control_branch_eq(control_branch_eq), 
		.control_branch_inc(control_branch_inc), 
		.is_jump_o(is_jump_o), 
		.branch_eq_o(branch_eq_o), 
		.branch_inc_o(branch_inc_o), 
		.zero(zero), 
		.jump_address(jump_address), 
		.wbi(wbi), 
		.M(M), 
		.regaddr1(regaddr1), 
		.regaddr2(regaddr2), 
		.wbi_o(wbi_o), 
		.M_o(M_o), 
		.regaddr_o(regaddr_o), 
		.data_b_o(data_b_o), 
		.out(out)
	);

	initial begin
		// Initialize Inputs
		clock = 1;
		reset = 1;
		data_a = 0;
		data_b = 0;
		data_imm = 0;
		control_oper = 0;
		control_use_b = 0;
		control_Reg_DST = 0;
		npc = 0;
		control_is_jump = 0;
		control_branch_eq = 0;
		control_branch_inc = 0;
		wbi = 0;
		M = 0;
		regaddr1 = 0;
		regaddr2 = 0;
		
		// Wait 110 ns for global reset to finish
		#110;
        
		// Add stimulus here
		reset = 0;
		#90;
		//Progam simulation start
		
		//Expected: Out = 5 -> Pass
		data_a = 3;
		data_b = 2;
		data_imm = 32'b00000000000000000000000000100000;
		control_oper = 4'b0010;
		control_use_b = 1;
		npc = 0;
		#100;
		
		//Expected: Out = 1 -> Pass
		data_a = 3;
		data_b = 2;
		data_imm = 32'b00000000000000000000000000100010;
		control_oper = 4'b0010;
		control_use_b = 1;
		npc = 1;
		#100;
		
		//Expected: Out = 4 -> Pass
		data_a = 3;
		data_b = 2;
		data_imm = 32'b00000000000000000000000000000001;
		control_oper = 4'b1000;
		control_use_b = 0;
		npc = 2;
		#100;
		
		//Expected: Out = 1 -> Pass
		data_a = 3;
		data_b = 2;
		data_imm = 32'b00000000000000000000000000000001;
		control_oper = 4'b1100;
		control_use_b = 0;
		npc = 3;
		#100;
		
		//Expected: Out = 0, zero = 1, jump_address = 11 -> 
		data_a = 3;
		data_b = 3;
		data_imm = 32'b00000000000000000000000000000111;
		control_oper = 4'b0001;
		control_use_b = 1;
		npc = 4;
		#100;

	end
      
	always
	begin
		#50;
		clock = ~clock;
	end		

endmodule

