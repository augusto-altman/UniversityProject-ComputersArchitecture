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
	 input reset,
    input [1:0] wbi,
	 input [4:0] regaddr,
    output reg [1:0] wbo,
    input M,
	 input nop_exe,
    input [31:0] data,
    input [31:0] dataaddr,
	 input forw,
	 input [31:0] result_from_mem,
	 output  [31:0] datafrommem,
    output reg [31:0] datafromimm,
	 output reg [4:0] regaddrout,
	 output reg nop
    );
	 
	 wire [31:0] douta;
	 
	 reg [31:0] processed_entry;
	 wire processed_M = (nop_exe)? 1'b0 : M; 
	 
	always @ (*)
	begin
		if(forw == 1)
			processed_entry = result_from_mem;
		else
			processed_entry = data;
	end
	 
	 
	 
	rammemory memory (
  .clka(clk), // input clka
  .wea(processed_M), // input [0 : 0] wea
  .addra(dataaddr), // input [12 : 0] addra
  .dina(processed_entry), // input [31 : 0] dina
  .douta(datafrommem), // output [31 : 0] douta
  .rsta(reset)
);
	 
	 always @ (posedge clk)
	 begin
	   if (reset)
			begin
				wbo = 2'b0;
				datafromimm = 32'b0;
				//datafrommem = 32'b0;
				regaddrout = 5'b0;
				nop = 1;
			end
		wbo = wbi;
		datafromimm = dataaddr;
		regaddrout = regaddr;
		nop = nop_exe;
	 end


endmodule
