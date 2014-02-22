`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:43:11 02/17/2014
// Design Name:   mem
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/memwb/testmemstage.v
// Project Name:  memwb
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: mem
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testmemstage;

	// Inputs
	reg clk;
	reg [1:0] wbi;
	reg [3:0] regaddr;
	reg M;
	reg [31:0] data;
	reg [31:0] dataaddr;

	// Outputs
	wire [1:0] wbo;
	wire [31:0] datafrommem;
	wire [31:0] datafromimm;
	wire [3:0] regaddrout;

	// Instantiate the Unit Under Test (UUT)
	mem uut (
		.clk(clk), 
		.wbi(wbi), 
		.regaddr(regaddr), 
		.wbo(wbo), 
		.M(M), 
		.data(data), 
		.dataaddr(dataaddr), 
		.datafrommem(datafrommem), 
		.datafromimm(datafromimm), 
		.regaddrout(regaddrout)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		wbi = 0;
		regaddr = 0;
		M = 0;
		data = 0;
		dataaddr = 0;

		// Wait 100 ns for global reset to finish
		#100;
      wbi = 3;
		regaddr = 13;
		data = 10;
		dataaddr = 1;
		#2;
		M = 1;
		#2;
		M = 0;
		// Add stimulus here

	end
      
	always
	begin
		#1 
		clk = ~clk;
	end
endmodule

