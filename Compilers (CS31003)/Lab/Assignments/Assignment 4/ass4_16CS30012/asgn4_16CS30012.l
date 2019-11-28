/* 
Name:- Ishwarkar Rohan Shankar
Roll No:- 16CS30012
Assignment 4 Compilers Lab
Autumn Semester 2018
*/

%{

#include "y.tab.h"
#include <math.h>
void comment (void);
extern void yyerror(const char *);

%}

/************** Regular Expression Definitions *******************/


ALPHABET 			 		[a-zA-Z_]
DIGIT						[0-9]
IDENTIFIER 					{ALPHABET}({ALPHABET}|{DIGIT})*
NON_ZERO_DIGIT				[1-9]
EXPONENT_PART				([Ee][+-]?{DIGIT}+)
INTEGER_CONSTANT 			{NON_ZERO_DIGIT}{DIGIT}*|0
FLOATING_CONSTANT 			({FRACTIONAL_PART}{EXPONENT_PART}?)|({DIGIT}+{EXPONENT_PART})
FRACTIONAL_PART 			(({DIGIT}+)?\.{DIGIT}+)|(({DIGIT}+)\.) 
ENUMERATION_CONSTANT 		{IDENTIFIER}
ESCAPE_SEQUENCE				\\['"?\\abfnrtv]
c_char 						[^'\\\n]|{ESCAPE_SEQUENCE}
character_constant 			'({c_char})+'
s_char 						[^"\\\n]|{ESCAPE_SEQUENCE}
string_constant 			\"({s_char}+)\"
backother  					[ \t\v\n\f]

%%

"/*"			{ comment(); }
"//".*  	   	{  /* consume //-comment */ }

"auto"			{ return AUTO; }
"enum"          { return ENUM; }
"restrict"      { return RESTRICT; }
"unsigned"      { return UNSIGNED; }
"break"         { return BREAK; }
"extern"        { return EXTERN; }
"return"        { return RETURN; }
"void"          { return VOID; }
"case"          { return CASE; }
"float"         { return FLOAT; }
"short"         { return SHORT; }
"volatile"      { return VOLATILE; }
"char"          { return CHAR; }
"for"           { return FOR; }
"signed"        { return SIGNED; }
"while"         { return WHILE; }
"const"         { return CONST; }
"goto"          { return GOTO; }
"sizeof"        { return SIZEOF; }
"_Bool"         { return BOOL; }
"continue"      { return CONTINUE; }
"if"            { return IF; }
"static"        { return STATIC; }
"_Complex"      { return COMPLEX; }
"default"       { return DEFAULT; }
"inline"        { return INLINE; }
"struct"        { return STRUCT; }
"_Imaginary"    { return IMAGINARY; }
"do"            { return DO; }
"int"           { return INT; }
"switch"        { return SWITCH; }
"double"        { return DOUBLE; }
"long"          { return LONG; }
"typedef"       { return TYPEDEF; }
"else"          { return ELSE; }
"register"      { return REGISTER; }
"union"         { return UNION; }


{string_constant} 			{ return STRING_LITERAL; }
{IDENTIFIER}				{ return IDENTIFIER; }
{INTEGER_CONSTANT} 			{ return INT_CONSTANT; }
{FLOATING_CONSTANT} 		{ return FLOAT_CONSTANT; }
{character_constant} 		{ return CHAR_CONSTANT; }




"("				{ return OPENROUND; }
")"				{ return CLOSEROUND; }
"{"				{ return OPENCURLY; }
"}"				{ return CLOSECURLY; }
"."				{ return DOT; }
"!"				{ return EXCLAMATION; }
","				{ return COMMA; }
"#"				{ return HASH; }
"^"				{ return XOR; }
"?"				{ return QUESTIONMARK; }
":"				{ return COLON; }
";"				{ return SEMICOLON; }
"["				{ return OPENSQUARE; }
"]"				{ return CLOSESQUARE; }
"/"				{ return DIVIDE; }
"%"				{ return PERCENTAGE; }
"<"				{ return LESSTHAN; }
">"				{ return GREATERTHAN; }
"="				{ return EQUAL; }
"&"				{ return AND; }
"*"				{ return MULTIPLY; }
"+"				{ return PLUS; }
"-"				{ return MINUS; }
"~"				{ return NOT; }
"++"			{ return INCREMENT; }
"<<"			{ return LEFTSHIFT; }
"--"			{ return DECREMENT; }
">>"			{ return RIGHTSHIFT; }
"&&"			{ return AND; }
"||"			{ return OR; }
"<="			{ return LESSTHANEQUAL; }
">="			{ return GREATERTHANEQUAL; }
"=="			{ return EQUALEQUAL; }
"!="			{ return NOTEQUAL; }
"->"			{ return POINTER; }
"*="			{ return MULTIPLYASSIGN; }
"..."			{ return ELLIPSIS; }
"/="			{ return DIVIDEASSIGN; }
"%="			{ return MODASSIGN; }
"+="			{ return ADDASSIGN; }
"<<="			{ return LEFTSHIFTASSIGN; }
">>="			{ return RIGHTSHIFTASSIGN; }
"-="			{ return SUBASSIGN; }
"&="			{ return ANDASSIGN; }
"^="			{ return XORASSIGN; }
"|="			{ return ORASSIGN; }


{backother}			{ /* whitespace separates tokens */ }

%%

int column = 0,row=0,temp;
void comment(void) {
	char c, prev = 0;
	while ((c = input()) != 0) {     /* (EOF maps to 0) */
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	error("Unproper commenting Please Check!");
}