`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:00:11 02/15/2014 
// Design Name: 
// Module Name:    program_memory 
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
module program_memory(
    input [31:0] dir,
	 input record,
    output reg [31:0] instr
    );

	reg [31:0] mem [0:2048]; //2048? si tengo 32 bits de direccion... mmm

	always @ (*)
	begin
		if (record)
		begin
			mem[0] = 32'b0;
			mem[1] = 32'b1;
			mem[2] = 32'b2;
			mem[3] = 32'b3;
			mem[4] = 32'b4;
		end
		else
			instr = mem[dir];
	end
	
endmodule
