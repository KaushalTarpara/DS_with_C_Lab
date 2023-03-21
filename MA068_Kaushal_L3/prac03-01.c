#include<stdio.h>
struct book
{
	char Book_Name[20];
	char Author_Name[20];
	float price;
	int pages;
};
void display(int size,struct book *);
void (*function)(int,struct book *);
int main()
{
	int n;
	printf("Enter How Many Book Details You Want To Add???");
	scanf("%d",&n);
	struct book total[n];
	struct book *ptr;
	ptr=total;
	function=display;
	printf("Enter Details\n");
	for(int i=0;i<n;i++,ptr++)
	{
		printf("Enter Book Name For %d=",(i+1));
		scanf("%s",ptr->Book_Name);
		printf("Enter Author Name For %d=",(i+1));
		scanf("%s",ptr->Author_Name);
		printf("Enter Price Of Book %d=",(i+1));
		scanf("%f",&ptr->price);
		printf("Enter Pages Of Book %d=",(i+1));
		scanf("%d",&ptr->pages);
	}
	printf("Book Details Which IS starts With D...\n");
	
	ptr=total;

	for(int i=0;i<n;i++,ptr++)
	{
		if(ptr->Book_Name[0]=='D')
		{
			printf("Book %d Details\n",(i+1));
			printf("Book %d Name=%s\n",(i+1),ptr->Book_Name);
			printf("Author Name=%s\n",ptr->Author_Name);
			printf("Book Price=%f\n",ptr->price);
			printf("Book Name=%d\n",ptr->pages);
			printf("----------------------------\n");
		//printf("%s\t\t%s\t\t%f\t%d\n",ptr->Book_Name,ptr->Author_Name,ptr->price,ptr->pages);
		}
	}
	function(n,total);
}
void display(int size,struct book *ptr)
{
	printf("\nBook Details\n");
	
	for(int i=0;i<size;i++,ptr++)	
	{
		printf("Book %d Details\n",(i+1));
		printf("Book %d Name=%s\n",(i+1),(*ptr).Book_Name);
		printf("Author Name=%s\n",(*ptr).Author_Name);
		printf("Book Price=%f\n",(*ptr).price);
		printf("Book Name=%d\n",(*ptr).pages);
		printf("----------------------------\n");
	printf("\n");
	}
}
