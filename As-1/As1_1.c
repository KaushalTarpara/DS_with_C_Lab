#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE], temp_stack[MAX_SIZE];
int top = -1;

// function prototypes
void push(int value);
int pop();
void display();
void sort_stack();

int main() {
    int n, value;

    printf("Enter the number of elements to push into stack: ");
    scanf("%d", &n);

    printf("Enter the elements to push into stack: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    printf("Stack before sorting: ");
    display();

    sort_stack();

    printf("Stack after sorting: ");
    display();

    return 0;
}

// function to push an element onto the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

// function to remove and return the top element from the stack
int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

// function to display the elements of the stack
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

// function to sort the stack using a temporary array stack
void sort_stack() {
    int temp_top = -1;
    while (top >= 0) {
        int element = pop();
        while (temp_top >= 0 && temp_stack[temp_top] < element)
            push(temp_stack[temp_top--]);
        temp_stack[++temp_top] = element;
    }
    while (temp_top >= 0)
        push(temp_stack[temp_top--]);
}
