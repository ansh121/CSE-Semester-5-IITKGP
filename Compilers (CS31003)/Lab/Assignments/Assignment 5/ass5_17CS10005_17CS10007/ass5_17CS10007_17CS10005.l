%{	
  #include "ass5_17CS10007_17CS10005_translator.h"
  #include "y.tab.h"  
  extern void yyerror(char*);
  void comment();
%}

%option noyywrap

WS          [ \n\t]
SIGN 				[+-]
DIGIT      			[0-9]
NON_ZERO_DIGIT      [1-9]
DIGIT_SEQ			{DIGIT}+
ALPHABET			[_a-zA-Z]
ESCAPE_SEQ_C		[\"\?\\\a\b\f\r\t\v]
ESCAPE_SEQ_S		[\'\?\\\a\b\f\r\t\v]
C_CHAR				[^\'\\\n]|{ESCAPE_SEQ_C}
C_CHAR_SEQ			{C_CHAR}+
S_CHAR				[^\"\\\n]|{ESCAPE_SEQ_S} 
S_CHAR_SEQ			{S_CHAR}+
EXPONENTIAL			[eE]({SIGN}?){DIGIT_SEQ}
INT_CONST			"0"|({NON_ZERO_DIGIT}({DIGIT}*))
FRACTION_CONST		({DIGIT_SEQ}?\.{DIGIT_SEQ})|({DIGIT_SEQ}\.)
FLOAT_CONST			({FRACTION_CONST}({EXPONENTIAL}?))|({DIGIT_SEQ}{EXPONENTIAL})
ENUM_CONST			{ID}
CHAR_CONST			\'{C_CHAR_SEQ}\'

ID      			({ALPHABET}+)({DIGIT}{ALPHABET})*

STRL         		\"{S_CHAR_SEQ}?\"         



%%

"//"[^\n]*		{;}
"/*"			{comment();}

{WS}       {;}

"auto"		{yylval.str=strdup("auto"); return AUTO;}
"break" 	{yylval.str=strdup("break"); return BREAK;}
"case"  	{yylval.str=strdup("case"); return CASE;}
"char"  	{yylval.str=strdup("char"); return CHAR;}
"const" 	{yylval.str=strdup("const"); return CONST;}
"continue"	{yylval.str=strdup("continue"); return CONTINUE;}
"default"	{yylval.str=strdup("default"); return DEFAULT;}
"do"		{yylval.str=strdup("do"); return DO;}
"double"    {yylval.str=strdup("double"); return DOUBLE;}
"else"		{yylval.str=strdup("else"); return ELSE;}
"enum"		{yylval.str=strdup("enum"); return ENUM;}
"extern"	{yylval.str=strdup("extern"); return EXTERN;}
"float"		{yylval.str=strdup("float"); return FLOAT;}
"for"		{yylval.str=strdup("for"); return FOR;}
"goto"		{yylval.str=strdup("goto"); return GOTO;}
"if"		{yylval.str=strdup("if"); return IF;}
"inline"	{yylval.str=strdup("inline"); return INLINE;}
"int"		{yylval.str=strdup("int"); return INT;}
"long"		{yylval.str=strdup("long"); return LONG;}
"register"	{yylval.str=strdup("register"); return REGISTER;}
"restrict"	{yylval.str=strdup("restrict"); return RESTRICT;}
"return"	{yylval.str=strdup("return"); return RETURN;}
"short"		{yylval.str=strdup("short"); return SHORT;}
"signed"	{yylval.str=strdup("signed"); return SIGNED;}
"sizeof" 	{yylval.str=strdup("sizeof"); return SIZEOF;}
"static"	{yylval.str=strdup("static"); return STATIC;}
"struct"	{yylval.str=strdup("struct"); return STRUCT;}	
"switch"	{yylval.str=strdup("switch"); return SWITCH;}
"typedef"	{yylval.str=strdup("typedef"); return TYPEDEF;}
"union"		{yylval.str=strdup("union"); return UNION;}
"unsigned"	{yylval.str=strdup("unsigned"); return UNSIGNED;}
"void"		{yylval.str=strdup("void"); return VOID;}
"volatile"	{yylval.str=strdup("volatile"); return VOLATILE;}
"while"		{yylval.str=strdup("while"); return WHILE;}
"bool"		{yylval.str=strdup("_Bool"); return _BOOL;}
"_Complex"	{yylval.str=strdup("_Complex"); return _COMPLEX;}
"_Imaginary" {yylval.str=strdup("_Imaginary"); return _IMAGINARY;}

{INT_CONST}     	{yylval.intval=atoi(yytext); return INT_CONST;}
{FRACTION_CONST}	{sscanf(yytext, "%lf", &yylval.real);return FRACTION_CONST;}
{FLOAT_CONST}		{sscanf(yytext, "%lf", &yylval.real); return FLOAT_CONST;}
{CHAR_CONST}		{yylval.str=strdup(yytext); return CHAR_CONST;}

{ID}        {yylval.symnode=new SymNode;yylval.symnode->name=string(yytext); return IDENTIFIER;}

"["			{yylval.str=strdup("["); return L_SQRB;}
"]"			{yylval.str=strdup("]"); return R_SQRB;}
"("			{yylval.str=strdup("("); return L_PARAN;}
")"			{yylval.str=strdup(")"); return R_PARAN;}
"{"			{yylval.str=strdup("{"); return L_BRACES;}
"}"			{yylval.str=strdup("}"); return R_BRACES;}
"."			{yylval.str=strdup("."); return DOT;}
"->"		{yylval.str=strdup("->"); return ARROW_ASSIGN;}
"++"		{yylval.str=strdup("++"); return INCREMENT;}
"--"		{yylval.str=strdup("--"); return DECREMENT;}
"&"			{yylval.str=strdup("&"); return BIT_AND;}
"*"			{yylval.str=strdup("*"); return MUL;}
"+"			{yylval.str=strdup("+"); return ADD;}
"-"			{yylval.str=strdup("-"); return MINUS;}
"~"			{yylval.str=strdup("~"); return NEGATE;}
"!"			{yylval.str=strdup("!"); return NOT;}
"/"			{yylval.str=strdup("/"); return DIVIDE;}
"%"			{yylval.str=strdup("%"); return REMAINDER;}
"<<"		{yylval.str=strdup("<<"); return L_SHIFT;}
">>"		{yylval.str=strdup(">>"); return R_SHIFT;}
"<"			{yylval.str=strdup("<"); return LESS_THAN;}
">"			{yylval.str=strdup(">"); return GREATER_THAN;}
"<="		{yylval.str=strdup("<="); return LESS_THAN_EQUAL;}
">="		{yylval.str=strdup(">="); return GREATER_THAN_EQUAL;}
"=="		{yylval.str=strdup("=="); return IS_EQUAL;}
"!="		{yylval.str=strdup("!="); return NOT_EQUAL;}
"^"			{yylval.str=strdup("^"); return BIT_XOR;}
"|="		{yylval.str=strdup("|="); return BIT_OR_ASSIGN;}
"&&"		{yylval.str=strdup("&&"); return BOOL_AND;}
"||"		{yylval.str=strdup("||"); return BOOL_OR;}
"?"			{yylval.str=strdup("?"); return QM;}
":"			{yylval.str=strdup(":"); return COLON;}
";"			{yylval.str=strdup(";"); return SEMICOLON;}
"..."		{yylval.str=strdup("..."); return ELLIPSES;}
"="			{yylval.str=strdup("="); return ASSIGN;}
"*="		{yylval.str=strdup("*="); return MUL_ASSIGN;}
"/="		{yylval.str=strdup("/="); return DIVIDE_ASSIGN;}
"%="		{yylval.str=strdup("%="); return REM_ASSIGN;}
"+="		{yylval.str=strdup("+="); return ADD_ASSIGN;}
"-="		{yylval.str=strdup("-="); return MINUS_ASSIGN;}
"<<="		{yylval.str=strdup("<<="); return L_SHIFT_ASSIGN;}
">>="		{yylval.str=strdup(">>="); return R_SHIFT_ASSIGN;}
"&="		{yylval.str=strdup("&="); return BIT_AND_ASSIGN;}
"^="		{yylval.str=strdup("^="); return BIT_XOR_ASSIGN;}
","			{yylval.str=strdup(","); return COMMA;}
"#"			{yylval.str=strdup("#"); return HASH;}
"|"			{yylval.str=strdup("|"); return BIT_OR;}
{STRL}      {yylval.str=strdup(yytext); return STRING_LITERAL;}

%%

void comment(){
	char c, prev = 0;
	while ((c = yyinput()) != 0){
		if (c == '/' && prev == '*') return;
		prev = c;
	}
	char* temp=(char*)calloc(30,sizeof(char));
	strcpy(temp,"unterminated comment");
	yyerror(temp);
}

