`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:39:00 03/04/2014
// Design Name:   RegisterBank
// Module Name:   D:/Estudio/facu/arquitectura de computadoras/final/workspace - trunk/PracticoFinal_MIPS/MIPS/testBankRegister.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: RegisterBank
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testBankRegister;

	// Inputs
	reg clock;
	reg [4:0] addr1;
	reg [4:0] addr2;
	reg [4:0] writeAddr;
	reg [31:0] writeData;
	reg regWrite;

	// Outputs
	wire [31:0] reg1;
	wire [31:0] reg2;

	// Instantiate the Unit Under Test (UUT)
	RegisterBank uut (
		.clock(clock), 
		.addr1(addr1), 
		.addr2(addr2), 
		.writeAddr(writeAddr), 
		.writeData(writeData), 
		.regWrite(regWrite), 
		.reg1(reg1), 
		.reg2(reg2)
	);

	initial begin
		// Initialize Inputs
		clock = 0;
		addr1 = 0;
		addr2 = 0;
		writeAddr = 0;
		writeData = 0;
		regWrite = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
//********** Escritura **********//	
		// escribimos
		clock = ~clock;
		writeAddr = 0;
		writeData = 6;
		regWrite = 1;
		addr1 = 0;
		addr2 = 1;
		#100;
		clock = ~clock;
		#100;
		// grabamos dir 1
		clock = ~clock;
		writeAddr = 1;
		writeData = 7;
		regWrite = 1;
		addr1 = 0;
		addr2 = 1;
		#100;
		clock = ~clock;
		#100;
		
		// grabamos dir 2
		clock = ~clock;
		writeAddr = 2;
		writeData = 8;
		regWrite = 1;
		addr1 = 2;
		addr2 = 3;
		#100;
		clock = ~clock;
		#100;
		
		// grabamos dir 3
		clock = ~clock;
		writeAddr = 3;
		writeData = 9;
		regWrite = 1;
		addr1 = 2;
		addr2 = 3;
		#100; 
		clock = ~clock;
		#100;
		
		//terminamos de leer.
		clock = ~clock;
		writeAddr = 3;
		writeData = 9;
		regWrite = 0;
		addr1 = 0;
		addr2 = 1;
		#100; 
		clock = ~clock;
		#100;
		//
		clock = ~clock;
		writeAddr = 3;
		writeData = 9;
		regWrite = 0;
		addr1 = 2;
		addr2 = 3;
		#100; 
		clock = ~clock;
		#100;
		//ultima grabada
		clock = ~clock;
		writeAddr = 30;
		writeData = -3;
		regWrite = 1;
		addr1 = 30;
		addr2 = 0;
		#100;
		clock = ~clock;
		#100;
		//ultima leida
		clock = ~clock;
		writeAddr = 30;
		writeData = -3;
		regWrite = 0;
		addr1 = 30;
		addr2 = 0;
		#100;
		clock = ~clock;
		#100;
	end
      
endmodule

