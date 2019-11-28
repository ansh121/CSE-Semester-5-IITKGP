/******************************* 
Name - Anshul Choudhary
Roll No - 17CS10005
Assignment - 4 (Parser for tinyC)
********************************/

%{ 
	#include <string.h>
	#include <stdio.h>
	extern int yylex();
	void yyerror(char *s);
%}






%union { int intval; }

// Punctuators and operators
%token NOT EXCLAMATION HASH PERCENTAGE XOR AND MULTIPLY OPENROUNDBRACKET CLOSEROUNDBRACKET MINUS DECREMENT EQUAL EQUALEQUAL PLUS INCREMENT OPENCURLYBRACKET CLOSECURLYBRACKET OPENSQUAREBRACKET CLOSESQUAREBRACKET OR COLON SEMICOLON COMMA LESSTHAN LEFTSHIFT DOT GREATERTHAN RIGHTSHIFT QUESTIONMARK DIVIDE LESSTHANEQUAL GREATERTHANEQUAL NOTEQUAL POINTER MULTIPLYASSIGN ELLIPSIS DIVIDEASSIGN MODASSIGN ADDASSIGN LEFTSHIFTASSIGN RIGHTSHIFTASSIGN SUBTRACTASSIGN ANDASSIGN XORASSIGN ORASSIGN

// Keywords
%token SIZEOF EXTERN STATIC AUTO REGISTER VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED BOOL COMPLEX IMAGINARY ENUM CONST RESTRICT VOLATILE INLINE CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

// Extras 
%token INT_CONSTANT FLOAT_CONSTANT ENU_CONSTANT CHAR_CONSTANT IDENTIFIER STRING_LITERAL


%start translation_unit




%%

constant : INT_CONSTANT 
			| FLOAT_CONSTANT 
			| ENU_CONSTANT 
			| CHAR_CONSTANT ;

primary_expression : IDENTIFIER 
			| constant 
			| STRING_LITERAL 
			| OPENROUNDBRACKET expression CLOSEROUNDBRACKET 
			{printf("EXPRESSIONS -> PRIMARY_EXPRESSION\n");};

postfix_expression : primary_expression 
			| postfix_expression OPENSQUAREBRACKET expression CLOSESQUAREBRACKET 
			| postfix_expression OPENROUNDBRACKET CLOSEROUNDBRACKET 
			| postfix_expression OPENROUNDBRACKET argument_expression_list CLOSEROUNDBRACKET 
			| postfix_expression DOT IDENTIFIER 
			| postfix_expression POINTER IDENTIFIER 
			| postfix_expression INCREMENT 
			| postfix_expression DECREMENT 
			| OPENROUNDBRACKET type_name CLOSEROUNDBRACKET OPENCURLYBRACKET initializer_list CLOSECURLYBRACKET 
			| OPENROUNDBRACKET type_name CLOSEROUNDBRACKET OPENCURLYBRACKET initializer_list COMMA CLOSECURLYBRACKET 
			{printf("EXPRESSIONS -> POSTFIX_EXPRESSION\n");};

argument_expression_list : assignment_expression 
			| argument_expression_list COMMA assignment_expression 
			{printf("EXPRESSIONS -> ARGUMENT EXPRESSION LIST\n");};

unary_expression : postfix_expression 
			| INCREMENT unary_expression 
			| DECREMENT unary_expression
			| unary_operator cast_expression 
			| SIZEOF unary_expression 
			| SIZEOF OPENROUNDBRACKET type_name CLOSEROUNDBRACKET
			{printf("EXPRESSIONS -> UNARY EXPRESSION\n");};

unary_operator: AND 
			| MULTIPLY 
			| PLUS 
			| MINUS 
			| NOT 
			| EXCLAMATION 
			{printf("EXPRESSIONS -> UNARY OPERATOR\n");};

cast_expression : unary_expression 
			| OPENROUNDBRACKET type_name CLOSEROUNDBRACKET cast_expression 
			{printf("EXPRESSIONS -> CAST EXPRESSION\n");};

multiplicative_expression : cast_expression 
			| multiplicative_expression MULTIPLY cast_expression
			| multiplicative_expression DIVIDE cast_expression 
			| multiplicative_expression PERCENTAGE cast_expression
			{printf("EXPRESSIONS -> MULTIPLICATIVE EXPRESSION\n");};

additive_expression : multiplicative_expression 
			| additive_expression PLUS multiplicative_expression 
			| additive_expression MINUS multiplicative_expression 
			{printf("EXPRESSIONS -> ADDITIVE EXPRESSION\n");};

shift_expression : additive_expression 
			| shift_expression LEFTSHIFT additive_expression 
			| shift_expression RIGHTSHIFT additive_expression 
			{printf("EXPRESSIONS -> SHIFT EXPRESSION\n");};

relational_expression : shift_expression 
			| relational_expression LESSTHAN shift_expression 
			| relational_expression GREATERTHAN shift_expression 
			| relational_expression LESSTHANEQUAL shift_expression 
			| relational_expression GREATERTHANEQUAL shift_expression 
			{printf("EXPRESSIONS -> RELATIONAL EXPRESSION\n");};

equality_expression : relational_expression 
			| equality_expression EQUALEQUAL relational_expression 
			| equality_expression NOTEQUAL relational_expression 
			{printf("EXPRESSIONS -> EQUALITY EXPRESSION\n");};

AND_expression : equality_expression 
			| AND_expression AND equality_expression 
			{printf("EXPRESSIONS -> AND_expression\n");};

exclusive_OR_expression : AND_expression 
			| exclusive_OR_expression XOR AND_expression 
			{printf("EXPRESSIONS -> EXCLUSIVE OR EXPRESSION \n");}; 

inclusive_OR_expression : exclusive_OR_expression 
			| inclusive_OR_expression '|' exclusive_OR_expression 
			{printf("EXPRESSIONS -> INCLUSIVE OR EXPRESSION\n");};

logical_and_expression : inclusive_OR_expression 
			| logical_and_expression AND inclusive_OR_expression 
			{printf("EXPRESSIONS -> LOGICAL AND EXPRESSION\n");};

logical_or_expression : logical_and_expression 
			| logical_or_expression OR logical_and_expression 
			{printf("EXPRESSIONS -> LOGICAL OR EXPRESSION \n");};

conditional_expression : logical_or_expression 
			| logical_or_expression QUESTIONMARK expression COLON conditional_expression 
			{printf("EXPRESSIONS -> CONDITIONAL EXPRESSION\n");};

assignment_expression : conditional_expression 
			| unary_expression assignment_operator assignment_expression 
			{printf("EXPRESSIONS -> ASSIGNMENT EXPRESSION\n");};

assignment_operator : EQUAL 
			| MULTIPLYASSIGN 
			| DIVIDEASSIGN 
			| MODASSIGN 
			| ADDASSIGN 
			| SUBTRACTASSIGN 
			| LEFTSHIFTASSIGN 
			| RIGHTSHIFTASSIGN 
			| ANDASSIGN 
			| XORASSIGN 
			| ORASSIGN 
			{printf("EXPRESSIONS -> ASSIGNMENT OPERATOR\n");};

expression : assignment_expression 
			| expression COMMA assignment_expression 
			{printf("EXPRESSIONS -> EXPRESSION\n");};

constant_expression : conditional_expression 
			{printf("EXPRESSIONS -> CONSTANT EXPRESSION\n");};

declaration : declaration_specifiers SEMICOLON 
			| declaration_specifiers init_declarator_list SEMICOLON 
			{printf("DECLARATIONS -> DECLARATION\n");};

declaration_specifiers : storage_class_specifier 
			| storage_class_specifier declaration_specifiers 
			| type_specifier 
			| type_specifier declaration_specifiers 
			| type_qualifier 
			| type_qualifier declaration_specifiers 
			| function_specifier  
			| function_specifier declaration_specifiers 
			{printf("DECLARATIONS -> DECLARATION SPECIFIERS\n");};

init_declarator_list : init_declarator 
			| init_declarator_list COMMA init_declarator 
			{printf("DECLARATIONS -> INIT DECLARATOR LIST\n");};

init_declarator : declarator 
			| declarator EQUAL initializer 
			{printf("DECLARATIONS -> INIT DECLARATOR\n");};

storage_class_specifier : EXTERN 
			| STATIC 
			| AUTO 
			| REGISTER 
			{printf("DECLARATIONS -> STORAGE CLASS SPECIFIER\n");};

type_specifier : VOID 
			| CHAR 
			| SHORT 
			| INT 
			| LONG 
			| FLOAT 
			| DOUBLE 
			| SIGNED 
			| UNSIGNED 
			| BOOL 
			| COMPLEX 
			| IMAGINARY 
			| enum_specifier 
			{printf("DECLARATIONS -> TYPE SPECIFIER\n");};

specifier_qualifier_list : type_specifier specifier_qualifier_list 
			| type_specifier 
			| type_qualifier specifier_qualifier_list 
			| type_qualifier 
			{printf("DECLARATIONS -> SPECIFIER_QUALIFIER_LIST\n");};


enum_specifier : ENUM OPENCURLYBRACKET enumerator_list CLOSECURLYBRACKET 
			| ENUM IDENTIFIER OPENCURLYBRACKET enumerator_list CLOSECURLYBRACKET 
			| ENUM OPENCURLYBRACKET enumerator_list COMMA CLOSECURLYBRACKET 
			| ENUM IDENTIFIER OPENCURLYBRACKET enumerator_list COMMA CLOSECURLYBRACKET 
			| ENUM IDENTIFIER 
			{printf("DECLARATIONS -> ENUM_SPECIFIER\n");};

enumerator_list : enumerator 
			| enumerator_list COMMA enumerator 
			{printf("DECLARATIONS -> ENUMERATOR_LIST\n");};

enumerator : IDENTIFIER 
			| IDENTIFIER EQUAL constant_expression 
			{printf("DECLARATIONS -> ENUMERATOR\n");};

type_qualifier : CONST 
			| VOLATILE 
			| RESTRICT 
			{printf("DECLARATIONS -> TYPE QUAIFIER \n");};

function_specifier : INLINE 
			{printf("DECLARATIONS -> FUNCTION SPECIFIER\n");};

declarator : pointer direct_declarator 
			| direct_declarator 
			{printf("DECLARATIONS -> DECLARATOR\n");};

direct_declarator : IDENTIFIER 
			| OPENROUNDBRACKET declarator CLOSEROUNDBRACKET 
			| direct_declarator OPENSQUAREBRACKET  type_qualifier_list_opt assignment_expression_opt CLOSESQUAREBRACKET 
			| direct_declarator OPENSQUAREBRACKET STATIC type_qualifier_list_opt assignment_expression CLOSESQUAREBRACKET 
			| direct_declarator OPENSQUAREBRACKET type_qualifier_list_opt MULTIPLY CLOSESQUAREBRACKET 
			| direct_declarator OPENROUNDBRACKET parameter_type_list CLOSEROUNDBRACKET 
			| direct_declarator OPENROUNDBRACKET identifier_list CLOSEROUNDBRACKET 
			| direct_declarator OPENROUNDBRACKET CLOSEROUNDBRACKET 
			{printf("DECLARATIONS -> DIRECT_DECLARATOR\n");};

type_qualifier_list_opt : %empty 
			| type_qualifier_list 
			{printf("DECLARATIONS -> TYPE QUALIFIER LIST OPT\n");};

assignment_expression_opt : %empty 
			| assignment_expression 
			{printf("DECLARATIONS -> ASSIGNMENT EXPRESSION OPT\n");};

pointer : MULTIPLY 
			| MULTIPLY type_qualifier_list 
			| MULTIPLY pointer 
			| MULTIPLY type_qualifier_list pointer 
			{printf("DECLARATIONS -> POINTER\n");};

type_qualifier_list : type_qualifier 
			| type_qualifier_list type_qualifier 
			{printf("DECLARATIONS -> TYPE QUALIFIER LIST\n");};

parameter_type_list : parameter_list 
			| parameter_list COMMA ELLIPSIS 
			{printf("DECLARATIONS -> PARAMETER TYPE LIST\n");};

parameter_list : parameter_declaration 
			| parameter_list COMMA parameter_declaration 
			{printf("DECLARATIONS -> PARAMETER LIST\n");};

parameter_declaration : declaration_specifiers declarator 
			| declaration_specifiers 
			{printf("DECLARATIONS -> PARAMETER DECLARATION\n");};

identifier_list: IDENTIFIER 
			| identifier_list COMMA IDENTIFIER 
			{printf("DECLARATIONS -> IDENTIFIER LIST\n");};

type_name : specifier_qualifier_list 
			{printf("DECLARATIONS -> TYPE NAME\n");};

initializer : assignment_expression 
			| OPENCURLYBRACKET initializer_list CLOSECURLYBRACKET 
			| OPENCURLYBRACKET initializer_list COMMA CLOSECURLYBRACKET
			{printf("DECLARATIONS -> INITIALIZER\n");};

initializer_list : initializer 
			| designation initializer 
			| initializer_list COMMA initializer 
			|  initializer_list COMMA designation initializer 
			{printf("DECLARATIONS -> INITIALIZER LIST\n");};

designation : designator_list EQUAL 
			{printf("DECLARATIONS -> DESIGNATION\n");};

designator_list : designator 
			| designator_list designator 
			{printf("DECLARATIONS -> DESIGNATOR LIST\n");};

designator : OPENSQUAREBRACKET constant_expression CLOSESQUAREBRACKET 
			| DOT IDENTIFIER 
			{printf("DECLARATIONS -> DESIGNATOR\n");};

statement : labeled_statement 
			| compound_statement 
			| expression_statement 
			| selection_statement 
			| iteration_statement 
			| jump_statement 
			{printf("STATEMENTS -> STATEMENT\n");} ;

labeled_statement : IDENTIFIER COLON statement 
			| CASE constant_expression COLON statement 
			| DEFAULT COLON statement 
			{printf("STATEMENTS -> LABELED STATMENT\n");};

compound_statement : OPENCURLYBRACKET CLOSECURLYBRACKET 
			| OPENCURLYBRACKET block_item_list CLOSECURLYBRACKET 
			{printf("STATEMENTS -> COMPOUND STATEMENT\n");};

block_item_list : block_item 
			| block_item_list block_item 
			{printf("STATEMENTS -> BLOCK ITEM LIST\n");};

block_item : declaration 
			| statement 
			{printf("STATEMENTS -> BLOCK ITEM\n");};

expression_statement : SEMICOLON 
			| expression SEMICOLON 
			{printf("STATEMENTS -> EXPRESSION STATEMENT\n");};

selection_statement : IF OPENROUNDBRACKET expression CLOSEROUNDBRACKET statement 
			| IF OPENROUNDBRACKET expression CLOSEROUNDBRACKET statement ELSE statement 
			| SWITCH OPENROUNDBRACKET expression CLOSEROUNDBRACKET statement 
			{printf("STATEMENTS -> SELECTION STATEMENT\n");};

iteration_statement : WHILE OPENROUNDBRACKET expression CLOSEROUNDBRACKET statement 
			| DO statement WHILE OPENROUNDBRACKET expression CLOSEROUNDBRACKET SEMICOLON 
			| FOR OPENROUNDBRACKET expression_statement expression_statement CLOSEROUNDBRACKET statement 
			| FOR OPENROUNDBRACKET expression_statement expression_statement expression CLOSEROUNDBRACKET statement 
			{printf("STATEMENTS -> ITERATION STATEMENT\n");};

jump_statement : GOTO IDENTIFIER SEMICOLON 
			| CONTINUE SEMICOLON 
			| BREAK SEMICOLON 
			| RETURN SEMICOLON 
			| RETURN expression SEMICOLON 
			{printf("STATEMENTS -> JUMP STATEMENT\n");} ;

translation_unit : external_declaration 
			| translation_unit external_declaration 
			{printf("EXTERNAL DEFINITIONS -> TRANSLATION UNIT\n");};

external_declaration : function_definition 
			| declaration 
			{printf("EXTERNAL DEFINITIONS -> EXTERNAL DECLARATION\n");};

function_definition : declaration_specifiers declarator declaration_list compound_statement 
			| declaration_specifiers declarator compound_statement 
			| declarator declaration_list compound_statement 
			| declarator compound_statement 
			{printf("EXTERNAL DEFINITIONS -> FUNCTION DEFINITION\n");};

declaration_list : declaration 
			| declaration_list declaration 
			{printf("EXTERNAL DEFINITIONS -> DECLARATION LIST\n");};

%%

void yyerror(char *s) {
	printf ("ERROR IS : %s",s);
}