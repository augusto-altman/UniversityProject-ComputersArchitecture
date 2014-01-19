`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:43:16 01/18/2014
// Design Name:   MuxB
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/bipI/MuxBTest.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: MuxB
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module MuxBTest;

	// Inputs
	reg [15:0] Memory;
	reg [15:0] Immediate;
	reg SelB;

	// Outputs
	wire [15:0] Alu;

	// Instantiate the Unit Under Test (UUT)
	MuxB uut (
		.Memory(Memory), 
		.Immediate(Immediate), 
		.SelB(SelB), 
		.Alu(Alu)
	);

	initial begin
		// Initialize Inputs
		Memory = 0;
		Immediate = 0;
		SelB = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		Memory = 247;
		
		#100;
		
		Immediate= 2222;
		SelB=1;
		
		end
      
endmodule

