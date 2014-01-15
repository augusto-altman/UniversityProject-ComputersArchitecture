`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:37:25 01/15/2014 
// Design Name: 
// Module Name:    PC 
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
module PC(
    input Clk,
	 input Reset,
    output reg [10:0] Addr
    );

	always @ (posedge Clk)
	begin
		if(Reset)
			Addr = 0;
		else
			Addr = Addr + 1;
	end

endmodule
