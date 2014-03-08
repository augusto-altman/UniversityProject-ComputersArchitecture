module fifo
  #(
    parameter B=8,
              W=4
  )
  (
	  input wire clk,reset,rd,wr,
	  input wire [B-1:0] w_data,
	  output wire full, empty,
	  output wire [B-1:0] r_data
  );

  reg [B-1:0] array_reg [(2**W)-1:0];
  reg [W-1:0] w_ptr_reg, w_ptr_next, w_ptr_succ;
  reg [W-1:0] r_ptr_reg, r_ptr_next, r_ptr_succ;
  reg full_reg, empty_reg, full_next, empty_next;
  wire wr_en;

  //Banco de registros y memoria
  always @(posedge clk)
	  if(wr_en)
		  array_reg[w_ptr_reg] <= w_data;

  assign r_data = array_reg[r_ptr_reg];
  assign wr_en = wr & ~full_reg;

  always @(posedge clk, posedge reset)
	  if(reset)
		begin
		  w_ptr_reg <= 0;
		  r_ptr_reg <= 0;
		  full_reg <= 1'b0;
		  empty_reg <= 1'b1;
		end
	  
	  else
		begin
		  w_ptr_reg <= w_ptr_next;
		  r_ptr_reg <= r_ptr_next;
		  full_reg <= full_next;
		  empty_reg <= empty_next;
		end

  //Logica del proximo estado
  always @*
  begin
	  w_ptr_succ = w_ptr_reg + 4'b1;
	  r_ptr_succ = r_ptr_reg + 4'b1;
	  full_next = full_reg;
	  empty_next = empty_reg;
	  w_ptr_next = w_ptr_reg;
	  r_ptr_next = r_ptr_reg;

	  case({wr,rd})
    //2'b00: No hay que hacer nada
		  2'b01:
			  //Hay que sacar el primer elemento de la cola
			  if(~empty_reg)
				begin
				  r_ptr_next = r_ptr_succ;
				  full_next = 1'b0;
				  if(r_ptr_succ == w_ptr_reg)
					  empty_next = 1'b1;
				end
				
		  2'b10:
			  //Hay que escribir un nuevo elemento en la cola
			  if(~full_reg)
				begin
				  w_ptr_next = w_ptr_succ;
				  empty_next = 1'b0;
				  if(w_ptr_succ == r_ptr_reg)
					  full_next = 1'b1;
				end
		  
		  2'b11:
			begin
			  w_ptr_next = w_ptr_succ;
			  r_ptr_next = r_ptr_succ;
			end
			
	  endcase
  end
  
  //Logica de salida
  assign full = full_reg;
  assign empty = empty_reg;

endmodule
