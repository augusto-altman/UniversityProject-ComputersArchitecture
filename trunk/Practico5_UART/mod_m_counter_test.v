`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:55:56 01/23/2014
// Design Name:   mod_m_counter
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Arquitectura de las computadoras/Practico5_UART/mod_m_counter_test.v
// Project Name:  Practico5_UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mod_m_counter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module mod_m_counter_test;

	// Inputs
	reg clk;
	reg reset;

	// Outputs
	wire max_tick;
	wire [1:0] q;

	// Instantiate the Unit Under Test (UUT)
	mod_m_counter #(.M(3), .N(2)) uut (
		.clk(clk), 
		.reset(reset), 
		.max_tick(max_tick), 
		.q(q)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 0;

		// Wait 100 ns for global reset to finish
		#50;
		reset = 1;
		#100;
		reset = 0;
        
		// Add stimulus here

	end
	
	always
	begin
		#100;
		clk = ~clk;
	end
      
endmodule

