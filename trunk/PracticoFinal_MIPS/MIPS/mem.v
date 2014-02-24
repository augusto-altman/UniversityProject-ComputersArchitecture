`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:33:57 02/17/2014 
// Design Name: 
// Module Name:    mem 
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
module mem(
	 input clk,
    input [1:0] wbi,
	 input [4:0] regaddr,
    output reg [1:0] wbo,
    input M,
    input [31:0] data,
    input [31:0] dataaddr,
	 output reg [31:0] datafrommem,
    output reg [31:0] datafromimm,
	 output reg [4:0] regaddrout
    );
	 
	 wire [31:0] douta;
	 
	rammemory memory (
  .clka(clk), // input clka
  .wea(M), // input [0 : 0] wea
  .addra(dataaddr), // input [12 : 0] addra
  .dina(data), // input [31 : 0] dina
  .douta(douta) // output [31 : 0] douta
);
	 
	 always @ (posedge clk)
	 begin
		wbo = wbi;
		datafromimm = dataaddr;
		datafrommem = douta;
		regaddrout = regaddr;
	 end


endmodule
