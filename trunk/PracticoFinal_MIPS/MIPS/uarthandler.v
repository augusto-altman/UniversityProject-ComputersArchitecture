`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:13:35 03/08/2014 
// Design Name: 
// Module Name:    uarthandler 
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
module uarthandler(
    input clk,
    input reset,
    input rx,
    output tx
    );
	
wire rd_empty;
wire [7:0] r_data;
uart uartt (
    .clk(clk), 
    .reset(reset), 
    .rx(rx), 
    .rd(~rd_empty), 
    .wr(~rd_empty), 
    .rd_empty(rd_empty), 
    .wr_full(), 
    .w_data(r_data), 
    .tx(tx), 
    .r_data(r_data)
    );
	 


endmodule
