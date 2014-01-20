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
	 input [0:15] address,
    output [0:15] out
    );

	
	reg [0:15] outputreg;
	reg [0:15] data [0:2048];
	integer i;
	
	assign out = outputreg;
	
	// inital program // 
	initial
	begin
		data[0] = 16'b0000_0000_0000_0000;
		data[1] = 16'b0000_0000_0000_0001;
		data[2] = 16'b0000_0000_0000_0010;
		data[3] = 16'b0000_0000_0000_0011;
		for(i = 4 ; i< 2048 ; i=i+1)
			data[i] = 16'b00000_00000_00000_0;
	end
	
	
	// logic //
	always@(posedge clock)
	begin
		outputreg = data[address];
	end
	

endmodule
