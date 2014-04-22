`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:03:41 04/08/2014
// Design Name:   adder_32b
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/PracticoFinal_MIPS/MIPS/test_exe_adder_iadd.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: adder_32b
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_exe_adder_iadd;

	// Inputs
	reg [31:0] a;
	reg [31:0] b;

	// Outputs
	wire [31:0] c;

	// Instantiate the Unit Under Test (UUT)
	adder_32b uut (
		.a(a), 
		.b(b), 
		.c(c)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		b = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		a = 10;
		b = -2;

	end
      
endmodule

