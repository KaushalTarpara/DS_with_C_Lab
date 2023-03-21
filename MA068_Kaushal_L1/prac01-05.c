#include<stdio.h>

int main()
{
    int arr[5]={1,2,3,4,5,};
    int **ptr[5];
    printf("Enter elements :\n ");
    for(int i=0;i<5;i++)
    {
        ptr[i] = &arr[i];
        printf("Address of %d is %d \n",*ptr[i],ptr[i]);
    }
    return 0;
}