`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:19:09 08/25/2019 
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
	input [7:0] in,
	input [2:0] shamt,
	input dir,
	output [7:0] out
	);

	 wire [7:0] w1;
	 wire [7:0] w2;
	 wire [7:0] w3;
	 wire [7:0] out1;
	 wire [7:0] out2;

	 assign w1=dir?{in[3:0],4'b0}:{4'b0,in[7:4]};
	 MUX_2x1 M1(in,w1,shamt[2],out1);

	 assign w2=dir?{out1[5:0],2'b0}:{2'b0,out1[7:2]};
	 MUX_2x1 M2(out1,w2,shamt[1],out2);

	 assign w3=dir?{out2[6:0],1'b0}:{1'b0,out2[7:1]};
	 MUX_2x1 M3(out2,w3,shamt[0],out);
endmodule

module MUX_2x1(
    input [7:0] in1,
    input [7:0] w1,
    input s,
    output [7:0] out
    );
	 
	 assign out=s?w1:in1;

endmodule
