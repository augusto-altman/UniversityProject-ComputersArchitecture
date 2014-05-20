`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:05:33 03/05/2014 
// Design Name: 
// Module Name:    GetRegAddr 
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
module GetRegAddr(
    input [31:0] instr,
    output reg [4:0] regAddr1,
    output reg [4:0] regAddr2,
	 output reg [4:0] rs
    );


always@(*)
begin
	regAddr1 			= instr[15:11];
	regAddr2 			= instr[20:16];
	rs						= instr[25:21];
end

endmodule
