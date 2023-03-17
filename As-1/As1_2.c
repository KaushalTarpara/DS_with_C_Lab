#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    char data[MAX_SIZE];
} stack;

void push(stack *s, char c) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = c;
}

char pop(stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

int is_empty(stack *s) {
    return s->top == -1;
}

void sort_string(char *str) {
    stack main_stack, temp_stack;
    main_stack.top = -1;
    temp_stack.top = -1;
    int len = strlen(str);

    push(&main_stack, str[0]); // push first character

    for (int i = 1; i < len; i++) {
        char c = str[i];
        if (c >= main_stack.data[main_stack.top]) {
            push(&main_stack, c);
        } else {
            while (!is_empty(&main_stack) && main_stack.data[main_stack.top] > c) {
                push(&temp_stack, pop(&main_stack));
            }
            push(&main_stack, c);
            while (!is_empty(&temp_stack)) {
                push(&main_stack, pop(&temp_stack));
            }
        }
    }

    while (!is_empty(&main_stack)) {
        printf("%c", pop(&main_stack));
    }
    printf("\n");
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Sorted string: ");
    sort_string(str);
    return 0;
}
