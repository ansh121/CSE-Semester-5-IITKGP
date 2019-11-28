`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:25:09 09/25/2019 
// Design Name: 
// Module Name:    FP_adder_32 
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
module FP_adder_32(
    input clk,
    input rst,
    input start,
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
    );
	 
	 step_1 S1(clk, rst, start, a, b, sum);


endmodule

module step_1 (input clk,
    input rst,
    input start,
    input [31:0] a,
    input [31:0] b,
    output [31:0] sum
    );
	 reg [32:0] new_a;
	 reg [32:0] new_b;
	 
	 always @ (posedge clk) begin
		 if(rst == 1) begin
			 new_a = 0;
			 new_b = 0;
		 end
		 else begin
			if(a[30:23] < b[30:23]) begin
				 new_b = {b[31:23],1'b1,b[22:0]};
				 new_a = {a[31], b[30:23], {1'b1,a[22:0]}>>(b[30:23]-a[30:23])};
			 end
			 else begin
				 new_a = {a[31:23],1'b1,a[22:0]};
				 new_b = {b[31], a[30:23], {1'b1,b[22:0]}>>(a[30:23]-b[30:23])};
			 end
		 end
	 end
	 
	 step_2 S2 (clk, rst, start, new_a, new_b, sum);
	 
endmodule

module step_2 (input clk,
    input rst,
    input start,
    input [32:0] a,
    input [32:0] b,
    output [31:0] sum
    );
	 reg [33:0] add;
	 
	 always @ (posedge clk) begin
		 if(rst == 1) begin
			 add = 0;
		 end
		 else begin
			 if(a[32]==b[32])
				 add = {a[32:24], a[23:0]+b[23:0]};
			 else if(a[23:0] > b[23:0])
			    add = {a[32:24], a[23:0]-b[23:0]};
			 else
			    add = {b[32:24], b[23:0]-a[23:0]};
		 end
	 end
	 
	 step_3 S3 (clk, rst, start, add, sum);
	 
	 
endmodule

module step_3 (input clk,
    input rst,
    input start,
    input [33:0] add_in,
    output [31:0] sum
    );
	 reg [6:0] count;
	 reg [7:0] exp;
	 reg [25:0] mantissa;
	 reg [31:0] ans;
	 
	 assign sum = ans;
	 
	 initial begin
		count = 0;
	 end
	 
	 always @ (posedge clk) begin
		 count = 7'b0;
		 if(rst == 1) begin
			 ans = 0;
		 end
		 else begin
			 if(add_in[24:0] == 0)
				 ans = 0;
			 else
				 exp = add_in[32:25]+1;
				 mantissa = {1'b0,add_in[24:0]};
				 
			    while(mantissa[24] == 0 && count<24) begin
					 mantissa = mantissa << 1;
					 exp = exp - 1;
					 count = count +1;
				 end
				 
				 if(mantissa[1]==1) 
					 mantissa[25:1] = mantissa[24:1]+mantissa[0];
				 
				 if(mantissa[25] == 1) begin
				    mantissa = mantissa >> 1;
					 exp = exp + 1;
				 end
				 
				 ans = {add_in[33], exp, mantissa[23:1]};
					 
		 end
	 end
	 
	 
endmodule
