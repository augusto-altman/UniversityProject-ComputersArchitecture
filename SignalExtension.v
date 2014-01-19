`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:25:16 01/18/2014 
// Design Name: 
// Module Name:    SignalExtension 
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
module SignalExtension(
    input [10:0] eleven,
    output [15:0] sixteen
    );
reg [15:0]Sig;

assign sixteen=Sig;

always  @ (eleven)
begin
	Sig = eleven;
end

endmodule
