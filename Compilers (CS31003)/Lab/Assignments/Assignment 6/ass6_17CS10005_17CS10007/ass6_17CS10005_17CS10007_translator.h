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
