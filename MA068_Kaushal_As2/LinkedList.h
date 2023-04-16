#include <stdio.h>
#include <stdlib.h>


// structure of a singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// create a new node 
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add a new node to the end of the list
void addNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}


// Print all elements of the list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    
}
// bubbleSort For Linked List
Node* sortLL(Node* headRef) {
    if (headRef == NULL) {
        return NULL;
    }

    int swapped = 1;
    Node* current;
    Node* last = NULL;

    while (swapped) {
        swapped = 0;
        current = headRef;

        while (current->next != last) {
            if (current->data > current->next->data) {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    }

    return headRef;
}
