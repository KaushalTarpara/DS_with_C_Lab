#include <stdio.h>
#include <stdlib.h>

// Circular doubly linked list 
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;



void insertFirst(int data) {
  
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

  
    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

   
    struct Node* last = head->prev;
    newNode->next = head;
    head->prev = newNode;
    newNode->prev = last;
    last->next = newNode;
    head = newNode;
}
void insertAt(int data, int position) {
    if (head == NULL || position == 1) {
        insertFirst(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    struct Node* current = head;
    for (int i = 1; i < position - 1; i++) {
        if (current == NULL) {
            printf("Invalid position!\n");
            return;
        }
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
}


void insertLast(int data) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;


    if (head == NULL) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    
    struct Node* last = head->prev;
    newNode->prev = last;
    newNode->next = head;
    last->next = newNode;
    head->prev = newNode;
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    struct Node* temp = head;

  
    if (head->next == head) {
        head = NULL;
    }
    else {
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
    }

    free(temp);
}


void deleteLast() {
    if (head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    struct Node* temp = head;

    // If there is only one node
    if ((head)->next == head) {
        head = NULL;
    }
    else {
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->prev->next = head;
        (head)->prev = temp->prev;
    }

    free(temp);
}
void deleteAt( int position) {
    if (head == NULL) {
        printf("List is empty, deletion not possible.\n");
        return;
    }

    if (position == 1) {
        deleteFirst(head);
        return;
    }

    struct Node* temp = head;
    int i;

    for (i = 1; i < position && temp->next != head; i++) {
        temp = temp->next;
    }

    if (i != position) {
        printf("Invalid position, deletion not possible.\n");
        return;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}


void displayList() {
   
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

   
    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

int main() {
   
    insertFirst(10);
    printf("List: ");   
    displayList();
    
    insertLast( 20);
    printf("List: ");
    displayList();
    
    insertAt(30, 2);
    printf("List: ");
    displayList();

    insertAt( 40, 1);
    printf("List: ");
    displayList();

    insertAt( 50, 6);
    printf("List: ");
    displayList();

  
    deleteFirst();
    printf("List: ");
    displayList();

    deleteLast();
    printf("List: ");
    displayList();

    deleteAt( 2);
    printf("List: ");
    displayList();


    return 0;
}
