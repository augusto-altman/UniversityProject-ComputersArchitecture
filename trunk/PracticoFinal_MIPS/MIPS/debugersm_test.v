`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:39:00 03/19/2014
// Design Name:   debugersm
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/tpfinal/PracticoFinal_MIPS/MIPS/debugersm_test.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: debugersm
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module debugersm_test;

	// Inputs
	reg clk;
	reg reset;
	reg rd_empty;
	reg [31:0] result;
	reg [1:0] size;

	// Outputs
	wire wr;
	wire rd;
	wire [7:0] w_data;

	// Instantiate the Unit Under Test (UUT)
	debugersm uut (
		.clk(clk), 
		.reset(reset), 
		.rd_empty(rd_empty), 
		.result(result), 
		.size(size), 
		.wr(wr), 
		.rd(rd), 
		.w_data(w_data)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		rd_empty = 1;
		result = 0;
		size = 0;

		// Wait 100 ns for global reset to finish
		#100;
		
		reset = 0;
		#1;
		rd_empty = 0;
		result = 32'h41424344;
		size = 2'd0;
		#3;
		rd_empty = 1;
		
		
	
	
        
		// Add stimulus here

	end
	
	always
		begin
			clk = ~clk;
			#1;
		end
endmodule

