`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:17:00 02/15/2014
// Design Name:   alu
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/PracticoFinal_MIPS/MIPS/alu_test1.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: alu
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module alu_test1;

	// Inputs
	reg [31:0] a;
	reg [31:0] b;
	reg [2:0] aluop;

	// Outputs
	wire [31:0] out;
	wire zero;

	// Instantiate the Unit Under Test (UUT)
	alu uut (
		.a(a), 
		.b(b), 
		.out(out), 
		.zero(zero), 
		.aluop(aluop)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		b = 0;
		aluop = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		a = 1;
		b = 2;
		#100;
		aluop = 1;
		#100;
		aluop = 2;
		#100;
		a = 3;
		b = 3;
		aluop = 1;
		#100;
		a = 3;
		b = 3;
		aluop = 3;

	end
      
endmodule

