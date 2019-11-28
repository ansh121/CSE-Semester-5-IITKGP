/******************************* 
Name - Anshul Choudhary
Roll No - 17CS10005
Assignment - 3 (Lexer for tinyC)
********************************/

%{
	#define KEYWORD 1
	#define IDENTIFIER 2
	#define CONSTANT 3
	#define STRING_LITERAL 4
	#define PUNCTUATOR 5
	#define COMMENT 6
	#define COMMENT_ERROR 7
	#define ESCAPE_SEQUENCE 8
%}

/*///////////////////////////////	Lexical Grammer for tinyC	//////////////////////////////*/

KEYWORD             		"auto"|"enum"|"restrict"|"unsigned"|"break"|"extern"|"return"|"void"|"case"|"float"|"short"|"volatile"|"char"|"for"|"signed"|"while"|"const"|"goto"|"sizeof"|"_Bool"|"continue"|"if"|"static"|"_Complex"|"default"|"inline"|"struct"|"_Imaginary"|"do"|"int"|"switch"|"double"|"long"|"typedef"|"else"|"register"|"union"
IDENTIFIER 					{IDENTIFIER_NONDIGIT}({IDENTIFIER_NONDIGIT}|{DIGIT})*
IDENTIFIER_NONDIGIT 		[a-zA-Z_]
DIGIT						[0-9]
CONSTANT					{INTEGER_CONSTANT}|{FLOATING_CONSTANT}|{ENUMERATION_CONSTANT}|{CHARACTER_CONSTANT}
INTEGER_CONSTANT 			0|{NON_ZERO_DIGIT}{DIGIT}*
NON_ZERO_DIGIT				[1-9]
FLOATING_CONSTANT 			({FRACTIONAL_CONSTANT}{EXPONENT_PART}?)|({DIGIT}+{EXPONENT_PART})
FRACTIONAL_CONSTANT 		(({DIGIT}+)?\.{DIGIT}+)|(({DIGIT}+)\.)
EXPONENT_PART				([eE][-+]?{DIGIT}+)
SIGNS						[-+]
ENUMERATION_CONSTANT 		{IDENTIFIER}
CHARACTER_CONSTANT 			'({C_CHAR})+'
C_CHAR 						[^'\\\n]|{ESCAPE_SEQUENCE}
ESCAPE_SEQUENCE				\\['"?\\abfnrtv]
STRING_LIT 					\"({S_CHAR}+)\"
S_CHAR 						[^"\\\n]|{ESCAPE_SEQUENCE}
WHITESPACE  				[ \t\v\n\f]
PUNCTUATOR					"["|"]"|"("|")"|"{"|"}"|"."|"->"|"++"|"--"|"&"|"*"|"+"|"-"|"~"|"!"|"/"|"%"|"<<"|">>"|"<"|">"|"<="|">="|"=="|"!="|"^"|"|"|"&&"|"||"|"?"|":"|";"|"..."|"="|"*="|"/="|"%="|"+="|"-="|"<<="|">>="|"&="|"^="|"|="|","|"#"


%%
{KEYWORD}					{ return KEYWORD;}
{IDENTIFIER}				{ return IDENTIFIER; }
{CONSTANT}					{ return CONSTANT; }
{STRING_LIT} 				{ return STRING_LITERAL; }
{PUNCTUATOR}				{ return PUNCTUATOR;}
{WHITESPACE}				{ /* Ignore whitespace */ }
"/*"						{ 	
								char a, prev = 'a';
								while ((a = input()) != EOF) {
									if (prev == '*' && a == '/')  return COMMENT;
									prev = a;
								}
								return COMMENT_ERROR;
							}
"//".*  	   				{ return COMMENT;}
{ESCAPE_SEQUENCE} 			{ return ESCAPE_SEQUENCE;}
%%
