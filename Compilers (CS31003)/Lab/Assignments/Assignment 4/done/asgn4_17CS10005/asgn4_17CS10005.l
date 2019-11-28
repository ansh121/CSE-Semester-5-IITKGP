/******************************* 
Name - Anshul Choudhary
Roll No - 17CS10005
Assignment - 4 (Parser for tinyC)
********************************/

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
INTEGER_CONSTANT 			{NON_ZERO_DIGIT}{DIGIT}*|0
FRACTIONAL_PART 			(({DIGIT}+)?\.{DIGIT}+)|(({DIGIT}+)\.) 
EXPONENT_PART				([Ee][+-]?{DIGIT}+)
FLOATING_CONSTANT 			({FRACTIONAL_PART}{EXPONENT_PART}?)|({DIGIT}+{EXPONENT_PART})
ENUMERATION_CONSTANT 		{IDENTIFIER}
ESCAPE_SEQUENCE				\\['"?\\abfnrtv]
C_CHAR 						[^'\\\n]|{ESCAPE_SEQUENCE}
CHARACTER_CONSTANT 			'({C_CHAR})+'
S_CHAR 						[^"\\\n]|{ESCAPE_SEQUENCE}
STRING_CONSTANT 			\"({S_CHAR}+)\" 
WHITESPACE  				[ \t\v\n\f]


%%

"/*"			{ comment(); }
"//".*  	   	{ /* Single line comment */}

"sizeof"        { return SIZEOF; }
"extern"        { return EXTERN; }
"static"        { return STATIC; }
"auto"			{ return AUTO; }
"register"      { return REGISTER; }
"void"          { return VOID; }
"char"          { return CHAR; }
"short"         { return SHORT; }
"int"           { return INT; }
"long"          { return LONG; }
"float"         { return FLOAT; }
"double"        { return DOUBLE; }
"signed"        { return SIGNED; }
"unsigned"      { return UNSIGNED; }
"_Bool"         { return BOOL; }
"_Complex"      { return COMPLEX; }
"_Imaginary"    { return IMAGINARY; }
"enum"          { return ENUM; }
"const"         { return CONST; }
"restrict"      { return RESTRICT; }
"volatile"      { return VOLATILE; }
"inline"        { return INLINE; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"if"            { return IF; }
"else"          { return ELSE; }
"switch"        { return SWITCH; }
"while"         { return WHILE; }
"do"            { return DO; }
"for"           { return FOR; }
"goto"          { return GOTO; }
"continue"      { return CONTINUE; }
"break"         { return BREAK; }
"return"        { return RETURN; }




"~"				{ return NOT; }
"!"				{ return EXCLAMATION; }
"#"				{ return HASH; }
"%"				{ return PERCENTAGE; }
"^"				{ return XOR; }
"&"				{ return AND; }
"&&"			{ return AND; }
"*"				{ return MULTIPLY; }
"("				{ return OPENROUNDBRACKET; }
")"				{ return CLOSEROUNDBRACKET; }
"-"				{ return MINUS; }
"--"			{ return DECREMENT; }
"="				{ return EQUAL; }
"=="			{ return EQUALEQUAL; }
"+"				{ return PLUS; }
"++"			{ return INCREMENT; }
"{"				{ return OPENCURLYBRACKET; }
"}"				{ return CLOSECURLYBRACKET; }
"["				{ return OPENSQUAREBRACKET; }
"]"				{ return CLOSESQUAREBRACKET; }
"||"			{ return OR; }
":"				{ return COLON; }
";"				{ return SEMICOLON; }
","				{ return COMMA; }
"<"				{ return LESSTHAN; }
"<<"			{ return LEFTSHIFT; }
"."				{ return DOT; }
">"				{ return GREATERTHAN; }
">>"			{ return RIGHTSHIFT; }
"?"				{ return QUESTIONMARK; }
"/"				{ return DIVIDE; }
"<="			{ return LESSTHANEQUAL; }
">="			{ return GREATERTHANEQUAL; }
"!="			{ return NOTEQUAL; }
"->"			{ return POINTER; }
"*="			{ return MULTIPLYASSIGN; }
"..."			{ return ELLIPSIS; }
"/="			{ return DIVIDEASSIGN; }
"%="			{ return MODASSIGN; }
"+="			{ return ADDASSIGN; }
"<<="			{ return LEFTSHIFTASSIGN; }
">>="			{ return RIGHTSHIFTASSIGN; }
"-="			{ return SUBTRACTASSIGN; }
"&="			{ return ANDASSIGN; }
"^="			{ return XORASSIGN; }
"|="			{ return ORASSIGN; }


{STRING_CONSTANT} 			{ return STRING_LITERAL; }
{IDENTIFIER}				{ return IDENTIFIER; }
{INTEGER_CONSTANT} 			{ return INT_CONSTANT; }
{FLOATING_CONSTANT} 		{ return FLOAT_CONSTANT; }
{CHARACTER_CONSTANT} 		{ return CHAR_CONSTANT; }
{WHITESPACE}			{ /* whitespace separates tokens */ }

%%

void comment(void) {
	char c, p = 0;
	while ((c = input()) != 0) {
		if (c == '/' && p == '*') return;
		p = c;
	}
	error("Error in Commenting!");
}