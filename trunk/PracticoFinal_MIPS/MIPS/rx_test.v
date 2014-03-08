`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:11:54 01/23/2014
// Design Name:   uart_rx
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Arquitectura de las computadoras/Practico5_UART/rx_test.v
// Project Name:  Practico5_UART
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: uart_rx
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module rx_test;

	// Inputs
	reg clk;
	reg reset;
	reg rx;
	wire s_tick;

	// Outputs
	wire rx_done_tick;
	wire [7:0] dout;

	// Instantiate the Unit Under Test (UUT)
	uart_rx uut (
		.clk(clk), 
		.reset(reset), 
		.rx(rx), 
		.s_tick(s_tick), 
		.rx_done_tick(rx_done_tick), 
		.dout(dout)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 0;
		rx = 0;
		//s_tick = 0;

		// Wait 100 ns for global reset to finish
		#50;
		reset = 1;
		#100;
		reset = 0;
        
		// Add stimulus here

	end
	
	always @ (s_tick)
	begin
		rx = ~rx;
	end
	
	mod_m_counter #(.M(3), .N(2)) baud_gen_unit
		 (.clk(clk), .reset(reset), .q(), .max_tick(s_tick));
		 
	always
	begin
		#100;
		clk = ~clk;
	end
      
endmodule

