module flag_buf
  #( parameter W = 8) // Número de bits del buffer.
  (
    input wire clock, reset,
    input wire clear_flag, set_flag,
    input wire [W-1:0] data_in,
    output wire flag,
    output wire [W-1:0] data_out
  );
  
  //Declaración de señales
  reg [W-1:0] buf_reg, buf_next;
  reg flag_reg, flag_next;
  
  //Cuerpo
  //FF y registro
  always @(posedge clock, posedge reset)
    if(reset)
    begin
      buf_reg <= 0;
      flag_reg <= 1'b0;
    end
      
    else
    begin
      buf_reg <= buf_next;
      flag_reg <= flag_next;
    end
    
  //Lógica del siguiente estado.
  always @*
  begin
    buf_next = buf_reg;
    flag_next = flag_reg;
    
    if(set_flag)
    begin
      buf_next = data_in;
      flag_next = 1'b1;
    end
    
    else if(clear_flag)
      flag_next = 1'b0;
  end
  
  //Lógica de salida
  assign data_out = buf_reg;
  assign flag = flag_reg;
  
endmodule
