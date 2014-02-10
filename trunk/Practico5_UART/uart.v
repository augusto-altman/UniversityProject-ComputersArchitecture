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
    input wire rx,
    input wire [7:0] w_data,
    output wire tx,
    output wire [7:0] r_data
  );
  
  // Declaración de señales
  wire tick, rx_done_tick, tx_done_tick;
  wire [7:0] rx_data_out;
  
  // Cuerpo
  mod_m_counter #(.M(DVSR), .N(DVSR_BIT)) baud_gen_unit
    (.clk(clk), .reset(reset), .q(), .max_tick(tick));
    
  uart_rx #(.DBIT(DBIT), .SB_TICK(SB_TICK)) uart_rx_unit
    (.clk(clk), .reset(reset), .rx(rx), .s_tick(tick),
     .rx_done_tick(rx_done_tick), .dout(rx_data_out));
     
  uart_tx #(.DBIT(DBIT), .SB_TICK(SB_TICK)) uart_tx_unit
    (.clk(clk), .reset(reset), .tx_start(rx_done_tick),
     .s_tick(tick), .data_in(rx_data_out),
     .tx_done_tick(tx_done_tick), .tx(tx));
  
endmodule
