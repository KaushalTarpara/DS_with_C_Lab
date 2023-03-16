#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
}*head=NULL;


struct node* createnode(int info){

    struct node *newnode=(struct node *)malloc(sizeof(struct node ));
    newnode->next=NULL;
    newnode->data=info;
    return newnode;
}
void insertEnd(int info){

    struct node* tnode =createnode(info);
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

void bubbleSort() {
    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data =ptr1->next->data;
                ptr1->next->data = temp;

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void display() {
    struct node *current = head;

    printf("\nLinked List : head -> ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    insertEnd(1);
    insertEnd(3);
    insertEnd(2);  

    display();

    bubbleSort();

    display();

    
        return 0;
}
