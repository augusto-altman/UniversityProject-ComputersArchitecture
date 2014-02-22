`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:07:58 02/17/2014
// Design Name:   mux
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/memwb/testmux.v
// Project Name:  memwb
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mux
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testmux;

	// Inputs
	reg [15:0] mem;
	reg [15:0] imm;
	reg sel;
	
	wire [15:0] toWriteData;

	// Instantiate the Unit Under Test (UUT)
	mux uut (
		.mem(mem), 
		.imm(imm), 
		.sel(sel), 
		.toWriteData(toWriteData)
	);

	initial begin
		// Initialize Inputs
		mem = 10;
		imm = 0;
		sel = 0;

		// Wait 100 ns for global reset to finish
		#100;
		sel = 1;
		#100;
		sel = 0;
        
		// Add stimulus here

	end
      
endmodule

