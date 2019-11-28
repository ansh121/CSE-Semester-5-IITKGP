`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:29:56 10/30/2019 
// Design Name: 
// Module Name:    MUX_2x1 
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
module MUX_2x1(
    input [31:0] in1,
    input [31:0] w1,
    input s,
    output [31:0] out
    );
	 
	 assign out=s?w1:in1;

endmodule
