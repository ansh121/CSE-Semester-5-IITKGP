/************************************************
Name -  Anshul Choudhary (17CS10005),
        Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/
// Test File 2

int printInt(int num);
int printStr(char * c);
int readInt(int *eP);

int main()
{

	int p, n, a=1, b=1, t, i;
	printStr("\n\n\n*********** Finding nth fibonacci number ***********\n");
	printStr("Enter n (n>0) = ");
	n = readInt(&p);

	if(n==1 || n==2) {
		printStr("nth fibonacci number is 1.\n");
	}
	else{
		for(i=2;i<n;i++){
			t=a+b;
			a=b;
			b=t;
		}
		printStr("nth fibonacci number is ");
		printInt(t);
		printStr(".\n");
	}
	return 0;
}
