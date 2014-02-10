`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:57:46 01/18/2014
// Design Name:   Acc
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/bipI/AccTest.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Acc
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module AccTest;

	// Inputs
	reg [15:0] SelA;
	reg WrAcc;
	reg Clock;

	// Outputs
	wire [15:0] AccOut;

	// Instantiate the Unit Under Test (UUT)
	Acc uut (
		.SelA(SelA), 
		.WrAcc(WrAcc), 
		.Clock(Clock), 
		.AccOut(AccOut)
	);

	initial begin
		// Initialize Inputs
		SelA = 0;
		WrAcc = 0;
		Clock=0;

		// Wait 100 ns for global reset to finish
		#100;
        
		SelA = 247;
		
		#100;
		
		WrAcc = 1;
		
		#100;
		
		SelA = 2222;
		
		#50
		WrAcc=0;

	end
	
	always
	begin
		#10 
		Clock = ~Clock;
	end 
      
endmodule

