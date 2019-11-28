`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    22:03:18 09/29/2019 
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
    output reg [31:0] sum
    );
	integer i;
	integer counter;
	reg [23:0] mant_a;
	reg [23:0] mant_b;

	//With extra bit for overflow
	reg [24:0] mant_a1;
	reg [24:0] mant_b1;

	integer exp_a;
	integer exp_b;
	reg sign_a ;
	reg sign_b ;
	reg s[1:0];
	integer exp;
	integer exp_1;
	integer exp_2;
	reg [23:0] temp;

	//add
	reg [25:0] a1;
	reg [25:0] b1;
	reg signed [25:0] tempsum;
	reg signed [25:0] tempsum1;

	initial begin
		counter = 0;
	end

	//Step-3: Round and Normalize
	always@(posedge clk)
	begin
		if(counter >= 2)
		begin
			sum[31] = tempsum[25];
			if(tempsum[24] == 1 && tempsum[25] == 0) begin		//Overflow case(round up if last bit is 1)
					tempsum1 = {tempsum >> 1} + tempsum[0];		//Adding last bit after right shifting
					exp_2 = exp_1 + 1;
					if(tempsum1[24] == 1) begin						//Need to re-normalize
						tempsum1 = {tempsum1 >> 1};					//Re-normalized
						exp_2 = exp_2 + 1;
					end
					sum[30:23] = exp_2 + 127;								//Storing exponent
					sum[22:0] = tempsum1[22:0];						//Last 23 bits stored in sum
				end
			else begin
				i = 23;
				while(i > 0 && tempsum[i] == 0)begin				//Detecting 1st 1
					i = i - 1;
				end
				tempsum1 = tempsum<<(23 - i);							//Shifting by required amount
				exp_2 = exp_1 - (23 - i);										//Shifting by required amount
				sum[22:0] = tempsum1[22:0];							//Last 23 bits stored in sum
				sum[30:23] = exp_2 + 127;									//Storing exponent
			end		
		end//end of if counter >=2
	end

	//Step-2: Add Significands
	always@(posedge clk)
	begin
		if(counter >= 1)
		begin
			mant_a1 = {1'b0,mant_a};												//Adding extra bit for overflow
			mant_b1 = {1'b0,mant_b};												//Adding extra bit for overflow
			
			if(sign_a == 1)														//Taking 2's complement if negative
				a1 = ~{1'b0,mant_a1} + 1'b1;
			else
				a1 = {1'b0,mant_a1};
			
			if(sign_b == 1)														//Taking 2's complement if negative
				b1 = ~{1'b0,mant_b1} + 1'b1;
			else
				b1 = {1'b0,mant_b1};
			
			tempsum = a1 + b1;
			if(tempsum[25] == 1) begin								   //Taking 2's complement if negative
				tempsum = ~tempsum + 1'b1;
				tempsum[25] = 1;
				end
			exp_1 = exp;															//Storing exponent for 3rd step
		end
	end

	//Step-1: Load input and shift exponents to bring all inputs in standard form
	always@(posedge clk)
	begin
		mant_a[23:0] = {1'b1,a[22:0]};								//Significand
		mant_b[23:0] = {1'b1,b[22:0]};								//Significand
		exp_a = {24'b0,a[30:23]} - 127;							//Actual exponent
		exp_b = {24'b0,b[30:23]} - 127;							//Actual exponent
		temp = exp_a<exp_b ? mant_a>>(exp_b-exp_a) : mant_b>>(exp_a-exp_b);			//Making similar exponents
		exp = exp_a>exp_b?exp_a:exp_b;											//Selecting higher exponent
		mant_a = exp_a<exp_b?temp:mant_a;										//Updating Significand
		mant_b = exp_a>=exp_b?temp:mant_b;										//Updating Significand
		sign_a = a[31];													//Loading sign bit
		sign_b = b[31];													//Loading sign bit
		counter = counter + 1;										//counter increased
	end
endmodule
