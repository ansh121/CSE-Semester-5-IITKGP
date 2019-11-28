`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:41:53 08/07/2019
// Design Name:   riiple_carry_adder
// Module Name:   E:/17CS10005_17CS10007/asgn6_1/tb.v
// Project Name:  asgn6_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: riiple_carry_adder
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module tb;

	// Inputs
	reg [7:0] a;
	reg [7:0] b;

	// Outputs
	wire [7:0] sum;
	wire cout;

	// Instantiate the Unit Under Test (UUT)
	riiple_carry_adder uut (
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
		#1 a=8'b00010010; b=8'b10010101; 
		#1 a=8'b00010010; b=8'b10010101; 
		#1 a=8'b11010010; b=8'b10010101; 
		#1 a=8'b00010010; b=8'b10110101; 
		#1 a=8'b00000001; b=8'b11111111;
		#1 $finish; 
		

	end
      
endmodule

