`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    20:13:43 03/19/2014 
// Design Name: 
// Module Name:    debugersm 
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
module debugersm(
	input clk, reset, rd_empty,
	input [31:0] result,
	input [1:0] size,
	output wr, rd,
	output [7:0] w_data
    );
	 
	localparam [1:0]
		idle  = 2'b00,
		start = 2'b01,
      data  = 2'b10,
		waitstate  = 2'b11;
		
	reg [7:0] w_data_out, w_data_next;
	reg rd_out, wr_out, rd_next, wr_next;
	reg [1:0] state_reg, state_next;
	reg [2:0] datasize, datasize_next;
	reg [7:0] datatosend[3:0], datatosend_next[3:0];	

	assign rd = rd_out;
	assign wr = wr_out;
	assign w_data = w_data_out;

	always @(posedge clk, posedge reset)
    if(reset)
		 begin
			state_reg = idle;
			rd_out = 0;
			wr_out = 0;
			w_data_out = 0;
			datatosend[0] = 0; 
			datatosend[1] = 0;
			datatosend[2] = 0;
			datatosend[3] = 0;
			datasize = 0;
			
		 end
    
    else
		 begin
			state_reg = state_next;
			rd_out = rd_next;
			wr_out = wr_next;
			w_data_out = w_data_next;
			datatosend[0] = datatosend_next[0]; 
			datatosend[1] = datatosend_next[1];
			datatosend[2] = datatosend_next[2];
			datatosend[3] = datatosend_next[3];
			datasize = datasize_next;
		 end

	always @*
	  begin
	  
		state_next = state_reg;
		rd_next = rd_out;
		wr_next = wr_out;
		w_data_next = w_data_out;
		datatosend_next[0] = datatosend[0]; 
		datatosend_next[1] = datatosend[1];
		datatosend_next[2] = datatosend[2];
		datatosend_next[3] = datatosend[3];
		datasize_next = datasize;
		case (state_reg)
			idle:
			  if(~rd_empty)
				  begin
					 state_next = waitstate;
				  end
				  
			waitstate:
			  begin
				 state_next = start;
				 rd_next = 1;
				 datatosend_next[0] = result[7:0];
				 datatosend_next[1] = result[15:8];
				 datatosend_next[2] = result[23:16];
				 datatosend_next[3] = result[31:24];
				 datasize_next = size + 3'b1;
			  end
			
			start:
				 begin
					rd_next = 0;
					wr_next = 1;
					state_next = data;
					w_data_next = datatosend[datasize - 3'b1];
					datasize_next = datasize - 3'b1;
				 end
			data:
				begin
					if (datasize == 3'b0)
						begin
							wr_next = 0;
							state_next = idle;
						end
					else 
						begin
							w_data_next = datatosend[datasize - 3'b1];
							datasize_next = datasize - 3'b1;
						end
				end
	  endcase
	end


endmodule
