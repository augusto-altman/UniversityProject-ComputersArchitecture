module uart
  #(  // Configuración por defecto:
      // 19,200 baudios, 8 bits de datos, 1 bit de stop, 2^2 FIFO
    parameter DBIT = 8,        // Bits de datos
              SB_TICK = 16,  // Ticks para el bit de stop. 16/24/32 para 1/1,5/2 bits
              DVSR = 326,        // DVSR para generar el Baudrate. DVSR = 100M/(16*baudrate)
              DVSR_BIT = 9     // Bits del DVSR  
	)
  (
    input wire clk, reset,
    input wire rx, rd, wr, 
    input wire [7:0] w_data,
    output wire tx, rd_empty, wr_full,
    output wire [7:0] r_data
  );
  
  // Declaración de señales
  wire tick, rx_done_tick, busy, empty;
  wire [7:0] rx_data_out, tx_data_in;
  fifo buffarini (
    .clk(clk), 
    .reset(reset), 
    .rd(rd), 
    .wr(rx_done_tick), 
    .w_data(rx_data_out), 
    .full(), 
    .empty(rd_empty), 
    .r_data(r_data)
    );
	 
  fifo bufferout (
    .clk(clk), 
    .reset(reset), 
    .rd(~empty && ~busy), 
    .wr(wr), 
    .w_data(w_data), 
    .full(wr_full), 
    .empty(empty), 
    .r_data(tx_data_in)
    );

  // Cuerpo
  mod_m_counter #(.M(DVSR), .N(DVSR_BIT)) baud_gen_unit
    (.clk(clk), .reset(reset), .q(), .max_tick(tick));
    
  uart_rx #(.DBIT(DBIT), .SB_TICK(SB_TICK)) uart_rx_unit
    (.clk(clk), .reset(reset), .rx(rx), .s_tick(tick),
     .rx_done_tick(rx_done_tick), .dout(rx_data_out));
     
  uart_tx #(.DBIT(DBIT), .SB_TICK(SB_TICK)) uart_tx_unit
    (.clk(clk), .reset(reset), .tx_start(~empty && ~busy),
     .s_tick(tick), .data_in(tx_data_in),
     .busy(busy), .tx(tx));
  
endmodule
