`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:19:58 02/16/2014 
// Design Name: 
// Module Name:    RegisterBank 
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
module RegisterBank(
	 input clock,
    input [4:0] addr1,
    input [4:0] addr2,
    input [4:0] writeAddr,
    input [31:0] writeData,
	 input regWrite,
	 output [31:0] reg1,
	 output [31:0] reg2
    );

reg [31:0] data [31:0] ;
reg [31:0] registro1;
reg [31:0] registro2;

assign reg1 = registro1;
assign reg2 = registro2;

//lectura
always@(posedge clock)
	begin
		registro1 = data[addr1];
		registro2 = data[addr2];
	end
	
// escritura
always@(negedge clock)
	begin
		if(regWrite == 1)
			data[writeAddr] = writeData;
	end
	
	
endmodule
