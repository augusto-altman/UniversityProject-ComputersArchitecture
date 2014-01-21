`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:51:16 01/20/2014 
// Design Name: 
// Module Name:    ClockTree 
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
module ClockTree(
    input Clock,
    output ClockPc,
    output ClockWrRd
    );
reg [1:0] counter = 0;

assign  ClockPc = counter[1];
assign ClockWrRd  = Clock;

always@( Clock)
begin
	counter = counter + 1;
	
end

endmodule
