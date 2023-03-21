#include<stdio.h>
#include<string.h>

struct student{
    int sid;
    struct mark{
        int DS;
        int JAVA;
        int OS;
    }m;
    int total;
    int per;
}s[5];

int main()
{
    int i,m;
    for(i=0;i<5;i++)
    {
        printf("Enter id : ");
        scanf("%d",&s[i].sid);
        printf("DS : ");
        scanf("%d",&s[i].m.DS);
        printf("JAVA : ");
        scanf("%d",&s[i].m.JAVA);
        printf("OS : ");
        scanf("%d",&s[i].m.OS);

        s[i].total = s[i].m.DS + s[i].m.JAVA + s[i].m.OS;
        s[i].per = (s[i].total*100)/150;

        printf("Total = %d\n",s[i].total);
        printf("Percentage = %d\n",s[i].per);
    }
}