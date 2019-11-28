/*
Name -  Anshul Choudhary
Roll No. - 17CS10005
Assignment No. - 2 
Date:- 23/07/2018
*/

#include "myl.h"

int main(){

	float f;
	int input,integer;

	printStr("\n/* All the print statements are printed using PrintStr function */");

    while(1){
    	printStr("\n Choose function:");

        printStr("\n1.Read Integer\n2.Print integer\n3.Read Float\n4.Print Float\n\nEnter input: ");

        if(readInt(&input)==ERR)
        {
            printStr("------>'You entered an invalid option.'\n");
        }
        else
        {
          if(input==1)
          {
              printStr("Enter integer: ");

              if(readInt(&integer)==ERR) 
              {
                  printStr("------>'ERR! Invalid Integer.'\n");
              }
              else
              {
                  printStr("------>'Integer read.'\n");
              }
          }
          else if(input==2)
          {
              printInt(integer);
          }
          else if(input==3)
          {
              printStr("Enter float: ");

              if(readFlt(&f)==ERR)
              {
                  printStr("------>'ERR! Invalid Float.'\n");
              }
              else
              {
                  printStr("------>'Float read.'\n");
              }
          }
          else if(input==4)
          {
              printFlt(f);
          }
          else
          {
              printStr("------>'Please choose one of the above options.'\n");
          }
      }
    }
  
  return 0;
}
