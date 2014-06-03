`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:03:11 06/01/2014 
// Design Name: 
// Module Name:    StallHandler 
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
module StallHandler(
	 input clock,
	 input reset,
    input isFromAlu,
	 input nop_exe,
	 input reg_Dst,
    input [4:0] regAddrOutAlu,
    input [4:0] regAddrInRs,
    input [4:0] regAddrInRt,
	 input [4:0] regAddrInRd,
    output reg		stall
    );
		
	wire [4:0] regAddrParam;
	
	assign regAddrParam = (reg_Dst) ? regAddrInRt : regAddrInRd ;
	reg  counter;
	always@(negedge clock)
	begin
		if(reset)
		begin
			stall = 0;
			counter = 0;
		end
		else if(~isFromAlu )
		begin
			if((regAddrOutAlu == regAddrInRs || regAddrOutAlu == regAddrParam) && ~counter )
			begin
				stall = 1 && ~nop_exe; // si debo poner stall Y no es un nop. => stall
				counter = 1;
			end
			else
			begin
				stall = 0;
				counter = 0;
			end
		end
		else
			stall = 0;
	end

endmodule
