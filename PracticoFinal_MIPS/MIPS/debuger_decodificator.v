`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:57:10 03/14/2014 
// Design Name: 
// Module Name:    debuger_decoder 
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
module debuger_decoder(
    input [7:0] code,
	 input clk,
    output reg [31:0] result,
	 output reg [2:0] size
    );

/* Inputs */
wire [1:0] wbi;
wire [4:0] regaddr;
wire M;
wire [31:0] data, dataaddr;

/* Outputs */
wire [1:0] wbo;
wire [4:0] regaddrout;
wire [31:0] datafrommem, datafromimm;

assign wbi = 2'b11;
assign regaddr = 5'd13;
assign M = 1'b0;
assign data = 32'd10;
assign dataaddr = 32'd1;

mem module_tested (
    .clk(clk),
    .wbi(wbi), 
    .regaddr(regaddr), 
    .wbo(wbo), 
    .M(M), 
    .data(data), 
    .dataaddr(dataaddr), 
    .datafrommem(datafrommem), 
    .datafromimm(datafromimm), 
    .regaddrout(regaddrout)
    );

always @ (*)
begin
	case (code[4:0])
	5'b11010: result = datafrommem;
	5'b11011: result = datafromimm;
	5'b11100: result = regaddrout;
	default: result = 0;
	endcase
	
	size = code[7:5];
end

endmodule
