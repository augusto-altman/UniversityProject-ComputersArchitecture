`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:16:19 01/18/2014
// Design Name:   MuxA
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/bipI/TestMuxA.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: MuxA
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module TestMuxA;

	// Inputs
	reg [15:0] Memory;
	reg [15:0] Immediate;
	reg [15:0] Alu;
	reg [1:0] SelA;

	// Outputs
	wire [15:0] Acc;

	// Instantiate the Unit Under Test (UUT)
	MuxA uut (
		.Memory(Memory), 
		.Immediate(Immediate), 
		.Alu(Alu), 
		.SelA(SelA), 
		.Acc(Acc)
	);

	initial begin
		// Initialize Inputs
		Memory = 0;
		Immediate = 0;
		Alu = 0;
		SelA = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		Memory = 247;
		
		#100;
		
		Immediate = 135;
		SelA=1;
		
		#100;
		
		Alu = 22222;
		SelA = 2;
		
		

	end
      
endmodule

