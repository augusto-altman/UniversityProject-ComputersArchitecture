`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   19:40:46 02/17/2014
// Design Name:   rammemory
// Module Name:   D:/facu/Arquitecturas de las computadoras/Practico/memwb/testmem.v
// Project Name:  memwb
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: rammemory
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testmem;

	// Inputs
	reg clka;
	reg [0:0] wea;
	reg [12:0] addra;
	reg [31:0] dina;

	// Outputs
	wire [31:0] douta;

	// Instantiate the Unit Under Test (UUT)
	rammemory uut (
		.clka(clka), 
		.wea(wea), 
		.addra(addra), 
		.dina(dina), 
		.douta(douta)
	);

	initial begin
		// Initialize Inputs
		clka = 0;
		wea = 0; // write enable ?
		addra = 0; // direccion de los datos (para leer o escribir)
		dina = 0; // entrada de datos para grabar.

		// Wait 100 ns for global reset to finish
		#100;
		wea = 1;
		addra= 1;
		dina = 1;
		#2
		wea =1;
		addra = 2;
		dina = 2;
		#2
		wea =1;
		addra = 3;
		dina = 3;
		#2
		wea =1;
		addra = 4;
		dina = 4;
		#2;
		wea = 0;
		addra = 1;
		#2;
		wea = 0;
		addra = 2;
		#2;
		wea = 0;
		addra = 3;
		#2;
		wea = 0;
		addra = 4;
		
		
        
		// Add stimulus here

	end
      
	always
	begin
		#1 
		clka = ~clka;
	end
endmodule

