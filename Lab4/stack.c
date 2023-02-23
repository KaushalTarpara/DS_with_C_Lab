#include "stack.h"    /* Always include the header file that declares something
                     * in the C file that defines it. This makes sure that the
                     * declaration and definition are always in-sync.  Put this
                     * header first in foo.c to ensure the header is self-contained.
                     */
#include <stdio.h>
                       
/**
 * This is the function definition.
 * It is the actual body of the function which was declared elsewhere.
 */

void push(char item ,int top,int MAX,int stack) {
    if (top == MAX - 1) {
        printf("Error: Stack overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop(int top,int stack) {
    if (top == -1) {
        printf("Error: Stack underflow\n");
        return 0;
    }
    return stack[top--];
}

char peek(int top, int stack) {
    if (top == -1) {
        printf("Error: Stack is empty\n");
        return 0;
    }
    return stack[top];
}

void display(int top,int stack) {
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

void change(int position, char item,int top,int stack) {
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

int isFull(int top,int MAX) {
    if (top == MAX - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(int top) {
    if (top == -1) {
        return 1;
    }
    return 0;
}