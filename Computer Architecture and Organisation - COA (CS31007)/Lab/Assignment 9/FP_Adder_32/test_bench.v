`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   22:29:52 09/29/2019
// Design Name:   FP_adder_32
// Module Name:   D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 9/FP_Adder_32/FP_Adder_32/test_bench.v
// Project Name:  FP_Adder_32
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: FP_adder_32
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module test_bench;

	// Inputs
	reg clk;
	reg rst;
	reg start;
	reg [31:0] a;
	reg [31:0] b;

	// Outputs
	wire [31:0] sum;

	// Instantiate the Unit Under Test (UUT)
	FP_adder_32 uut (
		.clk(clk), 
		.rst(rst), 
		.start(start), 
		.a(a), 
		.b(b), 
		.sum(sum)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		start = 0;
		a = 0;
		b = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		a=32'b10000000100100000000000000000000; b=32'b00000000101100000000000000000000;
		#10; clk=1; #10; clk=0;
		a=32'b10000000100100000000000000000000; b=32'b10000000101000000000000000000000;
		#10; clk=1; #10; clk=0;
		a=32'b10000000100100000000000000000000; b=32'b10000000100100000000000000000000;
		#10; clk=1; #10; clk=0;
		a=32'b11110000100100000000000000000000; b=32'b00000011101100000000000000000000;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		

	end
      
endmodule

