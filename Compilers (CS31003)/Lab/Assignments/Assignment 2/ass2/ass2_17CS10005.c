/*
Name -  Anshul Choudhary
Roll No. - 17CS10005
Assignment No. - 2 
Date:- 23/07/2018
*/

#include "myl.h"
#define SYS_READ 0
#define STDIN_FILENO 0

int printStr(char *s)
{
    int char_count;
    
    for(char_count = 0; s[char_count] != '\0'; char_count++);
    __asm__ __volatile__ (
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t" 
        // making the  syscall
        "syscall \n\t"
        :
        :"S"(s), "d"(char_count)
    );
    return char_count;
}


int printInt(int n)
{
    char buff[20],zero='0';
    int i=0,j=0,bytes,k;
    if(n<0)
    {
        n=-n;
        buff[i++]='-';
    }
    if(n==0)
        buff[i++]=zero;
    while(1){
        if(n==0)
            break;
        buff[i++]= (char)(n%10 + zero);
        n=n/10;
    }
    if(buff[0]=='-')j=1;
    k=i-1;
    bytes=i;
    while(j<k){
        char tmp;
        tmp=buff[j];
        buff[j]=buff[k];
        buff[k]=tmp;
        j++;k--;
    }
  __asm__ __volatile__ (
        "movl $1, %%eax \n\t"
        "movq $1, %%rdi \n\t"
        "syscall \n\t"
        :
        :"S"(buff), "d"(bytes)
    );
    return bytes;
}


int readInt(int *n){
        char bufferarray[100];                
        int disp,i,num,flag=0;
        
        asm volatile("syscall" 
      : "=a" (disp) 
      : "0" (SYS_READ), "D" (STDIN_FILENO), "S" (bufferarray), "d" (sizeof(bufferarray))
      : "rcx", "r11", "memory", "cc");


    bufferarray[--disp] = 0x0;
    i=disp-1;
    while(i>=0 && bufferarray[i--]==' ');     
    bufferarray[i+2]=0x0;
    disp = i+2;
    i=-1;
    while(bufferarray[++i]==' ');            
    if(bufferarray[i]=='-')
    {
        i++;
        flag=1;
    }      
    if(bufferarray[i]>='0' && bufferarray[i]<='9')
    {
        num=bufferarray[i]-'0';
        i++;
    }
    else return ERR;    
    for(;i<disp;i++){             
        if(!(bufferarray[i]>='0' && bufferarray[i]<='9'))
            return ERR;
        num = num*10 + (bufferarray[i]-'0');
    }       
    if(flag)
        num=-num;             
    *n=num;                       
    return OK; 
}


int readFlt(float *f){
        char buff[100];                
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
    if(buff[i]=='-'){i++;flag=1;}              
    if(buff[i]>='0' && buff[i]<='9'){inte=buff[i]-'0';i++;}
    else if(buff[i]=='.'){f2=1;i++;} 
    else return ERR;
    
    for(;i<charsread;i++){                      
        if(buff[i]=='.'){      
                if(f2==1)return ERR;  
                f2=1;
                continue;
        }
        else if(!(buff[i]>='0' && buff[i]<='9'))return ERR;    
        else if(f2){
                dec = dec + fac*(buff[i]-'0');       
                fac = fac*0.1;
        }else{
                inte = inte*10+ (buff[i]-'0'); 
        }
    }  
            
    ans = inte+dec;    
    if(flag)ans=-ans;           
    *f=ans;             
    return OK;
}


int printFlt(float f){
    int temp2 = (int)f;
    int i=1,len=7;
    float partition = f - (float)temp2;
    char temp[20];    
    if(temp2==0 && f<0)printStr("-");          
    len += printInt(temp2);   
    if(partition<0)partition=-partition;                    
    temp[0]='.';   
    while(partition>0  && i<=6){                   
        partition = partition*10;
        temp2 = (int)partition;
        temp[i++] = temp2 + '0';
        partition = partition - temp2;
    }
    while(i<=6)                                 
        temp[i++]='0';
    temp[i]='\0';
    printStr(temp); 
    return len; 
}

