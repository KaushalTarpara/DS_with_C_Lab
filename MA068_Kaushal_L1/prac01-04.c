#include<stdio.h>

int main()
{
    int arr[15];
    printf("Enter elements : ");
    for(int i=0;i<15;i++)
    {
        scanf("%d ",arr+i);
    }
    for(int i = 0;i<15;i++)
    {
        printf("%d ",*(arr+i));
    }
    return 0;
}