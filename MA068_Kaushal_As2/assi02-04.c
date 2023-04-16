#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


// Function to find the middle element 
Node* findMiddle(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    
    Node* slowPtr = head;
    Node* fastPtr = head;
    
    while (fastPtr != NULL && fastPtr->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }
    
    return slowPtr;
}

// Main function 
int main(int argc, char* argv[]) {
    
    if (argc != 31) {
        printf("Please Enter 30 number in command line\n");
        return 1;
    }
    
    Node* head = NULL;
    for (int i = 1; i <= 30; i++) {
        int data = atoi(argv[i]);
        addNode(&head, data);
    }
    
    printf("Linked list: ");
    printList(head);
   
    
    Node* middle = findMiddle(head);
    printf("Middle element: %d\n", middle->data);
    return 0;
}
