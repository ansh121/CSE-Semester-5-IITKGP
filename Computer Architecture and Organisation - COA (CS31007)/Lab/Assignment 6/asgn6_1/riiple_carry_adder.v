`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:00:09 08/07/2019 
// Design Name: 
// Module Name:    riiple_carry_adder 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////

module Adder(a,b,cin,sum,c);
	input a, b, cin; 	// declaring inputs
	output sum,c; 		// declaring outputs
	assign sum = a ^ b ^ cin;
	assign c = a&b | b&cin | cin&a;

endmodule


module riiple_carry_adder(
    input [7:0] a,
    input [7:0] b,
    output [7:0] sum,
    output cout);
	 
	wire [6:0] c;	// Wire for carry
	wire cin; 		// Cin wire
	assign cin = 1'b0; 	// hardcoding cin as 0
	
	// adding each bit separately
	
	Adder A0(a[0],b[0],cin,sum[0],c[0]);
	Adder A1(a[1],b[1],c[0],sum[1],c[1]);
	Adder A2(a[2],b[2],c[1],sum[2],c[2]);
	Adder A3(a[3],b[3],c[2],sum[3],c[3]);
	Adder A4(a[4],b[4],c[3],sum[4],c[4]);
	Adder A5(a[5],b[5],c[4],sum[5],c[5]);
	Adder A6(a[6],b[6],c[5],sum[6],c[6]);
	Adder A7(a[7],b[7],c[6],sum[7],cout);

endmodule

