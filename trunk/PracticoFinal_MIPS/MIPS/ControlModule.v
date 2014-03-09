`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:21:58 02/16/2014 
// Design Name: 
// Module Name:    ControlModule 
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
module ControlModule(
    input 		[5:0] instr, 
    output reg [3:0] aluOp, //
    output reg			isJump, // 
	 output reg			isNotConditional, // 
	 output reg			isEq, //
    output reg 		memWrite, //
    output reg	[1:0] wbi,
    output reg			memRead, // 
    output reg			aluSrc, //
    output reg			regDst
    );


always@(instr)
 begin
 
/********    aluOp   *********/
// load y store (add)
	if(instr[5] == 1)
		aluOp = 4'b0000;
// Branch equal & J & JAL  (sub)
	else if( (instr == 6'b000101) || (instr == 6'b000100) ||  (instr == 6'b000010) || (instr == 6'b000011))
		aluOp = 4'b0001;
// depending on function code.
	else if ( instr == 0 )
		aluOp= 4'b0010;
// The others just send the last 4 bits of the opcode.
	else
		aluOp = instr[3:0];
	
/********    Branches   *********/

// Es la misma condicion que cuando se setea aluExit = 4'b0001
	if(instr == 2 || instr == 3 || instr == 4 || instr == 5 ) 
		isJump = 1;
	else
		isJump = 0;
	
	isNotConditional = ~instr[2];
	isEq = ~instr[0];
	
/********    MEMWrite *********/

	if(instr[5:3] == 5)
		memWrite = 1;
	else
		memWrite = 0;
		
/********    MEMRead *********/		
	if(instr[5:3] == 4)
		memRead = 1;
	else
		memRead = 0;
		
/********    MEMtoReg  ********/


/********    aluSrc *********/
	if(instr[5] == 1 || instr[3] == 1)
		aluSrc = 1;
	else 
		aluSrc = 0;

/********    regDst *********/
		
	if(instr == 0  ) 
		regDst = 1;
	else 
		regDst = 0;
	
/********    Wbi *********/

	// [o] src de writeback ( 0 para directo de memoria, 1 para Alu )
	if( instr[5] == 1)
		wbi[0] = 0; // Memoria
	else
		wbi[0] = 1; // Alu
	
	// [1] regWrite - si sedebe hacer un write back o no  - 
	if( instr[5:3] == 3'b101 || instr == 6'b000101 ||  instr == 6'b000100 || instr == 6'b000010 ||instr == 6'b000011 )
		wbi[1] = 0;
	else
		wbi[1] = 1;
		
/****************    ********************/	
		
	
	//end always
 end


	




endmodule
