`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:44:21 08/29/2012 
// Design Name: 
// Module Name:    multicomp 
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
module multicomp(
    input A,
    input B,
    input [1:0] SEL,
    output tito
    );
 reg mux;
	assign tito = mux;

	always @ (A or B or SEL)
	begin : multiplexor
	case (SEL)
	2'd0:
	mux <= A & B;
	2'd1:
	mux <= ~(A & B);
	2'd2:
	mux <= ~(A | B);
	2'd3:
	mux <= A | B;
	endcase // case (SEL)
	end
	/*
	wire [3:0] AB;
	assign AB[0] = A & B;
	assign AB[1] = ~(A & B);
	assign AB[2] = ~(A | B);
	assign AB[3] = A | B;
	assign tito = AB[SEL];
	*/

endmodule
