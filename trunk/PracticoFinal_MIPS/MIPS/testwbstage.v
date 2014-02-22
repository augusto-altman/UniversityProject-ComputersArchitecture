`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:53:13 02/19/2014
// Design Name:   wb
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/memwb/testwbstage.v
// Project Name:  memwb
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: wb
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testwbstage;

	// Inputs
	reg [31:0] datafrommem;
	reg [31:0] datafromimm;
	reg [1:0] wb;

	// Outputs
	wire [31:0] datatoregfile;
	wire weregfile;

	// Instantiate the Unit Under Test (UUT)
	wb uut (
		.datafrommem(datafrommem), 
		.datafromimm(datafromimm), 
		.wb(wb), 
		.datatoregfile(datatoregfile), 
		.weregfile(weregfile)
	);

	initial begin
		// Initialize Inputs
		datafrommem = 0;
		datafromimm = 1;
		wb = 0;

		// Wait 100 ns for global reset to finish
		#100;
        wb = 1;
		  #100;
		  wb = 2;
		// Add stimulus here

	end
      
endmodule

