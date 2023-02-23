#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char data) {
    stack[++top] = data;
}

char pop() {
    return stack[top--];
}


int is_valid_pair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

int is_valid_parentheses(char* parentheses) {
    int i;
    for (i = 0; i < strlen(parentheses); i++) {
        char c = parentheses[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            
            if (top == -1) {
                return 0; // Closing bracket with no opening bracket
            }


            char top_char = pop();
            if (!is_valid_pair(top_char, c)) {
                return 0; // Invalid pair of brackets
            }
        }
    }
    return (top == -1); // If the stack is empty, the parentheses are valid
}

int main() {
    char parentheses[] = "(({}[]))";
    if (is_valid_parentheses(parentheses)) {
        printf("The parentheses are valid!\n");
    } else {
        printf("The parentheses are not valid.\n");
    }
    return 0;
}
