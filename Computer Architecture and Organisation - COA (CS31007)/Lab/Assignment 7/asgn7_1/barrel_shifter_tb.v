`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   14:45:16 10/30/2019
// Design Name:   Barrel_Shifter
// Module Name:   D:/My Study Folder/3rd Year/Sem 5/COA/Lab/Assignment 7/asgn7_1/barrel_shifter_tb.v
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

module barrel_shifter_tb;

	// Inputs
	reg [31:0] in;
	reg [4:0] shamt;
	reg dir;

	// Outputs
	wire [31:0] out;

	// Instantiate the Unit Under Test (UUT)
	Barrel_Shifter uut (
		.in(in), 
		.shamt(shamt), 
		.dir(dir), 
		.out(out)
	);

	initial begin
		// Initialize Inputs
		in = 0;
		shamt = 0;
		dir = 0;

		// Wait 100 ns for global reset to finish
		#100;
      shamt = 5'b00011; in=32'b10000000000000000000000000000000; dir=0;
		#10;
		shamt = 5'b00100; in=32'b00000000000000000000000000000001; dir=1;
		// Add stimulus here

	end
      
endmodule

