`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:34:11 10/30/2019 
// Design Name: 
// Module Name:    Barrel_Shifter 
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
module Barrel_Shifter(
   input [31:0] in,
	input [4:0] shamt,
	input dir,
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

	 assign w1=dir?{in[15:0],16'b0}:{16'b0,in[31:16]};
	 MUX_2x1 M1(in,w1,shamt[4],out1);

	 assign w2=dir?{out1[23:0],8'b0}:{8'b0,out1[31:8]};
	 MUX_2x1 M2(out1,w2,shamt[3],out2);
	 
	 assign w3=dir?{out2[27:0],4'b0}:{4'b0,out2[31:4]};
	 MUX_2x1 M3(out2,w3,shamt[2],out3);

	 assign w4=dir?{out3[29:0],2'b0}:{2'b0,out3[31:2]};
	 MUX_2x1 M4(out3,w4,shamt[1],out4);

	 assign w5=dir?{out4[30:0],1'b0}:{1'b0,out4[31:1]};
	 MUX_2x1 M5(out4,w5,shamt[0],out);
endmodule
