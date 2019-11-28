/************************************************
Name -  Anshul Choudhary (17CS10005),
        Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/
// Test File 5

int printInt(int num);
int printStr(char * c);
int readInt(int *eP);

int gcd(int m, int n)
{
	if(n==0)
		return m;    
	return gcd(n, m%n);
}

int main()
{
	int a, b, c, p;
	printStr("\n\n\n********** GCD of two numbers **********\n");
	printStr("Enter first number : ");
	a = readInt(&p);
	printStr("Enter second number : ");
	b = readInt(&p);	
	printStr("The gcd of above two number is: ");
	c = gcd(a, b);
	printInt(c);
	printStr("\n");	
	return 0;
}