`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:57:36 01/19/2014 
// Design Name: 
// Module Name:    u_program_memory 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module u_program_memory(
    input clock,
	 input [10:0] address,
    output [15:0] out
    );

	
	reg [15:0] outputreg;
	reg [15:0] data [0:2048];
	integer i;
	
	assign out = outputreg;
	
	// inital program // 
	initial
	begin
//		data[0] = 16'b0000_0000_0000_0000;
//		data[1] = 16'b0000_0000_0000_0001;
//		data[2] = 16'b0000_0000_0000_0010;
//		data[3] = 16'b0000_0000_0000_0011;
		
		data[0] = 16'b0001100000000001; //LDi 1
		data[1] = 16'b0000100000000000; //STO 0
		data[2] = 16'b0001100000000010; //LDi 2
		data[3] = 16'b0000100000000001; //STO 1
		data[4] = 16'b0001000000000000; //LD 0
		data[5] = 16'b0010000000000001; //ADD 1
		data[6] = 16'b0000100000000010; //STO 2
		for(i = 7 ; i< 2048 ; i=i+1)
			data[i] = 16'b00000_00000_00000_0;
	end
	
	
	// logic //
	always@(posedge clock)
	begin
		outputreg = data[address];
	end
	

endmodule
