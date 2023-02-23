#include <stdio.h>
#define MAX 100

int top = -1;
char stack[MAX];

void push(char item) {
    if (top == MAX - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        printf("Error: Stack underflow\n");
        return 0;
    }
    return stack[top--];
}

char peek() {
    if (top == -1) {
        printf("Error: Stack is empty\n");
        return 0;
    }
    return stack[top];
}

void display() {
    if (top == -1) {
        printf("Error: Stack is empty\n");
        return;
    }
    int i;
    printf("Stack: ");
    for (i = top; i >= 0; i--) {
        printf("%c ", stack[i]);
    }
    printf("\n");
}

void change(int position, char item) {
    if (top == -1) {
        printf("Error: Stack is empty\n");
        return;
    }
    if (position > top + 1) {
        printf("Error: Invalid position\n");
        return;
    }
    stack[top - position + 1] = item;
}

int isFull() {
    if (top == MAX - 1) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    if (top == -1) {
        return 1;
    }
    return 0;
}

int main() {
    // testing the stack operations
    push('a');
    push('b');
    push('c');
    display();
    change(2, 'x');
    display();
    pop();
    display();
    printf("Top: %c\n", peek());
    printf("Full: %d\n", isFull());
    printf("Empty: %d\n", isEmpty());
    return 0;
}
