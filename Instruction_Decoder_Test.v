`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:20:01 01/15/2014
// Design Name:   Instruction_Decoder
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/Instruction_Decoder_Test.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Instruction_Decoder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Instruction_Decoder_Test;

	// Inputs
	reg [4:0] Opcode;

	// Outputs
	wire [1:0] SelA;
	wire SelB;
	wire WrAcc;
	wire Op;
	wire WrRam;
	wire RdRam;

	// Instantiate the Unit Under Test (UUT)
	Instruction_Decoder uut (
		.Opcode(Opcode), 
		.SelA(SelA), 
		.SelB(SelB), 
		.WrAcc(WrAcc), 
		.Op(Op), 
		.WrRam(WrRam), 
		.RdRam(RdRam)
	);

	initial begin
		// Initialize Inputs
		Opcode = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		Opcode = 1;
		#100;
		Opcode = 2;
		#100;
		Opcode = 3;
		#100;
		Opcode = 4;
		#100;
		Opcode = 5;
		#100;
		Opcode = 6;
		#100;
		Opcode = 7;
	end
      
endmodule

