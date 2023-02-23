#include <stdio.h>
int top=-1;
void push(int *stack, int max, char val)
{
	if(top==max-1)
	{
		printf("Overflow\n");		
	}else
	{	stack[++top] = val;
	}
}

int pop(int *stack)
{
	if(top==-1)
	{
		printf("Underflow\n");
		return 0;
	}
	return stack[top--];
	//printf("Poped Element : %d \n",stack[top--]);
}

void display(int *stack)
{
	if(top==-1)
	{
		printf("Underflow\n");
		return;
	}
	printf("\n");
	for(int i=top;i>=0;i--)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}
