/************************************************
Name -	Anshul Choudhary (17CS10005),
		Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/


#include "mylib.h"
#define MAX 100                        
#define PREC 6  


int printStr(char* s)
{
    int bytes = 0;              
    while(s[bytes] != '\0') 	
		bytes++;    						   
     __asm__ __volatile__ (     
         "movl $1, %%eax \n\t"  
         "movq $1, %%rdi \n\t"  
         "syscall \n\t"         
         :
         :"S"(s), "d"(bytes)    
         );
     return bytes;   			
}



int printInt(int n)
{
    char buff[MAX], zero='0';
    int i=0, j, k, bytes;	

    if(n == 0) 					
		buff[i++]=zero;		
    else{
       if(n < 0) {			
          buff[i++]='-';	
          n = -n;
       }
       while(n){			
          int dig = n%10;
          buff[i++] = (char)(zero+dig);
          n /= 10;
       }
       if(buff[0] == '-') j = 1;
       else j = 0;
       k=i-1;
       while(j<k){				
          char temp=buff[j];	
          buff[j++] = buff[k];
          buff[k--] = temp;
       }
    } 
    //buff[i]='\n';
    bytes = i;

    __asm__ __volatile__ (		
          "movl $1, %%eax \n\t"	
          "movq $1, %%rdi \n\t"	
          "syscall \n\t"		
          :
          :"S"(buff), "d"(bytes)
    ) ;  // $1: write, $1: on stdin
	return bytes;				
}


int readInt( int *eP)
{
    *eP = OK;                   
    char buff[MAX];             
    __asm__ __volatile__ (      
        "movl $0, %%eax \n\t"   
        "movq $0, %%rdi \n\t"   
        "syscall \n\t"         
        :
        :"S"(buff), "d"(MAX)   
        );
    int i = 0, neg_sign = 0;            
		  								
	long long result = 0;  
    
	if(buff[i] == '-')                  
    {
        neg_sign = 1;                   
        i++;							
    }
                   	 					
    while(buff[i] != '\n')              
    {
		if(buff[i]<'0' || buff[i]>'9')	
		{
			*eP = ERR;			
			return result;
		}
									
		result = result * 10;	
		int dig = buff[i] - '0';
		result = result + dig;	
		
		if(result >= (1LL<<31))	
		{
			*eP = ERR;			
			return result;
		}
			
		i++;					
    }

	if(neg_sign != 0)	
	{
		result = (-1) * result;	
	}
                                                 
    return result;	

}