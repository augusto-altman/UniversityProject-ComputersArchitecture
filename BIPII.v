`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    19:28:18 01/20/2014 
// Design Name: 
// Module Name:    BIPI 
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
module BIPI(
    input Clock,
	 input Reset
    );
	 
	wire [10:0] InsAddr, DataAddr;
	wire Rd, Wr;
	wire [15:0] Instruction, In_Data, Out_Data;
	wire ClockPc, ClockWrRd;
	
	
CPU cpu (
    .InsAddr(InsAddr), 
    .Instruction(Instruction), 
    .Rd(Rd), 
    .Wr(Wr), 
    .DataAddr(DataAddr), 
    .In_Data(In_Data), 
    .Out_Data(Out_Data), 
    .Clock(ClockPc), 
    .Reset(Reset)
    );
	 
 u_data_memory dataMemory (
	 .clock(ClockWrRd),
    .read(Rd), 
    .write(Wr), 
    .address(DataAddr), 
    .in_data(In_Data), 
    .out_data(Out_Data)
    );
u_program_memory programMemory (
    .clock(ClockPc), 
    .address(InsAddr), 
    .out(Instruction)
    );
ClockTree clockTree (
    .Clock(Clock), 
    .ClockPc(ClockPc), 
    .ClockWrRd(ClockWrRd)
    );


	 
endmodule
