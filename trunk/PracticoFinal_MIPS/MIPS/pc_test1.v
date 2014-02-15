`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:43:18 02/15/2014
// Design Name:   pc
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/PracticoFinal_MIPS/MIPS/pc_test1.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: pc
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module pc_test1;

	// Inputs
	reg clock;
	reg reset;
	reg control_use_npc;
	reg [31:0] data_jump_address;

	// Outputs
	wire [31:0] instruction_address;

	// Instantiate the Unit Under Test (UUT)
	pc uut (
		.clock(clock), 
		.reset(reset), 
		.control_use_npc(control_use_npc), 
		.data_jump_address(data_jump_address), 
		.instruction_address(instruction_address)
	);

	initial begin
		// Initialize Inputs
		clock = 0;
		reset = 1;
		control_use_npc = 0;
		data_jump_address = 0;

		// Wait 60 ns for global reset to finish
		#60;
        
		// Add stimulus here
		reset = 0;
		#40;
		
		//Expected: instruction_address = 4 -> Pass
		control_use_npc = 1;
		data_jump_address = 1;
		#100;

		//Expected: instruction_address = 8 -> Pass
		control_use_npc = 1;
		data_jump_address = 7;
		#100;
		
		//Expected: instruction_address = 15 -> Pass
		control_use_npc = 0;
		data_jump_address = 15;
		#100;
		
		//Expected: instruction_address = 19 -> Pass
		control_use_npc = 1;
		data_jump_address = 2;
		#100;
		
		//Expected: instruction_address = 3 -> Pass
		control_use_npc = 0;
		data_jump_address = 3;
		#100;
		
		//Expected: instruction_address = 7 -> Pass
		control_use_npc = 1;
		data_jump_address = 12;
		#100;

		//Expected: instruction_address = 11 -> Pass
		control_use_npc = 1;
		data_jump_address = 10;
		#100;
	end
	
	always
	begin
		#50;
		clock = ~clock;
	end
      
endmodule

