/************************************************
Name -	Anshul Choudhary (17CS10005),
		Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/

%{ /* C Declarations and Definitions */
	#include <string>
	#include <iostream>
	#include <fstream>
	using namespace std;
	extern int yylex();
	void yyerror(string s);
	extern int yyparse();


	#include "ass6_17CS10005_17CS10007_translator.h"

	Quad_Array Quad_arr;
	symbol_table GTable;
	symbol_table *symbol = &GTable;
	symbol_table *current_symbol = &GTable;
	type_inf *global_type;
	int global_width;
	vector<string> string_list;
	int literals_count;
%}


%union {
  int intval;
  float floatval;
  char charval;
  string *str;
  expression_attribute *expr_attribute;
  declaration *declaration_list;
  init_declration_list *init_dec_list;
  type_inf *type_;
  function_definition *function_def;
  function_list *func_list;
}


%token DIV_ASSIGN;
%token ELLIPSIS;
%token EQ_OP;
%token LEFT_SHIFT;
%token AND_ASSIGN;
%token AND_OP;
%token SUB_ASSIGN;
%token DECREMENT_OP;
%token RIGHT_SHIFT;
%token MUL_ASSIGN;
%token GREATER_EQ_OP;
%token LESS_EQ_OP;
%token POINTER_OP;
%token INCREMENT_OP;
%token LEFT_ASSIGN;
%token RIGHT_ASSIGN;
%token XOR_ASSIGN;
%token NOT_EQ_OP;
%token OR_OP;
%token OR_ASSIGN;
%token MOD_ASSIGN;
%token ADD_ASSIGN;


%token DOUBLE_;
%token DEFAULT_;
%token BREAK_;
%token BOOL_;
%token STRUCT_;
%token SIGNED_;
%token EXTERN_;
%token ELSE_;
%token CONTINUE_;
%token SHORT_;
%token SWITCH_;
%token TYPEDEF_;
%token AUTO_;
%token RETURN_;
%token WHILE_;
%token GOTO_;
%token UNION_;
%token INLINE_;
%token ENUM_;
%token CHAR_;
%token CONST_;
%token DO_;
%token REGISTER_;
%token RESTRICTED_;
%token CASE_;
%token IF_;
%token SIZEOF_;
%token FLOAT_;
%token LONG_;
%token IMAGINARY_;
%token STATIC_;
%token FOR_;
%token UNSIGNED_;
%token VOLATILE_;
%token COMPLEX_;
%token VOID_;
%token INT_;

%token <str> IDENTIFIER;
%token <str> STRING_LITERAL;

%type<expr_attribute> inclusive_or_exp
%type<declaration_list> direct_declarator
%type<expr_attribute> equality_exp
%type<expr_attribute> expression_statement
%type<expr_attribute> primary_exp
%type<func_list> parameter_type_list
%type<expr_attribute> unary_exp
%type<expr_attribute> constant_exp
%type<expr_attribute> block_item_list
%type<expr_attribute> selection_statement
%type<type_> type_specifier
%type<expr_attribute> multiplicative_exp
%type<func_list> parameter_type_list_opt
%type<expr_attribute> conditional_exp
%type<function_def> parameter_declaration
%type<expr_attribute> block_item
%type<expr_attribute> M
%type<type_>pointer
%type<func_list> parameter_list
%type<declaration_list> declarator
%type<expr_attribute> assignment_exp
%type<expr_attribute> logical_or_exp
%type<expr_attribute> initializer
%type<expr_attribute> and_exp
%type<expr_attribute> jump_statement
%type<expr_attribute> additive_exp
%type<init_dec_list> init_declarator_list
%type<expr_attribute> assignment_exp_opt
%type<type_> type_name
%type<type_> declaration_specifiers
%type<charval> unary_op
%type<expr_attribute> declaration
%type<type_> specifier_qualifier_list
%type<expr_attribute> exclusive_or_exp
%type<expr_attribute> cast_exp
%type<expr_attribute> logical_and_exp
%type<declaration_list> function_definition
%type<expr_attribute> postfix_exp
%type<expr_attribute> assignment_op
%type<declaration_list> initializer_list
%type<expr_attribute> N
%type<expr_attribute> expression_opt
%type<expr_attribute> relational_exp
%type<expr_attribute> iteration_statement
%type<expr_attribute> statement
%type<expr_attribute> exp
%type<expr_attribute> compound_statement
%type<expr_attribute> shift_exp
%type<declaration_list> init_declarator
%type<func_list> argument_exp_list

%token  <intval> INT_CONSTANT;
%token  <floatval> FLOAT_CONSTANT;
%token  <charval> CHAR_CONSTANT;



%start translation_unit

%%
//Expressions
M
    :   
    {
        $$ = new expression_attribute;
        $$->instr = Quad_arr.index;
    }
    ;

N
    :   
    {
        $$ = new expression_attribute;
        $$->nextlist = makelist(Quad_arr.index);
        Quad_arr.emit(GOTO,"","","");
    }
    ;

primary_exp
    : IDENTIFIER	
    {
        $$ = new expression_attribute;
        string t = (*($1)); 
        symtab *h = current_symbol->lookup(t);
        $$->loc = t;
    }
    | CHAR_CONSTANT 
    {
        $$ = new expression_attribute;
        type_inf type;
        type.type_name = "char";
        opcodeType op = COPY;
        $$->loc = current_symbol->gentemp(type);
        Quad_arr.emit(op,$$->loc, $1);
        init_value *init = new init_value;
        init->char_val = $1;
        current_symbol->lookup($$->loc)->init_val = init;
        $$->is_pointer_type = 0;
    }
    | STRING_LITERAL    
    {
        $$ = new expression_attribute;
        string s = ".LC";
        string temp = to_string(literals_count);
        s = s + temp;
        $$->loc = s;
        literals_count++;
        string_list.push_back(*$1);
    }
    | INT_CONSTANT
    {
        $$ = new expression_attribute;
        type_inf type;
        type.type_name = "int";
        opcodeType op = COPY;
        $$->loc = current_symbol->gentemp(type);
        Quad_arr.emit(op,$$->loc, $1);
        init_value *init = new init_value;
        init->int_val = $1;                     
        current_symbol->lookup($$->loc)->init_val = init;
        $$->is_pointer_type = 0;

    }
	| FLOAT_CONSTANT	
    {
        $$ = new expression_attribute;
        type_inf type;
        type.type_name = "double";
        opcodeType op = COPY;
        $$->loc = current_symbol->gentemp(type);
        Quad_arr.emit(op,$$->loc, $1);
        init_value *init = new init_value;
        init->double_val = $1;
        current_symbol->lookup($$->loc)->init_val = init;
        $$->is_pointer_type = 0;
    }
    | '(' exp ')'	
    {
        $$ = $2;
    }
    ;
postfix_exp 
    : primary_exp	
    {
        $$ = $1;
    }
    | postfix_exp '(' ')'   {}
    | postfix_exp POINTER_OP IDENTIFIER {}
    | postfix_exp INCREMENT_OP  
    {
    
        $$ = new expression_attribute;

        string s = $1->loc;
        symtab * f = current_symbol->lookup($1->loc);
        $$->loc = current_symbol->gentemp(f->type);
        if(f->type.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(f->type);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            Quad_arr.emit(COPY, $$->loc, temp, "");
            Quad_arr.emit(PLUS, temp, temp, "1");
            Quad_arr.emit(ARRAY_DEREFERENCE, $1->loc, temp, *($1->inner));
        }
        else
        {
            Quad_arr.emit(COPY, $$->loc, $1->loc, "");
            Quad_arr.emit(PLUS, $1->loc, $1->loc, "1");  
        }   
    }
    | postfix_exp '(' argument_exp_list ')' 
    {
        string f = $1->loc;
        symbol_table *fsym = GTable.lookup(f)->nested_table;
        function_list *flist = ($3);
        list<function_definition*>::iterator it;
        int c = 0;
        for(it = flist->func_def_list.begin(); it!=flist->func_def_list.end();it++)
        {
            function_definition *f = *it;
            c++;
            Quad_arr.emit(PARAM, f->param_name,"","");
        }
        string s = to_string(c);
            Quad_arr.emit(CALL,f,s,"");
    }
    | postfix_exp '[' exp ']'	
    {
        type_inf t = current_symbol->lookup($1->loc)->type;
        string s;
        type_inf t1;
        t1.type_name = "int";
    	int idx;
    	string s1;
    	idx = t.idx;
    	s = current_symbol->gentemp(t1);
            Quad_arr.emit(COPY, s, 0);
            $1 -> inner = new string(s); 
    	s = *($1->inner);
    	s1 = to_string(idx);
 
        Quad_arr.emit(MULT, s, s, s1);
        Quad_arr.emit(PLUS, s, s, $3->loc);
        Quad_arr.emit(MULT, s, s, string("4"));
        $$ = $1;
    }
    | postfix_exp '.' IDENTIFIER	{}
    | '(' type_name ')' '{' initializer_list '}'    {}
    | '(' type_name ')' '{' initializer_list ',' '}'    {}
    | postfix_exp DECREMENT_OP	
    {
        $$ = new expression_attribute;
        symtab * f = current_symbol->lookup($1->loc);
        $$->loc = current_symbol->gentemp(f->type);
        if(f->type.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(f->type);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            Quad_arr.emit(COPY, $$->loc, temp, "");
            Quad_arr.emit(MINUS, temp, temp, "1");
            Quad_arr.emit(ARRAY_DEREFERENCE, $1->loc, temp, *($1->inner));
        }
        else
        {
            Quad_arr.emit(COPY, $$->loc, $1->loc, "");
            Quad_arr.emit(MINUS, $1->loc, $1->loc, "1");    
        }
    }
    ;


argument_exp_list
    : assignment_exp	
    {
        function_definition *f = new function_definition;
        f->param_name = $1->loc;
        $$ = new function_list;
        f->type = &(current_symbol->lookup(f->param_name)->type);
        $$->func_def_list.push_back(f);
    }
    | argument_exp_list ',' assignment_exp	
    {
        function_definition *f = new function_definition;
        f->param_name = $3->loc;
        $$ = new function_list;
        f->type = &(current_symbol->lookup(f->param_name)->type);
	$$ = $1;
        $$->func_def_list.push_back(f);
    }
    ;

unary_exp
    :  DECREMENT_OP unary_exp	
    {
        opcodeType op;
        op = MINUS;
        $$ = new expression_attribute;
        type_inf type;
        type = current_symbol->lookup($2->loc)->type;
        $$->loc = current_symbol->gentemp(type);
        if(type.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(type);
            Quad_arr.emit(ARRAY_ACCESS, temp, $2->loc, *($2->inner));
            Quad_arr.emit(MINUS, temp, temp, "1");
            Quad_arr.emit(ARRAY_DEREFERENCE, $2->loc, temp, *($2->inner));
        }
        else
            Quad_arr.emit(op, $$->loc, $2->loc, "1");

        type = current_symbol->lookup($2->loc)->type;
        $$->loc = current_symbol->gentemp(type);
        
        op = COPY;
        Quad_arr.emit(op, $2->loc, $$->loc, "");        
    }
    | postfix_exp {}
    | INCREMENT_OP unary_exp    
    {
        opcodeType op;
        op = PLUS;
        $$ = new expression_attribute;
        type_inf type;
        type = current_symbol->lookup($2->loc)->type;
        if(type.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(type);
            Quad_arr.emit(ARRAY_ACCESS, temp, $2->loc, *($2->inner));
            Quad_arr.emit(PLUS, temp, temp, "1");
            Quad_arr.emit(ARRAY_DEREFERENCE, $2->loc, temp, *($2->inner));
        }
        else
            Quad_arr.emit(op, $$->loc, $2->loc, "1");

        type = current_symbol->lookup($2->loc)->type;
        $$->loc = current_symbol->gentemp(type);
        
        op = COPY;
        Quad_arr.emit(op, $2->loc, $$->loc, "");
    }
    | unary_op cast_exp	
    {
        $$ = new expression_attribute;
        type_inf type;
        type.type_name = string("int");
        if($1 == '-')
        {
            $$ = new expression_attribute; 
            $$->loc = current_symbol->gentemp(type);
            Quad_arr.emit(UNARY_MINUS,$$->loc,$2->loc,"");
        }
        else if($1 == '&')
        {
            $$ = new expression_attribute;
	    type.pointer_type = "ptr";
	    type.pointer_count = 1;
	    type.size = 8;
            $$->loc = current_symbol->gentemp(type);
            Quad_arr.emit(REFERENCE,$$->loc,$2->loc,"");
        }
        else if($1 == '*')
        {
            $$ = new expression_attribute; 
            $$->loc = current_symbol->gentemp(type);
            Quad_arr.emit(DEREFERENCE,$$->loc,$2->loc,"");
        }
        else
        {
            $$ = $2;
        }
        
    }
    | SIZEOF_ unary_exp	{}
    | SIZEOF_ '(' type_name ')'	{}
    ;

unary_op
    : '&'	
    {
        $$ = '&';
    }
    | '+'   
    {
        $$ = '+';
    }
    | '-'   
    {
        $$ = '-';
    }
    | '~'   
    {
        $$ = '~';
    }
    | '*'	
    {
        $$ = '*';
    }
    | '!'	
    {
        $$ = '!';
    }
    ;

cast_exp
    : unary_exp	{}
    | '(' type_name ')' cast_exp	{}
    ;

multiplicative_exp	
    : cast_exp	{}
    | multiplicative_exp '/' cast_exp	
    {

     $$ = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        int flag = 0;
        if(sym_type1.type_name == sym_type2.type_name)
        {
            type.type_name = sym_type1.type_name;
            flag = 1;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Int_to_Dbl(e,$3);
            type.type_name = sym_type1.type_name;
            //$3->loc
        }
        else if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Int_to_Dbl(e,$1);
            type.type_name = sym_type2.type_name;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Dbl(e,$3);
            type.type_name = sym_type1.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Char_to_Dbl(e,$1);
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,$1);
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,$3);
            type.type_name = sym_type1.type_name;
            
        }
        $$->loc = current_symbol->gentemp(type);
        //if(flag == 1)
        //cout<<$$->loc<<"\n";
        Quad_arr.emit(DIVIDE, $$->loc, $1->loc, $3->loc);


    }
    | multiplicative_exp '*' cast_exp   
    {
        $$ = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;


        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        int flag = 0;
        if(sym_type1.type_name == sym_type2.type_name)
        {
            type.type_name = sym_type1.type_name;
            flag = 1;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Int_to_Dbl(e,$3);
            type.type_name = sym_type1.type_name;
            //$3->loc
        }
        else if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Int_to_Dbl(e,$1);
            type.type_name = sym_type2.type_name;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Dbl(e,$3);
            type.type_name = sym_type1.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Char_to_Dbl(e,$1);
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,$1);
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,$3);
            type.type_name = sym_type1.type_name;
            
        }
        $$->loc = current_symbol->gentemp(type);
        Quad_arr.emit(MULT, $$->loc, $1->loc, $3->loc);

    }
    | multiplicative_exp '%' cast_exp	
    {

        $$ = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        int flag = 0;
        if(sym_type1.type_name == sym_type2.type_name)
        {
            type.type_name = sym_type1.type_name;
            flag = 1;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Int_to_Dbl(e,$3);
            type.type_name = sym_type1.type_name;
            //$3->loc
        }
        else if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Int_to_Dbl(e,$1);
            type.type_name = sym_type2.type_name;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Dbl(e,$3);
            type.type_name = sym_type1.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Char_to_Dbl(e,$1);
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,$1);
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,$3);
            type.type_name = sym_type1.type_name;
            
        }
        $$->loc = current_symbol->gentemp(type);
        //if(flag == 1)
        //cout<<$$->loc<<"\n";
        Quad_arr.emit(MODULO, $$->loc, $1->loc, $3->loc);

    }
    ;

additive_exp
    : multiplicative_exp	{$$ = $1;}
    | additive_exp '-' multiplicative_exp	
    {

        $$ = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        int flag = 0;
        if(sym_type1.type_name == sym_type2.type_name)
        {
            type.type_name = sym_type1.type_name;
            flag = 1;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Int_to_Dbl(e,$3);
            type.type_name = sym_type1.type_name;
            //$3->loc
        }
        else if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Int_to_Dbl(e,$1);
            type.type_name = sym_type2.type_name;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Dbl(e,$3);
            type.type_name = sym_type1.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Char_to_Dbl(e,$1);
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,$1);
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,$3);
            type.type_name = sym_type1.type_name;
            
        }
        $$->loc = current_symbol->gentemp(type);
        //if(flag == 1)
        //cout<<$$->loc<<"\n";
        Quad_arr.emit(MINUS, $$->loc, $1->loc, $3->loc);

    }
    | additive_exp '+' multiplicative_exp   
    {

        $$ = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        int flag = 0;
        if(sym_type1.type_name == sym_type2.type_name)
        {
            type.type_name = sym_type1.type_name;
            flag = 1;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Int_to_Dbl(e,$3);
            type.type_name = sym_type1.type_name;
            //$3->loc
        }
        else if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Int_to_Dbl(e,$1);
            type.type_name = sym_type2.type_name;
        }
        if(sym_type1.type_name.compare("double")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Dbl(e,$3);
            type.type_name = sym_type1.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("double")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type2;
            Quad_arr.convert_Char_to_Dbl(e,$1);
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("char")==0 && sym_type2.type_name.compare("int")==0)
        {   
            string t = current_symbol->gentemp(sym_type2);
            symtab *s = current_symbol->lookup(t, sym_type2.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,$1);
            type.type_name = sym_type2.type_name;
            
        }
        if(sym_type1.type_name.compare("int")==0 && sym_type2.type_name.compare("char")==0)
        {   
            string t = current_symbol->gentemp(sym_type1);
            symtab *s = current_symbol->lookup(t, sym_type1.type_name);
            expression_attribute *e = new expression_attribute;
            e->loc = t;
            e->type = sym_type1;
            Quad_arr.convert_Char_to_Int(e,$3);
            type.type_name = sym_type1.type_name;
            
        }
        $$->loc = current_symbol->gentemp(type);
        //if(flag == 1)
        //cout<<$$->loc<<"\n";
        Quad_arr.emit(PLUS, $$->loc, $1->loc, $3->loc);

    }
    ;

shift_exp
    : additive_exp	{}
    | shift_exp LEFT_SHIFT additive_exp	
    {
        $$ = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        int flag = 0;
        if(sym_type1.type_name.compare("int") == 0)
        {

        }
        else
        {
            if(sym_type1.type_name.compare("double") == 0)
            {
                sym_type1.type_name = "int";
                string t = current_symbol->gentemp(sym_type1);
                symtab *s = current_symbol->lookup(t, "int");
                expression_attribute *e = new expression_attribute;
                e->loc = t;
                e->type.type_name = "int";
                Quad_arr.convert_Dbl_to_Int(e,$3);
            }
            else if(sym_type1.type_name.compare("char") == 0)
            {
                sym_type1.type_name = "int";
                string t = current_symbol->gentemp(sym_type1);
                symtab *s = current_symbol->lookup(t, "int");
                expression_attribute *e = new expression_attribute;
                e->loc = t;
                e->type.type_name = "int";
                Quad_arr.convert_Char_to_Int(e,$3);
            }
        }
        sym_type1.type_name = "int";
        $$->loc = current_symbol->gentemp(sym_type1);
        Quad_arr.emit(SHIFT_LEFT, $$->loc, $1->loc, $3->loc);
    }
    | shift_exp RIGHT_SHIFT additive_exp	
    {
        $$ = new expression_attribute;
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        int flag = 0;
        if(sym_type1.type_name.compare("int") == 0)
        {

        }
        else
        {
            if(sym_type1.type_name.compare("double") == 0)
            {
                sym_type1.type_name = "int";
                string t = current_symbol->gentemp(sym_type1);
                symtab *s = current_symbol->lookup(t, "int");
                expression_attribute *e = new expression_attribute;
                e->loc = t;
                e->type.type_name = "int";
                Quad_arr.convert_Dbl_to_Int(e,$3);
                //type.type_name = sym_type1.type_name;
            }
            else if(sym_type1.type_name.compare("char") == 0)
            {
                sym_type1.type_name = "int";
                string t = current_symbol->gentemp(sym_type1);
                symtab *s = current_symbol->lookup(t, "int");
                expression_attribute *e = new expression_attribute;
                e->loc = t;
                e->type.type_name = "int";
                Quad_arr.convert_Char_to_Int(e,$3);
                //type.type_name = sym_type1.type_name;
            }
        }
        sym_type1.type_name = "int";
        $$->loc = current_symbol->gentemp(sym_type1);
        Quad_arr.emit(SHIFT_RIGHT, $$->loc, $1->loc, $3->loc);
    }
    ;

relational_exp
    : shift_exp	{}
    | relational_exp '<' shift_exp	
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        $$ = new expression_attribute;
        $$->type.type_name = "bool";
        $$->loc = current_symbol->gentemp($$->type);
        $$->truelist = makelist(Quad_arr.index);
        $$->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_LESS, "", $1->loc, $3->loc);
        Quad_arr.emit(GOTO,"","","");
    }
    | relational_exp '>' shift_exp	
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        $$ = new expression_attribute;
        $$->type.type_name = "bool";
        $$->loc = current_symbol->gentemp($$->type);
        $$->truelist = makelist(Quad_arr.index);
        $$->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_GREATER, "", $1->loc, $3->loc);
        Quad_arr.emit(GOTO,"","","");
    }
    | relational_exp LESS_EQ_OP shift_exp	
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        $$ = new expression_attribute;
        $$->type.type_name = "bool";
        $$->loc = current_symbol->gentemp($$->type);
        $$->truelist = makelist(Quad_arr.index);
        $$->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_LESS_EQUAL, "", $1->loc, $3->loc);
        Quad_arr.emit(GOTO,"","","");
    }
    | relational_exp GREATER_EQ_OP shift_exp	
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        $$ = new expression_attribute;
        $$->type.type_name = "bool";
        $$->loc = current_symbol->gentemp($$->type);
        $$->truelist = makelist(Quad_arr.index);
        $$->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_GREATER_EQUAL, "", $1->loc, $3->loc);
        Quad_arr.emit(GOTO,"","","");
    }
    ;
equality_exp
    : relational_exp	{}
    | equality_exp EQ_OP relational_exp	
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        $$ = new expression_attribute;
        $$->type.type_name = "bool";
        $$->loc = current_symbol->gentemp($$->type);
        $$->truelist = makelist(Quad_arr.index);
        $$->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_IS_EQUAL,"",$1->loc, $3->loc);
        Quad_arr.emit(GOTO,"","","");
    }
    | equality_exp NOT_EQ_OP relational_exp	
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        $$ = new expression_attribute;
        $$->type.type_name = "bool";
        $$->loc = current_symbol->gentemp($$->type);
        $$->truelist = makelist(Quad_arr.index);
        $$->falselist = makelist(Quad_arr.index + 1);
        Quad_arr.emit(IF_NOT_EQUAL,"",$1->loc, $3->loc);
        Quad_arr.emit(GOTO,"","","");
    }
    ;

and_exp
    : equality_exp	{}
    | and_exp '&' equality_exp	
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        $$ = new expression_attribute;
        symtab *f = current_symbol->lookup($1->loc);//check
        type_inf t;
        t = f->type;
        $$->loc = current_symbol->gentemp(t);
        Quad_arr.emit(LOGICAL_AND, $$->loc, $1->loc, $3->loc);
    }
    ;

exclusive_or_exp
    : and_exp	
    {
        //printf("exclusive_or_exp -> and_exp\n");
    }
    | exclusive_or_exp '^' and_exp	
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        $$ = new expression_attribute;
        symtab *f = current_symbol->lookup($1->loc);//check
        type_inf t;
        t = f->type;
        $$->loc = current_symbol->gentemp(t);
        Quad_arr.emit(XOR, $$->loc, $1->loc, $3->loc);
    }
    ;
inclusive_or_exp
    : exclusive_or_exp	{}
    | inclusive_or_exp '|' exclusive_or_exp	
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        $$ = new expression_attribute;
        symtab *f = current_symbol->lookup($1->loc);//check
        type_inf t;
        t = f->type;
        $$->loc = current_symbol->gentemp(t);
        Quad_arr.emit(OR, $$->loc, $1->loc, $3->loc);
    }
    ;

logical_and_exp
    : inclusive_or_exp	{}
    | logical_and_exp N AND_OP M inclusive_or_exp	N
    {
        type_inf sym_type1, sym_type2;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($5->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $5->loc, *($5->inner));
            $5->loc = temp;
            $5->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        type_inf type;
        type.type_name = "bool";
        $$ = new expression_attribute;
        $$->type = type;

        Quad_arr.backpatch($2->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool($1);

        Quad_arr.backpatch($6->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool($5);

        Quad_arr.backpatch($1->truelist, $4->instr);
        $$->truelist = $5->truelist;
        $$->falselist = merge($1->falselist, $5->falselist);
    }
    ;
logical_or_exp
    : logical_and_exp	{}
    | logical_or_exp N OR_OP M logical_and_exp N	
    {
        type_inf sym_type1, sym_type2;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($5->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $5->loc, *($5->inner));
            $5->loc = temp;
            $5->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $1->loc, *($1->inner));
            $1->loc = temp;
            $1->type.array_type = ""; //check
        }
        
        type_inf type;
        type.type_name = "bool";
        $$ = new expression_attribute;
        $$->type = type;
        
        Quad_arr.backpatch($2->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool($1);

        Quad_arr.backpatch($6->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool($5);

        Quad_arr.backpatch($1->falselist, $4->instr);
        $$->truelist = merge($1->truelist, $5->truelist);
        $$->falselist = $5->falselist;
        
    }
    ;
conditional_exp
    : logical_or_exp	
    {   }
    | logical_or_exp N '?' M exp N ':' M conditional_exp	
    {
        type_inf sym_type1, sym_type2;
        sym_type1 = current_symbol->lookup($5->loc)->type;
        sym_type2 = current_symbol->lookup($9->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $9->loc, *($9->inner));
            $9->loc = temp;
            $9->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type1);
            Quad_arr.emit(ARRAY_ACCESS, temp, $5->loc, *($5->inner));
            $9->loc = temp;
            $9->type.array_type = ""; //check
        }
        
        $$ = new expression_attribute;
        list<int> I;
        type_inf type;
        type = current_symbol->lookup($5->loc)->type;
        $$->loc = current_symbol->gentemp(type);
        Quad_arr.emit(COPY, $$->loc, $9->loc,"");
        I = makelist(Quad_arr.index);
        Quad_arr.emit(GOTO,"","","");
        Quad_arr.backpatch($6->nextlist, Quad_arr.index);
        Quad_arr.emit(COPY, $$->loc, $5->loc, "");
        I = merge(I, makelist(Quad_arr.index));
        Quad_arr.emit(GOTO,"", "", "");
        Quad_arr.backpatch($2->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool($1);
        Quad_arr.backpatch($1->truelist, $4->instr);
        Quad_arr.backpatch($1->falselist, $8->instr);
        Quad_arr.backpatch(I, Quad_arr.index);
    }
    ;
assignment_exp
    : conditional_exp{}
    | unary_exp assignment_op assignment_exp	
    {
        type_inf sym_type1, sym_type2, type;
        sym_type1 = current_symbol->lookup($1->loc)->type;
        sym_type2 = current_symbol->lookup($3->loc)->type;

        if(sym_type2.array_type.compare("array") == 0)
        {
            string temp = current_symbol->gentemp(sym_type2);
            Quad_arr.emit(ARRAY_ACCESS, temp, $3->loc, *($3->inner));
            $3->loc = temp;
            $3->type.array_type = ""; //check
        }
        
        if(sym_type1.array_type.compare("array") == 0)
        {
            Quad_arr.emit(ARRAY_DEREFERENCE, $1->loc, $3->loc, *($1->inner));
        }
        else
            Quad_arr.emit(COPY, $1->loc, $3->loc, "");
        $$ = $1;
    }
    ;

assignment_op
    : '='	        {}
    | MUL_ASSIGN	{}
    | DIV_ASSIGN	{}
    | MOD_ASSIGN	{}
    | ADD_ASSIGN	{}
    | SUB_ASSIGN	{}
    | LEFT_ASSIGN	{}
    | RIGHT_ASSIGN	{}
    | AND_ASSIGN	{}
    | XOR_ASSIGN	{}
    | OR_ASSIGN	    {}
    ;
exp
    : assignment_exp	
    {
        $$ = $1;
    }
    | exp ',' assignment_exp	{}
    ;
constant_exp
    : conditional_exp   {}
    ;


// Declarations

declaration
    : declaration_specifiers ';'	{}
    | declaration_specifiers init_declarator_list ';'	
    {
        init_declration_list *new_dec = new init_declration_list;
        new_dec = $2;
        int size = 0;
        type_inf *type = $1;
        if(type->type_name.compare("int")==0) size = 4;
        if(type->type_name.compare("double")==0) size = 8;
        if(type->type_name.compare("char")==0) size = 1;

        list<declaration*>::iterator it;
        for(it = $2->declaration_list.begin(); it != $2->declaration_list.end(); it++)
        {
            declaration *new_dec = *it;
		    if(new_dec->type!=NULL){
            if(new_dec->type->type_name.compare("function")==0)
            {
                string name = new_dec->dec_name;
                current_symbol = &GTable;
                Quad_arr.emit(_FUNCTION_END,name,"","");
            }
            
            symtab *ret, *f;
            symbol_table *nest;
            if(new_dec->type->type_name.compare("function")==0)
            {
                f = current_symbol->lookup(new_dec->dec_name, type->type_name);
                nest = f->nested_table;
                ret = nest->lookup("retVal", type->type_name, new_dec->pointer_count);
                f->offset = current_symbol->offset;
                f->size = size;
                f->init_val = NULL;
                continue;
            }
            }
            
            symtab *f1 = current_symbol->lookup(new_dec->dec_name, type->type_name);

            f1->nested_table = NULL;


            if(new_dec->alist == vector<int>() && new_dec->pointer_count == 0)
            {
                f1->offset = current_symbol->offset;
                //f1->offset = f1->offset + size;
                f1->type = *type;
                f1 = current_symbol->lookup(new_dec->dec_name, type->type_name);
            
                if(new_dec->init != NULL)
                {
            
                    string x = new_dec->init->loc;
                    Quad_arr.emit(COPY, new_dec->dec_name, x, "");
                    f1->init_val = current_symbol->lookup(x,f1->type.type_name)->init_val;
                }
                else
                    new_dec->init = NULL;
            }

            else if(new_dec -> pointer_count > 0)
            {
                symtab *sp;
                for(sp = current_symbol->sym_table; sp < &current_symbol->sym_table[current_symbol->no_of_entries]; sp++)
                {
                    if(!sp->id.empty() && !sp->id.compare(new_dec->dec_name))
                    {
                        sp->offset = current_symbol->offset-4;
                        sp->pointer_count = new_dec->pointer_count;
                        sp->type = *type;
                        sp->type.pointer_type = "ptr";
                        sp->size = 4;
                    }
                }
                
            }

            else if(new_dec->alist!=vector<int>())
            {
                symtab *sp;
                for(sp = current_symbol->sym_table; sp < &current_symbol->sym_table[current_symbol->no_of_entries]; sp++)
                {
                    if(!sp->id.empty() && !sp->id.compare(new_dec->dec_name))
                    {
                        int temp_size = size;
                        sp->offset = current_symbol->offset-4;
                        sp->type = *type;
			            sp->type.type_name = type->type_name;
                        sp->type.array_type = "array";
                        sp->type.pointer_type = "";
                        for(int i = 0; i < new_dec->alist.size(); i++)
                        {
                            sp->type.array_list.push_back(new_dec->alist[i]);
                        }
                        for (int i = 0; i < sp->type.array_list.size(); ++i)
                        {
                            temp_size = temp_size * sp->type.array_list[i];
                        }
                        sp->size = temp_size;
                        current_symbol->offset = current_symbol->offset + temp_size;
                    }
                }
                
            }

            
        }
    }
    ;

declaration_specifiers
    : storage_class_specifier	
    {
    }
    | storage_class_specifier declaration_specifiers	
    {
    }
    | type_specifier	
    {
        $$ = $1;
    }
    | type_specifier declaration_specifiers	
    {
    }
    | type_qualifier	
    {
    }
    | type_qualifier declaration_specifiers	
    {
    }
    | function_specifier	
    {
    }
    | function_specifier declaration_specifiers	
    {
    }
    ;


init_declarator_list
    : init_declarator	
    { 
        $$ = new init_declration_list;
        $$->declaration_list.push_back($1);
    }
    | init_declarator_list ',' init_declarator	
    {
        $1->declaration_list.push_back($3);
        $$ = $1;
    }
    ;


init_declarator
    : declarator	
    {
        $$ = $1;
        $$->init = NULL;
    }
    | declarator '=' initializer	
    {
        $$ = $1;
        $$->init = $3;
    }
    ;
storage_class_specifier
    : EXTERN_	{printf("storage_class_specifier -> extern\n");}
    | STATIC_	{printf("storage_class_specifier -> static\n");}
    | AUTO_	{printf("storage_class_specifier -> auto\n");}
    | REGISTER_	{printf("storage_class_specifier -> register\n");}
    ;

type_specifier              //done
    : VOID_	
		{
            $$ = new type_inf;
			$$->type_name = string("void"); 
		}
    | CHAR_	
		{
            $$ = new type_inf;
			$$->type_name = string("char");
			$$->next = NULL;
		}
    | SHORT_	{
        }
    | INT_	
		{
            $$ = new type_inf;
			$$->type_name = string("int");
			$$->next = NULL;
			
			
		}
    | LONG_	{
        }
    | FLOAT_	{
        }
    | DOUBLE_	
	{
        $$ = new type_inf;
		$$->type_name = string("double");
		$$->next = NULL;
	}
    | SIGNED_	{
    }
    | UNSIGNED_	{
    }
    | BOOL_	{
    }
    | COMPLEX_	{
    }
    | IMAGINARY_	{
    }
    | enum_specifier
    ;

specifier_qualifier_list
    : type_specifier 	
		{
			$$ = $1;
		}
    | type_specifier specifier_qualifier_list	
    {
    }
    | type_qualifier	{
                        }
    | type_qualifier specifier_qualifier_list	{
                        }
    ;
enum_specifier
    : ENUM_ '{' enumerator_list '}'	{printf("enum_specifier -> enum {enumerator_list}\n");}
    | ENUM_ IDENTIFIER '{' enumerator_list '}'	{printf("enum_specifier -> enum IDENTIFIER {enumerator_list} \n");}
    | ENUM_ '{' enumerator_list ',' '}'	{printf("enum_specifier -> enum {enumerator_list, }\n");}
    | ENUM_ IDENTIFIER '{' enumerator_list ',' '}'	{printf("enum_specifier -> enum IDENTIFIER {enumerator_list ,}\n");}
    | ENUM_ IDENTIFIER	{printf("enum_specifier->enum IDENTIFIER\n");}
    ;
enumerator_list
    : enumerator	{printf("enumerator_list -> enumerator\n");}
    | enumerator_list ',' enumerator	{printf("enumerator_list -> enumerator_list , enumerator\n");}
    ;
enumerator
    : enumeration_constant	{printf("enumerator -> enumeration_constant\n");}
    | enumeration_constant '=' constant_exp	{printf("enumerator -> enumeration_constant = constant_exp\n");}
    ;
enumeration_constant
    : IDENTIFIER	{printf("enumeration_constant -> IDENTIFIER\n");}
    ;
type_qualifier
    : CONST_	{printf("type_qualifier -> const\n");}
    | RESTRICTED_	{printf("type_qualifier -> restrict\n");}
    | VOLATILE_	{printf("type_qualifier -> volatile\n");}
    ;
function_specifier
    : INLINE_	{printf("function_specifier -> inline\n");}
declarator
    : pointer direct_declarator	
    {
        $$ = $2;
        $$->pointer_count = $1->pointer_count;
        //printf("declarator -> pointer direct_declarator\n");
    }
    | direct_declarator	
	{

		$$ = $1;
        $$->pointer_count = 0;
			//printf("declarator -> direct_declarator\n");
	}
    ;


direct_declarator 
    : IDENTIFIER	
    {//printf("direct_declarator -> IDENTIFIER\n");
        $$ = new declaration; 
        $$->dec_name = *($1);
    }
    | '(' declarator ')'	
    {
        $$ = $2;
    }
    | direct_declarator '[' type_qualifier_list_opt assignment_exp_opt ']'	
    {
	
        $$ = $1;
        int idx = current_symbol->lookup($4->loc)->init_val->int_val;
        $$->alist.push_back(idx);
    }
    | direct_declarator '[' STATIC_ type_qualifier_list_opt assignment_exp ']'	
    {
    }
    | direct_declarator '[' type_qualifier_list STATIC_ assignment_exp ']'	
    {
    }
    | direct_declarator '[' type_qualifier_list_opt '*' ']'	
    {
    }
    | direct_declarator '(' parameter_type_list_opt')'	
    {
        //name of func is available
        list<function_definition*> l = $3->func_def_list;
        
        symbol_table *new_sym = new symbol_table;
        $$ = $1;
        string name = $$->dec_name;
        //cout<<name<<"\n";
        $$->type = new type_inf;
        $$->type->type_name = string("function");
        $$->type->no_of_params = l.size();
        symtab *func_lookup = symbol->lookup($$->dec_name, $$->type->type_name);
		for(int i=0; i < symbol->no_of_entries; i++)
       		{
	    	if(symbol->sym_table[i].id.compare($$->dec_name)==0)
	    	{
				symbol->sym_table[i].type.type_name = "function";
				symbol->sym_table[i].type.no_of_params = l.size();
	    	}
        }

        func_lookup -> nested_table = new_sym;

        list<function_definition*>::iterator it;
        for(it = l.begin(); it != l.end(); it++)
        {
            function_definition *temp = *it;
            new_sym -> lookup(temp->param_name, temp->type->type_name);
	    for(int i = 0; i<new_sym->no_of_entries; i++)
	    {
		if(new_sym->sym_table[i].id.compare(temp->param_name)==0)
		{
			if(temp->type->array_type.compare("array")==0){
				new_sym->sym_table[i].type.array_type = "array";
				new_sym->sym_table[i].type.idx = temp->type->idx;
				}
		}
	    }

            //func_lookup->nested_table -> lookup(temp->param_name, temp->type->type_name);
        }

        symtab *sp;
        for(sp = symbol->sym_table; sp < &symbol->sym_table[symbol->no_of_entries]; sp++)
        {
            //cout<<s<<"\n";
            //cout<<"loop\n";
            if(!sp->id.empty() && !sp->id.compare($$->dec_name))
            {
                sp->nested_table = new_sym;
            }
        }
        current_symbol = new_sym;
        Quad_arr.emit(_FUNCTION_START, name,"","");
    }
    | direct_declarator '(' identifier_list')'	
    {
        //printf("direct_declarator -> direct_declarator (identifier_list_opt)\n");

    }
    ;

assignment_exp_opt
   : assignment_exp	
   {
    //printf("assignment_exp_opt -> assignment_exp\n");
   }
   |
   ;
type_qualifier_list_opt
    : type_qualifier_list	
    {
        //printf("type_qualifier_list_opt -> type_qualifier_list\n");
    }
    |
    ;

pointer
    : '*'	
    {
        //printf("pointer -> '*'\n");
        $$ = new type_inf;
        $$->type_name = string("ptr");
        $$->next = NULL;
        $$->pointer_type = string("ptr");
        $$->pointer_count = 1;
    }
    | '*' type_qualifier_list	
    {
    //    printf("pointer -> *type_qualifier_list\n");
    }
    | '*' pointer	
    {
        //printf("pointer -> *pointer\n");
        $$ = new type_inf;
        $$->type_name = string("ptr");
        $$->next = NULL;
        $$->pointer_type = string("ptr");
        
        $$->pointer_count = $2->pointer_count + 1;
        
    }
    | '*' type_qualifier_list pointer	
    {
        //printf("pointer -> *type_qualifier_list pointer\n");
    }
    ;
type_qualifier_list
    : type_qualifier	
    {
        //printf("type_qualifier_list -> type_qualifier\n");
    }
    | type_qualifier_list type_qualifier	
    {
        //printf("type_qualifier_list -> type_qualifier_list type_qualifier\n");
    }
    ;
parameter_type_list_opt
    :parameter_type_list
    |   
    {
        $$ = new function_list;
    }
    ;
parameter_type_list
    : parameter_list	
    {
        $$ = new function_list;
        $$ = $1;
        //printf("parameter_type_list -> parameter_list\n");
    }
    | parameter_list ',' ELLIPSIS	
    {
        //printf("parameter_type_list -> parameter_list, ELLIPSIS\n");
    }
    ;
parameter_list
    : parameter_declaration	
    {
        //create a new list
        $$ = new function_list;
        $$->func_def_list.push_back($1);

        //printf("parameter_list -> parameter_declaration\n");
    }
    | parameter_list ',' parameter_declaration	
    {
        //make use of old list

        $1->func_def_list.push_back($3);
        $$ = $1;
        //printf("parameter_list -> parameter_list, parameter_declaration\n");
    }
    ;
parameter_declaration
    : declaration_specifiers declarator	
    {
        $$ = new function_definition;
        $$->type = $1;
	if($2->alist.size()>0)
		{$$->type->array_type = "array";$$->type->idx = $2->alist[0];$$->type->type_name = $1->type_name;
	}
	for(int i=0; i<current_symbol->no_of_entries; i++)
	{
		if(current_symbol->sym_table[i].id.compare($2->dec_name)==0)
		{
			if($2->type->array_type.compare("array")==0 || current_symbol->sym_table[i].type.array_type.compare("array")==0)
			{
				current_symbol->sym_table[i].type.array_type = "array";
				$$->type->array_type = "array";
			}
		}
	}
	$$->param_name = $2->dec_name;

        //printf("parameter_declaration -> declaration_specifiers declarator\n");
    }
    | declaration_specifiers	
    {
        //printf("parameter_declaration -> declaration_specifiers\n");
    }
    ;

identifier_list
    : IDENTIFIER	
    {
        //printf("identifier_list -> IDENTIFIER\n");
    }
    | identifier_list ',' IDENTIFIER	
    {
        //printf("identifier_list -> identifier_list, IDENTIFIER\n");
    }
    ;

type_name
    : specifier_qualifier_list	
    {
        $$ = $1;
        //printf("type_name -> specifier_qualifier_list\n");
    }
    ;

initializer
    : assignment_exp	
    {//printf("initializer -> assignment_exp\n");
        $$ = $1;
    }
    | '{' initializer_list '}'	
    {
        //printf("initializer -> {initializer_list}\n");
    }
    | '{' initializer_list ',' '}'	
    {
        //printf("initializer -> {initializer_list, }\n");
    }
    ;

initializer_list
    : initializer	
    {
        //printf("initializer_list -> initializer\n");
    }
    | designation initializer	
    {
        //printf("initializer_list -> designation initializer\n");
    }
    | initializer_list ',' initializer	
    {//printf("initializer_list -> initializer_list, initializer\n");
    }
    | initializer_list ',' designation initializer	
    {
        //printf("initializer_list -> initializer_list, designation initializer\n");
    }
    ;

designation
    : designator_list '='	
    {
        //printf("designation -> designator_list -\n");
    }
    ;

designator_list
    : designator	
    {
        //printf("designator_list -> designator\n");
    }
    | designator_list designator	
    {
        //printf("designator_list -> designator_list designator\n");
    }
    ;
designator
    : '[' constant_exp ']'	
    {
        //printf("designator -> [constant_exp]\n");
    }
    | '.' IDENTIFIER	
    {
        //printf("designator -> IDENTIFIER\n");
    }
    ;


// Statements

statement
    : labeled_statement	
    {
        //printf("statement -> labeled_statement\n");
    }
    | compound_statement	
    {
        //printf("statement -> compound_statement\n");
    }
    | expression_statement	
    {
        //printf("statement -> expression_statement\n");
    }
    | selection_statement	
    {
        //printf("statement -> selection_statement\n");
    }
    | iteration_statement	
    {
        //printf("statement -> iteration_statement\n");
    }
    | jump_statement	
    {
        //printf("statement -> jump_statement\n");
    }
    ;
labeled_statement
    : IDENTIFIER ':' statement	
    {
        //printf("labeled_statement -> IDENTIFIER : statement\n");
    }
    | CASE_ constant_exp ':' statement	
    {
        //printf("labeled_statement -> case constant_exp : statement\n");
    }
    | DEFAULT_ ':' statement	
    {
        //printf("labeled_statement -> default : statement\n");
    }
    ;

compound_statement
	:'{' '}'	
    {
        //printf("compound_statement -> {}\n");
    }
	|'{' block_item_list '}'	
    {
        $$ = $2;
        //printf("compound_statement -> {block_item_list}\n");
    }
    ;

block_item_list
    : block_item	
    {
        $$ = $1;
        Quad_arr.backpatch($1->nextlist, Quad_arr.index);
        //printf("block_item_list -> block_item\n");
    }
    | block_item_list M block_item	
    {
        Quad_arr.backpatch($1->nextlist, $2->instr);
        $$ = new expression_attribute;
        $$->nextlist = $3->nextlist;
        //printf("block_item_list -> block_item_list block_item\n");
    }
    ;
block_item
    : declaration	
    {
        $$ = new expression_attribute;
        //printf("block_item -> declaration\n");
    }
    | statement	
    {
        //printf("block_item -> statement\n");
    }
    ;
expression_statement
    : ';'	
    {
        $$ = new expression_attribute;
        //printf("expression_statement -> ;\n");
    }
    | exp ';'	
    {
        //$$ = $1;
        //printf("expression_statement -> exp ;\n");
    }
    ;
selection_statement
    : IF_ '(' exp N')' M statement N	
    {
        $$ = new expression_attribute;
        //if($3->type.type_name.compare("bool"))
        Quad_arr.backpatch($4->nextlist, Quad_arr.index);

        //cout<<$3->type.type_name<<"\n";
        Quad_arr.convInt2Bool($3);
        
        Quad_arr.backpatch($3->truelist, $6->instr);
        //$$->nextlist

        $$->nextlist = merge($8->nextlist, $7->nextlist);
        $$->nextlist = merge($$->nextlist, $3->falselist);
        //printf("selection_statement -> if (exp) statement\n");
    }
    | IF_ '(' exp N')' M statement N ELSE_ M statement	N
    {
        $$ = new expression_attribute;

        Quad_arr.backpatch($4->nextlist , Quad_arr.index);

        Quad_arr.convInt2Bool($3);

        $$->nextlist = merge($7->nextlist, $8->nextlist);

        Quad_arr.backpatch($3->truelist, $6->instr);
        Quad_arr.backpatch($3->falselist, $10->instr);

        $$->nextlist = merge($$->nextlist, $12->nextlist);
        $$->nextlist = merge($$->nextlist, $11->nextlist);
        //printf("selection_statement -> if(exp) statement else statement\n");
    }
    | SWITCH_ '(' exp ')' statement	
    {
        //printf("selection_statement -> switch(exp) statement\n");
    }
    ;
iteration_statement
    : WHILE_ M '(' exp N ')' M statement	
    {
        Quad_arr.emit(GOTO,"","","");
        Quad_arr.backpatch(makelist(Quad_arr.index-1),$2->instr);    

        Quad_arr.backpatch($5->nextlist,Quad_arr.index);
        Quad_arr.convInt2Bool($4);

        $$ = new expression_attribute;
        Quad_arr.backpatch($8->nextlist, $2->instr);
        Quad_arr.backpatch($4->truelist, $7->instr);
        $$->nextlist = $4->falselist;
        //printf("iteration_statement -> while(exp) statement\n");
    }
    | DO_ M statement M WHILE_ '(' exp ')' ';'	
    {
        $$ = new expression_attribute;
        Quad_arr.convInt2Bool($7);
        Quad_arr.backpatch($3->nextlist, $4->instr);
        Quad_arr.backpatch($7->truelist, $2->instr);
        $$->nextlist = $7->falselist;
        //printf("iteration_statement -> do statement while(exp);\n");
    }
    | FOR_ '(' expression_opt ';' M expression_opt N ';' M expression_opt N ')' M statement	
    {
        $$ = new expression_attribute;
    
        Quad_arr.emit(GOTO,"","","");
        Quad_arr.backpatch(makelist(Quad_arr.index-1),$9->instr);    
        Quad_arr.backpatch($7->nextlist, Quad_arr.index);
        Quad_arr.convInt2Bool($6);

        Quad_arr.backpatch($11->nextlist,$5->instr);
        Quad_arr.backpatch($6->truelist,$13->instr);
        Quad_arr.backpatch($14->nextlist,$9->instr);
    
        $$->nextlist = $6->falselist;

        //printf("iteration_statement -> for(expression_opt expression_opt expression_opt) statement\n");
    }
    | FOR_ '(' declaration expression_opt ';' expression_opt ')' statement	
    {
        //printf("iteration_statement -> for (declaration expression_opt expression_opt) statement\n");
    }
    ;
expression_opt
	:exp	
    {
        //printf("expression_opt -> exp\n");
    }
	|
	;
jump_statement
    : GOTO_ IDENTIFIER ';'	
    {
        //printf("jump_statement -> goto IDENTIFIER :\n");
    }
    | CONTINUE_ ';'	
    {
        //printf("jump_statement -> continue ;\n");
    }
    | BREAK_ ';'	
    {
        //printf("jump_statement -> break;\n");
    }
    | RETURN_ ';'	
    {
        $$ = new expression_attribute;

        if(current_symbol->lookup("retVal")->type.type_name.compare("void")==0)
        {
            Quad_arr.emit(RETURN_VOID,"","","");
        }
        
        //printf("jump_statement -> return;\n");
    }
    | RETURN_ exp ';'	
    {
        $$ = new expression_attribute;
        type_inf sym_type1, sym_type2, type3;
        sym_type1 = current_symbol->lookup("retVal")->type;
        sym_type2 = current_symbol->lookup($2->loc)->type;
        for(int i=0; i<symbol->no_of_entries;i++)
	{
		if(symbol->sym_table[i].id.compare($2->loc)==0)
			type3 = symbol->sym_table[i].type;
	}
	if(type3.type_name.compare("function")==0)
	{	
		string t = current_symbol->gentemp(sym_type1);
		Quad_arr.emit(COPY, t, $2->loc, "");
		Quad_arr.emit(RETURN,t,"","");
	}
	else if(sym_type1.type_name == sym_type2.type_name)
        {
            Quad_arr.emit(RETURN, $2->loc, "", "");
        }
	
        //printf("jump_statement -> return exp;\n");

    }
    ;


// External Definitions

translation_unit
    : external_declaration	
    {
        //printf("translation_unit -> external_declaration\n");
    }
    | translation_unit external_declaration	
    {
        //printf("translation_unit -> translation_unit external_declaration\n");
    }
    ;

external_declaration
    : function_definition	
    {
        //printf("external_declaration -> function_definition\n");
    }
    | declaration	
    {
        //printf("external_declaration -> declaration\n");
    }
    ;

function_definition
    : declaration_specifiers declarator declaration_list compound_statement	
    {
        //printf("function_definition -> declaration_specifiers declarator declaration_list compound_statement\n");
    }
    | declaration_specifiers declarator compound_statement	
    {
        //symbol->nested_table = NULL;
        //current_symbol->nested_table = NULL;
        
        declaration *new_dec = $2;
        int size = 0;
        type_inf *type = $1;
        if(type->type_name.compare("int")==0) size = 4;
        if(type->type_name.compare("double")==0) size = 8;
        if(type->type_name.compare("char")==0) size = 1;
        if(type->type_name.compare("void")==0) size = 0;
        //cout<<$2->type->type_name;
        symbol_table *gt = &GTable;
        Quad_arr.emit(_FUNCTION_END,new_dec->dec_name,"","");
        symtab *func = gt->lookup($2->dec_name);
        //cout<<"function_definition "<<$2->dec_name<<"\n";
        //func->nested_table = new symbol_table;
        if(func->nested_table != NULL)
        {
            //cout<<"nested\n";
            //cout<<new_dec->dec_name<<" "<<new_dec->pointer_count<<type->type_name<<"\n";
            if($2->pointer_count>0)
                type->pointer_type = "ptr";
            symtab *ret = func->nested_table->lookup("retVal", type->type_name, $2->pointer_count);
            /*symtab *sp;
            for(sp = func->nested_table->sym_table; sp < &func->nested_table->sym_table[func->nested_table->no_of_entries]; sp++)
            {
                //cout<<s<<"\n";
                //cout<<"loop\n";
                if(!sp->id.empty() && !sp->id.compare($$->dec_name))
                {

                    sp->type = *type;
                    sp->pointer_count = $2->pointer_count;
                }
            }*/
        
            if($2->pointer_count>0)
            {
                ret->pointer_count = $2->pointer_count;
                ret->type.pointer_type = "ptr";
            }
            ret->offset = current_symbol->offset;
            ret->size = size;
            ret->init_val = NULL;
        }
        //current_symbol = func->nested_table;
        current_symbol = gt;
        $$ = $2;
        //printf("function_definition -> declaration_specifiers declarator compound_statement\n");
    }

    ;
declaration_list
    :declaration	
    {
        //printf("declaration_list -> declaration\n");
    }
    |declaration_list declaration	
    {
        //printf("declaration_list -> declaration_list declaration\n");
    }
    ;



%%
void yyerror(string s) 
{
	cout << s << endl;
}





