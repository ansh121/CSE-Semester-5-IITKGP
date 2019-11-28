`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   21:07:13 08/18/2019
// Design Name:   hybrid_adder
// Module Name:   D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 6/asgn6_2/test_bench.v
// Project Name:  asgn6_2
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: hybrid_adder
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

	// Outputs
	wire [7:0] sum;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	hybrid_adder uut (
		.a(a), 
		.b(b), 
		.sum(sum), 
		.cout(cout)
	);

	initial begin
		// Initialize Inputs
		a = 0;
		b = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		a=8'b00000001; b=8'b01111111;

	end
      
endmodule

