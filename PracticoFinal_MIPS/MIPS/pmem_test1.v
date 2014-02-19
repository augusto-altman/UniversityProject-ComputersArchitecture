`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:48:16 02/17/2014
// Design Name:   pmem
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/PracticoFinal_MIPS/MIPS/pmem_test1.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: pmem
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module pmem_test1;

	// Inputs
	reg clka;
	reg [10:0] addra;

	// Outputs
	wire [31:0] douta;

	// Instantiate the Unit Under Test (UUT)
	pmem uut (
		.clka(clka), 
		.addra(addra), 
		.douta(douta)
	);

	initial begin
		// Initialize Inputs
		clka = 0;
		addra = 0;

		// Wait 100 ns for global reset to finish
		#50;
        
		// Add stimulus here
		addra = addra + 1;
		#100;
		
		addra = addra + 1;
		#100;
		
		addra = addra + 1;
		#100;
		
		addra = addra + 1;
		#100;

	end
	
	always
	begin
		#50;
		clka = ~clka;
	end
      
endmodule

