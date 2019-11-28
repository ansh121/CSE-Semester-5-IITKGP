/*
Name:- Anshul Choudhary
Roll No:- 17CS10005

Name:- Ayush Kumar
Roll No:- 17CS10007

Compilers Assignment 5
*/

#ifndef TRANSLATOR_H
#define TRANSLATOR_H
 
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <stack>
#define NSYM 100

extern FILE* yyin;
extern FILE* yyout;
extern int yylex();
extern int yyparse();
extern char* yytext;

using namespace std;

typedef enum{        
	PLUS=1,
	SUB,	
	DIV,
	MULT,
	UMINUS,
	COPY,
	PLUSPLUS,
	MINUSMINUS,
	NEG,
	NT,
	REM,
	LEFTSHIFT,
	RIGHTSHIFT,
	LESSTHAN,
	GREATERTHAN,
	LESSTHANEQUAL,
	GREATERTHANEQUAL,
	ISEQUAL,
	NOTEQUAL,
	XOR,
	BITOR,
	BITAND,
	QUESTIONMARK,
	COLN,
	ASSIGNMENT,
	LOGICALOR,
	LOGICALAND,
	_GOTO,
	FUNC,
	PARAM,
	_RETURN,
	ARRAY,
}OpcodeType;

struct SymNode;
struct SymTab;
struct list;

typedef struct Value{			// flag=0 =>void
	int ival;					// flag=1 => int
	double dval;				// flag=2 => double					
	string str;					// flag=3 => char	
	void* ptr;			   		// flag=4 => function			
	int flag;				  	// flag=5 => void*
}Value; 					    					

typedef struct SymNode{ 			// Entry to symbol table 
	string name;					// Variable name
	string type;					// variable type 
	Value value; 					// value of variable
	int size,offset;				// size of variable and its offset
	struct SymTab *next;			// next symbol table (functions) 
	struct list* truelist,*falselist;
	struct list* arglist; 		// To the list of array indices in array type with pointer level at the beginning of the list
}SymNode;

typedef struct SymTab{ 				// symbol table
	int count;						// no of entries to the SymTab 
	SymNode symbol[NSYM]; 			// entry to synbol table
}SymTab;

typedef struct list{
	int index;
	struct list* next;
}List;

typedef struct quad{
	OpcodeType op;
	string arg1,arg2,result;
}quad;

typedef struct IdList{ 			
	SymNode* id;
	struct IdList* next;
}IdList;

typedef struct ParamList{      
	string type;
	string name;
	struct ParamList* next;
}ParamList;

extern quad qArray[256];       
extern int noTemp;				// noTemp= no. of temporaries
extern int nextinstr; 			// Index of nextinstruction
extern SymTab* currentTab;      
extern SymTab* globalTab;

SymTab* newTable();
SymNode* lookup(SymTab*,string);
SymNode* gentemp(SymTab*);
void update(SymTab*,SymNode*,string);
void printSymTab(SymTab);
void emit(string,OpcodeType,string c="",string s="");
void printquad(quad);
List* makelist(int);
List* merge(List*,List*);
void backpatch(List*,int);
void typecheck(SymNode*,SymNode*);
SymNode* convert(string,SymNode*);
IdList* makelist(SymNode*);
IdList* merge(IdList*,IdList*);
ParamList* makelist(string,string);
ParamList* merge(ParamList*,ParamList*);
void convInt2Bool(SymNode*);
#endif
