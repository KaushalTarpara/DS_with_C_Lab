#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"


// merge two sorted linked lists into a single sorted list
Node* mergeLists(Node *head1, Node *head2) {
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;    
    
    Node *mergedHead = NULL;
    
    if (head1->data <= head2->data) {
        mergedHead = head1;
        mergedHead->next = mergeLists(head1->next, head2);
    } else {
        mergedHead = head2;
        mergedHead->next = mergeLists(head1, head2->next);
    }
    
    return mergedHead;
}

// Main function 
int main(int argc, char* argv[]) {
    if (argc != 21) {
        printf("Please Enter 20 number in command line\n");
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
    
    //Sort both unsorted list
    list1=sortLL(list1);  
    list2=sortLL(list2);
    

    // Merge the two lists into a single sorted list
    Node* mergedList = mergeLists(list1, list2);
    printf("Merged list: ");
    printList(mergedList);
    return 0;
}
