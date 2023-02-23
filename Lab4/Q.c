#include <stdio.h>
#define n 5
int rear=-1,front=-1;
int queue[n];
void enqueue(int num){
    if(front==-1)
        front++;
    if(rear==n-1)
    {    printf("\nQueue is overflow");
        return;
    }
    queue[++rear]=num;
    
}
void display(){
    
    if(front>=0 && !front==rear)
    {   for(int i=front; i<=rear; i++ )
            printf("%d--",queue[i]);
    }
    else{
        printf("\nQueue is empty");
    }
}
int dequeue()
{
    if(front>rear){
        printf("Queue is underfloaw");
    }
    return queue[front++];
}
// int peek();
// int isEmpty();
int main(){
   // int queue[n];
    int choice,num,del;
    do{

        printf("\n1)enqueue");
        printf("\n2)dequeue");
        printf("\n3)peek/top");
        printf("\n4)isEmpty");
        printf("\n5)Display");
        
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter Element");
                scanf("%d",&num);
                enqueue(num);
                display();
                break;
            case 2:
                
                del= dequeue();
                printf("\nDeleted Element :%d",del);
                display();
                break;
            case 3:
               // int top=peek();
               // printf("\nTop element of Queue : %d",top);
                break;
            case 4:
                // if(isEmpty())
                //     printf("Queue is not empty");
                // else
                //     printf("Queue is empty");
                
                break;
            case 5:
                display();
                break;
            default:
              printf("Please Enter Right choice");
        }   

    }while(choice<6);
    return 0;
}