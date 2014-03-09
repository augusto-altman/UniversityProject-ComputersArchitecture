`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:50:47 03/04/2014
// Design Name:   signExtension
// Module Name:   D:/Estudio/facu/arquitectura de computadoras/final/workspace - trunk/PracticoFinal_MIPS/MIPS/testSignExtension.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: signExtension
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testSignExtension;

	// Inputs
	reg [15:0] instr;

	// Outputs
	wire [31:0] extendedInstr;

	// Instantiate the Unit Under Test (UUT)
	signExtension uut (
		.instr(instr), 
		.extendedInstr(extendedInstr)
	);

	initial begin
		// Initialize Inputs
		instr = 0;

		// Wait 100 ns for global reset to finish
		#100; 
        
		// Add stimulus here
	instr = 5;
	#10;
		//
	instr = -5;
	#10;
		
	end
      
endmodule

