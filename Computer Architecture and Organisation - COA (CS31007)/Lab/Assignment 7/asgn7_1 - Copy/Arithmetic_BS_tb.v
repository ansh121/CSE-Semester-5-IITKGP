`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   15:19:14 10/30/2019
// Design Name:   Arithmetic_Barrel_Right_Shifter
// Module Name:   D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 7/asgn7_1 - Copy/Arithmetic_BS_tb.v
// Project Name:  asgn7_1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Arithmetic_Barrel_Right_Shifter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Arithmetic_BS_tb;

	// Inputs
	reg [31:0] in;
	reg [4:0] shamt;

	// Outputs
	wire [31:0] out;

	// Instantiate the Unit Under Test (UUT)
	Arithmetic_Barrel_Right_Shifter uut (
		.in(in), 
		.shamt(shamt), 
		.out(out)
	);

	initial begin
		// Initialize Inputs
		in = 0;
		shamt = 0;

		// Wait 100 ns for global reset to finish
		#100;
      shamt = 5'b00011; in=32'b11000000000000000000000000000000;
		#10;
		shamt = 5'b00100; in=32'b01000000000000000000000000000001;
		// Add stimulus here
		// Add stimulus here

	end
      
endmodule

