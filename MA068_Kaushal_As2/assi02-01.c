#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// Function to find all possible subsets 
void findAllSubsets(Node* head) {
    int size = 0;
   
    Node* current = head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
 
    int numSubsets = 1 ;
    for (int i = 0; i < size; i++) {
        numSubsets *= 2;
    }

    printf("{NULL}\n");
    for (int i = 1; i < numSubsets; i++) {
        printf("{");
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {
                // The j-th element is in this subset
                Node* current = head;
                for (int k = 0; k < j; k++) {
                    current = current->next;
                }
                printf("%d,", current->data);
            }
        }
        printf("\b}\n");
    }
    
}

// Main function 
int main() {
    Node* head = NULL;
    addNode(&head, 4);
    addNode(&head, 5);
    addNode(&head, 6);
   
    printf("Elements of the set: ");
    printList(head);

    printf("All possible subsets:\n");
    findAllSubsets(head);
    
    return 0;
}
