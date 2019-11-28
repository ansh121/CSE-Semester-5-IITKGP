/* 
Name:- Ishwarkar Rohan Shankar
Roll No:- 16CS30012
Assignment 4 Compilers Lab
Autumn Semester 2018
*/
#include <stdio.h>
#include "y.tab.h"
extern char* yytext;
extern int yyparse();
int main() {
  int token;
  yyparse();
  return 0;  
}