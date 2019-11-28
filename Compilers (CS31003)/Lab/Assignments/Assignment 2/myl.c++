#include "myl.h"
#define BUFF 200

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
	double num=f*1000000;
	long long int n=num;
	char buff[BUFF], zero='0';
	int i=0, j, k, bytes,m=6;
	if(n == 0) buff[i++]=zero;
	else{
		if(n < 0) {
			buff[i++]='-';
			n = -n;
		}
		while(m--){
			int dig = n%10;
			buff[i++] = (char)(zero+dig);
			n /= 10;
		}

		buff[i++]='.';

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