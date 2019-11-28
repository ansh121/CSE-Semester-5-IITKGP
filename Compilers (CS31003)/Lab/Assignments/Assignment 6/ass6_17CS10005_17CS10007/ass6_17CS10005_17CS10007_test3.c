/************************************************
Name -  Anshul Choudhary (17CS10005),
        Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/
// Test File 3

int printInt(int num);
int printStr(char * c);
int readInt(int *eP);



int binary_search(int arr[10], int l, int r, int key)
{
	int m, t;
	if(l < r || l == r)
	{
		m = (l + r)/2;
		if(arr[m] == key)	return m;
		else if (key < arr[m]){
			t = binary_search(arr, l, m - 1, key);
			return t;
		}
		else{
			t = binary_search(arr,m + 1, r, key);
			return t;			
		}
	}
	else{
		return -1;		
	}
}
int main()
{
	int n, p, i, x, value;
	int a[10];
	printStr("\n\n\n********* Binary Search in Sorted Array *********\n");
	printStr("Enter the no. of = ");
	n = readInt(&p);
	printStr("Enter the elements in sorted order = \n");

	for(i=0; i<n ;i++)
	{
		x = readInt(&p);
		a[i] = x;
	}	

	printStr("Element to search = ");
	value = readInt(&p);

	int ans = binary_search(a, 0, n-1, value);
	if(ans == -1)
		printStr("Not found!!\n");
	else
	{
		printStr("Found at position (0 indexed) = ");
		printInt(ans);
		printStr("\n");
	}
	return 0;
}
