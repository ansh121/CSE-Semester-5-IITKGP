#define BUFF 20

void print_int(int n) {
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
}