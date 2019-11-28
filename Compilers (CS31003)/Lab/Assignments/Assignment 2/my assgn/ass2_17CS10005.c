#include "myl.h"
#define BUFF 200
#define SYS_READ 0
#define STDIN_FILENO 0

int printInt(int n) {
	char buff[BUFF], zero='0';
	int i=0, j, k, bytes;
	if(n == 0) buff[i++]=zero;
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
	buff[i]='\n';
	bytes = i+1;
	__asm__ __volatile__ (
		"movl $1, %%eax \n\t"
		"movq $1, %%rdi \n\t"
		"syscall \n\t"
		:
		:"S"(buff), "d"(bytes)
	) ; // $4: write, $1: on stdin
	return i;
}

int printFlt(float f) {
	int n = (int)f;
    int i=1,len=7,bytes;
    float p = f - (float)n;
    char buff[BUFF];    

    if(n==0 && f<0)printStr("-"); 

    len += printInt(n);

    if(p<0)p=-p;                    
    buff[0]='.';  

    while(p>0  && i<=6){                   
        p = p*10;
        n = (int)p;
        buff[i++] = n + '0';
        p = p - n;
    }
    while(i<=6)                                 
        buff[i++]='0';

    buff[i]='\n';
	bytes = i+1;
	__asm__ __volatile__ (
		"movl $1, %%eax \n\t"
		"movq $1, %%rdi \n\t"
		"syscall \n\t"
		:
		:"S"(buff), "d"(bytes)
	) ; // $4: write, $1: on stdin
	return len;	
}

int printStr(char *s) {
	char buff[BUFF];
	int i=0, bytes;
	while(s[i]!='\0') {
		buff[i]=s[i];
		i++;
	}
	buff[i]='\n';
	bytes = i+1;
	__asm__ __volatile__ (
		"movl $1, %%eax \n\t"
		"movq $1, %%rdi \n\t"
		"syscall \n\t"
		:
		:"S"(buff), "d"(bytes)
	) ; // $4: write, $1: on stdin
	return i;
}

int readInt(int *n){
    char buff[BUFF];                
    int disp,i,num,flag=0;
        
        asm volatile("syscall" 
      : "=a" (disp) 
      : "0" (SYS_READ), "D" (STDIN_FILENO), "S" (buff), "d" (sizeof(buff))
      : "rcx", "r11", "memory", "cc");

    if(disp>11) return ERR;
    buff[--disp] = 0x0;
    i=disp-1;

    while(i>=0 && buff[i--]==' '); 

    buff[i+2]=0x0;
    disp = i+2;
    i=-1;

    while(buff[++i]==' '); 

    if(buff[i]=='-')
    {
        i++;
        flag=1;
    }      
    if(buff[i]>='0' && buff[i]<='9')
    {
        num=buff[i]-'0';
        i++;
    }
    else return ERR; 

    for(;i<disp;i++){             
        if(!(buff[i]>='0' && buff[i]<='9'))
            return ERR;
        num = num*10 + (buff[i]-'0');
    }       
    if(flag) num=-num;             
    *n=num;                       
    return OK; 
}

int readFlt(float *f){
    char buff[BUFF];                
    int charsread;
    int i,inte=0,flag=0,f2=0;
    float fac=0.1,dec=0,ans;

        asm volatile("syscall" 
      : "=a" (charsread) 
      : "0" (SYS_READ), "D" (STDIN_FILENO), "S" (buff), "d" (sizeof(buff))
      : "rcx", "r11", "memory", "cc");

        
    buff[--charsread] = 0x0;
    i=charsread-1;

    while(i>=0 && buff[i--]==' ');              
    buff[i+2]=0x0;
    charsread = i+2;
    i=-1;

    while(buff[++i]==' ');

    if(buff[i]=='-'){
    	i++;
    	flag=1;
    }              
    if(buff[i]>='0' && buff[i]<='9'){
    	inte=buff[i]-'0';
    	i++;
    }
    else if(buff[i]=='.'){
    	f2=1;
    	i++;
    } 
    else return ERR;
    
    for(;i<charsread;i++){                      
        if(buff[i]=='.'){      
                if(f2==1)return ERR;  
                f2=1;
                continue;
        }
        else if(!(buff[i]>='0' && buff[i]<='9')) return ERR;    
        else if(f2){
                dec = dec + fac*(buff[i]-'0');       
                fac = fac*0.1;
        }
        else{
                inte = inte*10+ (buff[i]-'0'); 
        }
    }  
            
    ans = inte+dec;    
    if(flag)ans=-ans;           
    *f=ans;             
    return OK;
}

