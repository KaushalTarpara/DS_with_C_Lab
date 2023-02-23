#include <stdio.h>
int top=-1;
void push(char *stack, int max, char val)
{
	if(top==max-1)
	{
		printf("Overflow\n");
		return;
	}
	stack[++top] = val;
}

void pop(char *stack)
{
	if(top==-1)
	{
		printf("Underflow\n");
		return;
	}
	printf("Poped Element : %c \n",stack[top--]);
}
void change(char *stack)
{
	char ch,to_ch;
	printf("Enter Char that you want to replace : ");
	scanf(" %c",&ch);
	printf("Enter Char that you want to change : ");
	scanf(" %c",&to_ch);
	
	for(int i=top;i>0;i--)
	{
		if(ch==stack[i])
		{
			stack[i] = to_ch;
			return;
		}
	}
	printf("\nNot Found : Can not change");
}
void peep(char *stack)
{
	char f;
	printf("Enter Char to Find : ");
	scanf(" %c",&f);
	for(int i=top;i>0;i--)
	{
		if(stack[i]==f)
		{
			printf("Found\n");
			return;
		}
	}
	printf("Not Found\n");
}
void Isempty()
{
	if(top==-1)
		printf("\nEmpty\n");
	else
		printf("\nNot Empty\n");
}

void Isfull(int max)
{
	if(top==max)
		printf("\nFull");
	else
		printf("\nNot Full");
}

void rev(char *stack,char *reverse)
{
	int j=0;
	for(int i=0;i<=top;i++)
	{
		reverse[j] = stack[i];
		j++;
	}
	for(int i=0;i<=j;i++)
	{
		printf(" %c",reverse[i]);
	}
}
void display(char *stack)
{
	if(top==-1)
	{
		printf("Underflow\n");
		return;
	}
	printf("\n");
	for(int i=top;i>=0;i--)
	{

		printf("| %c | \n",stack[i]);
	}
	printf("----");
	printf("\n");
}
