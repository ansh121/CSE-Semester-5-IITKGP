#include <iostream>
using namespace std;

#include "myl.h"

int main()
{
	int n;
	cout << "Enter an integer: ";
	cin >> n;
	printInt(n);

	char str[100];
	cout << "Enter aa String: ";
	cin >> str;
	printStr(str);

	float f;
	cout << "Enter aa String: ";
	cin >> str;
	printStr(str);

	return 0;
}