#include<stdio.h>
#include<ctype.h>
#include "stackint.h"
#define max 50
int stack[max];
//int top=-1;
void postfix(char postf[]);
int main()
{
	int i;
	char postf[max];
	printf("Enter postfix expression For Evaluation= ");
	for(i=0;i<=25-1;i++)
	{
		scanf("%c",&postf[i]);
		if(postf[i]=='\n')
		break;
	}
    postfix(postf);
	return 0;
}

void postfix(char postf[])
{
	int i,val,A,B;
	char ch;
	for(i=0;postf[i]!='\0';i++)
	{
		ch=postf[i];
		if(isdigit(ch))
		{
			push(stack,max,ch - '0');
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
		{
			A = pop(stack);
			B = pop(stack);
			switch(ch)
			{
				case '*':val=B*A; 
				break;
				case '/':val=B/A; 
				break;
				case '+':val=B+A; 
				break;
				case '-':val=B-A; 
				break;
			}
			push(stack,max,val);
		}
	}
printf("Evaluation Of Postfix Operation=:%d\n",pop(stack));
}
