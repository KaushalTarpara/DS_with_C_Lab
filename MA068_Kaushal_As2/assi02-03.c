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

// Function to merge two sorted linked lists into a single sorted list
Node* mergeLists(Node* list1, Node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }
    if (list1->data < list2->data) {
        list1->next = mergeLists(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeLists(list1, list2->next);
        return list2;
    }
}

// Main function to test the linked list and mergeLists function
int main(int argc, char* argv[]) {
    if (argc != 21) {
        printf("Usage: ./merge_lists int1 int2 ... int20\n");
        return 1;
    }
    // Divide the 20 integers into two unsorted lists of 10 elements each
    Node* list1 = NULL;
    Node* list2 = NULL;
    for (int i = 1; i <= 20; i++) {
        int data = atoi(argv[i]);
        if (i <= 10) {
            addNode(&list1, data);
        } else {
            addNode(&list2, data);
        }
    }
    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);
    // Merge the two lists into a single sorted list
    Node* mergedList = mergeLists(list1, list2);
    printf("Merged list: ");
    printList(mergedList);
    return 0;
}
