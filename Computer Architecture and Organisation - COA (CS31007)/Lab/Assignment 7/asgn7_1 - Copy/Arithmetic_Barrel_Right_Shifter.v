`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:09:36 10/30/2019 
// Design Name: 
// Module Name:    Arithmetic_Barrel_Right_Shifter 
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
module Arithmetic_Barrel_Right_Shifter(
   input [31:0] in,
	input [4:0] shamt,
	output [31:0] out
	);

	 wire [31:0] w1;
	 wire [31:0] w2;
	 wire [31:0] w3;
	 wire [31:0] w4;
	 wire [31:0] w5;
	 wire [31:0] out1;
	 wire [31:0] out2;
	 wire [31:0] out3;
	 wire [31:0] out4;

	 assign w1=in[31]?{16'b1111111111111111,in[31:16]}:{16'b0,in[31:16]};
	 MUX_2x1 M1(in,w1,shamt[4],out1);

	 assign w2=out1[31]?{8'b11111111,out1[31:8]}:{8'b0,out1[31:8]};
	 MUX_2x1 M2(out1,w2,shamt[3],out2);
	 
	 assign w3=out2[31]?{4'b1111,out2[31:4]}:{4'b0,out2[31:4]};
	 MUX_2x1 M3(out2,w3,shamt[2],out3);

	 assign w4=out3[31]?{2'b11,out3[31:2]}:{2'b0,out3[31:2]};
	 MUX_2x1 M4(out3,w4,shamt[1],out4);

	 assign w5=out4[31]?{1'b1,out4[31:1]}:{1'b0,out4[31:1]};
	 MUX_2x1 M5(out4,w5,shamt[0],out);
endmodule
