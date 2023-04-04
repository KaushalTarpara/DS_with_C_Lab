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

// Function to find the middle element of the linked list in one pass
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

// Main function to test the linked list and findMiddle function
int main(int argc, char* argv[]) {
    if (argc != 31) {
        printf("Usage: ./find_middle int1 int2 ... int30\n");
        return 1;
    }
    // Create the singly linked list with the given integers
    Node* head = NULL;
    for (int i = 1; i <= 30; i++) {
        int data = atoi(argv[i]);
        addNode(&head, data);
    }
    printf("Linked list: ");
    printList(head);
    // Find the middle element of the list
    Node* middle = findMiddle(head);
    printf("Middle element: %d\n", middle->data);
    return 0;
}
