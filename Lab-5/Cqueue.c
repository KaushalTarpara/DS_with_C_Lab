#include <stdio.h>

#define MAX_QUEUE_SIZE 10

int queue[MAX_QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if ((rear + 1) % MAX_QUEUE_SIZE == front) {
        printf("Queue is full!\n");
        return;
    }
    rear = (rear + 1) % MAX_QUEUE_SIZE;
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
        front = (front + 1) % MAX_QUEUE_SIZE;
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
        i = (i + 1) % MAX_QUEUE_SIZE;
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
    enqueue(50);
    enqueue(60);
    enqueue(70);
    enqueue(80);
    display();
    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());
    display();
    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());
    printf("Dequeuing element: %d\n", dequeue());
    display();
    return 0;
}