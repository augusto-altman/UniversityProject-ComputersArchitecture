`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:39:37 01/19/2014 
// Design Name: 
// Module Name:    U_Data_memoriy 
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
module u_data_memory(
    input read,
    input write,
    input [0:10] address,
    input [0:15] in_data,
    output [0:15] out_data
    );


	reg [0:15] outputer;
	reg [0:15] data [0:2047];
	integer i;
	
	assign out_data = outputer;
	
	initial
	begin
		outputer = 0;
		for(i = 0 ; i< 2048 ; i=i+1)
			data[i] = 16'b00000_00000_00000_0;
	end
	
	always@(posedge read, posedge write )
	begin
		if(read == 1)
			outputer = data[address];
		else if( write == 1)
			data[address] = in_data;
	end
	
	
endmodule
