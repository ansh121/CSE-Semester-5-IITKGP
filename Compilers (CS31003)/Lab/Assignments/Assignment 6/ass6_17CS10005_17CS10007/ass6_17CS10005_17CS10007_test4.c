/************************************************
Name -  Anshul Choudhary (17CS10005),
        Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/
// Test File 4

int printInt(int num);
int printStr(char * c);
int readInt(int *eP);

int Sum(int n, int a[100])
{	
	int sum = 0;
  	for(i=0; i<n ;i++)
	{
		sum = sum + a[i];
	}	

	return sum;
}

int main()
{
	int n, p, i, x, val;
	int a[100];
	printStr("\n\n\n********* Sum of element of Array *********\n");

	printStr("Enter array size = ");
	n = readInt(&p);

	printStr("Enter the elements = ");

	for(i=0; i<n ;i++)
	{
		x = readInt(&p);
		a[i] = x;
	}

	val = Sum(n,a);
	
	printStr("Sum = ");
	printInt(val);
	printStr("\n");
	
	return 0;
}
