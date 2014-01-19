`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:28:50 01/18/2014
// Design Name:   Datapath
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/bipI/DatapathTest.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Datapath
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module DatapathTest;

	// Inputs
	reg [1:0] SelA;
	reg SelB;
	reg [10:0] Addr;
	reg WrAcc;
	reg Op;
	reg Clock;
	reg [15:0] Out_Data;

	// Outputs
	wire [15:0] In_Data;

	// Instantiate the Unit Under Test (UUT)
	Datapath uut (
		.SelA(SelA), 
		.SelB(SelB), 
		.Addr(Addr), 
		.WrAcc(WrAcc), 
		.Op(Op), 
		.Clock(Clock), 
		.In_Data(In_Data), 
		.Out_Data(Out_Data)
	);

	initial begin
		// Initialize Inputs
		SelA = 0;
		SelB = 0;
		Addr = 0;
		WrAcc = 0;
		Op = 0;
		Clock = 0;
		Out_Data = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		SelA = 1;
		Addr = 247;
		WrAcc = 1;
		
		#10;
		
		WrAcc = 0;
		
		#10;
		
		Out_Data = 13;
		SelA = 2;
		
		WrAcc=1;
		#11;
		WrAcc=0;
		
	end
	
	always
	begin
		#5
		Clock = ~Clock;
	end 
      
endmodule

