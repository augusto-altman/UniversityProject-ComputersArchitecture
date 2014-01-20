`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:55:26 01/19/2014
// Design Name:   u_data_memory
// Module Name:   D:/Estudio/facu/arquitectura de computadoras/final/memorias/dataMemTest.v
// Project Name:  memorias
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: u_data_memory
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

 module dataMemTest;

	// Inputs
	reg read;
	reg write;
	reg [0:15] address;
	reg [0:15] in_data;

	// Outputs
	wire [0:15] out_data;

	// Instantiate the Unit Under Test (UUT)
	u_data_memory uut (
		.read(read), 
		.write(write), 
		.address(address), 
		.in_data(in_data), 
		.out_data(out_data)
	);

	initial begin
		// Initialize Inputs
		read = 0;
		write = 0;
		address = 0;
		in_data = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here


		// write 1st data
		#100;
		in_data = 16'b0000_0000_0000_1010;
		address = 10'b10_1010_1010;
		#10;
		write = 1;
		#20;
		write = 0;
		address = 0;
		in_data = 0;
		#100
		
		// write 2nd data
		in_data = 16'b1111_0000_1111_0000;
		address = 16'b11_1111_1111;
		#10;
		write = 1;
		#20;
		write = 0;
		address = 0;
		in_data = 0;
		#100;
		
		// read 1st data: 
		address = 16'b10_1010_1010;
		#10;
		read = 1;
		#20;
		read = 0;
		#100;
		
		//read 2nd data:
		address = 16'b11_1111_1111;
		#10;
		read = 1;
		#20;
		read = 0;
		#100;
		
		
		
	end
      
endmodule

