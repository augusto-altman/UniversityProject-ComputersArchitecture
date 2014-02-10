`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:43:00 01/15/2014
// Design Name:   PC
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/PC_test.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: PC
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module PC_test;

	// Inputs
	reg Clk;
	reg Reset;

	// Outputs
	wire [10:0] Addr;

	// Instantiate the Unit Under Test (UUT)
	PC uut (
		.Clk(Clk), 
		.Reset(Reset), 
		.Addr(Addr)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		Reset = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		Reset = 1;
		#150
		Reset = 0;

	end
      
	always
	begin
		#100 
		Clk = ~Clk;
	end 		

endmodule

