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




































/************************************************
Name -  Anshul Choudhary (17CS10005),
        Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/

#include "ass6_17CS10005_17CS10007_translator.h"

extern Quad_Array Quad_arr;
extern symbol_table GTable;
extern symbol_table *symbol;
extern symbol_table *current_symbol;
extern type_inf *global_type;
extern int global_width;
extern vector<string> string_list;
extern int yyparse();

void Code_Generator:: handle_strings()
{
    //handle global string literals
    int g_str_count = 0;

    cout<<"\t.section\t.rodata\n";
    vector<string>::iterator it;
    for(it = string_list.begin(); it != string_list.end(); it++)
    {
        cout<<global_string_start<<g_str_count++<<":\n";
        cout<<"\t.string "<<*it<<"\n";
    }
    
}

void Code_Generator:: create_Function_Prologue()
{
    int countss=100;
    int tempppp;
    for(int i=0;i<100;i++)
        countss++;
    stack_req = ((stack_size>>4)+1)<<4; //align with word boundary

    cout<<"\t.globl\t"<<function_name<<"\n";    //create a global function
    cout<<"\t.type\t"<<function_name<<", @function\n";  //declare that the function is a function
    cout<<function_name<<":\n";
    //cout<<".cfi_startproc\n";
    cout<<"\tpushq\t%rbp\n";
    cout<<"\tmovq\t%rsp, %rbp\n";
    cout<<"\tsubq\t$"<<stack_req<<",\t%rsp\n";  //allocate stack for local variables
}

void Code_Generator:: create_Function_Epilogue()
{
    //cout << "\t" << "leave" <<endl;
    cout << "\t" << "ret"<<endl;
   // cout<<"\t.cfi_endproc\n";
    //cout << "\t.size\t"<<it->result<<",\t.-"<<it->result<<endl;
}

void Code_Generator:: handle_Globals()
{
    symtab *p;
    int i;
    for(i = 0 ; i < (&GTable)->no_of_entries; i++)
    {
        if((&GTable)->sym_table[i].id[0] != 't')
        {
            //handle chars
            if((&GTable)->sym_table[i].type.type_name.compare("char")==0)
            {
                if((&GTable)->sym_table[i].init_val == NULL)
                    cout<<"\tcomm\t"<<(&GTable)->sym_table[i].id<<",1,1\n";
                else
                {
                    cout << "\t.globl\t"<<(&GTable)->sym_table[i].id<<"\n";
                    cout << "\t.data"<<endl;
                    cout << "\t.type\t"<<(&GTable)->sym_table[i].id<<", @object"<<"\n";
                    cout << "\t.size\t"<<(&GTable)->sym_table[i].id<<", 1"<<"\n";
                    cout << (&GTable)->sym_table[i].id<< ":" << "\n";
                    cout << "\t.byte\t"<<(&GTable)->sym_table[i].init_val->int_val<<"\n";
                }
            }
        //handle int
        if((&GTable)->sym_table[i].type.type_name.compare("int")==0)
            {
                if((&GTable)->sym_table[i].init_val == NULL)
                    cout<<"\tcomm\t"<<(&GTable)->sym_table[i].id<<",4,4\n";
                else
                {
                    cout << "\t.globl\t"<<(&GTable)->sym_table[i].id<<"\n";
                    cout << "\t.data"<<endl;
                    cout << "\t.align 4"<<endl;
                    cout << "\t.type\t"<<(&GTable)->sym_table[i].id<<", @object"<<"\n";
                    cout << "\t.size\t"<<(&GTable)->sym_table[i].id<<", 4"<<"\n";
                    cout << (&GTable)->sym_table[i].id<< ":" << "\n";
                    cout << "\t.long\t"<<(&GTable)->sym_table[i].init_val->int_val<<"\n";
                }
            }

        }
     
    }
}

string Code_Generator:: generate_GOTO_Labels()
{
    string t = ".L";
    t = t + to_string(goto_label_count);
    goto_label_count++;
    return t;
}

void Code_Generator:: set_GOTO_Labels_target()
{
    int countss=100;
    int tempppp;
    for(int i=0;i<100;i++)
        countss++;
    for(vector<Quad>::iterator it = Quad_arr.arr.begin(); it != Quad_arr.arr.end(); it++)
    {
        if(it->op >= IF_LESS && it->op <= GOTO)
        {
            int backpatch_result = atoi(((*it).result).c_str());
            if(generate_goto.count(backpatch_result)==0)
            {
                string label = generate_GOTO_Labels();
                generate_goto[backpatch_result] = label;
            }
            (*it).result = generate_goto[backpatch_result];
        }
    }
}


void Code_Generator:: Map_TAC_to_Assembly()
{
    int countss=100;
    int tempppp;
    for(int i=0;i<100;i++)
        countss++;
    int arg1_binding, arg2_binding, result_binding;
    arg1_binding = arg2_binding = result_binding = 0;   //make quad argument bindings

    symtab *global_arg1, *global_arg2, *global_result;    

    symtab* curr_arg1 ;
    curr_arg1 = current_symbol->lookup(current_quad.arg_1);
    symtab* curr_arg2 ;
    curr_arg2= current_symbol->lookup(current_quad.arg_2);
    symtab* curr_result;
    curr_result = current_symbol->lookup(current_quad.result); //All are present in symbol_table, so lookup will handle it fine
    
    global_arg1 = NULL;
    global_arg2 = NULL;
    global_result = NULL;
   
    for(int j = 0; j < (&GTable)->no_of_entries; j++)
    {
        if((&GTable)->sym_table[j].id.compare(current_quad.arg_1)==0)
            global_arg1 = &((&GTable)->sym_table[j]);
        
    }
    
    for(int j = 0; j < (&GTable)->no_of_entries; j++)
    {
        if((&GTable)->sym_table[j].id.compare(current_quad.arg_2)==0)
            global_arg2 = &((&GTable)->sym_table[j]);
    }
    
    for(int j = 0; j < (&GTable)->no_of_entries; j++)
    {
        if((&GTable)->sym_table[j].id.compare(current_quad.result)==0)
            global_result = &((&GTable)->sym_table[j]);
        else 
        global_result = NULL;
    }
    
    
     

    string generator_arg1 = empty_string;
    string generator_arg2 = empty_string;
    string generator_result = empty_string;

    if(current_quad.result[0] <= '0' || current_quad.result[0] >= '9')
    {
        if(global_result == NULL)
        {
            result_binding = curr_result->offset;
            //cout<<result_binding<<"\n";
        string bind = to_string(result_binding);
            generator_result = bind + "(%rbp)";
        }
        else
            generator_result = current_quad.result;
    }
    

    if(current_quad.arg_1[0] <= '0' || current_quad.arg_1[0] >= '9')
    {
        if(global_arg1 == NULL)
        {
            arg1_binding = curr_arg1->offset;
        string bind = to_string(arg1_binding);
            generator_arg1 = bind + "(%rbp)";
            //cout<<arg1_binding<<"\n";
        }
        else
    {
        if(global_arg1->type.type_name.compare("function")==0)
        {
        func_type = 1;      //handle functions, particularly the library functions which were created
        }
        else
                {generator_arg1 = current_quad.arg_1;}
    }

    }            

        if(current_quad.arg_2[0] <= '0' || current_quad.arg_2[0] >= '9')
        {
        if(global_arg2 == NULL)
        {
            arg2_binding = curr_arg2->offset;
        string bind = to_string(arg2_binding);
            generator_arg2 = bind + "(%rbp)";
        }
        else
    {
        //cout<<"#--"<<global_arg2->type.type_name<<endl;

        generator_arg2 = current_quad.arg_2;
        
    }
            
    }            

    //start with the operations
    
    if(current_quad.op == UNARY_MINUS)
    {
        int countss=100;
        int tempppp;
        for(int i=0;i<100;i++)
            countss++;
        cout << "\t" << "movq" << "\t" <<generator_arg1<< ",\t%rax" << endl; 
        cout << "\t" << "negq\t %rax"<< endl;
        cout << "\t" << "movq" << "\t" << "%rax,\t" << generator_result << "\t"  << endl; 
    }

    else if(current_quad.op == COPY)
    {
    /*if(ptr_type == 1)
    {
        if(current_quad.arg_1[0]>='0' && current_quad.arg_1[0]<='9')
        {
            cout<<"\tmovq\t$"<<current_quad.arg_1<<",\t"<<generator_result<<"\n";
        }

        else
        {
            cout << "\t" << "movq" << "\t" <<generator_arg1 << ",\t%rax" << endl; 
            cout << "\t" << "movq" << "\t" << "%rax,\t" << generator_result << "\t"  << endl; 
        }
    
    }*/
    if(func_type==1)
    {
        //cout<<"\tmovq\t%rax,\t%rdx\n";
        cout<<"\tmovl\t%eax,\t"<<generator_result<<endl;
        func_type = 0;
        
    }
    else
    {
        if(current_quad.arg_1[0]>='0' && current_quad.arg_1[0]<='9')
        {
            cout<<"\tmovl\t$"<<current_quad.arg_1<<",\t"<<generator_result<<"\n";
        }

        else
        {
            cout<<"\tmovl\t"<<generator_arg1<<",\t%eax\n"; 
            cout<<"\tmovl\t"<<"%eax,\t"<<generator_result<<"\n"; 
        }
    }
    }

    else if(current_quad.op == PLUS)
    {
        if((current_quad.arg_2.compare("1"))==0)
        {//result = a + 1
            cout<< "\tmovl\t" <<generator_arg1<<",\t%edx\n";
            cout<< "\taddl\t$1,\t%edx\n";
            cout<< "\tmovl\t%edx,\t%eax\n";
            cout<< "\tmovl\t%eax,\t"<< generator_result<<"\n";
        }
        else
        {
            //result = a + b
            cout<<"\tmovl\t" <<generator_arg1<<",\t%edx\n";
            if(current_quad.arg_2[0]>='0' && current_quad.arg_2[0]<='9')
                cout<<"\tmovl\t$" <<current_quad.arg_2<<",\t%eax\n";
            else
                cout << "\tmovl\t" <<generator_arg2 << ",\t%eax\n";
            cout<<"\taddl\t %edx,\t%eax\n";
            cout<<"\tmovl\t %eax,\t"<<generator_result<<"\n";     
        }

    }

    else if(current_quad.op == MINUS)
    {
        if((current_quad.arg_2).compare("1")==0)
        {
        //result = a + 1
            cout << "\tmovl\t" <<generator_arg1<< ",\t%edx\n";
            cout << "\tsubl\t$1,\t %edx\n";
            cout << "\tmovl\t %edx,\t %eax\n";
            cout << "\tmovl \t %eax,\t"  << generator_result<< "\n";
        }
        else
        {
            //result = a - b

            cout<< "\tmovl\t" <<generator_arg1<< ",\t%edx\n";
            cout<< "\tmovl\t" <<generator_arg2 << ",\t%eax\n";
            cout<< "\tsubl\t%eax,\t%edx\n";
            cout<< "\tmovl\t%edx,\t%eax\n";
            cout<< "\tmovl \t%eax,\t" << generator_result<<"\n";       
        }
        int countss=100;
        int tempppp;
        for(int i=0;i<100;i++)
            countss++;

    }

    else if(current_quad.op==MULT)
    {
        
        cout<< "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        if(current_quad.arg_2[0]>='0' && current_quad.arg_2[0]<='9')
            cout<< "\timull\t$" << current_quad.arg_2 << ",%eax\n";
        else
        {
            cout<< "\timull\t" <<generator_arg2 << ",%eax\n";
        }
        cout<< "\tmovl\t%eax,\t"<< generator_result<< "\n";           
        
    }

    else if(current_quad.op==DIVIDE)
    {
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcltd\n";
        cout << "\tidivl\t"<< generator_arg2 << "\n";
        cout << "\tmovl\t%eax,\t" << generator_result<< "\n";       
        
    }
    else if(current_quad.op==MODULO)
    {
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcltd\n";
        cout << "\tidivl\t"<< generator_arg2 << "\n";
        cout << "\tmovl\t%edx,\t"  << generator_result << "\n";          
        
    }

    
    else if(current_quad.op==IF_LESS)
    {
        
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
        cout << "\tjge\t.L" << goto_label_count <<"\n";
        cout << "\tjmp\t" <<current_quad.result <<"\n";
        cout << ".L" << goto_label_count  << ":\n";
        goto_label_count = goto_label_count + 1;

    }

    else if(current_quad.op==IF_GREATER)
    {
        //  if a > b goto .L1
        cout<< "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout<< "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
    //jump on less
        cout<< "\tjle\t.L" << goto_label_count << "\n";
        cout<< "\tjmp\t" <<current_quad.result << "\n";
        cout<< ".L"<< goto_label_count  << ":\n";
        goto_label_count = goto_label_count + 1;

    }

    else if(current_quad.op==IF_IS_EQUAL)
    {
        //  if a == b goto L1
        
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
        cout << "\tjne\t.L" << goto_label_count << "\n";
        cout << "\tjmp\t" <<current_quad.result << "\n";
        cout << ".L" << goto_label_count  << ":\n";
        goto_label_count = goto_label_count + 1;

    }

    else if(current_quad.op==IF_NOT_EQUAL)
    {
        //  if a != b goto .L1
        
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
        cout << "\tje\t.L" << goto_label_count << "\n";
        cout << "\tjmp\t" <<current_quad.result << "\n";
        cout << ".L" << goto_label_count  << ":\n";
        goto_label_count = goto_label_count + 1;

    }
    
    else if(current_quad.op==IF_NOT_EXPRESSION)
    {
    //if a==0 goto .L1
        cout<< "\tcmpl\t$0,\t"<<generator_arg1<< "\n"; 
        cout<< "\tjne\t.L"<< goto_label_count<<"\n"; 
        cout<< "\tjmp\t"<<current_quad.result<<endl;
        cout<< ".L"<<goto_label_count<<" : \n";  
        goto_label_count = goto_label_count + 1;     
    }

    else if(current_quad.op==IF_EXPRESSION)
    {  
    //if a!= 0 goto .L1
        cout<< "\tcmpl\t$0,\t"<<generator_arg1<< endl; 
        cout<< "\tje\t.L"<< goto_label_count<<endl; 
        cout<< "\tjmp\t"<<current_quad.result<<endl;
        cout<< ".L" <<goto_label_count<<" : \n" ;  
        goto_label_count++;
    }

  
    else if(current_quad.op==GOTO)
    {
        //goto .L1
        cout<<"\tjmp\t" <<current_quad.result<<"\n";
    }


    else if(current_quad.op == PARAM)
    {
    //cout<<"#--"<<next_quad.result<<endl;
        if(next_quad.result.compare("printInt")==0 || next_quad.result.compare("printStr")==0 || next_quad.result.compare("readInt")==0)
    {
        if(current_quad.result[0]=='.')
        {
        cout<<"\tmovq\t$"<<current_quad.result<<",\t%rdi\n";
        }
        else if(current_quad.result[0]>='0' && current_quad.result[0]<='9')
                cout<<"\tmovq\t$"<<current_quad.result<<",\t%rdi\n";
            else
                cout<<"\tmovq\t"<<generator_result<<",\t%rdi\n";
            no_of_params++;
    }
    else
    {
         string s;
             std::vector<string> str1;
         int flag = 0;

             if(current_quad.result[0]>='0' && current_quad.result[0]<='9')
             {
                s = s + "\tmovq\t$" + current_quad.result + ",\t%rax\n";
             }
             else{
         flag = 0;
         for(int i=0;i<new_sym->no_of_entries;i++)
         {
             if(current_quad.result.compare(new_sym->sym_table[i].id)==0 && new_sym->sym_table[i].type.array_type.compare("array")==0)
             {
            //flag = 0;
                if(result_binding>0)
                {s = s + "\tmovq\t" + generator_result + ",\t%rax\n";flag = 1;}
            else
                {s = s + "\tleaq\t" + generator_result + ",\t%rax\n";flag = 1;}
             }
              
            //s = s + "\tmovq\t" + generator_result + ",\t%rax\n";
         }
         if(flag == 0)
                    s = s + "\tmovq\t" + generator_result + ",\t%rax\n";
             str1.push_back(s);
             str1.push_back("\tpushq\t%rax\n");
             stack_of_parameters.push(str1);
      
        }
    }
    }

    else if(current_quad.op==CALL)
    {
    if(current_quad.result.compare("printInt")==0 || current_quad.result.compare("printStr")==0 || current_quad.result.compare("readInt")==0)
    {
       int num;
           num = atoi((current_quad.arg_1).c_str());
           num=num*4;
           cout << "\t" << "call\t"<<current_quad.result << endl;
           //cout << "\t" << "addq\t$"<<num<<",\t%rsp"<< endl;
           if(current_quad.arg_2 != "")
               cout << "\t" << "movq\t%rax,\t"<<generator_arg2<< endl;

    }
    else{
    int num;
        num = atoi((current_quad.arg_1).c_str());
        num=num*8;
        while(stack_of_parameters.size() > 0)
        {
            vector<string> str; 
            str = stack_of_parameters.top();
            for(int i = 0; i<str.size(); i++)
            {
                cout<<str[i];
            }
        stack_of_parameters.pop();    //pop from stack
        }
        
        cout << "\tcall\t"<<current_quad.result << "\n";
        cout << "\taddq\t$"<<num<<",\t%rsp"<< "\n";
    cout<<"#--"<<current_quad.arg_2<<"\n";
          //          cout << "\t" << "movq\t%rax,\t"<<generator_arg2<< endl;
    }

    }

    else if(current_quad.op==RETURN)
    {
        if(current_quad.result.compare(empty_string)!=0)
            cout<<"\tmovq\t"<<generator_result<< ",\t%rax"<< endl;
    cout <<"\tleave\n\tret\n";
        //function_name = empty_string;
    no_of_params = 0;
      /*  memory = 16;
        memory_bind_ebp = 0;*/
            
    }

    else if(current_quad.op==DEREFERENCE)
    {
        // a = *p
        cout<<"\tmovq\t"<<generator_arg1<<",\t%rax\n";
        cout<<"\tmovl\t(%rax),\t %ecx\n";
        cout<<"\tmovl\t%ecx,\t"<<generator_result<<"\n";
    }

    else if(current_quad.op==REFERENCE)
    {
        //p = &a
        cout<<"\tleaq\t"<<generator_arg1<<",\t%rax\n";
        cout<<"\tmovq\t%rax,\t"<<generator_result<<"\n";
    }


    
    else if(current_quad.op==ARRAY_ACCESS)
    {
        //b = a[i]
    if(arg1_binding>0)      //required for passing array as parameters
    {
        cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx\n";
        cout<<"\tmovq\t"<<arg1_binding<<"(%rbp),\t%rdi\n";
        cout<<"\taddq\t%rdi,\t%rdx\n";
        cout<<"\tmovl\t(%rdx),\t%eax\n";
        cout<<"\tmovl\t%eax,\t"<<generator_result<<"\n";
    }
    else
    {
        cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx"<< endl;
        cout<<"\tmovl\t"<<arg1_binding<<"(%rbp,%rdx,1),\t%eax\n";
        cout<<"\tmovl\t%eax,\t"<<generator_result<<"\n";
    } 
    }

    else if(current_quad.op==ARRAY_DEREFERENCE)
    {
        //a[i] = b
    if(result_binding>0)        //required for passing array as parameters
    {
        cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx\n";
        cout<<"\tmovl\t"<<generator_arg1<<",\t%eax\n";
        cout<<"\tmovq\t"<<result_binding<<"(%rbp),\t%rdi\n";
        cout<<"\taddq\t%rdi,\t%rdx\n";
        
        cout<<"\tmovl\t%eax,\t(%rdx)\n";
    }
    else{
        cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx\n";
        cout<<"\tmovslq\t"<<generator_arg1<<",\t%rax\n";
        cout<<"\tmovq\t%rax,\t"<<result_binding<<"(%rbp,%rdx,1)\n";}
    }

    

}

void Code_Generator:: Bind_Memory_Record()
{
    
    handle_strings();
    handle_Globals();
    set_GOTO_Labels_target();

    int quad_size = Quad_arr.arr.size();
    for(int i = 0; i < quad_size; i++)
    {
    //print the quads for reference
    cout<<"  # "; Quad_arr.arr[i].print();
        
        if(generate_goto.count(i)>0)
        {
            cout<<generate_goto[i]<<":\n";
        }
        current_quad = Quad_arr.arr[i];    //update current quad
    if(i<quad_size-1)
        next_quad = Quad_arr.arr[i+1]; //update next quad
        //cout<<current_quad.arg_1<<"\n";
        if(Quad_arr.arr[i].op == _FUNCTION_START)
        {
            if(Quad_arr.arr[i+1].op != _FUNCTION_END)
            {
        ptr_type=0;
                symtab *p=NULL;
                for(int j = 0; j < (&GTable)->no_of_entries; j++)
                {
                    //cout<<j<<": ";
                    //cout<<(&GTable)->sym_table[j].id<<"\n";
                    if(((&GTable)->sym_table[j].id).compare(Quad_arr.arr[i].result)==0)
                        p = &((&GTable)->sym_table[j]);
                }
                
                function_name = Quad_arr.arr[i].result;
                row = p;
        
                //new_sym = current_symbol;
                //if(p!=NULL)
                new_sym = p->nested_table;
                current_symbol = new_sym;
                flag_parameter = 1;
                int total_count; 
                total_count =  row->type.no_of_params;
                //if (p==NULL)
                //    cout<<"1\n";
        for(int j = 0; j < total_count; j++)
        {
            new_sym->sym_table[j].offset = memory;
            memory = memory + 8;
            cout<<"#--param_offset:"<<memory<<"\n";
        }
        //cout<<"#--total:"<<total_count<<"\n";
        memory_bind_ebp = 0;
                for(int j = total_count; j < new_sym->no_of_entries; j++)
                {
            if(new_sym->sym_table[j].id.compare("retVal")==0)
            {
            //new_sym->sym_table[j].size = 4;
            }
                    if(new_sym->sym_table[j].id.compare("retVal"))
                    {
                        memory_bind_ebp = memory_bind_ebp - new_sym->sym_table[j].size;
                        new_sym->sym_table[j].offset = memory_bind_ebp;
            cout<<"#--loacl var offset: "<<new_sym->sym_table[j].size<<" "<<new_sym->sym_table[j].offset<<"\n";
                    }
                }
                cout<<"#"<<memory_bind_ebp<<endl;
                stack_size = memory_bind_ebp*(-1) + memory;
        for(int j = 0; j< new_sym->no_of_entries; j++)
        {
            if(new_sym->sym_table[j].id.compare(current_quad.result)==0||!new_sym->sym_table[j].id.compare(current_quad.arg_1)==0
                       ||!new_sym->sym_table[j].id.compare(current_quad.arg_2)==0)
            {
                if(new_sym->sym_table[j].type.pointer_type.compare("ptr")==0)
                    ptr_type = 1;
                cout<<"##ptr"<<new_sym->sym_table[j].id<<endl;
            }
        }
                create_Function_Prologue();
            }
            else
            {
                i++;
        no_of_params = 0;
        memory = 16;
        memory_bind_ebp = 0;
                continue;
            }
        }
        else if(Quad_arr.arr[i].op == _FUNCTION_END)
        {
            symbol = &GTable;
            current_symbol = &GTable;
        cout<<"\tleave\n\tret\n";
            cout << "\t.size\t"<<function_name<<",\t.-"<<function_name<<endl;
        function_name = "";
            no_of_params = 0;
        memory = 16;
        memory_bind_ebp = 0;
        continue;
        }

        if(function_name.compare(empty_string))
        {
            Map_TAC_to_Assembly();
        }

    }
}


int main(int argc, char *argv[])
{   
    int countss=100;
    int tempppp;
    for(int i=0;i<100;i++)
        countss++;
    bool failure = yyparse();
    int arr_size = Quad_arr.arr.size();
    
    string output_file = "a.out";
    if(argc==2) output_file = string(argv[1]);
    string quad_file = "ass6_17CS10005_17CS10007_quads" + output_file + ".out";
    ofstream outf1(quad_file.c_str());
    streambuf *coutbuf1 = cout.rdbuf();
    cout.rdbuf(outf1.rdbuf());
    
    //freopen(argv[2],"w",stdout);
    cout<<"********************Here are all Quads**********************\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"*********************Quads******************************\n";
    for(int i = 0; i<arr_size;i++)
    {
        cout<<i<<" : "; 
        Quad_arr.arr[i].print();
    }

    cout<<"\n----------------SYMBOL TABLE (ST.gbl)-----------------------\n";
    symbol_table *g = &GTable;
    g->print();
    cout<<"----------------------------------------------------\n";
    //cout<<g->no_of_entries<<endl;

    for(int i = 0; i< g->no_of_entries; i++)
    {
        if(g->sym_table[i].nested_table != NULL)
        {
            cout<<"----------------SYMBOL TABLE of "<<g->sym_table[i].id<<"----------------"<<endl;
            g->sym_table[i].nested_table->print();
            cout<<"--------------------------------------------"<<endl;
        }
    }
    cout<<"----------------Compilation Result------------------\n";
    if(failure != 0)
        printf("Compilation Failure\n");
    else
        printf("Compilation Success\n");
    cout<<"*****************************************************\n";
    
    cout.rdbuf(coutbuf1);

    string tmp = "ass6_17CS10005_17CS10007_" + output_file + ".s";
    ofstream outfile(tmp.c_str());
    streambuf *coutbuf = cout.rdbuf();
    cout.rdbuf(outfile.rdbuf());
    current_symbol = symbol;
    Code_Generator c;
    c.Bind_Memory_Record();
    
    cout.rdbuf(coutbuf);
    return 0;

}
















































'



/************************************************
Name -  Anshul Choudhary (17CS10005),
        Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/

#include "ass6_17CS10005_17CS10007_translator.h"
void Quad :: print()
{
    if(op >= PLUS && op <=GREATER_EQUAL)
    {
        if(result.compare("")==1)
            cout<<result<<" = "<<arg_1;
        else 
            cout<<arg_1;
        switch(op)
        {
            case PLUS: 
                cout<<"+"; 
                break;
            case MINUS: 
                cout<<"-"; 
                break;
            case MULT: 
                cout<<"*"; 
                break;
            case DIVIDE: 
                cout<<"/"; 
                break;
            case AND: 
                cout<<"&"; 
                break;
            case MODULO: 
                cout<<"%"; 
                break;
            case SHIFT_LEFT: 
                cout<<"<<"; 
                break;
            case SHIFT_RIGHT: 
                cout<<">>"; 
                break;
            case XOR: 
                cout<<"^"; 
                break;
            case OR: 
                cout<<"|"; 
                break;
            case LOGICAL_AND: 
                cout<<"&&"; 
                break;
            case LOGICAL_OR: 
                cout<<"||"; 
                break;
            case LESS: 
                cout<<"<"; 
                break;
            case GREATER: 
                cout<<">"; 
                break;
            case IS_EQUAL: 
                cout<<"=="; 
                break;
            case NOT_EQUAL: 
                cout<<"!="; 
                break;
            case LESS_EQUAL: 
                cout<<"<="; 
                break;
            case GREATER_EQUAL: 
                cout<<">="; 
                break;
        }
        cout<<arg_2<<"\n";
    }
    else if(op >= UNARY_PLUS && op <=NOT)
    {
        cout<<result<<" = ";
        switch(op)
        {
            case UNARY_PLUS:
                cout<<"+";
                break;
            case UNARY_MINUS:
                cout<<"-";
                break;
            case COMPLEMENT:
                cout<<"~";
                break;
            case NOT:
                cout<<"!";
                break; 
        }
        cout<<arg_1<<"\n";
    }
    else if(op >= IF_LESS && op <= IF_NOT_EXPRESSION)
    {
        cout<<"if "<<arg_1<<" ";
        switch(op)
        {
            case IF_LESS:
                cout<<"<";
                break;

            case IF_GREATER:
                cout<<">";
                break;
            case IF_LESS_EQUAL:
                cout<<"<=";
                break;
            case IF_GREATER_EQUAL:
                cout<<">=";
                break;
            case IF_IS_EQUAL:
                cout<<"==";
                break;
            case IF_NOT_EQUAL:
                cout<<"!=";
                break;
            case IF_EXPRESSION:
                cout<<"!= 0";
                break;
            case IF_NOT_EXPRESSION:
                cout<<"== 0";
                break;
        }
        cout<<arg_2<<" goto "<<result<<"\n";
    }
    else if(op == GOTO)
    {
        cout<<"goto "<<result<<"\n";
    }
    else if (op == COPY)
    {
        cout<<result<<" = "<<arg_1<<"\n";
    }
    else if (op == ARRAY_ACCESS)
    {
        cout<<result<<" = "<<arg_1<<"["<<arg_2<<"]\n";
    }
    else if (op == ARRAY_DEREFERENCE)
    {
        cout<<result<<"["<<arg_2<<"] = "<<arg_1<<"\n";
    }
    else if (op == REFERENCE)
    {
        cout<<result<<"= &"<<arg_1<<"\n";
    }
    else if (op == DEREFERENCE)
    {
        cout<<result<<"= *"<<arg_1<<"\n";
    }
    else if(op == CALL)
    {
        cout<<"call "<<result<<" "<<arg_1<<"\n";
    }
    else if (op == PARAM)
    {
        cout<<"param "<<result<<"\n";
    }
    else if (op == RETURN)
    {
        cout<<"return "<<result<<"\n";
    }
    else if (op == RETURN_VOID)
    {
        cout<<"return\n";
    }
    else if (op >= C2I && op <= D2I)
    {
        cout<<result<<" = ";
        switch(op)
        {
            case C2I : 
                cout<<" Char2Int(" <<arg_1<<")" <<endl; 
                break;
            case C2D : 
                cout<<" Char2Double(" <<arg_1<<")" <<endl; 
                break;
            case I2C : 
                cout<<" Int2Char("<<arg_1<<")"<<endl; 
                break;
            case D2C : 
                cout<<" Double2Char("<<arg_1<<")"<<endl; 
                break;
            case I2D : 
                cout<<" Int2Double("<<arg_1<<")"<<endl; 
                break;
            case D2I : 
                cout<<" Double2Int("<<arg_1<<")"<<endl; 
                break;
        }
    }
    else if (op == _FUNCTION_START)
    {
        cout<<"function "<<result<<" start\n";
    }
    else if (op == _FUNCTION_END)
    {
        cout<<"function "<<result<<" end\n";
    }
}

void Quad_Array :: emit(opcodeType op, string result, double double_num)
{
    Quad q;
    q.op = op;
    q.result = result;
    string s = to_string(double_num);
    q.arg_1 = s;
    arr.push_back(q);
    index++;
}

void Quad_Array :: emit(opcodeType op, string result, char char_const)
{
    Quad q;
    q.op = op;
    q.result = result;
    string s = "";
    s = s + char_const;
    q.arg_1 = s;
    arr.push_back(q);
    index++;
}

void Quad_Array :: emit(opcodeType op, string result, string arg_1, string arg_2)
{
    Quad q;
    q.op = op;
    q.result = result;
    q.arg_1 = arg_1;    //check these
    q.arg_2 = arg_2;
    arr.push_back(q);
    index++;
}

void Quad_Array :: emit(opcodeType op, string result, int num)
{
    Quad q;
    q.op = op;
    q.result = result;
    string s = to_string(num);
    q.arg_1 = s;
    arr.push_back(q);
    index++;
}

void Quad_Array :: backpatch(list<int> bp_list, int i)
{
    string s = to_string(i);
    list<int>::iterator it;
    for(it = bp_list.begin(); it != bp_list.end(); it++)
    {
        arr[*it].result = s; 
    }
}

//type conversions
void Quad_Array :: convert_Int_to_Dbl(expression_attribute * e1, expression_attribute *e2)
{
    int countss=100;
    for(int posss=1;posss<=10;posss++)
        countss--;
    if(e2->type.type_name.compare("double")==0)
        return;
    else
    {
        e1 = e2;
        e1->type.type_name = "double";
        emit(I2D, e1->loc, e2->loc, "");
    }
}

void Quad_Array :: convert_Int_to_Char(expression_attribute * e1, expression_attribute *e2)
{
    if(e2->type.type_name.compare("char")==0)
        return;
    else
    {
        e1 = e2;
        e1->type.type_name = "char";
        emit(I2C, e1->loc, e2->loc, "");
    }
}

void Quad_Array :: convert_Dbl_to_Int(expression_attribute * e1, expression_attribute *e2)
{
    int countss=100;
    for(int posss=1;posss<=10;posss++)
        countss--;
    if(e2->type.type_name.compare("int")==0)
        return;
    else
    {
        e1 = e2;
        e1->type.type_name = "int";
        emit(D2I, e1->loc, e2->loc, "");
    }
}

void Quad_Array :: convert_Dbl_to_Char(expression_attribute * e1, expression_attribute *e2)
{
    int countss=100;
    for(int posss=1;posss<=10;posss++)
        countss--;
    if(e2->type.type_name.compare("char")==0)
        return;
    else
    {
        e1 = e2;
        e1->type.type_name = "char";
        emit(D2C, e1->loc, e2->loc, "");
    }
}


void Quad_Array :: convert_Char_to_Dbl(expression_attribute * e1, expression_attribute *e2)
{
    int countss=100;
    for(int posss=1;posss<=10;posss++)
        countss--;
    if(e2->type.type_name.compare("double")==0)
        return;
    else
    {
        e1 = e2;
        e1->type.type_name = "double";
        emit(C2D, e1->loc, e2->loc, "");
    }
}

void Quad_Array :: convert_Char_to_Int(expression_attribute * e1, expression_attribute *e2)
{
    int countss=100;
    for(int posss=1;posss<=10;posss++)
        countss--;
    if(e2->type.type_name.compare("int")==0)
        return;
    else
    {
        e1 = e2;
        e1->type.type_name = "int";
        emit(C2I, e1->loc, e2->loc, "");
    }
}


void Quad_Array :: convInt2Bool(expression_attribute *exp)
{
    long long int pxx,qxxx;
    type_inf bool_type;
    bool_type.type_name = "bool";
    if(exp->type.type_name.compare("bool")==0)
        return;
    else
    {
        backpatch(exp->truelist, index);
        backpatch(exp->falselist,index);
        exp->falselist = makelist(index);
        emit(IF_NOT_EXPRESSION,"",exp->loc,"");
        //emit(COPY, exp->loc, "~1","");
        exp->truelist = makelist(index);
        emit(GOTO,"","","");
    }
    exp->type.type_name = "bool";

}


symtab* symbol_table :: lookup(string s, string type, int pc)
{
    symtab *sp;
    for(sp = sym_table; sp < &sym_table[MAX]; sp++)
    {
        //cout<<s<<"\n";
        if(!sp->id.empty() && !sp->id.compare(s))
        {
            return sp;
        }
        if(sp->id.empty())
        {
            sp = new symtab;
            sp->id = s;
            //include type
            type_inf t;
            
            t.type_name = type;
            int t_size = 0;
            if(pc == 0)
            {
                if(type.compare("int") == 0)
                    t_size = 4;
                else if(type.compare("double") == 0)
                    t_size = 8;
                else if(type.compare("char") == 0)
                    t_size = 1;
                else if(type.compare("function")==0 || type.compare("void")==0)
                    t_size = 0;
                t.size = t_size;
                sp->type = t;
                sp->size = t_size;
                sp->offset = offset;
                sp->init_val = NULL;
                offset = offset + t_size;
                
                sym_table[no_of_entries] = *sp;
                no_of_entries++;
                break;
            }
            else if(pc>0)
            {
                sp->size = 8;
                sp->type.type_name = type;
                cout<<type<<"\n";
                sp->pointer_count = pc;
                sp->offset = offset;
                sp->init_val = NULL;
                
                offset = offset + 8;
                sym_table[no_of_entries] = *sp;
                no_of_entries++;
                break;
            }
            int countss=100;
            for(int posss=1;posss<=10;posss++)
                countss--;          
        }
    }
    return sp;
}

void symbol_table:: print()
{
    int countss=100;
    for(int posss=1;posss<=10;posss++)
        countss--;
    int i;
    cout<<"Name\tType\tSize\tOffset\tInitVal\n";
    cout<<"---------------------------------------\n";
    for(i=0;i<no_of_entries;i++)
    {
        int flag = 0;
        cout<<sym_table[i].id<<"\t";
        if(sym_table[i].pointer_count == 0 && sym_table[i].type.array_type.compare("array")!=0)
        {
            if(sym_table[i].type.type_name.compare("int")==0)
                cout<<"int\t";
            else if(sym_table[i].type.type_name.compare("char")==0)
                cout<<"char\t";
            else if(sym_table[i].type.type_name.compare("double")==0)
                cout<<"double\t";
            else if(sym_table[i].type.type_name.compare("void")==0)
                cout<<"void\t";
            else if(sym_table[i].type.type_name.compare("function")==0)
                {cout<<"function\t";cout<<sym_table[i].type.no_of_params<<"\t";}
        }
        else if(sym_table[i].type.pointer_type.compare("ptr")==0)
        {
            sym_table[i].size = 8;
            //cout<<sym_table[i].type.type_name<<" ";
            for (int j = 0; j < sym_table[i].pointer_count; ++j)
            {
                cout<<"*";
            }
            cout<<"\t";
        }
        
        else if(sym_table[i].type.array_type.compare("array")==0)
        {
            cout<<sym_table[i].type.type_name;
            //cout<<"array:";cout<<sym_table[i].type.type_name<<" ";
            if(sym_table[i].type.idx!=0 && sym_table[i].type.type_name!="")
                {cout<<" ["<<sym_table[i].type.idx<<"]";flag = 1;}
            else
                for (int j = 0; j < sym_table[i].type.array_list.size(); ++j)
                {
                    cout<<"["<<sym_table[i].type.array_list[j]<<"]";
                }
            cout<<"\t";
        }
        if(flag==1) 
            {cout<<"\t"<<sym_table[i].size*sym_table[i].type.idx<<"\t";sym_table[i].size = sym_table[i].size*sym_table[i].type.idx;}
        if(flag==0)
            cout<<"\t"<<sym_table[i].size<<"\t";
                if(i>=1)
            sym_table[i].offset = sym_table[i-1].offset + sym_table[i-1].size;
        cout<<sym_table[i].offset<<"\t";

        if(sym_table[i].init_val == NULL)
            cout<<"NULL";
        else
        {
            if(sym_table[i].type.type_name.compare("int")==0)
            {
                cout<<sym_table[i].init_val->int_val;
            }
            if(sym_table[i].type.type_name.compare("char")==0)
            {
                cout<<sym_table[i].init_val->char_val;
            }
            if(sym_table[i].type.type_name.compare("double")==0)
            {
                cout<<sym_table[i].init_val->double_val;
            }
        }
        cout<<"\n";
        int countss=100;
        for(int posss=1;posss<=10;posss++)
            countss--;  
    }
}

string symbol_table :: gentemp(type_inf type)
{
    //maintain counts generated
    static int temporary_count = 0;
    string s = "t";
    s = s + to_string(temporary_count);
    temporary_count++;

    sym_table[no_of_entries].id = s;
    //type
    sym_table[no_of_entries].type = type;
    //size
    int t_size = 0;
    if(type.type_name.compare("int") == 0)
        t_size = 4;
    else if(type.type_name.compare("double") == 0)
        t_size = 8;
    else if(type.type_name.compare("char") == 0)
        t_size = 1;
    else if(type.type_name.compare("function")==0 || type.type_name.compare("void")==0)
        t_size = 0;
    if(type.pointer_type.compare("ptr")==0)
    {
        t_size = 8;
    }
    sym_table[no_of_entries].size = t_size;
    //initial value
    sym_table[no_of_entries].init_val = NULL;
    //offset
    sym_table[no_of_entries].offset = offset;
    sym_table[no_of_entries].nested_table = NULL;
    offset = offset + t_size;
    
    int countss=100;
    for(int posss=1;posss<=10;posss++)
        countss--;
    no_of_entries++;
    return s;
}


list<int> makelist(int index)
{
    list<int> temp;
    temp.push_back(index);
    int countss=100;
    for(int posss=1;posss<=10;posss++)
        countss--;
    return temp;
}

list<int> merge(list<int> a, list<int> b)
{
    list<int> temp;
    temp.merge(a);
    temp.merge(b);
    int countss=100;
    for(int posss=1;posss<=10;posss++)
        countss--;
    return temp;
}










































/************************************************
Name -  Anshul Choudhary (17CS10005),
        Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/


#ifndef __ASS6_17CS10005_17CS10007_TRANSLATOR_H
#define __ASS6_17CS10005_17CS10007_TRANSLATOR_H
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <list>
#include <map>
using namespace std;



#define MAX 100000
#define DSP 100000
enum opcodeType{

    PLUS = 1,
    GREATER,
    IS_EQUAL,
    MULT,
    SHIFT_LEFT,
    AND,
    LESS,
    XOR,
    DIVIDE,
    LOGICAL_OR,
    MINUS,
    OR,
    MODULO,
    SHIFT_RIGHT,
    GREATER_EQUAL,
    LOGICAL_AND,
    NOT_EQUAL,
    LESS_EQUAL,

    //unary operators.
    UNARY_PLUS,
    UNARY_MINUS,
    COMPLEMENT,
    NOT,

    //Conditional jump operators.
    IF_NOT_EQUAL,
    IF_LESS,
    IF_LESS_EQUAL,
    IF_GREATER,
    IF_EXPRESSION,
    IF_IS_EQUAL,
    IF_GREATER_EQUAL,
    IF_NOT_EXPRESSION,

    //Unconditional jump.
    GOTO,

    //Array Access and Dereferencing.
    ARRAY_ACCESS,
    ARRAY_DEREFERENCE,

    //Procedure Call.
    CALL,
    PARAM,

    //Return Value
    RETURN_VOID,
    RETURN,

    //assignment operator.
    COPY,

    //Address and Pointer Assignment Instructions.
    REFERENCE,
    DEREFERENCE,
    POINTER_ASSIGN,

    //Function opcodes.
    _FUNCTION_START,
    _FUNCTION_END,

    //Inc and Dec operators.
    _INCREMENT,
    _DECREMENT,

    //type conversion
    C2I,
    I2C,
    D2C,
    I2D,
    D2I,
    C2D

    
};

class Quad;
class expression_attribute;
class Quad_Array;
class Quad
{
public:
    opcodeType op;
    string arg_1, arg_2, result;
    void print();
};

class Quad_Array
{
public:
    //create an array of Quads
    vector<Quad> arr;
    //global pointer to maintain quad array index
    int index;
    //constructor, initialises array of quads to 0
    Quad_Array(){ index = 0; }

    //overloaded emits
    void emit(opcodeType op, string result, string arg_1, string arg_2 = 0);
    void emit(opcodeType op, string result, int num);
    void emit(opcodeType op, string result, double double_num);
    void emit(opcodeType op, string result, char char_const);

    void convert_Int_to_Dbl(expression_attribute *e1, expression_attribute *e2);
    void convert_Int_to_Char(expression_attribute *e1, expression_attribute *e2);
    void convert_Char_to_Int(expression_attribute *e1, expression_attribute *e2);
    void convert_Dbl_to_Int(expression_attribute *e1, expression_attribute *e2);
    void convert_Dbl_to_Char(expression_attribute *e1, expression_attribute *e2);
    void convert_Char_to_Dbl(expression_attribute *e1, expression_attribute *e2);
    
    //function responsible for backpatch
    void backpatch(list<int> bp_list, int i);
    void convInt2Bool(expression_attribute *e);
    

    
};


typedef union init{
    int int_val;
    double double_val;
    char char_val;
    //string string_lit;
}init_value;


//struct that updates the type information for each new type 
typedef struct type_inf
{
    string type_name;
    int size;
    int pointer_count;
    string pointer_type;
    string array_type;
    int no_of_params;
    int idx;
    vector<int> array_list;
    struct type_inf *next;
}type_inf;

class symbol_table;
//structure defines the fields of each row of the symbol_table
typedef struct symtab
{
    string id;
    type_inf type;
    int num_of_params;
    init_value *init_val;
    int size;
    int offset;
    int pointer_count;
    symbol_table *nested_table;
}symtab;

//full symbol table
class symbol_table
{
public:
    symtab sym_table[MAX];
    int no_of_entries;
    int offset;

    symbol_table() 
    {
        for(int i=0; i<MAX; i++)
            sym_table[i].nested_table = NULL;
        no_of_entries = 0;
        offset = 0;
    }

    symtab* lookup(string s, string type_nm = "int" , int pc = 0);
    string gentemp(type_inf type);
    void print();
    //void update(symtab* symbol);
};


//structure for maintaining function parameter definitions
typedef struct func_param_def
{
    string param_name;
    type_inf *type;
}function_definition;

//structure fo maintaining list of parameters
typedef struct func_param_list
{
    list<function_definition*> func_def_list;
}function_list;

//exp attribute for each non-terminal exp and statements
class expression_attribute
{
public:
    string loc;
    type_inf type;
    bool is_pointer_type;
    int dim ;
    string *inner;
    list<int> truelist, falselist, nextlist;
    int instr;
    
    expression_attribute()
    {
        dim = 0;
        inner = NULL;
        nextlist = list<int>();
    }
    int is_array_id;
};

class declaration
{
public:
    expression_attribute *init;
    string dec_name;
    type_inf *type;
    function_list *param_list;
    vector<int> alist;
    int pointer_count;
};


typedef struct init_decl_list
{
    list<declaration*> declaration_list;
}init_declration_list;

list<int> makelist(int index);
list<int> merge(list<int> a, list<int> b);


class Code_Generator
{
public:
    map<int, string> generate_goto;
    Quad current_quad;
    int goto_label_count;
    int func_type;
    int func_type_r;
    string function_name;
    string global_string_start;
    int flag_parameter;
    int ptr_type;
    string empty_string;
    int array_param ;
    stack<vector<string> > stack_of_parameters;
    int memory;
    symtab *row;
    int stack_size;
    int stack_req;
    int memory_bind_ebp;
    symbol_table *new_sym;
    int no_of_params;
    Quad next_quad;
    //string func_name;
    Code_Generator()
    {
        stack_size = 0;
        no_of_params = 0;
        memory_bind_ebp = 0;
        func_type = 0;
        global_string_start = ".LC";
        ptr_type = 0;
        function_name = "";
        goto_label_count = 0;
        empty_string = "";
        new_sym = NULL;
        memory = 16;
        row = NULL;
        func_type_r = 0;
        array_param = 0;

    }
    void Map_TAC_to_Assembly();
    void Bind_Memory_Record();
    void handle_strings();
    void create_Function_Epilogue();
    void create_Function_Prologue();
    void set_GOTO_Labels_target();
    string generate_GOTO_Labels();
    void handle_Globals();
};

 
#endif 
