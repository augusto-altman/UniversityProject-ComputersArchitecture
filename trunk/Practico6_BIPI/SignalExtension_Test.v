`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:43:01 01/18/2014
// Design Name:   SignalExtension
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/bipI/SignalExtension_Test.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: SignalExtension
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module SignalExtension_Test;

	// Inputs
	reg [10:0] eleven;

	// Outputs
	wire [15:0] sixteen;

	// Instantiate the Unit Under Test (UUT)
	SignalExtension uut (
		.eleven(eleven), 
		.sixteen(sixteen)
	);

	initial begin
		// Initialize Inputs
		eleven = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		eleven = 247;
		#100;
		eleven = 1024;
		
	end
      
endmodule

