`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:00:01 08/24/2019
// Design Name:   Mult_3
// Module Name:   D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 7/asgn7_2/test_bench.v
// Project Name:  asgn7_2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Mult_3
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
	reg [15:0] a;
	reg clk;

	// Outputs
	wire out;
	wire a_bit;

	// Instantiate the Unit Under Test (UUT)
	Mult_3 uut (
		.a(a), 
		.clk(clk), 
		.out(out), 
		.a_bit(a_bit)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		clk = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		#10; a=16'b0000000000000011;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		
		#100;
		#10; a=16'b1010010110100111;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;
		#10; clk=1; #10; clk=0;

	end
      
endmodule

