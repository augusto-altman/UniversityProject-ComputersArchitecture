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
			0: Instruction = 15'b001000000000001;
			1: Instruction = 15'b000010000000010;
			2: Instruction = 15'b000110000000011;
			3: Instruction = 15'b001000000000100;
			4: Instruction = 15'b001110000000101;
			5: Instruction = 15'b001010000000110;
			6: Instruction = 15'b001000000000111;
			7: Instruction = 15'b000000000001000;
			8: Instruction = 15'b111110000001001;
		endcase
	end

endmodule

