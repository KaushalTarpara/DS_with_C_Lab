#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node* next;

}node;

node *head=NULL,*tail=NULL;

void insertLast(int info){

    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=info;
    newnode->next=NULL;
  
    if(tail==NULL){
        head=tail=newnode;
        newnode->next=head;
    }else{
        tail->next=newnode;
        tail=newnode;
        tail->next=head;
    }


}
void insertFirst(int info){

    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=info;
    newnode->next=NULL;

      if(tail==NULL){
        head=tail=newnode;
        // newnode->next=head;
    }else{
        newnode->next=head;
        head=newnode;
        tail->next=newnode;
        

    }

}
void insertLoc(int info,int loc){

    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=info;
    newnode->next=NULL;

    node *temp=head;
    int count=2;

    while(count!=loc){
        temp=temp->next;
        count++;       
    }
    newnode->next=temp->next;
    temp->next=newnode;

}

void deleteFirst(){
    if(head==NULL){
        printf("Queue is Empty\n");
    
    }else{
        printf(" \n Dequqe element :%d\n ",head->data );
    
        tail->next=head->next;
       
        head=tail->next;
    }


}

void deleteLast(){
    if(head==NULL){
        printf("Queue is Empty\n");
    
    }else{
        node *temp=head;
        printf(" \n Dequqe element :%d\n ",tail->data );
        while(temp->next!=tail){
              temp=temp->next;
        }
        tail=temp;
        temp->next=head;
        
    }


}
void deleteLoc(int loc){
    int count=2;
    if(loc==1){
      deleteFirst();
    }else{
        node *temp=head;
          
        while(loc!=count){
            temp=temp->next;
            count++;
        }
        printf(" \n Dequqe element :%d\n ",temp->next->data );
        temp->next=temp->next->next;
    }

}
void display(){
    if(head==NULL)
        printf("\nQueue Empty");
    else{

        node *temp=head;
        printf("Queue : ");
        do
        {
               printf(" %d--> ",temp->data);
               temp=temp->next; 
        }while(temp!=head);
        printf("\n");
    }

    
}

int main(){

    insertLast(5);
    insertLast(1);
    insertLast(7);
   
    display();

    insertFirst(20);
    display();

    insertLoc(68,3);
    display();
    insertLoc(18,2);
    display();
    
    
    deleteFirst();
    display();
   
    deleteLast();
    display();

    deleteLoc(2);
    display();
    
    return 0;
}