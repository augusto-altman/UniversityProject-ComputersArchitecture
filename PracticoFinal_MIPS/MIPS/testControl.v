`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   01:53:58 03/05/2014
// Design Name:   ControlModule
// Module Name:   D:/Estudio/facu/arquitectura de computadoras/final/workspace - trunk/PracticoFinal_MIPS/MIPS/testControl.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ControlModule
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module testControl;

	// Inputs
	reg [5:0] instr;

	// Outputs
	wire [3:0] aluOp;
	wire isJump;
	wire isNotConditional;
	wire isEq;
	wire memWrite;
	wire [1:0] wbi;
	wire memRead;
	wire aluSrc;
	wire regDst;

	// Instantiate the Unit Under Test (UUT)
	ControlModule uut (
	// input
		.instr(instr), 
	//output
		.aluOp(aluOp), 
		.isJump(isJump), 
		.isNotConditional(isNotConditional), 
		.isEq(isEq), 
		.memWrite(memWrite), 
		.wbi(wbi), 
		.memRead(memRead), 
		.aluSrc(aluSrc), 
		.regDst(regDst)
	);
reg correcto;

	initial begin
		// Initialize Inputs
		instr = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		
		//R type
		instr = 6'b000000;
		#1;
		if( aluOp == 2 && isJump == 0  &&  memWrite == 0 && wbi[0]== 1 && wbi[1] == 1 && memRead == 0 && aluSrc == 0 && regDst == 1 )         // Comprobar q si 'isJump = 0' entonces isNotConditional no importa ??
			correcto = 1 ;
		
		#10;
		correcto = 0;
		#1;
		
		// 001000 ( ADDI )
		instr = 6'b001000;
		#1;
		if( aluOp == 4'b1000 && isJump == 0 && memWrite == 0 && wbi[0] == 1 && wbi[1] == 1 && memRead == 0 && aluSrc == 1 && regDst == 0 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 001001 ADDIU
		instr = 6'b001001;
		#1;
		if( aluOp == 4'b1001 && isJump == 0 && memWrite == 0 && wbi[0] == 1 && wbi[1] == 1 && memRead == 0 && aluSrc == 1 && regDst == 0 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 001100 ANDI
		instr = 6'b001100;
		#1;
		if( aluOp == 4'b1100 && isJump == 0 && memWrite == 0 && wbi[0] == 1 && wbi[1] == 1 && memRead == 0 && aluSrc == 1 && regDst == 0 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 001111 LUI
		instr = 6'b001111;
		#1;
		if( aluOp == 4'b1111 && isJump == 0 && memWrite == 0 && wbi[0] == 1 && wbi[1] == 1 && memRead == 0 && aluSrc == 1  && regDst == 0)
			correcto = 1;
		#10;
		correcto = 0 ;
		#1
		// 001101 ori
		instr = 6'b001101;
		#1;
		if( aluOp == 4'b1101 && isJump == 0 && memWrite == 0 && wbi[0] == 1 && wbi[1] == 1 && memRead == 0 && aluSrc == 1 && regDst == 0 ) 
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 001110 XORI
		instr = 6'b001110;
		#1;
		if( aluOp == 4'b1110 && isJump == 0 && memWrite == 0 && wbi[0] == 1 && wbi[1] == 1 && memRead == 0 && aluSrc == 1 && regDst == 0 ) 
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		// 100000 LB
		instr = 6'b100000;
		#1;
		if( aluOp == 0 && isJump == 0 && memWrite == 0 && wbi[0] == 0 && wbi[1] == 1 && memRead == 1 && aluSrc == 1 && regDst == 0 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		// 100001 LH
		instr = 6'b100001;
		#1;
		if( aluOp == 0 && isJump == 0 && memWrite == 0 && wbi[0] == 0 && wbi[1] == 1 && memRead == 1 && aluSrc == 1 && regDst == 0 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		// 100011 LW
		instr = 6'b100011;
		#1;
		if( aluOp == 0 && isJump == 0 && memWrite == 0 && wbi[0] == 0 && wbi[1] == 1 && memRead == 1 && aluSrc == 1 && regDst == 0 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		// 100111 LWU
		instr = 6'b100111;
		#1;
		if( aluOp == 0 && isJump == 0 && memWrite == 0 && wbi[0] == 0 && wbi[1] == 1 && memRead == 1 && aluSrc == 1 && regDst == 0 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 100100 LBU
		instr = 6'b100100;
		#1;
		if( aluOp == 0 && isJump == 0 && memWrite == 0 && wbi[0] == 0 && wbi[1] == 1 && memRead == 1 && aluSrc == 1 && regDst == 0 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 100101 LHU
		instr = 6'b100101;
		#1;
		if( aluOp == 0 && isJump == 0 && memWrite == 0 && wbi[0] == 0 && wbi[1] == 1 && memRead == 1 && aluSrc == 1 && regDst == 0 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 101000 SB
		instr = 6'b101000;
		#1;
		if( aluOp == 0 && isJump == 0 && memWrite == 1 && wbi[1] == 0 && memRead == 0 && aluSrc == 1 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
				
		// 101001 SH 
		instr = 6'b101001;
		#1;
		if( aluOp == 0 && isJump == 0 && memWrite == 1 && wbi[1] == 0 && memRead == 0 && aluSrc == 1 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 101011 SW
		instr = 6'b101011;
		#1;
		if( aluOp == 0 && isJump == 0 && memWrite == 1 && wbi[1] == 0 && memRead == 0 && aluSrc == 1 )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 000010 J 
		instr = 6'b000010;
		#1;
		if( aluOp == 1 && isJump == 1 && isNotConditional == 1 && memWrite == 0 && wbi[1] == 0 && memRead == 0  )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 000011 JAL
		instr = 6'b000011;
		#1;
		if( aluOp == 1 && isJump == 1 && isNotConditional == 1 && memWrite == 0 && wbi[1] == 0 && memRead == 0  )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 000100 BEQ
		instr = 6'b000100;
		#1;
		if( aluOp == 1 && isJump == 1 && isNotConditional == 0 && isEq == 1 && memWrite == 0 && wbi[1] == 0 && memRead == 0  )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		//	000101 BNE
		instr = 6'b000101;
		#1;
		if( aluOp == 1 && isJump == 1 && isNotConditional == 0 && isEq == 0 && memWrite == 0  && wbi[1] == 0 && memRead == 0  )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 001010 SLTI
		instr = 6'b001010;
		#1;
		if( aluOp == 4'b1010 && isJump == 0  && memWrite == 0 && wbi[0] == 1 && wbi[1] == 1 && memRead == 0 && aluSrc == 1 && regDst == 0  )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
		
		// 001011 SLTIU
		instr = 6'b001011;
		#1;
		if( aluOp == 4'b1011 && isJump == 0  && memWrite == 0 && wbi[0] == 1 && wbi[1] == 1 && memRead == 0 && aluSrc == 1 && regDst == 0  )
			correcto = 1;
		#10;
		correcto = 0;
		#1;
	// end

		
		

	end
      
endmodule

