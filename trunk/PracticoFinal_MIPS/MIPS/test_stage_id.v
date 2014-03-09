`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   04:16:16 03/05/2014
// Design Name:   stage_id
// Module Name:   D:/Estudio/facu/arquitectura de computadoras/final/workspace - trunk/PracticoFinal_MIPS/MIPS/test_stage_id.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: stage_id
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_stage_id;

	// Inputs
	reg clock;
	reg [31:0] instr;
	reg [31:0] writeData;
	reg [4:0] writeAddr;
	reg regWrite;

	// Outputs
	wire [3:0] aluOp;
	wire isJump;
	wire isNotConditional;
	wire isEq;
	wire memWrite;
	wire [1:0] wbi;
	wire memRead;
	wire aluSrc;
	wire [31:0] reg1;
	wire [31:0] reg2;
	wire [31:0] extendedInstr;
	wire [4:0] regAddr1;
	wire [4:0] regAddr2;
	wire regDst;

	// Instantiate the Unit Under Test (UUT)
	stage_id uut (
		.clock(clock), 
		.instr(instr), 
		.writeData(writeData), 
		.writeAddr(writeAddr), 
		.regWrite(regWrite), 
		.aluOp(aluOp), 
		.isJump(isJump), 
		.isNotConditional(isNotConditional), 
		.isEq(isEq), 
		.memWrite(memWrite), 
		.wbi(wbi), 
		.memRead(memRead), 
		.aluSrc(aluSrc), 
		.reg1(reg1), 
		.reg2(reg2), 
		.extendedInstr(extendedInstr), 
		.regAddr1(regAddr1), 
		.regAddr2(regAddr2), 
		.regDst(regDst)
	);

reg correcto;

	initial begin
		// Initialize Inputs
		clock = 0;
		instr = 0;
		writeData = 0;
		writeAddr = 0;
		regWrite = 0;
		correcto = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		
		// 1st clock ADD
		clock = ~clock; 
		instr = 32'b0000_0000_0000_0000_0000_0000_0010_0000;
		writeData = 5;
		writeAddr = 1;
		regWrite = 1;
		#10;
		clock = ~clock;
		#10;
		correcto= 0;
		#1;
		// 2nd clock ANDI
		clock = ~clock;
		instr = 32'b0011_0000_0010_0010_0000_1000_0010_0000; // leer reg1 ( reg1 Addr = 1 ) (reg2 Addr = 2)
		writeData = 6;
		writeAddr = 2;
		regWrite = 1;
		// comprobacion clock anterior ( 1 ) 
		#1;
		if( aluOp == 2 && isJump == 0  &&  memWrite == 0 && wbi[0]== 1 && wbi[1] == 1 && memRead == 0 && aluSrc == 0 && regDst == 1 && regAddr1 == 0 && regAddr2 == 0 ) // regAddr1 [15:11]
			correcto = 1 ;
			
		#10;
		clock = ~clock;
		#10;
		correcto= 0;
		#1;
		//3rd clock LH
		clock = ~clock; 
		instr = 32'b1000_0100_0010_0010_0000_0000_0010_0000;
		writeData = 13;
		writeAddr = 11;
		regWrite = 1;
		// comprobacion clock anterior ( 2 ) 
		#1;
		if(  aluOp == 4'b1100   &&  isJump == 0 && memWrite == 0 && wbi[0] == 1  && wbi[1] == 1 && memRead == 0  && aluSrc == 1   && regDst == 0  && reg1 == 5   && regAddr1 == 1 && regAddr2 == 2 ) // regAddr1 [15:11]
			correcto = 1 ;
		#10;
		clock = ~clock;
		#10;
		correcto= 0;
		#1;
		//4th clock SB
		clock = ~clock;
		instr = 32'b1010_0001_0110_0010_0000_1000_0010_0000;
		writeData = 14;
		writeAddr = 12;
		regWrite = 1;
		// comprobacion clock anterior ( 3 ) 
		#1;
		if(aluOp == 0 && isJump == 0 && memWrite == 0 && wbi[0] == 0 && wbi[1] == 1 && memRead == 1 && aluSrc == 1 && regDst == 0  && reg1 == 5 && reg2 == 6 && regAddr1 == 0 && regAddr2 == 2 ) // regAddr1 [15:11]
			correcto = 1 ;
		#10;
		clock = ~clock;
		#10;
		correcto= 0;
		#1;
		
		//5th clock J
		clock = ~clock;
		instr = 32'b0000_1001_0110_1100_0000_0000_0010_0000;
		writeData = 13;
		writeAddr = 13;
		regWrite = 0;
		// comprobacion clock anterior ( 4 ) 
		#1;
		if(aluOp == 0 && isJump == 0 && memWrite == 1 && wbi[1] == 0 && memRead == 0 && aluSrc == 1 && reg1 == 13 && reg2 == 6 && regAddr1 == 1 && regAddr2 == 2 ) // regAddr1 [15:11]
			correcto = 1 ;
		#10;
		clock = ~clock;
		#10;
		correcto= 0;
		#1;
		//6th clock BEQ
		clock = ~clock;
		instr = 32'b0001_0000_0010_0001_0000_1000_0010_0000;
		writeData = 40;
		writeAddr = 11;
		regWrite = 0;
				// comprobacion clock anterior ( 5 ) 
		#1;
		if( aluOp == 1 && isJump == 1 && isNotConditional == 1 && memWrite == 0 && wbi[1] == 0 && memRead == 0 && reg1 == 13 && reg2 == 14 && regAddr1 == 0 && regAddr2 == 12 ) // regAddr1 [15:11]
			correcto = 1 ;
		#10;
		clock = ~clock;
		#10;
				#10;
		correcto= 0;
		#1;
		//7th clock  R type - no importa ya que el objetivo es un clock de comprobacion.
		clock = ~clock;
		instr = 32'b0000_0000_0000_0000_0000_0000_0000_0000;
		writeData = 40;
		writeAddr = 11;
		regWrite = 0;
				// comprobacion clock anterior ( 6 ) 
		#1;
		if( aluOp == 1 && isJump == 1 && isNotConditional == 0 && isEq == 1 && memWrite == 0 && wbi[1] == 0 && memRead == 0  && reg1 == 5 && reg2 == 5 && regAddr1 == 1 && regAddr2 == 1 ) // regAddr1 [15:11]
			correcto = 1 ;
		#10;
		clock = ~clock;
		#10;
				#10;
		correcto= 0;
		#1;
		
	end
      
endmodule

