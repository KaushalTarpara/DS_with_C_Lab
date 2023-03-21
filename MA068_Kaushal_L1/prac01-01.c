#include<stdio.h>
#include<string.h>

struct student{
    char name[10];
    int sid;
    int mark;
}s[5];

int main()
{
    int i,m;
    for(i=0;i<5;i++)
    {
        printf("Enter name : ");
        scanf("%s",s[i].name);
        printf("Enter id : ");
        scanf("%d",&s[i].sid);
        printf("Enter mark : ");
        scanf("%d",&s[i].mark);
    }
    printf("Enter minimum marks : ");
    scanf("%d",&m);

    for(i=0;i<5;i++)
    {
        if(s[i].mark<m)
        {
            printf("%s has less marks %d \n",s[i].name,s[i].mark);
        }
    }

}