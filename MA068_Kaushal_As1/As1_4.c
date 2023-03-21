#include <stdio.h>
#define MAXSIZE 10

int stack[MAXSIZE];
int top = -1;

void push(int value) {
  if (top == MAXSIZE-1) {
    printf("Error: Stack is full\n");
    return;
  }
  stack[++top] = value;
}

int pop() {
  if (top == -1) {
    printf("Error: Stack is empty\n");
    return -1;
  }
  return stack[top--];
}

void insert(int value) {
  if (top == -1 || value > stack[top] ){
    push(value);
    return;
  }
  int temp = pop();
  insert(value);
  push(temp);
}

void sort() {
  if (top == -1) {
    return;
  }
  int temp = pop();
  sort();
  insert(temp);
}

int main() {
  push(-3);
  push(14);
  push(18);
  push(-5);
  push(30);


  sort();

  while (top != -1) {
    printf("%d ", pop());
  }

  return 0;
}
