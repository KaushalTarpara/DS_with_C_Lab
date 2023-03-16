#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*head=NULL;


struct node* createNode(int info){

    struct node *newNode=(struct node *)malloc(sizeof(struct node ));
    newNode->next=NULL;
    newNode->data=info;
    return newNode;
}

void insertFirst(int info){

    struct node* tnode =createNode(info);
    if(head==NULL){
        head=tnode;
        return ;
    }
    tnode->next=head;
    head=tnode;
   

}
void insertEnd(int info){

    struct node* tnode =createNode(info);
    if(head==NULL){
        head=tnode;
    }else{
        struct node *temp=head;
        while(temp->next){
             
                      temp=temp->next;
        }
           temp->next=tnode;

    }
    //free(temp);

}

void insertLoc(int loc,int info){
        
          int count =2; 
          struct node *temp=head;
          if(loc==1){
            insertFirst(info);
          }else{
            while(temp->next && count!=loc){
                count++;
                temp=temp->next;
            }
            struct node* tnode =createNode(info);
            tnode->next=temp->next;
            temp->next=tnode;
          }

}
void diplay(){
    if(head==NULL){
        printf("\n Empty List");
        return ;
    }
      struct node *temp=head;
        while(temp){             
            printf("%d->",temp->data);
            temp=temp->next;
        }
           //temp->next=tnode;
        printf("\n");
    free(temp);

}
struct node* deleteFisrt(){
    if(head==NULL){
        printf("List Empty");
        
    }else{
     struct node* tnode =head;
     head=head->next;
     return tnode;   

    }

}

struct node* deleteLast(){
   struct node *temp=head;
        while(temp->next->next){             
            
            temp=temp->next;
        }
        temp->next=NULL;
           //temp->next=tnode;
    return temp;  
  //  free(temp);

}

struct node* deleteLoc(int  loc){
          int count =2; 
          struct node *temp=head;
          if(loc==1){
            deleteFisrt();
          }else{
            while(temp->next->next && count!=loc){
                count++;
                temp=temp->next;
            }
         //   struct node* tnode =createNode(info);
            temp->next=temp->next->next;
            //temp->next=tnode;
          }

}
struct node* deleteVal(int  val){
         // int count =2; 
          struct node *temp=head;
            while(temp->next){
                if(temp->next->data==val )
                {
                    temp->next=temp->next->next;
                    
                }    
                temp=temp->next;
               
            }  
}

int main(){

    insertEnd(2);
    insertEnd(4);
    diplay();
    insertFirst(1);
    insertFirst(3);
    insertFirst(6);  
    diplay();

    //insertDes(10,3);
    deleteFisrt();
    //printf("\n Deleted at Last :%d",deleteFisrt());
    diplay();

    deleteLast();
    //printf("\n Deleted at Last :%d",deleteLast());
    diplay();
    
    insertLoc(3,10);
    diplay();

    deleteLoc(3);
    diplay();


    deleteVal(1);
    diplay();

    return 0;
}
