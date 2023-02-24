#include<stdio.h>
#include<string.h>
#include "stackchar.h"
#define max 20
int top;
char stackarr[max];
int main()
{
	char str[20];
	printf("Enter string=");
	gets(str);
	int len=strlen(str);
	int i;
	printf("Reverse string=\n");
	for(i=0;i<len;i++)
	{
		push(stackarr,max,str[i]);
	}
	for(i=0;i<len;i++)
	{
		pop(stackarr);
		printf("\n");
	}		
	
return 0;
}
