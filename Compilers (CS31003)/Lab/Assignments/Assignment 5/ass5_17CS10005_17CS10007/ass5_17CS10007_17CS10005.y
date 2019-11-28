/*

Name:- Anshul Choudhary
Roll:- 17CS10005

Name:- Ayush Kumar
Roll No:- 17CS10007

Compilers Assignment 5

*/

%{
#include "ass5_17CS10007_17CS10005_translator.h"
SymTab* globalTab;    
SymTab* currentTab;
quad qArray[256];
int noTemp=0;		  
int nextinstr=0;
string dataType;
int dataSize=0;
void yyerror(char *s);
%}


%union {
	int intval;
	double real;
	char *str;
	OpcodeType op;
	SymNode *symnode;  
	SymTab* symtab;
	List* list;
	IdList* idlist;
	ParamList* paramlist;
}

%token <str> AUTO BREAK CASE CHAR CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM EXTERN FLOAT FOR GOTO IF INLINE 
INT LONG REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT SWITCH TYPEDEF UNION UNSIGNED VOID 
VOLATILE WHILE _BOOL _COMPLEX _IMAGINARY

%token <intval> INT_CONST
%token <real> FRACTION_CONST FLOAT_CONST
%token <str> CHAR_CONST STRING_LITERAL
%token <symnode> IDENTIFIER

%token <str> L_PARAN R_PARAN L_SQRB R_SQRB DOT ARROW_ASSIGN INCREMENT DECREMENT L_BRACES R_BRACES COMMA
BIT_AND ADD MINUS MUL DIVIDE REMAINDER NEGATE NOT SPACE L_SHIFT R_SHIFT LESS_THAN GREATER_THAN 
LESS_THAN_EQUAL GREATER_THAN_EQUAL IS_EQUAL NOT_EQUAL BIT_OR BIT_XOR BOOL_OR BOOL_AND QM COLON ASSIGN
ADD_ASSIGN MINUS_ASSIGN MUL_ASSIGN DIVIDE_ASSIGN REM_ASSIGN L_SHIFT_ASSIGN R_SHIFT_ASSIGN BIT_AND_ASSIGN 
BIT_OR_ASSIGN BIT_XOR_ASSIGN ELLIPSES SEMICOLON HASH



// datatypes for non terminals

%type <symnode> primary_expression postfix_expression unary_expression cast_expression additive_expression multiplicative_expression shift_expression relational_expression equality_expression AND_expression exclusive_OR_expression
inclusive_OR_expression BOOL_AND_expression BOOL_OR_expression conditional_expression assignment_expression
expression constant_expression

%type <paramlist> argument_expression_list      
%type <op> unary_operator assignment_operator


%type <str> declaration_specifiers type_specifier specifier_qualifier_list type_name  // store "int" and "double" in symTab 


// List of identifiers in SymTab

%type <idlist> declaration init_declarator_list init_declarator declarator direct_declarator parameter_type_list
parameter_list parameter_declaration identifier_list initializer initializer_list designation designator_list 
 designator

%type <symnode> storage_class_specifier enum_specifier enumerator_list enumerator type_qualifier function_specifier
type_qualifier_list

%type <list> pointer	// linked list pointer level






// List of index of quads

%type <list> statement labeled_statement compound_statement block_item_list block_item expression_statement
selection_statement iteration_statement jump_statement

%type <symnode> expression_opt1 expression_opt2	



%type <idlist> external_declaration function_definition declaration_list


// control statements 
%type <intval> M    // rule for obtaining nextinstr
%type <list> N 		// list of indices of quads


%type <symtab> X Y  // function declaration and execution


%start translation_unit


%%

primary_expression : IDENTIFIER {$$=lookup(currentTab,$1->name);}
| INT_CONST 
{ 	
	$$=gentemp(currentTab);
  	$$->value.flag=1;
  	$$->value.ival=$1;
  	update(currentTab,$$,"int");
  	char temp[20];
  	sprintf(temp,"%d",$$->value.ival);
  	emit($$->name,COPY,temp);
}

| FLOAT_CONST
{ 
	$$=gentemp(currentTab);
  	$$->value.flag=2;
  	$$->value.dval=$1;
  	update(currentTab,$$,"double");
  	char temp[12];
  	sprintf(temp,"%lf",$$->value.dval);
  	emit($$->name,COPY,temp);
}

| FRACTION_CONST
{ 
	$$=gentemp(currentTab);
  	$$->value.flag=2;
  	$$->value.dval=$1;
  	update(currentTab,$$,"double");
  	char temp[12];
  	sprintf(temp,"%lf",$$->value.dval);
  	emit($$->name,COPY,temp);
}

| CHAR_CONST
{ 
	$$=gentemp(currentTab);
  	$$->value.flag=3;
  	$$->value.str=string($1);
  	update(currentTab,$$,"char");
  	emit($$->name,COPY,$$->value.str);
}

| STRING_LITERAL
{ 
	$$=gentemp(currentTab);
  	$$->value.flag=3;
  	$$->value.str=$1;
  	update(currentTab,$$,"char");
  	emit($$->name,COPY,$$->value.str);
}

| L_PARAN expression R_PARAN { $$=$2;}
;


postfix_expression : primary_expression {$$=$1;}

| postfix_expression L_SQRB expression R_SQRB
{
	SymNode* temp=gentemp(currentTab);
	update(currentTab,temp,"int");
	char arg2[20];
	sprintf(arg2,"%d",$1->size / $1->arglist->index);
	sprintf(arg2,"%d",$1->size / $1->arglist->index);
	emit(temp->name,MULT,$3->name,arg2);
	$$=gentemp(currentTab);
	emit($$->name,ARRAY,$1->name,temp->name);
	$$->value=$1->value;
	$$->size=$1->size / $1->arglist->index;
	$$->type=$1->type;
	$$->arglist=$1->arglist->next;
}

| postfix_expression L_PARAN R_PARAN
{
	$$=gentemp(currentTab); 
	emit($$->name,FUNC,$1->name,"0");
}

| postfix_expression L_PARAN argument_expression_list R_PARAN
{
	ParamList* temp=$3;
	int length=0;
	while(temp!=NULL){
		emit(temp->name,PARAM);
		temp=temp->next;
		length++;
	}
	char strg[20];
	sprintf(strg,"%d",length);
	if($1->type=="void")
		emit("",FUNC,$1->name,strg);
	else{
		$$=gentemp(currentTab);
		emit($$->name,FUNC,$1->name,strg);  
	}	
}

| postfix_expression DOT IDENTIFIER {} | postfix_expression ARROW_ASSIGN IDENTIFIER {}

| postfix_expression INCREMENT 
{
	$$=gentemp(currentTab);
    emit($$->name,COPY,$1->name);
    $$->value.ival=$1->value.ival;
    $$->value.flag=1;
    update(currentTab,$$,$1->type);
    emit($1->name,PLUS,$1->name,"1");
}

| postfix_expression DECREMENT
{
	$$=gentemp(currentTab);
    emit($$->name,COPY,$1->name);
    $$->value.ival=$1->value.ival;
    $$->value.flag=1;
    update(currentTab,$$,$1->type);
    emit($1->name,SUB,$1->name,"1");
}

| L_PARAN type_name R_PARAN L_BRACES initializer_list R_BRACES {} 
| L_PARAN type_name R_PARAN L_BRACES initializer_list COMMA R_BRACES {}
;


argument_expression_list : 
assignment_expression 
{
	$$=makelist($1->name,$1->type);
}

| argument_expression_list COMMA assignment_expression
{
	$$=merge($1,makelist($3->name,$3->type));
}
;

unary_expression : 
postfix_expression {$$=$1;} 

| INCREMENT unary_expression
{
	emit($2->name,PLUS,$2->name,"1");
    $$=$2;
}

| DECREMENT unary_expression
{
	emit($2->name,SUB,$2->name,"1");
    $$=$2;
}

| unary_operator cast_expression
{
	switch($1){
		case(PLUS):
			$$=gentemp(currentTab);
			emit($$->name,$1,$2->name);
			update(currentTab,$$,$2->type);
			$$->value.flag=$2->value.flag;
			//$$->value=$2->value;
			break;
		
		case(SUB):
			$$=gentemp(currentTab);
			emit($$->name,$1,$2->name);
			update(currentTab,$$,$2->type);
			$$->value.flag=$2->value.flag;
			break;
		
		case(MULT):
			$$=gentemp(currentTab);
			emit($$->name,$1,$2->name);
			$$->arglist=$2->arglist->next;
			if($2->type=="int"){
				update(currentTab,$$,"int");
				$$->value.flag=1;
			}
			else if($2->type=="double"){
				update(currentTab,$$,"double");
				$$->value.flag=2;
			}
			else if($2->type=="char"){
				update(currentTab,$$,"char");
				$$->value.flag=3;
			}
			break;

		case(NEG):
			if($2->value.flag==1){
				$$=gentemp(currentTab);
				update(currentTab,$$,$2->type);
				$$->value.flag=$2->value.flag;
				emit($$->name,$1,$2->name);
			}
			else
				cout<<"Invalid operand type"<<endl;
			break;
		
		case(BITAND):
			$$=gentemp(currentTab);
			emit($$->name,$1,$2->name);
			$$->arglist=makelist(0);
			$$->arglist->next=$2->arglist;
			$$->value.flag=5;
			if($2->type=="int"){
				update(currentTab,$$,"int");
			}
			else if($2->type=="double"){
				update(currentTab,$$,"double");
			}
			else if($2->type=="char"){
				update(currentTab,$$,"char");
			}
			break;
		
		case(NT):
			if($2->value.flag==1){
				$$=gentemp(currentTab);
				emit($$->name,$1,$2->name);
				update(currentTab,$$,$2->type);
				$$->value.flag=$2->value.flag;
			}
			else
				cout<<"Invalid operand type"<<endl;
			break;
	}
} 

| SIZEOF unary_expression {} | SIZEOF L_PARAN type_name R_PARAN {}
;


unary_operator : ADD {$$=PLUS;}
| MINUS {$$=SUB;}
| MUL {$$=MULT;}
| NEGATE {$$=NEG;}
| BIT_AND {$$=BITAND;}
| NOT {$$=NT;}
;


cast_expression : unary_expression {$$=$1;}

| L_PARAN type_name R_PARAN cast_expression 
{
	$$=gentemp(currentTab); 
	$$=$4; $$->type=$2; 
	typecheck($$,$4);
}
;


multiplicative_expression : cast_expression {$$=$1;}

| multiplicative_expression MUL cast_expression
{
	$$=gentemp(currentTab);
	if($1->type==$3->type){
		if($1->type=="int"){
    		$$->value.flag=1;
    		update(currentTab,$$,"int");
    	}
    	else if($1->type=="double"){
    		$$->value.flag=2;
    		update(currentTab,$$,"double");
    	}
    }
    else if($1->type=="int" && $3->type=="double"){
    	$$->value.flag=2;
    	update(currentTab,$$,"double");
    }
    else{
    	$$->value.flag=2;
    	update(currentTab,$$,"double");
    }
    emit($$->name,MULT,$1->name,$3->name);
}

| multiplicative_expression DIVIDE cast_expression
{
	$$=gentemp(currentTab);
	if($1->type==$3->type){
		if($1->type=="int"){
    		$$->value.flag=1;
    		update(currentTab,$$,"int");
    	}
    	else if($1->type=="double"){
    		$$->value.flag=2;
    		update(currentTab,$$,"double");
    	}
    }
    else if($1->type=="int" && $3->type=="double"){
    	$$->value.flag=2;
    	update(currentTab,$$,"double");
    }
    else{
    	$$->value.flag=2;
    	update(currentTab,$$,"double");
    }
	emit($$->name,DIV,$1->name,$3->name);
}

| multiplicative_expression REMAINDER cast_expression
{
    if($1->type=="int"){
    	$$=gentemp(currentTab);
    	$$->value.flag=1;
    	update(currentTab,$$,$1->type);
    	emit($$->name,REM,$1->name,$3->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
;


additive_expression : multiplicative_expression {$$=$1;}

| additive_expression ADD multiplicative_expression
{
	$$=gentemp(currentTab);
	if($1->type==$3->type){
		if($1->type=="int"){
    		$$->value.flag=1;
    		update(currentTab,$$,"int");
    	}
    	else if($1->type=="double"){
    		$$->value.flag=2;
    		update(currentTab,$$,"double");
    	}
    }
    else if($1->type=="int" && $3->type=="double"){
    	$$->value.flag=2;
    	update(currentTab,$$,"double");
    }
    else{
    	$$->value.flag=2;
    	update(currentTab,$$,"double");
    }
	emit($$->name,PLUS,$1->name,$3->name);
}

| additive_expression MINUS multiplicative_expression
{
	$$=gentemp(currentTab);
	if($1->type==$3->type){
		if($1->type=="int"){
    		$$->value.flag=1;
    		update(currentTab,$$,"int");
    	}
    	else if($1->type=="double"){
    		$$->value.flag=2;
    		update(currentTab,$$,"double");
    	}
    }
    else if($1->type=="int" && $3->type=="double"){
    	$$->value.flag=2;
    	update(currentTab,$$,"double");
    }
    else{
    	$$->value.flag=2;
    	update(currentTab,$$,"double");
    }
	emit($$->name,SUB,$1->name,$3->name);
}


shift_expression : additive_expression {$$=$1;}

| shift_expression L_SHIFT additive_expression
{
    if($1->type=="int"){
    	$$=gentemp(currentTab);
    	$$->value.flag=1;
    	update(currentTab,$$,$1->type);
    	emit($$->name,LEFTSHIFT,$1->name,$3->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}

| shift_expression R_SHIFT additive_expression
{
    if($1->type=="int"){
    	$$=gentemp(currentTab);
    	$$->value.flag=1;
    	update(currentTab,$$,$1->type);
    	emit($$->name,RIGHTSHIFT,$1->name,$3->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
;


relational_expression : shift_expression {$$=$1;}

| relational_expression LESS_THAN shift_expression
{
	$$=new SymNode;
	$$->type="bool";
	$$->truelist=makelist(nextinstr);
	$$->falselist=makelist(nextinstr+1);
	emit("",LESSTHAN,$1->name,$3->name);
	emit("",_GOTO);
}

| relational_expression GREATER_THAN shift_expression
{
	$$=new SymNode;
	$$->type="bool";
	$$->truelist=makelist(nextinstr);
	$$->falselist=makelist(nextinstr+1);
	emit("",GREATERTHAN,$1->name,$3->name);
	emit("",_GOTO);
}

| relational_expression LESS_THAN_EQUAL shift_expression
{
	$$=new SymNode;
	$$->type="bool";
	$$->truelist=makelist(nextinstr);
	$$->falselist=makelist(nextinstr+1);
	emit("",LESSTHANEQUAL,$1->name,$3->name);
	emit("",_GOTO);
}

| relational_expression GREATER_THAN_EQUAL shift_expression
{
	$$=new SymNode;
	$$->type="bool";
	$$->truelist=makelist(nextinstr);
	$$->falselist=makelist(nextinstr+1);
	emit("",GREATERTHANEQUAL,$1->name,$3->name);
	emit("",_GOTO);
}
;


equality_expression : relational_expression {$$=$1;}

| equality_expression IS_EQUAL relational_expression
{
	$$=new SymNode;
	$$->type="bool";
	$$->truelist=makelist(nextinstr);
	$$->falselist=makelist(nextinstr+1);
	emit("",ISEQUAL,$1->name,$3->name);
	emit("",_GOTO);
}

| equality_expression NOT_EQUAL relational_expression
{
	$$=new SymNode;
	$$->type="bool";
	$$->truelist=makelist(nextinstr);
	$$->falselist=makelist(nextinstr+1);
	emit("",NOTEQUAL,$1->name,$3->name);
	emit("",_GOTO);
}
;


AND_expression : equality_expression {$$=$1;}

| AND_expression BIT_AND equality_expression
{
    if($1->type=="int"){
    	$$=gentemp(currentTab);
    	$$->value.ival=$1->value.ival & $3->value.ival;
    	$$->value.flag=1;
    	update(currentTab,$$,$1->type);
    	emit($$->name,BITAND,$1->name,$3->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
;


exclusive_OR_expression : AND_expression {$$=$1;}

| exclusive_OR_expression BIT_XOR AND_expression
{
    if($1->type=="int"){
    	$$=gentemp(currentTab);
    	$$->value.ival=$1->value.ival ^ $3->value.ival;
    	$$->value.flag=1;
    	update(currentTab,$$,$1->type);
    	emit($$->name,XOR,$1->name,$3->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
;


inclusive_OR_expression : exclusive_OR_expression {$$=$1;}

| inclusive_OR_expression BIT_OR exclusive_OR_expression
{
    if($1->type=="int"){
    	$$=gentemp(currentTab);
    	$$->value.ival=$1->value.ival | $3->value.ival;
    	$$->value.flag=1;
    	update(currentTab,$$,$1->type);
    	emit($$->name,BITOR,$1->name,$3->name);
    }
    else
    	cout<<"Invalid operand"<<endl;
}
;


BOOL_AND_expression : inclusive_OR_expression {$$=$1;}

| BOOL_AND_expression BOOL_AND M inclusive_OR_expression
{
	$$=new SymNode;
	$$->type="bool";
	backpatch($1->truelist,$3);
	$$->truelist=$4->truelist;
	$$->falselist=merge($1->falselist,$4->falselist);
}
;


BOOL_OR_expression : BOOL_AND_expression {$$=$1;}

| BOOL_OR_expression BOOL_OR M BOOL_AND_expression
{
	$$=new SymNode;
	$$->type="bool";
	backpatch($1->falselist,$3);
	$$->truelist=merge($1->truelist,$4->truelist);
	$$->falselist=$4->falselist;
}
;


conditional_expression : BOOL_OR_expression {$$=$1;}

| BOOL_OR_expression QM M expression N COLON M conditional_expression
{
	$$=gentemp(currentTab);
	update(currentTab,$$,$4->type);
	emit($$->name,COPY,$8->name);  
	List* I=makelist(nextinstr);
	emit("",_GOTO);
	backpatch($5,nextinstr);
	emit($$->name,COPY,$4->name);
	I=merge(I,makelist(nextinstr));
	convInt2Bool($1);                
	backpatch($1->truelist,$3);
	backpatch($1->falselist,$7);
	backpatch(I,nextinstr);
}
;


assignment_expression : conditional_expression {$$=$1;}

| unary_expression assignment_operator assignment_expression
{  
	typecheck($1,$3);
	emit($1->name,COPY,$3->name);
}
;


assignment_operator : ASSIGN {$$=ASSIGNMENT;}
| ADD_ASSIGN {} 
| MINUS_ASSIGN {}
| MUL_ASSIGN  {}
| DIVIDE_ASSIGN  {}
| REM_ASSIGN {} 
| L_SHIFT_ASSIGN {}
| R_SHIFT_ASSIGN {}
| BIT_OR_ASSIGN {}
| BIT_AND_ASSIGN {}
| BIT_XOR_ASSIGN {}
;


expression : 
assignment_expression {$$=$1;} | expression COMMA assignment_expression {}
;


constant_expression : conditional_expression {$$=$1;};

storage_class_specifier : EXTERN {} | STATIC {} | AUTO {} | REGISTER {}
;

type_specifier : 
VOID
{ 
	dataType="void"; 
	dataSize=0;
}

| CHAR
{
	dataType="char"; 
	dataSize=1;
}

| SHORT {}
| INT 
{ 
	dataType="int"; 
	dataSize=4;
}
| LONG {}

| FLOAT 
{ 
	dataType="double"; 
	dataSize=8;
}

| DOUBLE 
{ 
	dataType="double"; 
	dataSize=8;
}
| SIGNED {}
| UNSIGNED {}
| _BOOL {}
| _COMPLEX {}
| _IMAGINARY {}
| enum_specifier {}
;

function_specifier : INLINE {}
;

init_declarator_list : init_declarator {$$=$1;}
| init_declarator_list COMMA init_declarator{$$=merge($1,$3);}
;

init_declarator : declarator {$$=$1;}
| declarator ASSIGN initializer
{
	IdList* idtemp=$1;
	while(idtemp->next != NULL)
		idtemp=idtemp->next; 					
	idtemp->id->value=$3->id->value;
	emit(idtemp->id->name,COPY,$3->id->name);
	$$=$1;
}
;

declaration_specifiers : storage_class_specifier {} 
| storage_class_specifier declaration_specifiers {}
| type_specifier {}
| type_specifier declaration_specifiers {}
| type_qualifier {}
| type_qualifier declaration_specifiers {}
| function_specifier {}
| function_specifier declaration_specifiers {}
;

declaration : declaration_specifiers {} | declaration_specifiers init_declarator_list {$$=$2;} 
;

type_qualifier : CONST {} | RESTRICT {} | VOLATILE {}
;

specifier_qualifier_list : type_specifier { $$=$1; }
| type_specifier specifier_qualifier_list {}
| type_qualifier   {}
| type_qualifier specifier_qualifier_list {}
;

enumerator : IDENTIFIER {} | IDENTIFIER ASSIGN constant_expression {}
;

enumerator_list : enumerator {} | enumerator_list COMMA enumerator {}
;

enum_specifier : ENUM IDENTIFIER L_BRACES enumerator_list R_BRACES {}
| ENUM L_BRACES enumerator_list R_BRACES {}
| ENUM IDENTIFIER L_BRACES enumerator_list COMMA R_BRACES {}
| ENUM L_BRACES enumerator_list COMMA R_BRACES {}
| ENUM IDENTIFIER {}
;

pointer : 
MUL 
{ 
	dataSize=4;
	$$=new List;
	$$->index=0;
} 
| MUL type_qualifier_list {}
| MUL type_qualifier_list pointer {}

| MUL pointer 
{
	$2->next=new List;
	$2->next->index=0;
	$$=$2;
}
;

direct_declarator :	
IDENTIFIER
{
	$1=lookup(currentTab,$1->name);
	$1->type=dataType;
	$1->size=dataSize;
	$$=makelist($1);
}
| L_PARAN declarator R_PARAN {$$=$2;}
| direct_declarator L_SQRB type_qualifier_list assignment_expression R_SQRB {}
| direct_declarator L_SQRB R_SQRB {}
| direct_declarator L_SQRB type_qualifier_list R_SQRB {}

| direct_declarator L_SQRB assignment_expression R_SQRB 
{
	List* node=new List;
	$1->id->size = $1->id->size * $3->value.ival;
	node->index=$3->value.ival;
	if($1->id->arglist==NULL)
		$1->id->arglist=node;
	else{
		List* temp=$1->id->arglist;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=node;
	}
	$$=$1;
}
| direct_declarator L_SQRB STATIC type_qualifier_list assignment_expression R_SQRB {}
| direct_declarator L_SQRB STATIC assignment_expression R_SQRB {}
| direct_declarator L_SQRB type_qualifier_list STATIC assignment_expression R_SQRB {}
| direct_declarator L_SQRB type_qualifier_list MUL R_SQRB {}
| direct_declarator L_SQRB MUL R_SQRB {}

| direct_declarator L_PARAN X parameter_type_list R_PARAN
{
	SymNode* ST=lookup(globalTab,$1->id->name);
	ST->next=$3;
	$1->id->size=0;
	$$=$1;
}

| direct_declarator L_PARAN X identifier_list R_PARAN
{
	SymNode* ST=lookup(globalTab,$1->id->name);
	ST->next=$3;
	$1->id->size=0;
	$$=$1;
}

| direct_declarator L_PARAN X R_PARAN
{
	SymNode* ST=lookup(globalTab,$1->id->name);
	ST->next=$3;
	$1->id->size=0;
	$$=$1;
}
;

declarator : direct_declarator {$$=$1;}

| pointer direct_declarator
{
	if($1!=NULL){
		$2->id->size=dataSize;
		List* temp=$2->id->arglist;
		$2->id->arglist=$1;
		List* t=$2->id->arglist;
		while(t->next!=NULL)
			t=t->next;
		t->next=temp;
	}
	$$=$2;
}
;

type_qualifier_list : type_qualifier {} | type_qualifier_list type_qualifier {}
;

parameter_type_list : parameter_list {$$=$1;} | parameter_list COMMA ELLIPSES {}
;

parameter_declaration : declaration_specifiers {}
| declaration_specifiers declarator {$$=$2;} 
;

parameter_list : parameter_declaration {$$=$1;}

| parameter_list COMMA parameter_declaration
{
	merge($1,$3);
	$$=$1;
} 
;

identifier_list : 
IDENTIFIER
{
	$1=lookup(currentTab,$1->name);
	$1->type=dataType;
	$1->size=dataSize;
	$$=makelist($1);
}

| identifier_list COMMA IDENTIFIER
{
	$3=lookup(currentTab,$3->name);
	$3->type=dataType;
	$3->size=dataSize;
	merge($1,makelist($3));
	$$=$1;
}
;


type_name : specifier_qualifier_list { $$=$1; }
;

initializer : 
assignment_expression {$$=makelist($1);}
| L_BRACES initializer_list R_BRACES {}
| L_BRACES initializer_list COMMA R_BRACES {}
;


initializer_list : designation initializer {}
| initializer {}
| initializer_list COMMA designation initializer {}
| initializer_list COMMA initializer {}
;

designation : designator_list ASSIGN {}
; 


designator_list : designator {} | designator_list designator {}
;


designator : L_SQRB constant_expression R_SQRB {} | DOT IDENTIFIER {}
;

labeled_statement : IDENTIFIER COLON statement {}
| CASE constant_expression COLON statement {}
| DEFAULT COLON statement {}
;


compound_statement : L_BRACES block_item_list R_BRACES {$$=$2;}
| L_BRACES R_BRACES {$$=NULL;}
;


block_item_list : block_item { $$=$1;}
| block_item_list M block_item { $$=$3;}
;


block_item : M declaration {$$=makelist($1);}
| statement {$$=$1;}
;


expression_statement : expression SEMICOLON {$$=NULL;}
| SEMICOLON {$$=NULL;}
;

M : {$$=nextinstr;};

N : 
{
	$$=makelist(nextinstr);
	emit("",_GOTO);
}
;

expression_opt1: 			{$$=new SymNode;} 
			  |expression   {$$=$1;}
			  ;

expression_opt2: 			

{
	$$=new SymNode;
	$$->truelist=makelist(nextinstr);
	emit("",_GOTO);
} 
| expression   
{
	if($1->type!="bool")
		convInt2Bool($1);
	$$=$1;
}
;

selection_statement : 
IF L_PARAN expression_opt2 R_PARAN M statement N ELSE M statement
{
	backpatch($3->truelist,$5);
	backpatch($3->falselist,$9);
	$$=merge(merge($6,$7),$10);
	backpatch($7,nextinstr);  
}

|IF L_PARAN expression_opt2 R_PARAN M statement
{
	backpatch($3->truelist,$5);
	$$=merge($3->falselist,$6);
	backpatch($3->falselist,nextinstr);     
}

| SWITCH L_PARAN expression R_PARAN statement {}
;


iteration_statement :
WHILE M L_PARAN expression_opt2 R_PARAN M statement
{
	backpatch($7,$2);
	backpatch($4->truelist,$6);
	$$=$4->falselist;
	char str[20];
	sprintf(str,"%d",$2);
	emit(str,_GOTO);
	backpatch($4->falselist,nextinstr); 
}

| DO M statement M WHILE L_PARAN expression_opt2 R_PARAN SEMICOLON
{
	backpatch($7->truelist,$2);
	backpatch($7->falselist,nextinstr);
	$$=$7->falselist;
}

| FOR L_PARAN expression_opt1 SEMICOLON M expression_opt2 SEMICOLON M expression_opt1 N R_PARAN M statement
{
	backpatch($6->truelist,$12);
	backpatch($10,$5);
	backpatch($13,$8);
	char str[20];
	sprintf(str,"%d",$8);
	emit(str,_GOTO);
	$$=$6->falselist;
	backpatch($6->falselist,nextinstr); 
}
| FOR L_PARAN declaration expression SEMICOLON expression R_PARAN statement {}
| FOR L_PARAN declaration expression SEMICOLON R_PARAN statement {}
| FOR L_PARAN declaration SEMICOLON expression R_PARAN statement {}
| FOR L_PARAN declaration SEMICOLON R_PARAN statement {}
;


jump_statement : 
GOTO IDENTIFIER SEMICOLON {}
| CONTINUE SEMICOLON {}
| BREAK SEMICOLON {}
| RETURN expression SEMICOLON {emit($2->name,_RETURN);}
| RETURN SEMICOLON {emit("",_RETURN);}
;

statement : labeled_statement {}
| compound_statement {$$=$1;}
| expression_statement {$$=$1;}
| selection_statement {$$=$1;}
| iteration_statement {$$=$1;}
| jump_statement {$$=$1;}
;

external_declaration : function_definition {$$=$1;} | declaration SEMICOLON Y {}
;

translation_unit : external_declaration {} | translation_unit external_declaration {}
;

declaration_list : declaration {$$=$1;}
| declaration_list declaration 
{
	merge($1,$2); 
	$$=$1;
}
;

function_definition : declaration_specifiers declarator declaration_list compound_statement Y  {$$=$2;}
| declaration_specifiers declarator compound_statement Y {$$=$2;}
;

X :	
{
	$$=newTable();
	currentTab=$$;
	dataSize=0;
}
;

Y : {currentTab=globalTab;};


%%

void yyerror(char *s) {
printf("%s",s);
}
