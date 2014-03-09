`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:59:16 02/16/2014 
// Design Name: 
// Module Name:    signExtension 
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
module signExtension(
    input [15:0] instr,
    output [31:0] extendedInstr
    );

assign extendedInstr[31:16] =  {16{instr[15]}};
assign extendedInstr[15:0] =  instr[15:0];

endmodule 


