module mod_m_counter
  #(parameter N=4, M=10) //M = Coun to M, N = reg size in bits to hold the M number
  (
	  input wire clk, reset,
	  output wire max_tick, //Set to 1 when the reach M
	  output wire [N-1:0] q //Count value
  );

	reg [N-1:0] r_reg;
	wire [N-1:0] r_next;

	always @ (posedge clk , posedge reset) //At each clock we get a new count
		if (reset)
			r_reg <= 0 ;
		else
			r_reg <= r_next;

	assign r_next = (r_reg==(M-1)) ? 1'b0 : r_reg + 1'b1;
	assign q = r_reg;
	assign max_tick = (r_reg==(M-1)) ? 1'b1: 1'b0;
	
endmodule
