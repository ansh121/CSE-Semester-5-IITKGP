`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:29:34 08/25/2019
// Design Name:   Barrel_Shifter
// Module Name:   D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 7/asgn7_1/test_bench.v
// Project Name:  asgn7_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Barrel_Shifter
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
	reg [7:0] in;
	reg [2:0] shamt;
	reg dir;

	// Outputs
	wire [7:0] out;

	// Instantiate the Unit Under Test (UUT)
	Barrel_Shifter uut (
		.in(in), 
		.shamt(shamt), 
		.dir(dir), 
		.out(out)
	);

	initial begin
	shamt = 3'b110; in=8'b10000000; dir=0;
	#100;
	end
      
endmodule

