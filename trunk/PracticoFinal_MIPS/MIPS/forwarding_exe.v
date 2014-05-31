`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:51:53 05/19/2014 
// Design Name: 
// Module Name:    forwarding_exe 
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
module forwarding_exe(
    input [4:0] rs_id,//direccion del dato que usaria sin el forwarding 
    input [4:0] rd_id,//direccion del dato que usaria sin el forwarding 
    input [4:0] rt_id,//direccion del dato que usaria sin el forwarding 
	 input 		 regDst,//bit selector de direccion de registro de salida
    input [4:0] outReg_exe,
    input [4:0] outReg_mem,
	 input nop_exe,
	 input nop_mem,
    output reg [1:0] selector_salida_a,//00->from id ,01->from exe, 10->from mem, 11->unused ... para entrada a (entrada superior alu)
	 output reg [1:0] selector_salida_b//00->from id ,01->from exe, 10->from mem, 11->unused ... para entrada b (entrada inferior alu)
    );

	reg [4:0] realOutput;
	reg [4:0] realInput; //registro que se utiliza como variable para la alu

	always @ (*)
	begin
		if(regDst)
		begin
			realOutput = rd_id; //1
			realInput = rt_id;
		end
		else
		begin
			realOutput = rt_id; //0
			realInput = rd_id;
		end
		
		//Caluclo de selector_salida_a
		if(outReg_exe == rs_id && ~nop_exe)
			selector_salida_a = 2'b01;
		else if(outReg_mem == rs_id && ~nop_mem)
			selector_salida_a = 2'b10;
		else
			selector_salida_a = 0;
			
		//Caluclo de selector_salida_b
		if(outReg_exe == realInput && ~nop_exe)
			selector_salida_b= 2'b01;
		else if(outReg_mem == realInput && ~nop_mem)
			selector_salida_b = 2'b10;
		else
			selector_salida_b = 0;
	end

endmodule
