#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node to the end of the list
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

// Function to print all elements of the list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to find all possible subsets of a given set
void findAllSubsets(Node* head) {
    int size = 0;
    Node* current = head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    int numSubsets = 1 << size; // 2^size
    for (int i = 0; i < numSubsets; i++) {
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

// Main function to test the linked list and subset functions
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
