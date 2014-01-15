`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:15:57 01/15/2014 
// Design Name: 
// Module Name:    Instruction_Decoder 
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
module Instruction_Decoder(
    input [4:0] Opcode,
    output [1:0] SelA,
    output SelB,
    output WrAcc,
    output Op,
    output WrRam,
    output RdRam
    );
	 
	 reg RWrAcc, RSelB, ROp, RWrRam, RRdRam;
	 reg [1:0] RSelA;
	 assign SelA = RSelA;
	 assign SelB = RSelB;
	 assign WrAcc = RWrAcc;
	 assign Op = ROp;
	 assign WrRam = RWrRam;
	 assign RdRam = RRdRam;

	always @ (Opcode)
	begin
		case (Opcode)
		5'b00001: //STO
		begin
			RSelA <= 2'bx;
			RSelB <= 1'bx;
			ROp <= 1'bx;
			RWrAcc <= 0;
			RWrRam <= 1;
			RRdRam <= 0;
		end
		5'b00010: //LD
		begin
			RSelA <= 2'd0;
			RSelB <= 1'bx;
			ROp <= 1'bx;
			RWrAcc <= 1;
			RWrRam <= 0;
			RRdRam <= 1;
		end
		5'b00011: //LDi
		begin
			RSelA <= 2'd1;
			RSelB <= 1'bx;
			ROp <= 1'bx;
			RWrAcc <= 1;
			RWrRam <= 0;
			RRdRam <= 0;
		end
		5'b00100: //ADD
		begin
			RSelA <= 2'd2;
			RSelB <= 0;
			ROp <= 0;
			RWrAcc <= 1;
			RWrRam <= 0;
			RRdRam <= 1;
		end
		5'b00101: //ADDi
		begin
			RSelA <= 2'd2;
			RSelB <= 1;
			ROp <= 0;
			RWrAcc <= 1;
			RWrRam <= 0;
			RRdRam <= 0;
		end
		5'b00110: // SUB
		begin
			RSelA <= 2'd2;
			RSelB <= 0;
			ROp <= 1;
			RWrAcc <= 1;
			RWrRam <= 0;
			RRdRam <= 1;
		end
		5'b00111: //SUBi
		begin
			RSelA <= 2'd2;
			RSelB <= 1;
			ROp <= 1;
			RWrAcc <= 1;
			RWrRam <= 0;
			RRdRam <= 0;
		end
		default:
		begin
			RSelA <= 2'd0;
			RSelB <= 0;
			ROp <= 0;
			RWrAcc <= 0;
			RWrRam <= 0;
			RRdRam <= 0;
		end
		endcase
	end

endmodule
