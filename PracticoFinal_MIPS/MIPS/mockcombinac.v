`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:58:43 03/14/2014 
// Design Name: 
// Module Name:    mockcombinac 
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
module mockcombinac(
    input [7:0] code,
    output [31:0] data,
    output [2:0] datasize,
    input clk
    );
	 reg [31:0] out;
	 reg [2:0] size;
	 always @*
	 begin
		if (code)
		begin
			out = (32'b11010100);
			size = 3'd4;
		end
	 end

assign data = out;
assign datasize = size;

endmodule
