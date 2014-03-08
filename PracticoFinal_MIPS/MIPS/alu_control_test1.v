`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:50:39 02/24/2014
// Design Name:   alu_control
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/tpfinal/PracticoFinal_MIPS/MIPS/alu_control_test1.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: alu_control
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module alu_control_test1;

	// Inputs
	reg [5:0] funct;
	reg [3:0] oper;

	// Outputs
	wire [3:0] alu_op;

	// Instantiate the Unit Under Test (UUT)
	alu_control uut (
		.funct(funct), 
		.oper(oper), 
		.alu_op(alu_op)
	);

	initial begin
		// Initialize Inputs
		funct = 0;
		oper = 0;

		// Wait 100 ns for global reset to finish
		#100;
		 //0  (add)
		 oper = 0;
		 funct = 6'b100100;
		 
		#10;
		//and 0100
		 oper = 4'b0010;
		 funct = 6'b100100;
		 
        
		// Add stimulus here

	end
      
endmodule

