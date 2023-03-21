// Write a C program to create a queue where insertion and deletion of elements
// can be done from both the ends
#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;
void EnqueueEnd(int data){
    if(rear==MAX-1)
    {        printf("\nOverflow");
    }else{
        queue[++rear]=data;
    }       
    if(front==-1){
        front++;
    }

}
void EnqueueFirst(int data){
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
     
        for (int i = rear; i >= front; i--) {
            queue[i+1] = queue[i];
        }
     
        queue[front] = data;
        rear++;
        if (front == -1) {
            front = 0;
        }
    }
}
int DequeueFront(){

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

int DequeueEnd(){

    if(front==-1 ){
        printf("\nUnderflow Or Empty");
    }else{
        int Dval=queue[rear];
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            rear--;
        }
        return Dval;
    }

}

void display(){
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


int main() {
    EnqueueEnd(10);
    display();
    EnqueueEnd(20);
    display();
  
    EnqueueFirst(40);
    display();
    EnqueueFirst(50);
    display();

    DequeueFront();
    display();
    
    DequeueEnd();
    display();
    
    return 0;
}
