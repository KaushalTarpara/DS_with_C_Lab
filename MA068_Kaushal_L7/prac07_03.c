#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    struct Node* pre;
    int data;   
    struct Node* next;

}node;

node *head=NULL,*tail=NULL;


void insertAtLast(int info){

    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=info;
    newnode->next=NULL;
    newnode->pre=NULL;
  
    if(head==NULL ){
        head=tail=newnode;    
    }else{
        tail->next=newnode;
        newnode->pre=tail;
        tail=newnode;
    }


}
void insertAtFirst(int info){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=info;
    newnode->next=NULL;
    newnode->pre=NULL;
  
    if(head==NULL){
        head=tail=newnode;
    }else{
        newnode->next=head;
        //newnode->pre=head;
        head=newnode;
    }
}
void insertLoc(int info,int loc){

        loc--;
        if(loc==1){
            insertAtFirst(info);
        }else{
            node *newnode=(node*)malloc(sizeof(node));
            newnode->data=info;
            newnode->next=NULL;
            newnode->pre=NULL;

            node *temp=head;
            while(--loc){
                temp=temp->next;
            }

            newnode->next=temp->next;
            newnode->pre=temp;
            temp->next=newnode;
            temp->next->pre=newnode;           

        }
}
void deleteLast(){
    if(tail==NULL){
        printf("\nLinked List is Empty...");
    }else{
        
        tail=tail->pre;
        tail->next=NULL;
    }
}
void deleteFirst(){
    if(head==NULL){
          printf("\nLinked List is Empty...");
    }else if(head->next==NULL){
        head=NULL;
    }
    else{
        head=head->next;
        head->pre=head;
    }

 }
void deletePosition(int pos)
{
	int i=1;
	node *temp, *position;
	temp=head;
	if(head==NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		if(pos==1)
		{
			deleteFirst();
            return;
		}
        
		while(i<pos-1)
		{
			temp=temp->next;
			i++;
		}
		position=temp->next;
		if(position->next!=NULL)
		{
			position->next->pre=temp;
		}
		temp->next=position->next;
		free(position);
	}
}
void display(){
    if(head==NULL)
        printf("\nQueue Empty");
    else{

        node *temp=head;
        printf("Doubly Linked List : ");
        while(temp!=NULL)
        {
               printf(" %d <--> ",temp->data);
               temp=temp->next; 
        }
        printf("\n\n");
    }

    
}

int main(){

    insertAtLast(10);
    display();
    insertAtLast(20);
    display();
    insertAtLast(30);
    display();

    
    
    insertAtFirst(-10);
    display();
    insertAtFirst(-20);
    display();

    insertLoc(45,3);
    display();

   
    deleteLast();
    display();
    deleteLast();
    display();
   
    deleteFirst();
    display();
    deleteFirst();
    display();

    deletePosition(2);
    display();
    
    deletePosition(1);
    display();

    return 0;
}