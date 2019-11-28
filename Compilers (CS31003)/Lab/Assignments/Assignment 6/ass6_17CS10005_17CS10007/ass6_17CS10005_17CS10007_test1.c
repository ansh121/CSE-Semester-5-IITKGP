/************************************************
Name -  Anshul Choudhary (17CS10005),
        Ayush Kumar (17CS10007)
Assignment No. - 6 (Target Code Generation)
************************************************/
// Test File 1

int printInt(int num);
int printStr(char * c);
int readInt(int *eP);
int main()
{
    int a,b,p;
    printStr("\n\n\n********* Multiplying two numbers a and b *********\n");
    printStr("a = ");
    a = readInt(&p);
    printStr("b = ");
    b = readInt(&p);
    printStr("Product = ");
    printInt(a*b);
    printStr("\n");
    return 0;
}
