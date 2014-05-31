`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:47:21 05/20/2014 
// Design Name: 
// Module Name:    forwarding_mem 
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
module forwarding_mem(
    input [4:0] rt_id,//direccion del dato que usaria sin el forwarding 
    input [4:0] outReg_mem,
	 input 		nop_mem,
    output reg selector_salida//0->from id ,1->from mem
    );

	always @ (*)
	begin
		if(nop_mem)
			selector_salida = 0;
		else
		begin
			//Caluclo de selector_salida
			if(outReg_mem == rt_id)
				selector_salida = 1;
			else
				selector_salida = 0;
		end
	end

endmodule
