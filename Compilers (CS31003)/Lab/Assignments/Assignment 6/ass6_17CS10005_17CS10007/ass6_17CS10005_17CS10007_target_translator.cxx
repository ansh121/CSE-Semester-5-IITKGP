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
    int k1, k2=10;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }

    vector<string>::iterator it;
    for(it = string_list.begin(); it != string_list.end(); it++)
    {
        cout<<global_string_start<<g_str_count++<<":\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
    int k1, k2=10;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    cout<<function_name<<":\n";
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    //cout<<".cfi_startproc\n";
    cout<<"\tpushq\t%rbp\n";
    cout<<"\tmovq\t%rsp, %rbp\n";
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    cout<<"\tsubq\t$"<<stack_req<<",\t%rsp\n";  //allocate stack for local variables
}

void Code_Generator:: create_Function_Epilogue()
{
    //cout << "\t" << "leave" <<endl;
    cout << "\t" << "ret"<<endl;
    int k1, k2=10;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }

    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
            int k1, k2=10;
		    for(k1=0;k1<5;k1++){
		    	if(k1==10){
		    		if(k2==0){
		    			//print();
		    			k2=1;
		    		}
		    		else if(k2==1){
		    			if(k2==0){
		    				//printf();
		    			}
		    		}
		    	}
		    	k1=10;
		    	break;
		    }
		    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
                for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
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
                    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
    int k1, k2=10;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
}

void Code_Generator:: set_GOTO_Labels_target()
{
    int countss=100;
    int tempppp;
    for(int i=0;i<100;i++)
        countss++;
    int k1, k2=10;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    for(vector<Quad>::iterator it = Quad_arr.arr.begin(); it != Quad_arr.arr.end(); it++)
    {
        if(it->op >= IF_LESS && it->op <= GOTO)
        {
            int backpatch_result = atoi(((*it).result).c_str());
            if(generate_goto.count(backpatch_result)==0)
            {
                string label = generate_GOTO_Labels();
                for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    	break;
    }
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
    int k1=10,k2 =100;	
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    arg1_binding = arg2_binding = result_binding = 0;   //make quad argument bindings

    symtab *global_arg1, *global_arg2, *global_result;    

    symtab* curr_arg1 ;
    curr_arg1 = current_symbol->lookup(current_quad.arg_1);
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    symtab* curr_arg2 ;
    curr_arg2= current_symbol->lookup(current_quad.arg_2);
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    symtab* curr_result;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    curr_result = current_symbol->lookup(current_quad.result); //All are present in symbol_table, so lookup will handle it fine
    
    global_arg1 = NULL;
    global_arg2 = NULL;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    global_result = NULL;
   
    for(int j = 0; j < (&GTable)->no_of_entries; j++)
    {
        if((&GTable)->sym_table[j].id.compare(current_quad.arg_1)==0)
            global_arg1 = &((&GTable)->sym_table[j]);
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        
    }
    
    for(int j = 0; j < (&GTable)->no_of_entries; j++)
    {
        if((&GTable)->sym_table[j].id.compare(current_quad.arg_2)==0)
            global_arg2 = &((&GTable)->sym_table[j]);
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    }


    
    for(int j = 0; j < (&GTable)->no_of_entries; j++)
    {
        if((&GTable)->sym_table[j].id.compare(current_quad.result)==0)
            global_result = &((&GTable)->sym_table[j]);
        else 
        global_result = NULL;
    }
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }

    
     

    string generator_arg1 = empty_string;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    string generator_arg2 = empty_string;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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

    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    

    if(current_quad.arg_1[0] <= '0' || current_quad.arg_1[0] >= '9')
    {
        if(global_arg1 == NULL)
        {
            arg1_binding = curr_arg1->offset;
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        string bind = to_string(arg2_binding);
            generator_arg2 = bind + "(%rbp)";
        }
        else
    {
        //cout<<"#--"<<global_arg2->type.type_name<<endl;

        generator_arg2 = current_quad.arg_2;
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        
    }
            
    }            

    //start with the operations
    
    if(current_quad.op == UNARY_MINUS)
    {
        int countss=100;
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        int tempppp;
        for(int i=0;i<100;i++)
            countss++;
        cout << "\t" << "movq" << "\t" <<generator_arg1<< ",\t%rax" << endl; 
        cout << "\t" << "negq\t %rax"<< endl;
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
            cout<<"\tmovl\t"<<"%eax,\t"<<generator_result<<"\n"; 
            for(k1=0;k1<5;k1++){
	    	if(k1==10){
	    		if(k2==0){
	    			//print();
	    			k2=1;
	    		}
	    		else if(k2==1){
	    			if(k2==0){
	    				//printf();
	    			}
	    		}
	    	}
	    	k1=10;
	    	break;
    		}
        }
    }
    }

    else if(current_quad.op == PLUS)
    {
        if((current_quad.arg_2.compare("1"))==0)
        {//result = a + 1
            cout<< "\tmovl\t" <<generator_arg1<<",\t%edx\n";
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
            cout<< "\taddl\t$1,\t%edx\n";
            for(k1=0;k1<5;k1++){
	    	if(k1==10){
	    		if(k2==0){
	    			//print();
	    			k2=1;
	    		}
	    		else if(k2==1){
	    			if(k2==0){
	    				//printf();
	    			}
	    		}
	    	}
	    	k1=10;
	    	break;
	    }
            cout<< "\tmovl\t%edx,\t%eax\n";
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
            cout << "\tmovl\t %edx,\t %eax\n";
            cout << "\tmovl \t %eax,\t"  << generator_result<< "\n";
        }
        else
        {
            //result = a - b

            cout<< "\tmovl\t" <<generator_arg1<< ",\t%edx\n";
            cout<< "\tmovl\t" <<generator_arg2 << ",\t%eax\n";
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
            cout<< "\tsubl\t%eax,\t%edx\n";
            cout<< "\tmovl\t%edx,\t%eax\n";
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();

    			}
    		}
    	}
    	k1=10;
    	break;
    }
        }
        cout<< "\tmovl\t%eax,\t"<< generator_result<< "\n";           
        
    }

    else if(current_quad.op==DIVIDE)
    {
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcltd\n";
        cout << "\tidivl\t"<< generator_arg2 << "\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout << "\tmovl\t%eax,\t" << generator_result<< "\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }       
        
    }
    else if(current_quad.op==MODULO)
    {
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcltd\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout << "\tidivl\t"<< generator_arg2 << "\n";
        cout << "\tmovl\t%edx,\t"  << generator_result << "\n";  
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }        
        
    }

    
    else if(current_quad.op==IF_LESS)
    {
        
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        cout << "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout << "\tjge\t.L" << goto_label_count <<"\n";
        cout << "\tjmp\t" <<current_quad.result <<"\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout << ".L" << goto_label_count  << ":\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        goto_label_count = goto_label_count + 1;

    }

    else if(current_quad.op==IF_GREATER)
    {
        //  if a > b goto .L1
        cout<< "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<< "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
    //jump on less
        cout<< "\tjle\t.L" << goto_label_count << "\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<< "\tjmp\t" <<current_quad.result << "\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<< ".L"<< goto_label_count  << ":\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        goto_label_count = goto_label_count + 1;

    }

    else if(current_quad.op==IF_IS_EQUAL)
    {
        //  if a == b goto L1
        
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout << "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout << "\tjne\t.L" << goto_label_count << "\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout << "\tjmp\t" <<current_quad.result << "\n";
        cout << ".L" << goto_label_count  << ":\n";
        goto_label_count = goto_label_count + 1;

    }

    else if(current_quad.op==IF_NOT_EQUAL)
    {
        //  if a != b goto .L1
        
        cout << "\tmovl\t" <<generator_arg1 << ",\t%eax\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout << "\tcmpl\t" <<generator_arg2 << ",\t%eax\n";
        cout << "\tje\t.L" << goto_label_count << "\n";
        cout << "\tjmp\t" <<current_quad.result << "\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout << ".L" << goto_label_count  << ":\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        goto_label_count = goto_label_count + 1;

    }
    
    else if(current_quad.op==IF_NOT_EXPRESSION)
    {
    //if a==0 goto .L1
        cout<< "\tcmpl\t$0,\t"<<generator_arg1<< "\n"; 
        cout<< "\tjne\t.L"<< goto_label_count<<"\n"; 
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<< "\tjmp\t"<<current_quad.result<<endl;
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<< ".L"<<goto_label_count<<" : \n";  
        goto_label_count = goto_label_count + 1;     
    }

    else if(current_quad.op==IF_EXPRESSION)
    {  
    //if a!= 0 goto .L1
        cout<< "\tcmpl\t$0,\t"<<generator_arg1<< endl;
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    } 
        cout<< "\tje\t.L"<< goto_label_count<<endl; 
        cout<< "\tjmp\t"<<current_quad.result<<endl;
        cout<< ".L" <<goto_label_count<<" : \n" ;  
        goto_label_count++;
    }

  
    else if(current_quad.op==GOTO)
    {
        //goto .L1
        cout<<"\tjmp\t" <<current_quad.result<<"\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
           	for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
             for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
              
            //s = s + "\tmovq\t" + generator_result + ",\t%rax\n";
         }
         if(flag == 0)
                    s = s + "\tmovq\t" + generator_result + ",\t%rax\n";
             str1.push_back(s);
             str1.push_back("\tpushq\t%rax\n");
             for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
             stack_of_parameters.push(str1);
      
        }
    }
    }

    else if(current_quad.op==CALL)
    {
    if(current_quad.result.compare("printInt")==0 || current_quad.result.compare("printStr")==0 || current_quad.result.compare("readInt")==0)
    {
       int num;
       for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
           num = atoi((current_quad.arg_1).c_str());
           num=num*4;
           cout << "\t" << "call\t"<<current_quad.result << endl;
           for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
           //cout << "\t" << "addq\t$"<<num<<",\t%rsp"<< endl;
           if(current_quad.arg_2 != "")
               cout << "\t" << "movq\t%rax,\t"<<generator_arg2<< endl;

    }
    else{
    int num;
        num = atoi((current_quad.arg_1).c_str());
        num=num*8;
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        while(stack_of_parameters.size() > 0)
        {
            vector<string> str; 
            str = stack_of_parameters.top();
            for(int i = 0; i<str.size(); i++)
            {
                cout<<str[i];
                for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
            }
        stack_of_parameters.pop();    //pop from stack
        }
        
        cout << "\tcall\t"<<current_quad.result << "\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
      /*  memory = 16;
        memory_bind_ebp = 0;*/
            
    }

    else if(current_quad.op==DEREFERENCE)
    {
        // a = *p
        cout<<"\tmovq\t"<<generator_arg1<<",\t%rax\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<<"\tmovl\t(%rax),\t %ecx\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<<"\tmovl\t%ecx,\t"<<generator_result<<"\n";
    }

    else if(current_quad.op==REFERENCE)
    {
        //p = &a
        cout<<"\tleaq\t"<<generator_arg1<<",\t%rax\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<<"\tmovq\t%rax,\t"<<generator_result<<"\n";
    }


    
    else if(current_quad.op==ARRAY_ACCESS)
    {
        //b = a[i]
    if(arg1_binding>0)      //required for passing array as parameters
    {
        cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<<"\tmovq\t"<<arg1_binding<<"(%rbp),\t%rdi\n";
        cout<<"\taddq\t%rdi,\t%rdx\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<<"\tmovl\t(%rdx),\t%eax\n";
        cout<<"\tmovl\t%eax,\t"<<generator_result<<"\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    }
    else
    {
        cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx"<< endl;
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<<"\tmovl\t"<<arg1_binding<<"(%rbp,%rdx,1),\t%eax\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<<"\tmovl\t%eax,\t"<<generator_result<<"\n";
    } 
    }



    else if(current_quad.op==ARRAY_DEREFERENCE)
    {
    	for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        //a[i] = b
    if(result_binding>0)        //required for passing array as parameters
    {
        cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx\n";
        cout<<"\tmovl\t"<<generator_arg1<<",\t%eax\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<<"\tmovq\t"<<result_binding<<"(%rbp),\t%rdi\n";
        cout<<"\taddq\t%rdi,\t%rdx\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        
        cout<<"\tmovl\t%eax,\t(%rdx)\n";
    }
    else{
        cout<<"\tmovslq\t"<<generator_arg2<<",\t%rdx\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<<"\tmovslq\t"<<generator_arg1<<",\t%rax\n";
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        cout<<"\tmovq\t%rax,\t"<<result_binding<<"(%rbp,%rdx,1)\n";}
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    }

    

}

void Code_Generator:: Bind_Memory_Record()
{
    
    handle_strings();
    int k1=10,k2=10;
    handle_Globals();
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    set_GOTO_Labels_target();

    int quad_size = Quad_arr.arr.size();
    for(int i = 0; i < quad_size; i++)
    {
    //print the quads for reference
    cout<<"  # "; Quad_arr.arr[i].print();
        
        if(generate_goto.count(i)>0)
        {
            cout<<generate_goto[i]<<":\n";
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
        int k1=0,k2=0;
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){

    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
                for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
                flag_parameter = 1;
                int total_count; 
                total_count =  row->type.no_of_params;
                //if (p==NULL)
                //    cout<<"1\n";
        for(int j = 0; j < total_count; j++)
        {
            new_sym->sym_table[j].offset = memory;
            memory = memory + 8;
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
                for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
    int k1, k2=10;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    
    string output_file = "a.out";
    if(argc==2) output_file = string(argv[1]);
    string quad_file = "ass6_17CS10005_17CS10007_quads" + output_file + ".out";
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    ofstream outf1(quad_file.c_str());
    streambuf *coutbuf1 = cout.rdbuf();
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    cout.rdbuf(outf1.rdbuf());
    
    //freopen(argv[2],"w",stdout);
    cout<<"********************Here are all Quads**********************\n";
    cout<<"--------------------------------------------------------\n";
    cout<<"*********************Quads******************************\n";
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    for(int i = 0; i<arr_size;i++)
    {
        cout<<i<<" : "; 
        Quad_arr.arr[i].print();
        for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    }

    cout<<"\n----------------SYMBOL TABLE (ST.gbl)-----------------------\n";
    symbol_table *g = &GTable;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
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
            for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
        }
    }
    cout<<"----------------Compilation Result------------------\n";
    if(failure != 0)
        printf("Compilation Failure\n");
    else
        printf("Compilation Success\n");
    cout<<"*****************************************************\n";
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    cout.rdbuf(coutbuf1);

    string tmp = "ass6_17CS10005_17CS10007_" + output_file + ".s";
    ofstream outfile(tmp.c_str());
    streambuf *coutbuf = cout.rdbuf();
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    cout.rdbuf(outfile.rdbuf());
    current_symbol = symbol;
    Code_Generator c;
    for(k1=0;k1<5;k1++){
    	if(k1==10){
    		if(k2==0){
    			//print();
    			k2=1;
    		}
    		else if(k2==1){
    			if(k2==0){
    				//printf();
    			}
    		}
    	}
    	k1=10;
    	break;
    }
    c.Bind_Memory_Record();
    
    cout.rdbuf(coutbuf);
    return 0;

}















































