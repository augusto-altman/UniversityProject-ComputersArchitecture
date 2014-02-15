`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:01:39 02/15/2014
// Design Name:   stage_exe
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/PracticoFinal_MIPS/MIPS/stage_exe_test1.v
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

module stage_exe_test1;

	// Inputs
	reg clock;
	reg reset;
	reg [31:0] data_a;
	reg [31:0] data_b;
	reg [31:0] data_imm;
	reg [2:0] control_alu_op;
	reg control_use_b;
	reg control_is_branch;
	reg [31:0] npc;

	// Outputs
	wire [31:0] out;
	wire use_npc;
	wire [31:0] jump_address;

	// Instantiate the Unit Under Test (UUT)
	stage_exe uut (
		.clock(clock),
		.reset(reset),
		.data_a(data_a), 
		.data_b(data_b), 
		.data_imm(data_imm), 
		.control_alu_op(control_alu_op), 
		.control_use_b(control_use_b), 
		.control_is_branch(control_is_branch), 
		.npc(npc), 
		.out(out), 
		.use_npc(use_npc), 
		.jump_address(jump_address)
	);

	initial begin
		// Initialize Inputs
		clock = 0;
		reset = 1;
		data_a = 0;
		data_b = 0;
		data_imm = 0;
		control_alu_op = 0;
		control_use_b = 0;
		control_is_branch = 0;
		npc = 0;

		// Wait 60 ns for global reset to finish
		#60;
        
		// Add stimulus here
		reset = 0;
		#40;
		//Progam simulation start
		
		//Expected: Out = 5, use_npc = 1, jump_address = 1 -> Pass
		data_a = 3;
		data_b = 2;
		data_imm = 1;
		control_alu_op = 0;
		control_use_b = 1;
		control_is_branch = 0;
		npc = 0;
		#100;
		
		//Expected: Out = 4, use_npc = 1, jump_address = 2 -> Pass
		data_a = 3;
		data_b = 2;
		data_imm = 1;
		control_alu_op = 0;
		control_use_b = 0;
		control_is_branch = 0;
		npc = 1;
		#100;
		
		//Expected: Out = 3, use_npc = 1, jump_address = 3 -> Pass
		data_a = 1;
		data_b = 2;
		data_imm = 1;
		control_alu_op = 2;
		control_use_b = 1;
		control_is_branch = 0;
		npc = 2;
		#100;
		
		//Expected: Out = 6, use_npc = 1, jump_address = 5 -> Pass
		data_a = 4;
		data_b = 3;
		data_imm = 2;
		control_alu_op = 2;
		control_use_b = 0;
		control_is_branch = 0;
		npc = 3;
		#100;
		
		//Expected: Out = 1, use_npc = 1, jump_address = 9 -> Pass
		data_a = 4;
		data_b = 3;
		data_imm = 5;
		control_alu_op = 1;
		control_use_b = 1;
		control_is_branch = 1;
		npc = 4;
		#100;
		
		//Expected: Out = 0, use_npc = 0, jump_address = 12 -> Pass
		data_a = 2;
		data_b = 2;
		data_imm = 7;
		control_alu_op = 1;
		control_use_b = 1;
		control_is_branch = 1;
		npc = 5;
		#100;
		
		//Expected: Out = 0, use_npc = 1, jump_address = 13 -> Pass
		data_a = 2;
		data_b = 2;
		data_imm = 7;
		control_alu_op = 1;
		control_use_b = 1;
		control_is_branch = 0;
		npc = 6;
		#100;

	end
	
	always
	begin
		#50;
		clock = ~clock;
	end
      
endmodule

