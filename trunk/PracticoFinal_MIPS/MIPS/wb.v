`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:45:00 02/19/2014 
// Design Name: 
// Module Name:    wb 
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
module wb(
    input [31:0] datafrommem,
    input [31:0] datafromimm,
    input [1:0] wb,
    output [31:0] datatoregfile,
    output weregfile
    );
	 
	 assign weregfile = wb[1];
	 mux multix (
    .mem(datafrommem), 
    .imm(datafromimm), 
    .sel(wb[0]), 
    .toWriteData(datatoregfile)
    );


endmodule
