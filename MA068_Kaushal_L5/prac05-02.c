#include <stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int data) {
    if ((rear + 1) % MAX == front) {
        printf("Queue is full!\n");
        return;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = data;
    if (front == -1) {
        front = 0;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return data;
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are:\n");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
    printf("%d ", queue[rear]);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());
    display();
    enqueue(80);
    display();
   return 0;
}