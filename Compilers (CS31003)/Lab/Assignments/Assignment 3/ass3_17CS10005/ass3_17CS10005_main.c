/******************************* 
Name - Anshul Choudhary
Roll No - 17CS10005
Assignment - 3 (Lexer for tinyC)
********************************/

#include <stdio.h>

extern char* yytext;

int main() {

  int token;
  while (token = yylex()) {

    switch (token) {
  		case KEYWORD:
  			printf("KEYWORD->          %s\n", yytext);
  			break;

		case IDENTIFIER: 
			printf("IDENTIFIER->       %s\n", yytext); 
			break;

		case CONSTANT: 
			printf("CONSTANT->         %s\n", yytext); 
			break;

		case STRING_LITERAL: 
			printf("STRING LITERAL->   %s\n", yytext); 
			break;

		case PUNCTUATOR: 
			printf("PUNCTUATOR->       %s\n", yytext); 
			break;

		case COMMENT: 
			printf("COMMENT\n"); 
			break;

		case COMMENT_ERROR: 
			printf("Error in Commenting\n"); 
			break;

    	case ESCAPE_SEQUENCE:
    		printf("ESCAPE CHARACTER-> %s\n", yytext);
  			break;

		default: 
			printf("PUNCTUATOR->       %s\n", yytext); 
			break;
    }
  }
}