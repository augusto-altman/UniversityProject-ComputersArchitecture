`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:38:47 01/18/2014 
// Design Name: 
// Module Name:    MuxB 
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
module MuxB(
    input [15:0] Memory,
    input [15:0] Immediate,
    input SelB,
    output [15:0] Alu
    );

	 reg [15:0] Output;
	 assign Alu = Output;
	 
	 always @ (Memory or Immediate or SelB)
		case(SelB)
      2'd0: Output = Memory;
      2'd1: Output = Immediate;
      default: Output = 0;
      endcase

endmodule
