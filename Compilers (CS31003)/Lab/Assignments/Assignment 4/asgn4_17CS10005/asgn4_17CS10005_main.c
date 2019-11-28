/******************************* 
Name - Anshul Choudhary
Roll No - 17CS10005
Assignment - 4 (Parser for tinyC)
********************************/
#include <stdio.h>
#include "y.tab.h"
extern char* yytext;
extern int yyparse();


int main() {
	int token;
	yyparse();
	return 0;  
}