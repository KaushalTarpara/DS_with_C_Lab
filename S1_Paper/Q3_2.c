#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100000

int stack[MAX_N], top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int main() {
    int n, m;
    int a[MAX_N], ans[MAX_N];

    // read input
    n = 8; // n is fixed in this example
    m = 3; // m is fixed in this example
    int indexes[] = {3, 6, 1}; // given indices
    int data[] = {1, 5, 3, 36, 55, 89, 100, 62}; // given array
    for (int i = 0; i < n; i++) {
        a[i] = data[i];
    }

    // find next greater elements using stack
    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty() && a[i] >= peek()) {
            pop();
        }
        if (isEmpty()) {
            ans[i] = -1;
        } else {
            ans[i] = peek();
        }
        push(a[i]);
    }

    // print answers for the given indices
    for (int i = 0; i < m; i++) {
        int idx = indexes[i];
        printf("%d ", ans[idx]);
    }
    printf("\n");

    return 0;
}
