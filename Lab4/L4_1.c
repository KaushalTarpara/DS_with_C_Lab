#include <stdio.h>
#include "stackchar.h"
int main()
{
	int n=0,max=50;
	char a,stack[max];
	while(n!=8)
	{
		printf("\n1.Push\n2.Pop\n3.Change\n4.Peep\n5.Isempty\n6.Isfull\n7.Display\n8.Exit\n\nChoice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("\nEnter Element:");
				scanf(" %c",&a);
				push(stack,max,a);
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				change(stack);
				break;
			case 4:
				peep(stack);
				break;
			case 5:
				Isempty();
				break;
			case 6:
				Isfull(max);
				break;
			case 7:
				display(stack);
				break;
			case 8:
				printf("\nBye....\n");
				break;
			default:
				printf("\nInvalid Choice...\n");
				break;
		}
	}
	return 0;
}
