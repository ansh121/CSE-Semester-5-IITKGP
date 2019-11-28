`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:39:04 08/19/2019
// Design Name:   Bit_Serial_Adder
// Module Name:   D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 6/asgn6/asgn6_3/test_bench.v
// Project Name:  asgn6_3
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Bit_Serial_Adder
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
	reg [7:0] a;
	reg [7:0] b;
	reg clk;
	reg reset;

	// Outputs
	wire [7:0] sum;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	Bit_Serial_Adder uut (
		.a(a), 
		.b(b), 
		.clk(clk), 
		.reset(reset), 
		.sum(sum), 
		.cout(cout)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		b = 0;
		clk = 0;
		reset = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		#1;clk =1; a =15;b =1; 
		#1;clk =0;
		#1;clk =1;
		#1;clk=0;
		#1;clk =1;
		#1;clk=0;
		#1;clk =1;
		#1;clk=0;
		#1;clk =1;
		#1;clk=0;
		#1;clk =1;
		#1;clk=0;
		#1;clk =1;
		#1;clk=0;
		#1;clk =1;
		#1;clk=0;
		#1;clk =1;
		#1;clk=0;

	end
      
endmodule

