/*
Name:- Anshul Choudhary
Roll:- 17CS10005

Name:- Ayush Kumar
Roll No:- 17CS10007

Compilers Assignment 5
*/

#include "ass5_17CS10007_17CS10005_translator.h"
#include "y.tab.h"


SymTab* newTable(){
	return new SymTab;
}

SymNode* lookup(SymTab* st,string name){
	int i;
	for(i=0;i<st->count;i++)
		if(st->symbol[i].name==name)
			return &(st->symbol[i]);
	for(i=0;i<globalTab->count;i++)
		if(globalTab->symbol[i].name==name)
			return &(globalTab->symbol[i]);
	st->symbol[st->count].name=name;
	st->count = st->count + 1;
	return &(st->symbol[st->count-1]);
}


SymNode* gentemp(SymTab* st){
	char temp[20];
    sprintf(temp,"t%d",noTemp++);
	return lookup(st,temp);
}

void update(SymTab* st,SymNode* sp,string type){
	if(!type.empty()){
		sp->type=type;
		if(sp->arglist!=NULL){
			if(sp->arglist->index==0)
				sp->size=4;	
		}
		else if(type=="int")
			sp->size=4;
		else if(type=="double")
			sp->size=8;
		else if(type=="char") 
			sp->size=1;
		else if(type=="void")
			sp->size=0;
		else if(type=="function")
			sp->size=0;
	}
}

void printSymTab(){
	int i,j;
	SymTab sp;
	printf("%5s %50s %15s %5s %7s %15s\n\n","NAME","TYPE","INITIAL VALUE","SIZE","OFFSET","NEXT TABLE");
	printf("GlobalTable\n");
	for(j=0;j<globalTab->count;j++){
		if(globalTab->symbol[j].arglist==NULL)
			printf("%5s %50s %15s %5d %7d %15p\n",globalTab->symbol[j].name.c_str(),globalTab->symbol[j].type.c_str(),"NULL",globalTab->symbol[j].size,globalTab->symbol[j].offset,globalTab->symbol[j].next);
		else{
			string str,str_end=globalTab->symbol[j].type;
			List* temp=globalTab->symbol[j].arglist;
			while(temp!=NULL){
				if(temp->index==0)
					str+="ptr(";
				else{
					char t[20];
					sprintf(t,"%d",temp->index);
					str+="array("+string(t)+",";
				}
				str_end+=")";
				temp=temp->next;
			}
			str+=str_end;
			printf("%5s %50s %15s %5d %7d %15p\n",globalTab->symbol[j].name.c_str(),str.c_str(),"NULL",globalTab->symbol[j].size,globalTab->symbol[j].offset,globalTab->symbol[j].next);
		}
	}
	for(j=0;j<globalTab->count;j++){
		if(globalTab->symbol[j].next==NULL)
			continue;
		printf("\n%s Function\n",globalTab->symbol[j].name.c_str());
		sp=*(globalTab->symbol[j].next);
		int offset=0;
		for(i=0;i<sp.count;i++){
			sp.symbol[i].offset=offset;
			offset+=sp.symbol[i].size;
			printf("%5s ",sp.symbol[i].name.c_str());
			string str,str_end=sp.symbol[i].type;
			if(sp.symbol[i].arglist!=NULL){
				List* temp=sp.symbol[i].arglist;
				while(temp!=NULL){
					if(temp->index==0)
						str+="ptr(";
					else{
						char t[20];
						sprintf(t,"%d",temp->index);
						str+="array("+string(t)+",";
					}
					str_end+=")";
					temp=temp->next;
				}
				str+=str_end;
				printf("%50s",str.c_str());
				if(sp.symbol[i].arglist->index==0)
					printf("%17p",sp.symbol[i].value.ptr);
				else if(sp.symbol[i].type=="int")
					printf("%17d",sp.symbol[i].value.ival);
				else if(sp.symbol[i].type=="double")
					printf("%17lf",sp.symbol[i].value.dval);
				else
					printf("%17s",sp.symbol[i].value.str.c_str());
			}
			else if(sp.symbol[i].type=="int")
				printf("%50s %15d ","int",sp.symbol[i].value.ival);
			else if(sp.symbol[i].type=="double")
				printf("%50s %15lf ","double",sp.symbol[i].value.dval);
			else 
				printf("%50s %15s ","char",sp.symbol[i].value.str.c_str());

			printf("%5d %7d ",sp.symbol[i].size,sp.symbol[i].offset);
			if(sp.symbol[i].next==NULL)
				printf("%15s ","null");
			else
				printf("%15p ",sp.symbol[i].next);
 			printf("\n");
 		}
 	}
 }

void emit(string result,OpcodeType op,string arg1,string arg2){
	qArray[nextinstr].op=op;
	qArray[nextinstr].arg1=arg1;
	qArray[nextinstr].arg2=arg2;
	qArray[nextinstr].result=result;
	nextinstr++;
}


void printquad(){
	int i;
	printf("quads\n");
	for(i=0;i<nextinstr;i++){
		printf("%2d  ",i);
		string op;
		switch(qArray[i].op){
			case(PLUS):
				op="+";
				break;
			case(SUB):
				op="-";
				break;
			case(DIV):
				op="/";
				break;
			case(MULT):
				op="*";
				break;
			case(UMINUS):
				op="-";
				break;
			case(COPY):
				op="";
				break;
			case(PLUSPLUS):
				op="++";
				break;
			case(MINUSMINUS):
				op="--";
				break;
			case(NEG):
				op="~";
				break;
			case(NT):
				op="!";
				break;
			case(REM):
				op="%";
				break;
			case(LEFTSHIFT):
				op="<<";
				break;
			case(RIGHTSHIFT):
				op=">>";
				break;
			case(LESSTHAN):
				op="<";
				break;
			case(GREATERTHAN):
				op=">";
				break;
			case(LESSTHANEQUAL):	
				op="<=";
				break;
			case(GREATERTHANEQUAL):
				op=">=";
				break;
			case(ISEQUAL):
				op="==";
				break;
			case(NOTEQUAL):
				op="!=";
				break;
			case(XOR):
				op="^";
				break;
			case(BITOR):
				op="|";
				break;
			case(BITAND):
				op="&";
				break;
			case(QUESTIONMARK):
				op="?";
				break;
			case(COLN):
				op=":";
				break;
			case(ASSIGNMENT):
				op="";
				break;
			case(LOGICALOR):
				op="||";
				break;
			case(LOGICALAND):
				op="&&";
				break;
			case(_GOTO):
				op="goto";
				break;
			case(FUNC):
				op="call";
				break;
			case(PARAM):
				op="param";
				break;
			case(_RETURN):
				op="return";
				break;
			case(ARRAY):
				op="array";
				break;
		}

		if((op == "+" || op == "-" || op == "*" || op == "~" || op == "!" || op == "&") && (qArray[i].arg2 == ""))
			printf("%5s  =	%2s %3s\n",qArray[i].result.c_str(),op.c_str(),qArray[i].arg1.c_str());
		
		else if(op == "<" || op == ">" || op == "<="  || op == ">=" || op == "==" || op == "!=")
			printf("%5s %5s %2s %3s %10s %3s\n","if",qArray[i].arg1.c_str(),op.c_str(),qArray[i].arg2.c_str(),"goto ",qArray[i].result.c_str());
		
		else if(op == "goto" || op == "param" || op == "return")
			printf("%5s %3s\n",op.c_str(),qArray[i].result.c_str());
		
		else if(op == "call"){
			if(qArray[i].result == "")
				printf("%5s %5s,%5s\n",op.c_str(),qArray[i].arg1.c_str(),qArray[i].arg2.c_str());
			else
				printf("%5s 	=	 %5s %5s,%5s\n",qArray[i].result.c_str(),op.c_str(),qArray[i].arg1.c_str(),qArray[i].arg2.c_str());
		}
		else if(op == "array")
			printf("%5s 	=	 %5s[%2s]\n",qArray[i].result.c_str(),qArray[i].arg1.c_str(),qArray[i].arg2.c_str());
		else
			printf("%5s 	=	 %5s %5s %5s\n",qArray[i].result.c_str(),qArray[i].arg1.c_str(),op.c_str(),qArray[i].arg2.c_str());
	}
}

List* makelist(int index){
	List* templist=new List;
	templist->index=index;
	return templist;
}

List* merge(List* l1,List* l2){
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	List *temp=l1;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=l2;
	return l1;
}

void backpatch(List *p, int index){
	char str[20];
	sprintf(str,"%d",index);
	while(p!=NULL){
		qArray[p->index].result=string(str);
		p=p->next;
	}
}

void typecheck(SymNode *s1,SymNode* s2){
	if(s1->type == s2->type)
		s1->value = s2->value;
	else if(s1->type == "int"){
			s1->value.ival = s2->value.dval;
			s1->value.flag = 1;
	}
	else if(s2->type == "double"){
		s1->value.dval = s2->value.ival;
		s2->value.flag = 2;
	}
}


IdList* makelist(SymNode* sp){
	IdList* templist = new IdList;
	templist->id = sp;
	return templist;
}

IdList* merge(IdList* l1,IdList* l2){
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	IdList *temp=l1;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=l2;
	return l1;
}

ParamList* makelist(string name,string type){
	ParamList* templist=new ParamList;
	templist->name=name;
	templist->type=type;
	return templist;
}

ParamList* merge(ParamList* l1,ParamList* l2){
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	ParamList *temp=l1;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=l2;
	return l1;
}


void convInt2Bool(SymNode* sp){
	if(sp->type!="bool"){
		sp->type=="bool";
		sp->falselist=makelist(nextinstr);
		emit("",ISEQUAL,sp->name,"0");
		sp->truelist=makelist(nextinstr);
		emit("",_GOTO);
	}
}
int main(){

	globalTab = newTable();
	currentTab = globalTab;
	char temp[20];
	if(yyparse()==0) 
		printf("Parsing successful\n");
	else 
		printf("Parsing Error\n");

	printSymTab();
	printf("\n");
	printquad();
  	return 0;
}
