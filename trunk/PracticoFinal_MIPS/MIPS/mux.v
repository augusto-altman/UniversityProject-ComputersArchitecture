`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:03:30 02/17/2014 
// Design Name: 
// Module Name:    mux 
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
module mux(
    input [31:0] mem,
    input [31:0] imm,
    input sel,
    output [31:0] toWriteData
    );
	 
reg [31:0] out;

assign toWriteData = out;

always @ (mem or imm or sel)
begin
	if(sel)
		out = imm;
	else
		out = mem;
end

endmodule
