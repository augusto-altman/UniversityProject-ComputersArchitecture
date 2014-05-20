`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   20:18:53 05/19/2014
// Design Name:   forwarding_exe
// Module Name:   C:/Users/aaquaran/Desktop/tito/Facu/Arquitectura de Computadoras/Tp Final/Trunk/PracticoFinal_MIPS/MIPS/forwarding_exe_test1.v
// Project Name:  MIPS
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: forwarding_exe
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module forwarding_exe_test1;

	// Inputs
	reg [4:0] rs_id;
	reg [4:0] rd_id;
	reg [4:0] rt_id;
	reg regDst;
	reg [4:0] outReg_exe;
	reg [4:0] outReg_mem;

	// Outputs
	wire [1:0] selector_salida_a;
	wire [1:0] selector_salida_b;

	// Instantiate the Unit Under Test (UUT)
	forwarding_exe uut (
		.rs_id(rs_id), 
		.rd_id(rd_id), 
		.rt_id(rt_id), 
		.regDst(regDst), 
		.outReg_exe(outReg_exe), 
		.outReg_mem(outReg_mem), 
		.selector_salida_a(selector_salida_a), 
		.selector_salida_b(selector_salida_b)
	);

	reg fail = 0;

	initial begin
		// Initialize Inputs
		rs_id = 0;
		rd_id = 0;
		rt_id = 0;
		regDst = 0;
		outReg_exe = 0;
		outReg_mem = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		/*
			TEST 1: Caso feliz
			
			Expected result: 
				selector_salida_a = 00 (rs_id = 3)
				selector_salida_b = 00 (rt_id = 0)
		*/
		rs_id = 3;
		rd_id = 6;
		rt_id = 0;
		regDst = 1; //salida real = rd
		outReg_exe = 4;
		outReg_mem = 8;
		#1;
		fail = (selector_salida_a == 2'b0) && (selector_salida_b == 2'b0);
		#100;
		fail = 0;
		
		/*
			TEST 2: Caso infeliz para a
			
			Expected result: 
				selector_salida_a = 01 (outReg_exe = 3)
				selector_salida_b = 00 (rt_id = 0)
		*/
		rs_id = 3;
		rd_id = 6;
		rt_id = 0;
		regDst = 1; //salida real = rd
		outReg_exe = 3;
		outReg_mem = 8;
		#1
		fail = (selector_salida_a == 01) && (selector_salida_b == 00);
		#100;
		fail = 0;
		
		/*
			TEST 3: Otro caso infeliz para a
			
			Expected result: 
				selector_salida_a = 10 (outReg_exe = 8)
				selector_salida_b = 00 (rt_id = 0)
		*/
		rs_id = 8;
		rd_id = 6;
		rt_id = 0;
		regDst = 1; //salida real = rd
		outReg_exe = 3;
		outReg_mem = 8;
		#1
		fail = (selector_salida_a == 10) && (selector_salida_b == 00);
		#100;
		fail = 0;
		
		/*
			TEST 4: Caso infeliz para b
			
			Expected result: 
				selector_salida_a = 00 (rs_id = 8)
				selector_salida_b = 01 (outReg_exe = 6)
		*/
		rs_id = 8;
		rd_id = 3;
		rt_id = 6;
		regDst = 1; //salida real = rd
		outReg_exe = 6;
		outReg_mem = 5;
		#1
		fail = (selector_salida_a == 00) && (selector_salida_b == 01);
		#100;
		fail = 0;
		
		/*
			TEST 5: Otro caso infeliz para b
			
			Expected result: 
				selector_salida_a = 00 (rs_id = 8)
				selector_salida_b = 10 (outReg_mem = 5)
		*/
		rs_id = 8;
		rd_id = 3;
		rt_id = 5;
		regDst = 1; //salida real = rd
		outReg_exe = 6;
		outReg_mem = 5;
		#1
		fail = (selector_salida_a == 00) && (selector_salida_b == 10);
		#100;
		fail = 0;
		
		/*
			TEST 6: Caso infeliz para b
			
			Expected result: 
				selector_salida_a = 00 (rs_id = 8)
				selector_salida_b = 01 (outReg_exe = 6)
		*/
		rs_id = 8;
		rd_id = 6;
		rt_id = 3;
		regDst = 0; //salida real = rt
		outReg_exe = 6;
		outReg_mem = 5;
		#1
		fail = (selector_salida_a == 00) && (selector_salida_b == 01);
		#100;
		fail = 0;
		
		/*
			TEST 7: Otro caso infeliz para b
			
			Expected result: 
				selector_salida_a = 00 (rs_id = 8)
				selector_salida_b = 10 (outReg_mem = 5)
		*/
		rs_id = 8;
		rd_id = 5;
		rt_id = 3;
		regDst = 0; //salida real = rt
		outReg_exe = 6;
		outReg_mem = 5;
		#1
		fail = (selector_salida_a == 00) && (selector_salida_b == 10);
		#100;
		fail = 0;
		
		/*
			TEST 8: Otro caso feliz con rd como entrada real
			
			Expected result: 
				selector_salida_a = 00 (rs_id = 3)
				selector_salida_b = 00 (rt_id = 0)
		*/
		rs_id = 3;
		rd_id = 6;
		rt_id = 0;
		regDst = 0; //salida real = rt
		outReg_exe = 4;
		outReg_mem = 8;
		#1
		fail = (selector_salida_a == 00) && (selector_salida_b == 00);
		#100;
		fail = 0;
	
		/*
			TEST 9: Caso infeliz con ambas entradas forwardeadas
			
			Expected result: 
				selector_salida_a = 01
				selector_salida_b = 10
		*/
		rs_id = 3;
		rd_id = 6;
		rt_id = 0;
		regDst = 0; //salida real = rt
		outReg_exe = 3;
		outReg_mem = 6;
		#1
		fail = (selector_salida_a == 01) && (selector_salida_b == 10);
		#100;
		fail = 0;

		/*
			TEST 10: Otro caso infeliz con ambas entradas forwardeadas
			
			Expected result: 
				selector_salida_a = 01
				selector_salida_b = 01
		*/
		rs_id = 3;
		rd_id = 3;
		rt_id = 0;
		regDst = 0; //salida real = rt
		outReg_exe = 3;
		outReg_mem = 3;
		#1
		fail = (selector_salida_a == 01) && (selector_salida_b == 01);
		#100;
		fail = 0;
		
		/*
			TEST 11: Otro caso infeliz con ambas entradas forwardeadas con rt como entrada real
			
			Expected result: 
				selector_salida_a = 01
				selector_salida_b = 01
		*/
		rs_id = 3;
		rd_id = 0;
		rt_id = 3;
		regDst = 1; //salida real = rt
		outReg_exe = 3;
		outReg_mem = 3;
		#1
		fail = (selector_salida_a == 01) && (selector_salida_b == 01);
		#100;
		fail = 0;
	end
      
endmodule

