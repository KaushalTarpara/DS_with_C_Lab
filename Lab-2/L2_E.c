#include <stdio.h>
void (*ptr)(int *);
void add(int *a)
{
	*a+=2;
}

void sub(int *a)
{	
	*a-=2;
}

void add_sub(int a,void (*ptr)())
{
	int i;
	do
	{
		printf("\n1.Add\n2.Subtract\n3.Exit");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
				ptr=add;
				(*ptr)(&a);
				printf("After Increment : %d\n",a);
				break;
			case 2:
				ptr=sub;
				(*ptr)(&a);
				printf("After Decrement : %d\n",a);
				break;
			case 3:
				printf("Program Terminated...\n");
				break;
			default:
				printf("Enter valid input...\n");
				break;
		}
	}while(i!=3);
}
int main()
{
	int a;
	printf("Enter a Number:");
	scanf("%d",&a);
	add_sub(a,ptr);
	return 0;
}
