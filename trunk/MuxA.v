`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:05:34 01/18/2014 
// Design Name: 
// Module Name:    MuxA 
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
module MuxA(
    input [15:0] Memory,
    input [15:0] Immediate,
    input [15:0] Alu,
	 input [1:0] SelA,
    output [15:0] Acc
    );
	 
	 reg [15:0] Accumulator;
	 assign Acc = Accumulator;
	 
	 always @ (Memory or Immediate or Alu or SelA)
		case(SelA)
      2'd0: Accumulator = Memory;
      2'd1: Accumulator = Immediate;
      2'd2: Accumulator = Alu;
      default: Accumulator = 0;
      endcase
endmodule
