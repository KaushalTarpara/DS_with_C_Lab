#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for book records
struct Book {
    char name[50];
    float price;
    int pages;
};

// Stack structure
struct Stack {
    struct Book arr[MAX_SIZE];
    int top;
};

// Function prototypes
void push(struct Stack *s, struct Book b);
struct Book pop(struct Stack *s);
int is_empty(struct Stack *s);
int is_full(struct Stack *s);

int main() {
    struct Stack s;
    s.top = -1;

    int n;
    printf("Enter the number of books: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        struct Book b;
        printf("Enter the name, price, and number of pages of book %d: ", i+1);
        scanf("%s %f %d", b.name, &b.price, &b.pages);
        push(&s, b);
    }

    printf("\nOriginal stack of books:\n");
    for (int i = 0; i <= s.top; i++) {
        printf("%s %.2fRP %d pages\n", s.arr[i].name, s.arr[i].price, s.arr[i].pages);
    }

    // Sort the stack of books based on price in ascending order
    for (int i = 0; i <= s.top; i++) {
        for (int j = i+1; j <= s.top; j++) {
            if (s.arr[i].price > s.arr[j].price) {
                struct Book temp = s.arr[i];
                s.arr[i] = s.arr[j];
                s.arr[j] = temp;
            }
        }
    }

    printf("\nSorted stack of books based on price:\n");
    for (int i = 0; i <= s.top; i++) {
        printf("%s %.2fRP %d pages\n", s.arr[i].name, s.arr[i].price, s.arr[i].pages);
    }

    return 0;
}

// Push function to add a book record to the stack
void push(struct Stack *s, struct Book b) {
    if (is_full(s)) {
        printf("Error: stack overflow\n");
        exit(1);
    }
    s->arr[++s->top] = b;
}

// Pop function to remove and return the top book record from the stack
struct Book pop(struct Stack *s) {
    if (is_empty(s)) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    return s->arr[s->top--];
}

// Check if the stack is empty
int is_empty(struct Stack *s) {
    return s->top == -1;
}

// Check if the stack is full
int is_full(struct Stack *s) {
    return s->top == MAX_SIZE-1;
}
