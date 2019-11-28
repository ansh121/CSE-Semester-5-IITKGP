`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:26:28 09/29/2019 
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
integer count;
reg [23:0] ma;
reg [23:0] mb;

//With extra bit for overflow
reg [24:0] ma1;
reg [24:0] mb1;

integer ea;
integer eb;
reg sa ;
reg sb ;
reg s[1:0];
integer e;
integer e1;
integer e2;
reg [23:0] temp;

//add
reg [25:0] a1;
reg [25:0] b1;
reg signed [25:0] tempsum;
reg signed [25:0] tempsum1;

initial begin
	count = 0;
end

//Step-3: Round and Normalize
always@(posedge clk)
begin
	if(count >= 2)
	begin
		sum[31] = tempsum[25];
		if(tempsum[24] == 1 && tempsum[25] == 0) begin		//Overflow case(round up if last bit is 1)
				tempsum1 = {tempsum >> 1} + tempsum[0];		//Adding last bit after right shifting
				e2 = e1 + 1;
				if(tempsum1[24] == 1) begin						//Need to re-normalize
					tempsum1 = {tempsum1 >> 1};					//Re-normalized
					e2 = e2 + 1;
				end
				sum[30:23] = e2 + 127;								//Storing exponent
				sum[22:0] = tempsum1[22:0];						//Last 23 bits stored in sum
			end
		else begin
			i = 23;
			while(i > 0 && tempsum[i] == 0)begin				//Detecting 1st 1
				i = i - 1;
			end
			tempsum1 = tempsum<<(23 - i);							//Shifting by required amount
			e2 = e1 - (23 - i);										//Shifting by required amount
			sum[22:0] = tempsum1[22:0];							//Last 23 bits stored in sum
			sum[30:23] = e2 + 127;									//Storing exponent
		end		
	end//end of if count >=2
end

//Step-2: Add Significands
always@(posedge clk)
begin
	if(count >= 1)
	begin
		ma1 = {1'b0,ma};												//Adding extra bit for overflow
		mb1 = {1'b0,mb};												//Adding extra bit for overflow
		
		if(sa == 1)														//Taking 2's complement if negative
			a1 = ~{1'b0,ma1} + 1'b1;
		else
			a1 = {1'b0,ma1};
		
		if(sb == 1)														//Taking 2's complement if negative
			b1 = ~{1'b0,mb1} + 1'b1;
		else
		   b1 = {1'b0,mb1};
		
		tempsum = a1 + b1;
		if(tempsum[25] == 1) begin								   //Taking 2's complement if negative
		   tempsum = ~tempsum + 1'b1;
			tempsum[25] = 1;
			end
		e1 = e;															//Storing exponent for 3rd step
	end
end

//Step-1: Load input and shift exponents to bring all inputs in standard form
always@(posedge clk)
begin
	ma[23:0] = {1'b1,a[22:0]};								//Significand
	mb[23:0] = {1'b1,b[22:0]};								//Significand
	ea = {24'b0,a[30:23]} - 127;							//Actual exponent
	eb = {24'b0,b[30:23]} - 127;							//Actual exponent
	temp = ea<eb ? ma>>(eb-ea) : mb>>(ea-eb);			//Making similar exponents
	e = ea>eb?ea:eb;											//Selecting higher exponent
	ma = ea<eb?temp:ma;										//Updating Significand
	mb = ea>=eb?temp:mb;										//Updating Significand
	sa = a[31];													//Loading sign bit
	sb = b[31];													//Loading sign bit
	count = count + 1;										//counter increased
end
endmodule
