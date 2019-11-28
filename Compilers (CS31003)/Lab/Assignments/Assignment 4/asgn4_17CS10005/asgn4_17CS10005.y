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






%union {
	int intval;
}

// Punctuators and operators
%token AND DECREMENT EQUALEQUAL INCREMENT OR LEFTSHIFT RIGHTSHIFT LESSTHANEQUAL GREATERTHANEQUAL
%token NOTEQUAL POINTER MULTIPLYASSIGN ELLIPSIS DIVIDEASSIGN MODASSIGN ADDASSIGN LEFTSHIFTASSIGN
%token RIGHTSHIFTASSIGN SUBTRACTASSIGN ANDASSIGN XORASSIGN ORASSIGN

// Keywords
%token SIZEOF EXTERN STATIC AUTO REGISTER VOID CHAR SHORT INT LONG FLOAT DOUBLE SIGNED UNSIGNED BOOL COMPLEX IMAGINARY
%token ENUM CONST RESTRICT VOLATILE INLINE CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

// Extras 
%token INT_CONSTANT FLOAT_CONSTANT ENU_CONSTANT CHAR_CONSTANT IDENTIFIER STRING_LITERAL
%start translation_unit







%%

constant : INT_CONSTANT | FLOAT_CONSTANT | ENU_CONSTANT | CHAR_CONSTANT ;

primary_expression : IDENTIFIER | constant | STRING_LITERAL | '(' expression ')' { printf("PRIMARY_EXPRESSION\n");};

postfix_expression : primary_expression | postfix_expression '[' expression ']' | postfix_expression '(' ')' | postfix_expression '(' argument_expression_list ')' | postfix_expression '.' IDENTIFIER | postfix_expression POINTER IDENTIFIER | postfix_expression INCREMENT | postfix_expression DECREMENT | '(' type_name ')' '{' initializer_list '}' |  '(' type_name ')' '{' initializer_list ',' '}' {printf("POSTFIX_EXPRESSION\n");};

argument_expression_list : assignment_expression | argument_expression_list ',' assignment_expression {printf("ARGUMENT EXPRESSION LIST\n");};

unary_expression : postfix_expression | INCREMENT unary_expression | DECREMENT unary_expression | unary_operator cast_expression | SIZEOF unary_expression | SIZEOF '(' type_name ')' {printf("UNARY EXPRESSION\n");};

unary_operator: '&' | '*' | '+' | '-' | '~' | '!' {printf("UNARY OPERATOR\n");};

cast_expression : unary_expression | '(' type_name ')' cast_expression {printf("CAST EXPRESSION\n");};

multiplicative_expression : cast_expression | multiplicative_expression '*' cast_expression
| multiplicative_expression '/' cast_expression | multiplicative_expression '%' cast_expression
{printf("MULTIPLICATIVE EXPRESSION\n");};

additive_expression : multiplicative_expression | additive_expression '+' multiplicative_expression | additive_expression '-' multiplicative_expression {printf("ADDITIVE EXPRESSION\n");};

shift_expression : additive_expression | shift_expression LEFTSHIFT additive_expression | shift_expression RIGHTSHIFT additive_expression {printf("SHIFT EXPRESSION\n");};

relational_expression : shift_expression | relational_expression '<' shift_expression | relational_expression '>' shift_expression | relational_expression LESSTHANEQUAL shift_expression | relational_expression GREATERTHANEQUAL shift_expression {printf("RELATIONAL EXPRESSION\n");};

equality_expression : relational_expression | equality_expression EQUALEQUAL relational_expression | equality_expression NOTEQUAL relational_expression {printf("EQUALITY EXPRESSION\n");};

AND_expression : equality_expression | AND_expression '&' equality_expression {printf("AND_expression\n");};

exclusive_OR_expression : AND_expression | exclusive_OR_expression '^' AND_expression {printf("EXCLUSIVE OR EXPRESSION \n");}; 

inclusive_OR_expression : exclusive_OR_expression | inclusive_OR_expression '|' exclusive_OR_expression {printf("INCLUSIVE OR EXPRESSION\n");};

logical_AND_expression : inclusive_OR_expression | logical_AND_expression AND inclusive_OR_expression {printf("LOGICAL '&' EXPRESSION\n");};

logical_OR_expression : logical_AND_expression | logical_OR_expression OR logical_AND_expression {printf("LOGICAL OR EXPRESSION \n");};

conditional_expression : logical_OR_expression | logical_OR_expression '?' expression ':' conditional_expression {printf("CONDITIONAL EXPRESSION\n");};

assignment_expression : conditional_expression | unary_expression assignment_operator assignment_expression {printf("ASSIGNMENT EXPRESSION\n");};

assignment_operator : '=' | MULTIPLYASSIGN | DIVIDEASSIGN | MODASSIGN | ADDASSIGN | SUBTRACTASSIGN | LEFTSHIFTASSIGN | RIGHTSHIFTASSIGN | ANDASSIGN | XORASSIGN | ORASSIGN {printf("ASSIGNMENT OPERATOR\n");};

expression : assignment_expression | expression ',' assignment_expression {printf("EXPRESSION\n");};

constant_expression : conditional_expression {printf("CONSTANT EXPRESSION\n");};

declaration : declaration_specifiers ';' | declaration_specifiers init_declarator_list ';' {printf("DECLARATION\n");};

declaration_specifiers : storage_class_specifier | storage_class_specifier declaration_specifiers | type_specifier | type_specifier declaration_specifiers | type_qualifier | type_qualifier declaration_specifiers | function_specifier  | function_specifier declaration_specifiers {printf("DECLARATION SPECIFIERS\n");};

init_declarator_list : init_declarator | init_declarator_list ',' init_declarator {printf("INIT DECLARATOR LIST\n");};

init_declarator : declarator | declarator '=' initializer {printf("INIT DECLARATOR\n");};

storage_class_specifier : EXTERN | STATIC | AUTO | REGISTER {printf("STORAGE CLASS SPECIFIER\n");};

type_specifier : VOID | CHAR | SHORT | INT | LONG | FLOAT | DOUBLE | SIGNED | UNSIGNED | BOOL | COMPLEX | IMAGINARY | enum_specifier {printf("TYPE SPECIFIER\n");};

specifier_qualifier_list : type_specifier specifier_qualifier_list | type_specifier | type_qualifier specifier_qualifier_list | type_qualifier {printf("SPECIFIER_QUALIFIER_LIST\n");};


enum_specifier : ENUM '{' enumerator_list '}' | ENUM IDENTIFIER '{' enumerator_list '}' | ENUM '{' enumerator_list ',' '}' | ENUM IDENTIFIER '{' enumerator_list ',' '}' | ENUM IDENTIFIER {printf("ENUM_SPECIFIER\n");};

enumerator_list : enumerator | enumerator_list ',' enumerator {printf("ENUMERATOR_LIST\n");};

enumerator : IDENTIFIER | IDENTIFIER '=' constant_expression {printf("ENUMERATOR\n");};

type_qualifier : CONST | VOLATILE | RESTRICT {printf("TYPE QUAIFIER \n");};

function_specifier : INLINE {printf("FUNCTION SPECIFIER\n");};

declarator : pointer direct_declarator | direct_declarator {printf("DECLARATOR\n");};

direct_declarator : IDENTIFIER | '(' declarator ')' | direct_declarator '['  type_qualifier_list_opt assignment_expression_opt ']' | direct_declarator '[' STATIC type_qualifier_list_opt assignment_expression ']' | direct_declarator '[' type_qualifier_list_opt '*' ']' | direct_declarator '(' parameter_type_list ')' | direct_declarator '(' identifier_list ')' | direct_declarator '(' ')' {printf("DIRECT_DECLARATOR\n");};

type_qualifier_list_opt : %empty | type_qualifier_list {printf("TYPE QUALIFIER LIST OPT\n");};

assignment_expression_opt : %empty | assignment_expression {printf("ASSIGNMENT EXPRESSION OPT\n");};

pointer : '*' | '*' type_qualifier_list | '*' pointer | '*' type_qualifier_list pointer {printf("POINTER\n");};

type_qualifier_list : type_qualifier | type_qualifier_list type_qualifier {printf("TYPE QUALIFIER LIST\n");};

parameter_type_list : parameter_list | parameter_list ',' ELLIPSIS {printf("PARAMETER TYPE LIST\n");};

parameter_list : parameter_declaration | parameter_list ',' parameter_declaration {printf("PARAMETER LIST\n");};

parameter_declaration : declaration_specifiers declarator | declaration_specifiers {printf("PARAMETER DECLARATION\n");};

identifier_list: IDENTIFIER | identifier_list ',' IDENTIFIER {printf("IDENTIFIER LIST\n");};

type_name : specifier_qualifier_list {printf("TYPE NAME\n");};

initializer : assignment_expression | '{' initializer_list '}' | '{' initializer_list ',' '}'{printf("INITIALIZER\n");};

initializer_list : initializer | designation initializer | initializer_list ',' initializer |  initializer_list ',' designation initializer {printf("INITIALIZER LIST\n");};

designation : designator_list '=' {printf("DESIGNATION\n");};

designator_list : designator | designator_list designator {printf("DESIGNATOR LIST\n");};

designator : '[' constant_expression ']' | '.' IDENTIFIER {printf("DESIGNATOR\n");};

statement : labeled_statement | compound_statement | expression_statement | selection_statement | iteration_statement | jump_statement {printf("STATEMENT\n");} ;

labeled_statement : IDENTIFIER ':' statement | CASE constant_expression ':' statement | DEFAULT ':' statement {printf("LABELED STATMENT\n");};

compound_statement : '{' '}' | '{' block_item_list '}' {printf("COMPOUND STATEMENT\n");};

block_item_list : block_item | block_item_list block_item {printf("BLOCK ITEM LIST\n");};

block_item : declaration | statement {printf("BLOCK ITEM\n");};

expression_statement : ';' | expression ';' {printf("EXPRESSION STATEMENT\n");};

selection_statement : IF '(' expression ')' statement | IF '(' expression ')' statement ELSE statement | SWITCH '(' expression ')' statement {printf("SELECTION STATEMENT\n");};

iteration_statement : WHILE '(' expression ')' statement | DO statement WHILE '(' expression ')' ';' | FOR '(' expression_statement expression_statement ')' statement | FOR '(' expression_statement expression_statement expression ')' statement {printf("ITERATION STATEMENT\n");};

jump_statement : GOTO IDENTIFIER ';' | CONTINUE ';' | BREAK ';' | RETURN ';' | RETURN expression ';' {printf("JUMP STATEMENT\n");} ;

translation_unit : external_declaration | translation_unit external_declaration {printf("TRANSLATION UNIT\n");};

external_declaration : function_definition | declaration {printf("EXTERNAL DECLARATION\n");};

function_definition : declaration_specifiers declarator declaration_list compound_statement | declaration_specifiers declarator compound_statement | declarator declaration_list compound_statement | declarator compound_statement {printf("FUNCTION DEFINITION\n");};

declaration_list : declaration | declaration_list declaration {printf("DECLARATION LIST\n");};

%%

void yyerror(char *s) {
	printf ("ERROR IS : %s",s);
}