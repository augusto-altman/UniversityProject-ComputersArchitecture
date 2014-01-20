`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:55:03 01/15/2014
// Design Name:   Control
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/Control_test.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Control
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Control_test;

	// Inputs
	reg Clk;
	reg [15:0] Instruction;
	reg Reset;

	// Outputs
	wire [10:0] Addr;
	wire [1:0] SelA;
	wire SelB;
	wire WrAcc;
	wire Op;
	wire WrRam;
	wire RdRam;
	wire [10:0] Operand;

	// Instantiate the Unit Under Test (UUT)
	Control uut (
		.Clk(Clk), 
		.Instruction(Instruction), 
		.Reset(Reset), 
		.Addr(Addr), 
		.SelA(SelA), 
		.SelB(SelB), 
		.WrAcc(WrAcc), 
		.Op(Op), 
		.WrRam(WrRam), 
		.RdRam(RdRam), 
		.Operand(Operand)
	);

	initial begin
		// Initialize Inputs
		Clk = 0;
		Instruction = 0;
		Reset = 0;

		// Wait 100 ns for global reset to finish
		#50;
        
		// Add stimulus here
		Reset = 1;
		#100
		Reset = 0;

	end
	
	always
	begin
		#100 
		Clk = ~Clk;
	end 

	always @ (Addr)
	begin: Memory_Mock
		case (Addr)
			0: Instruction = 16'b0010000000000001;
			1: Instruction = 16'b0000100000000010;
			2: Instruction = 16'b0001100000000011;
			3: Instruction = 16'b0010000000000100;
			4: Instruction = 16'b0011100000000101;
			5: Instruction = 16'b0010100000000110;
			6: Instruction = 16'b0010000000000111;
			7: Instruction = 16'b0000000000001000;
			8: Instruction = 16'b1111100000001001;
		endcase
	end

endmodule

