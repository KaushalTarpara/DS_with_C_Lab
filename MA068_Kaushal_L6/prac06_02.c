#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*top=NULL;


struct node* createNode(int info){

    struct node *newNode=(struct node *)malloc(sizeof(struct node ));
    newNode->next=NULL;
    newNode->data=info;
    return newNode;
}

void push(int info){

    struct node* tnode =createNode(info);
    if(top==NULL){
        top=tnode;
        return ;
    }
    tnode->next=top;
    top=tnode;
   

}

void diplay(){
    if(top==NULL){
        printf("\n Empty List");
        return ;
    }
      struct node *temp=top;
        printf("\nDisplay Stack :\n");
        while(temp){  
            // printf("");         
            printf("| %d |\n",temp->data);
            temp=temp->next;
        }
        printf("-----");
           //temp->next=tnode;
        printf("\n");
    free(temp);

}
struct node* pop(){
    if(top==NULL){
        printf("List Empty");
        
    }else{
     struct node* tnode =top;
     top=top->next;
     return tnode;   

    }

}
struct node* peep(int loc){

    int count=0;
      if(top==NULL){
        printf("List Empty");
        
    }else{
     struct node* tnode =top;
     while(tnode->next && count != loc)
     {
        tnode=tnode->next;
        count++;
     }
     //top=top->next;
     printf("Pop Value :%d\n",tnode->data);
     return tnode;   

    }

    

}
void change(int loc,int info){
        int count =2; 
          struct node *temp=top;
          if(loc==1){
            push(info);
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
int main(){

    push(1);
    push(3);
    push(6);  
    diplay();
   
    peep(0);
   
   // struct node* peep=peep(2);  
   //  printf("Peep Element is :%d \n",peep->data);
    //insertDes(10,3);
    pop();
    //printf("\n Deleted at Last :%d",pop());
    diplay();

    change(0,4);

    
    pop();
    diplay();

    return 0;
}
