#include <stdio.h>
#define DIM 20
void ReadMat(int n, int data[][DIM]);
void TransMat(int n, int data[][DIM]);
int VectMult(int n, int firstMat[], int secondMat[]);
void MatMult(int n, int firstMat[][DIM], int secondMat[][DIM], int M[][DIM]);
int main()
{
int n, i, j;
int A[DIM][DIM],B[DIM][DIM],C[DIM][DIM];
printf("Enter the dimension of a square matrix: ");
scanf("%d", &n);
printf("Enter the first matix (row-major): ");
ReadMat(n, A);
printf("Enter the second matix (row-major): ");
ReadMat(n, B);
MatMult(n, A, B, C);
printf("\nThe result matrix:\n");
for(i=0; i<n; ++i){
for(j=0; j<n; ++j) {
printf("%d ", C[i][j]);
}
printf("\n");
}
return 0;
}
void ReadMat(int n, int data[][DIM])
{
int i, j;
for(i=0; i<n; ++i) {
for(j=0; j<n; ++j) {
scanf("%d", &data[i][j]);
}
}
}
void TransMat(int n, int data[][DIM])
{
int i, j, t;
for(i=0; i<n; i++) {
for(j=0; j<i; j++) {
t = data[i][j];
data[i][j] = data[j][i];
data[j][i] = t;
}
}
printf("\nThe transpose of the second matrix:\n");
for(i=0; i<n; ++i){
for(j=0; j<n; ++j) {
printf("%d ", data[i][j]);
}
printf("\n");
}
}
int VectMult(int n, int firstMat[], int secondMat[])
{
int i, result = 0;
for(i=0; i<n; i++) {
result+=firstMat[i]*secondMat[i];
}
return result;
}
void MatMult(int n, int firstMat[][DIM], int secondMat[][DIM], int M[][DIM])
{
int i, j;
TransMat(n, secondMat);
for(i=0; i<n; i++) {
for(j=0; j<n; j++) {
M[i][j] = VectMult(n, &firstMat[i][0], &secondMat[j][0]);
}
}
}
