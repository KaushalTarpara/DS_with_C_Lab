#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node* next;

}node;

node *front=NULL,*rear=NULL;


void enqueue(int info){

    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=info;
    newnode->next=NULL;

  
    if(rear==NULL){
        front=rear=newnode;
        newnode->next=front;
    }else{
        //temp->next=rear;        
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }


}
void display(){
    if(front==NULL)
        printf("\nQueue Empty");
    else{

        node *temp=front;
        printf("Queue : ");
        do
        {
               printf(" %d--> ",temp->data);
               temp=temp->next; 
        }while(temp!=front);
        printf("\n");
    }

    
}

void dequeue(){
    if(front==NULL){
        printf("Queue is Empty\n");
    
    }else{
       // node *temp=rear;
        printf(" \n Dequqe element :%d\n ",front->data );
        rear->next=front->next;
        front=front->next;
    }


}
int main(){

    enqueue(5);
    enqueue(1);
    enqueue(4);
    enqueue(2);
    display();


   dequeue();
   display();
    return 0;
}