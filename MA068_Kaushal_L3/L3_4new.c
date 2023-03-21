#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int empID;
	char name[25];
	int age;
}employee;
int main()
{
	int n,count=1,i=0;
	employee * emp  = (employee *) malloc (count * sizeof(employee));
	do
	{
		count++;
		printf("\nEnter Id, Name and Age:\n");
		scanf("%d %s %d",&(emp+i)->empID,(emp+i)->name,&(emp+i)->age);
		printf("\n1.Insert record\n2.Exit\nChoose: ");
		scanf("%d",&n);
		if(n==1)
		{	
			emp = (employee *) realloc (emp,count * sizeof(employee));
			i++;
		}
	}while(n!=2);
	
	for(i=0;i<count-1;i++)
	{
		printf("\nempID: %d\n",(emp+i)->empID);
		printf("Name: %s\n",(emp+i)->name);
		printf("Age: %d\n",(emp+i)->age);
	}
	free(emp);
	return 0;
}
