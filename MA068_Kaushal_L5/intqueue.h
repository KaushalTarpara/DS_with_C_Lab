#include <stdio.h>

void display(int *queue,int *front,int *rear){
    if(*front ==  -1){
        printf("\n Empty \n");
        return;
    }
    printf("Queue Display  : \n ");
    for(int i=*front; i<=*rear; i++){
        printf("%d <= ",queue[i]);
    }
    printf("\n");
}
void enqueue(int *queue,int front,int rear,int MAX,int value){
    if(*rear == MAX-1)
    {
        printf("Queue Overflow");
        return;
    }
    queue[++(*rear)]=value;
   
    if(*front == -1){
        (*front)++;
    }
     display(queue,&front,&rear);
}
int dequeue(int *queue,int *front,int *rear){
    if(*front ==-1){
        printf("Queue Underflow");
        return -1;
    }
    return queue[(*front)++];
}