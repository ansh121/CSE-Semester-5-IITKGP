`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:48:36 08/21/2019 
// Design Name: 
// Module Name:    Mult_3 
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
module Mult_3(
    input [15:0]a,
	 input clk,
    output out,
	 output a_bit
    );
	 		
    wire[4:0] count;
	 wire[1:0] state;
	 
	 Counter_loop CL(clk, count);	  
	 Parallel_in_Serial_out PISO(a, clk, count, a_bit);
	 Change_state CS( a_bit, clk, out);
	 //assign_answer getans(clk, state, out);

endmodule

/*module assign_answer(input clk, input [1:0] state, output out);
	reg ans;
	assign out=ans;
	
	initial								//state initialisation
        begin
            ans <= 0;
        end
		  
	always @(posedge clk)			//cycle to change state at every clock
    begin
        if(state == 0) ans = 1;
		  else ans = 0;            
    end
endmodule
*/
module Counter_loop(input clk, output [4:0]count);
	reg [4:0] counter;
	assign count = counter;
	
	initial
		begin
			counter <=0;
		end
		
	always @(posedge clk)
		begin
			 if(counter < 16) 
					counter = counter + 1; 
    end
	
endmodule

module Change_state (input a_bit, input clk, output out);
	reg [1:0] state;
	reg ans;
	assign out = ans;
	
	initial
		begin
			state <= 0;
		end
		
	always @(posedge clk)			//cycle to change state at every clock
    begin
        if(state == 0)
				begin
					if(a_bit == 1) 
						state = state + 1;
				end
		  else if(state == 1)
				begin
					if(a_bit==0)
						state = state + 1;
					else state = state - 1;
				end
		  else if(a_bit==0) 
				state = state - 1;
				
		  if(state == 0) ans = 1;
		  else ans = 0;
             
    end
endmodule

module Parallel_in_Serial_out(input [15:0] a, input clk, input [4:0] count, output a_bit);
    reg [15:0] a_store;		   	// store bits of a and b
    assign a_bit = a_store[15];  // bit is current bit in consideratin
    always @(posedge clk)
        begin
				if(count == 0)      // store all bits of a into a_store initially
                a_store <= a;
            else if (count < 16)
                a_store <= {a_store[14:0], a_store[15]}; // left shify by 1 bit
				else
					 a_store[15] <= a[0];

        end
endmodule
