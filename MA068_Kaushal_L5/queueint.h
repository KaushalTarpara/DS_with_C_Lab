#include <stdio.h>
int front=-1,rear=-1;
void Enqueue(int *queue,int max,int data){
    if(rear==max-1)
    {        printf("\nOverflow");
    }else{
        queue[++rear]=data;
    }       
    if(front==-1){
        front++;
    }
}
int Dequeue(int *queue){

    if(front==-1 ){
        printf("\nUnderflow Or Empty");
    }else{
        int Dval=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front++;
        }
        return Dval;
    }

}
void display(int *queue){
    if(front==-1){
         printf("\nEmpty");
        
    }else{
    printf("\n Display\n ");
    for(int i=front; i<=rear; i++){
        
        printf("%d --> ",queue[i]);
        
    }
    printf("\n");
    }
}
int Revqueue(int *queue,int max){
    if(front==-1)
    {        printf("\nUnderflow");
             return -1;
    } 
        //int data=queue[front];

        int data=Dequeue(queue);
        Revqueue(queue,max);
        Enqueue(queue,max,data);
       // return queue[++rear]=data;
        

}