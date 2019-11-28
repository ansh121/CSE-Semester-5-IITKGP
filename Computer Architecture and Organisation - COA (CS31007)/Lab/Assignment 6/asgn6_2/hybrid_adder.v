`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:33:45 08/14/2019 
// Design Name: 
// Module Name:    hybrid_adder 
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

module four_bit_CLA_adder(input [3:0]a, input [3:0]b, input cin, output [3:0]sum, output cout);
	 wire [3:0]G,P,C; 	// wire for generator propagator and carry
	 assign G = a&b; 		// G(generator) = a&b
	 assign P = a^b;		// p(propagator) = a ^ b
	 assign C[0] = cin; 	// C[0] = cin
	 // Calculating carry for adddition of each bit
	 assign C[1]=G[0] + (P[0]&C[0]);
	 assign C[2]=G[1] + (P[1]&G[0]) + (P[1]&P[0]&cin);
	 assign C[3]=G[2] + (P[2]&G[1]) + (P[2]&P[1]&G[0]) +  (P[2]&P[1]&P[0]&cin);
	 assign cout=G[3]+ (P[3]&G[2]) + (P[3]&P[2]&G[1]) +  (P[3]&P[2]&P[1]&G[0]) + (P[3]&P[2]&P[1]&P[0]&cin);	 
	 // sum = a ^ b ^ C(carry)
	 assign sum = P^C;
endmodule

module hybrid_adder(
    input [7:0] a,
    input [7:0] b,
    output [7:0] sum,
    output cout
    );
	 
	 wire cin = 0; //Hardcoding cin as 0
	 wire c;			// Cout for summation of last 4 bit 
	 four_bit_CLA_adder Adder1(a[3:0], b[3:0], cin, sum[3:0], c); // summation of last 4 bit
	 four_bit_CLA_adder Adder2(a[7:4], b[7:4], c, sum[7:4], cout); // summation of first 4 bit

endmodule
