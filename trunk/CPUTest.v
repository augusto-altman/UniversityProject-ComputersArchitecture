`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:24:22 01/19/2014
// Design Name:   CPU
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/bipI/CPUTest.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CPU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module CPUTest;

	// Inputs
	reg [15:0] Instruction;
	reg [15:0] Out_Data;
	reg Clock;
	reg Reset;

	// Outputs
	wire [10:0] InsAddr;
	wire Rd;
	wire Wr;
	wire [10:0] DataAddr;
	wire [15:0] In_Data;

	// Instantiate the Unit Under Test (UUT)
	CPU uut (
		.InsAddr(InsAddr), 
		.Instruction(Instruction), 
		.Rd(Rd), 
		.Wr(Wr), 
		.DataAddr(DataAddr), 
		.In_Data(In_Data), 
		.Out_Data(Out_Data), 
		.Clock(Clock), 
		.Reset(Reset)
	);

	initial begin
		// Initialize Inputs
		Instruction = 0;
		Out_Data = 0;
		Clock = 0;
		Reset = 0;

		// Wait 100 ns for global reset to finish
		#100;

		Instruction= 16'b 0001100001010101;
        
		// Add stimulus here

	end
      
	always
	begin
		#1 
		Clock = ~Clock;
	end 
endmodule

