`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:24:26 02/19/2014 
// Design Name: 
// Module Name:    alu_control 
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
module alu_control(
    input [5:0] funct,
    input [3:0] oper,
    output reg [3:0] alu_op
    );

	always @ (oper)
	begin
		if(oper != 4'b0010)
		begin
			case (oper)
				4'b0000: alu_op = 0; //Load y Store (add)
				4'b0001: alu_op = 1; //BNE BEQ J y JAL (todos los jump y branch q no pertenecen a losr type) (sub) 
				//4'b0010: //R type (va por function)
				4'b1000:	alu_op = 0; //ADDI (add)
				4'b1001:	alu_op = 0; //ADDUI (add)
				4'b1100:	alu_op = 4'b0100; //ANDI (and)
				4'b1111:	alu_op = 0; //LUI (add)
				4'b1101:	alu_op = 4'b0010; //ORI (or)
				4'b1110:	alu_op = 4'b0110; //XORI (xor)
				default: alu_op = 0; //Will never happen (add)
			endcase
		end
		else
		begin
			case (funct)
				6'b100000: alu_op = 0; //ADD (add)
				6'b100001: alu_op = 0; //ADDU (add)
				6'b100100: alu_op = 4'b0100; //AND (and)
				6'b100111: alu_op = 4'b0011; //NOR (nor)
				6'b100101: alu_op = 4'b0010; //OR (or)
				6'b101010: alu_op = 4'bxxxx; //SLT (?)
				6'b101011: alu_op = 4'bxxxx; //SLTU (?)
				6'b100010: alu_op = 4'b0001; //SUB (sub)
				6'b100011: alu_op = 4'b0001; //SUBU (sub)
				6'b100110: alu_op = 4'b0110; //XOR (xor)
				6'b000000: alu_op = 4'b0111; //SLL (sll)
				6'b000100: alu_op = 4'b0111; //SLLV (sll)
				6'b000011: alu_op = 4'b1001; //SRA (sra)
				6'b000111: alu_op = 4'b1001; //SRAV (sra)
				6'b000010: alu_op = 4'b1000; //SRL (srl)
				6'b000110: alu_op = 4'b1000; //SRLV (srl)
			endcase
		end
	end

endmodule
