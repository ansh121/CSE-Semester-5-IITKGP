/************************************************
Name -  Anshul Choudhary (17CS10005),
        Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/

%{
    /*C Declarations and Definitions*/
    #include "ass6_17CS10005_17CS10007_translator.h"
    #include "y.tab.h"

%}

/*Regular Expressions*/

CASE            "case"
EXTERN          "extern"
RETURN          "return"
LONG            "long"
_IMAGINARY      "_Imaginary"
GOTO            "goto"
STRUCT          "struct"
INT             "int"
SIZEOF          "sizeof"
REGISTER        "register"
WHILE           "while"
DEFAULT         "default"
CHAR            "char"
IF              "if"
VOID            "void"
BREAK           "break"
UNION           "union"
DO              "do"
CONST           "const"
UNSIGNED        "unsigned"
FOR             "for"
FLOAT           "float"
RESTRICT        "restrict"
INLINE          "inline"
AUTO            "auto"
VOLATILE        "volatile"
SHORT           "short"
CONTINUE        "continue"
_COMPLEX        "_Complex"
ENUM            "enum"
DOUBLE          "double"
SIGNED          "signed"
STATIC          "static"
_BOOL           "_Bool"
SWITCH          "switch"
TYPEDEF         "typedef"
ELSE            "else"


/*Regular Expressions*/

ID ([a-zA-Z_]([a-zA-Z_]|[0-9])*)
WS [ \t\n]
NONZERODIG [1-9]
DIGIT [0-9]
INT_CONST (({NONZERODIG}({DIGIT}*))|[0]+)
DECIMALPT "."
DIGIT_SEQ {DIGIT}+
FRAC_CONST {DIGIT_SEQ}?{DECIMALPT}{DIGIT_SEQ}|{DIGIT_SEQ}{DECIMALPT}
SIGN [+-]
EXPONENT ([eE]{SIGN}?{DIGIT_SEQ})
FLOAT_CONST ({FRAC_CONST}{EXPONENT}?|{DIGIT_SEQ}{EXPONENT})
ENUMERATION_CONST   {ID}
ESCAPE_SEQ ([\\][\'\"\?\\abfnrtv])
C_CHAR [^\'\\\n]|{ESCAPE_SEQ}
C_CHAR_SEQ {C_CHAR}+
C_CHAR_CONST (\'{C_CHAR_SEQ}\')
CONSTANT {INT_CONST}|{FLOAT_CONST}|{ENUMERATION_CONST}|{C_CHAR_CONST}
S_CHAR [^\"\\\n]|{ESCAPE_SEQ}
S_CHAR_SEQ {S_CHAR}+
STRING_LITERAL (\"{S_CHAR_SEQ}*\")
SINGLE_LINE_COMMENT [/][/].*
MULTI_COMMENT_START [/][\*]+
MULTI_COMMENT_END   [\*]+[/]
MULTI_LINE_COMMENT ({MULTI_COMMENT_START}(([^\*])|((\*)+[^/\*]))*{MULTI_COMMENT_END})
COMMENT {SINGLE_LINE_COMMENT}|{MULTI_LINE_COMMENT}



/*Actions(FSMs)*/
%%

{VOLATILE}      {return VOLATILE_;}
{_IMAGINARY}    {return IMAGINARY_;}
{CONST}         {return CONST_;}
{INT}           {return INT_;}
{TYPEDEF}       {return TYPEDEF_;}
{FLOAT}         {return FLOAT_;}
{UNSIGNED}      {return UNSIGNED_;}
{CASE}          {return CASE_;}
{AUTO}          {return AUTO_;}
{BREAK}         {return BREAK_;}
{EXTERN}        {return EXTERN_;}
{DEFAULT}       {return DEFAULT_;}
{RETURN}        {return RETURN_;}
{CHAR}          {return CHAR_;}
{LONG}          {return LONG_;}
{ELSE}          {return ELSE_;}
{ENUM}          {return ENUM_;}
{GOTO}          {return GOTO_;}
{REGISTER}      {return REGISTER_;}
{WHILE}         {return WHILE_;}
{INLINE}        {return INLINE_;}
{DO}            {return DO_;}
{DOUBLE}        {return DOUBLE_;}
{SHORT}         {return SHORT_;}
{_COMPLEX}      {return COMPLEX_;}
{UNION}         {return UNION_;}
{RESTRICT}      {return RESTRICTED_;}
{IF}            {return IF_;}
{STATIC}        {return STATIC_;}
{SWITCH}        {return SWITCH_;}
{VOID}          {return VOID_;}
{STRUCT}        {return STRUCT_;}
{CONTINUE}      {return CONTINUE_;}
{SIGNED}        {return SIGNED_;}
{_BOOL}         {return BOOL_;}
{SIZEOF}        {return SIZEOF_;}
{FOR}           {return FOR_;}

"..."                   { return ELLIPSIS; }
">>="                   { return RIGHT_ASSIGN; }
"<<="                   { return LEFT_ASSIGN; }
"+="                    { return ADD_ASSIGN; }
"-="                    { return SUB_ASSIGN; }
"*="                    { return MUL_ASSIGN; }
"/="                    { return DIV_ASSIGN; }
"%="                    { return MOD_ASSIGN; }
"&="                    { return AND_ASSIGN; }
"^="                    { return XOR_ASSIGN; }
"|="                    { return OR_ASSIGN; }
">>"                    { return RIGHT_SHIFT; }
"<<"                    { return LEFT_SHIFT; }
"++"                    { return INCREMENT_OP; }
"--"                    { return DECREMENT_OP; }
"->"                    { return POINTER_OP; }
"&&"                    { return AND_OP; }
"||"                    { return OR_OP; }
"<="                    { return LESS_EQ_OP; }
">="                    { return GREATER_EQ_OP; }
"=="                    { return EQ_OP; }
"!="                    { return NOT_EQ_OP; }
";"                     { return ';'; }
"{"                     { return '{'; }
"}"                     { return '}'; }
","                     { return ','; }
":"                     { return ':'; }
"="                     { return '='; }
"("                     { return '('; }
")"                     { return ')'; }
"["                     { return '['; }
"]"                     { return ']'; }
"."                     { return '.'; }
"&"                     { return '&'; }
"!"                     { return '!'; }
"~"                     { return '~'; }
"-"                     { return '-'; }
"+"                     { return '+'; }
"*"                     { return '*'; }
"/"                     { return '/'; }
"%"                     { return '%'; }
"<"                     { return '<'; }
">"                     { return '>'; }
"^"                     { return '^'; }
"|"                     { return '|'; }
"?"                     { return '?'; }
"#"                     { return '#'; }


{SINGLE_LINE_COMMENT}           {;}
{MULTI_LINE_COMMENT}            {;}

{ID}                    { yylval.str = new string(yytext); return IDENTIFIER;}
{INT_CONST}             { yylval.intval = atoi(yytext); return INT_CONSTANT;}
{FLOAT_CONST}           { yylval.floatval = atof(yytext); return FLOAT_CONSTANT;}
{C_CHAR_CONST}          { yylval.charval = yytext[1]; return CHAR_CONSTANT;}
{STRING_LITERAL}        { yylval.str = new string(yytext); return STRING_LITERAL;}

{WS}                {}                          /*Ignore white spaces, so do nothing*/

%%


































