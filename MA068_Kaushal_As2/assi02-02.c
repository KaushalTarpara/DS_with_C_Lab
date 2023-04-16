#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// remove duplicates from an unsorted list
void removeDuplicates(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* current = head;
    while (current != NULL) {
        Node* runner = current;
        while (runner->next != NULL) {
            if (runner->next->data == current->data) {
                // duplicate node remove it
                Node* temp = runner->next;
                runner->next = temp->next;
                free(temp);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}

// Main function
int main() {
    Node* head = NULL;
    addNode(&head, 4);
    addNode(&head, 5);
    addNode(&head, 6);
    addNode(&head, 5);
    addNode(&head, 4);
    addNode(&head, 6);
    addNode(&head, 5);
    addNode(&head, 6);
   
    printf("Original list: ");
    printList(head);
   
    removeDuplicates(head);
    
    printf("List after removing duplicates: ");
    printList(head);
    return 0;
}
