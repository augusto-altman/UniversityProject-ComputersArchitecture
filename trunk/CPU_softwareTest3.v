`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:13:51 01/20/2014
// Design Name:   CPU
// Module Name:   C:/Tito/Facultad/Arquitecturas de las computadoras/Tp Final/CPU_softwareTest3.v
// Project Name:  bipI
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: CPU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module CPU_softwareTest3;

	// Inputs
	reg [15:0] Instruction;
	reg [15:0] Out_Data;
	reg Clock;
	reg Reset;

	// Outputs
	wire [10:0] InsAddr;
	wire Rd;
	wire Wr;
	wire [10:0] DataAddr;
	wire [15:0] In_Data;

	// Instantiate the Unit Under Test (UUT)
	CPU uut (
		.InsAddr(InsAddr), 
		.Instruction(Instruction), 
		.Rd(Rd), 
		.Wr(Wr), 
		.DataAddr(DataAddr), 
		.In_Data(In_Data), 
		.Out_Data(Out_Data), 
		.Clock(Clock), 
		.Reset(Reset)
	);

	initial begin
		// Initialize Inputs
		Instruction = 0;
		Out_Data = 0;
		Clock = 0;
		Reset = 0;

		// Wait 100 ns for global reset to finish
		#50;
		Reset = 1;
		#100
		Reset = 0;        
		// Add stimulus here
	end
      
	always
	begin
		#100 
		Clock = ~Clock;
	end
	
	/*
		Embebed software:
		A = 0
		A = A + 1
		A = A + 2
		A = A + 3
		A = A - 3
		A = A - 2
		A = A - 1
		
		Assembler code:
		LDi 0
		STO A
		ADDi 1
		STO A
		ADDi 2
		STO A
		ADDi 3
		STO A
		SUBi 3
		STO A
		SUBi 2
		STO A
		SUBi 1
		STO A
		
		Expected result:
		After the code execution A must be 0
	*/
	always @ (InsAddr)
	begin: ProgramMemory_Mock
		case (InsAddr)
			0: Instruction = 16'b0001100000000000; //LDi 0
			1: Instruction = 16'b0000100000000000; //STO 0
			2: Instruction = 16'b0010100000000001; //ADDi 1
			3: Instruction = 16'b0000100000000000; //STO 0
			4: Instruction = 16'b0010100000000010; //ADDi 2
			5: Instruction = 16'b0000100000000000; //STO 0
			6: Instruction = 16'b0010100000000011; //ADDi 3
			7: Instruction = 16'b0000100000000000; //STO 0
			8: Instruction = 16'b0011100000000011; //SUBi 3
			9: Instruction = 16'b0000100000000000; //STO 0
			10: Instruction = 16'b0011100000000010; //SUBi 2
			11: Instruction = 16'b0000100000000000; //STO 0
			12: Instruction = 16'b0011100000000001; //SUBi 1
			13: Instruction = 16'b0000100000000000; //STO 0
		endcase
	end
	
	reg [15:0]DataMemory[1:0];
	
	always @ (DataAddr or Rd or Wr or Reset)
	begin: DataMemory_Mock
		if (Reset)
		begin
			DataMemory[0] = 0;
			DataMemory[1] = 0;
		end
		else if (Rd)
			Out_Data = DataMemory[DataAddr];
		else if (Wr)
			DataMemory[DataAddr] = In_Data;
	end
      
endmodule

