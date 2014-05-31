`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:58:36 03/31/2014
// Design Name:   debuger_decoder
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/tpfinal/PracticoFinal_MIPS/MIPS/testdeco.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: debuger_decoder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testdeco;

	// Inputs
	//reg clk;
	reg reset;
	reg [7:0] code;
	
	wire [31:0] result;
	reg [1:0] size;

	// Instantiate the Unit Under Test (UUT)
	debuger_decoder uut (
		//.clk(clk),
		.code(code),
		.result(result), 
		.reset(reset),
		.size(size)
	);

	initial begin
		// Initialize Inputs
		code = 8'b00111111;
		reset = 1;

		// Wait 100 ns for global reset to finish
		#10;
		reset = 0;
	
		// Add stimulus here

	end
	
	always
	begin
		code = 8'b00111111;
		#1;
		code = 8'b00111000;
		#1;
	end
      
endmodule

