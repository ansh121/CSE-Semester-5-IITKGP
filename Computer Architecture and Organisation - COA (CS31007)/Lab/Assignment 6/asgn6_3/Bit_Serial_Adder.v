`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    21:37:30 08/19/2019 
// Design Name: 
// Module Name:    Bit_Serial_Adder 
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
module Bit_Serial_Adder(input [7:0]a, input [7:0] b, input clk, input reset, output [7:0] sum, output cout);
	 wire cin;
	 assign cin =0;
    wire a_bit;						//store current bit of a under consideration in each clock
    wire b_bit; 						//store current bit of a under consideration in each clock
    wire sum_bit;						//store current sum bit 
    wire cout_bit;					//store current cout bit 
    wire cin_bit;						//store current cin bit 
    assign cout = cout_bit;		//link cout to cout_bit

    reg [3:0] state;					//register will go from state 0 to state 7 creating 8 bit counter
    wire[3:0] count=state;			//link count to state

    initial								//state initialisation
        begin
            state <= 0;
        end

	 always @(posedge clk)			//cycle to change state at every clock
    begin
		  if(reset == 1)				//reset to go to start state i.e. state 0
				state = 0;
        else if(state <= 8) 
            state = state + 1; 
    end
	
    Parallen_in_Serial_out inputa(a, clk, count, a_bit);		//function to move a_bit to next bit of a in every cycle
    Parallen_in_Serial_out inputb(b, clk, count, b_bit);		//function to move b_bit to next bit of b in every cycle

	 assign {cout_bit, sum_bit} = a_bit + b_bit + cin_bit;	//evaluate current cout_bit and sum_bit 

    D_flip_flop D(clk, reset, cout_bit, count, cin, cin_bit);	//make cout_bit as cin_bit for next calculation using d flipflop
    Serial_in_Parallel_out sum_sipo(clk, reset, sum_bit, count, sum);	//store current result

endmodule 

module Serial_in_Parallel_out(input clk, input reset, input a, input [3:0] count, output [7:0] final);
    reg [7:0] ans;				// store final answer
    assign final = ans;
    initial							// initialisation to 0
            begin 
            ans <= 8'b00000000;
            end
    always @(posedge clk)
        begin
				if(reset == 1)			// reset condition
					ans = 8'b00000000;
            else if (count <= 8 && count >= 1)
                ans = {a, ans[7:1]};
        end
endmodule


module D_flip_flop(input clk, input reset, input cout, input [3:0] count, input cin, output q);
    reg d;
    assign q = d;
    initial			// initial cin_bit i.e. q = 0
        begin
            d = 0;
        end
    always @(posedge clk)
    begin
		  if(reset == 1)		// reset condition 
				d <= 0;
        else if(count == 0)	// initail start consition
            d <= cin;
        else if(count <= 8)
            d <= cout;
    end
endmodule 


module Parallen_in_Serial_out(input [7:0] a, input clk, input [3:0] count, output bit);
    reg [7:0] a_store;			// store bits of a and b
    assign bit = a_store[0];  // bit is current bit in consideratin
    always @(posedge clk)
        begin
				if(count == 0)    // store all bits of a into a_store initially
                a_store <= a;
            else if (count <= 8)
                a_store <= {a_store[0], a_store[7:1]}; // right shify by 1 bit
				else
					 a_store[0] <= a[7];
        end
endmodule 
