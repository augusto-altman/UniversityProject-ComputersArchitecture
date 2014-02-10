module uart_test
  (
    input wire clk, reset,
    input wire rx,
    output wire tx
  );
   
	wire [7:0] rec_data;

  uart uart_unit
    (.clk(clk), .reset(reset), .rx(rx), .w_data(rec_data),
     .r_data(rec_data), .tx(tx));

endmodule
