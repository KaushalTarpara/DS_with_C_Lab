#include<stdio.h>

int main()
{
    int a=10;
    int *A=&a;
    int **a1=&A;

    printf("a = %d , addr = %d\n",a,&a);
    printf("A = %d , addr = %d\n",*A,A);
    printf("a1 = %d , addr = %d\n",**a1,a1);
}