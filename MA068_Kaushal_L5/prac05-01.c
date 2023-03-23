#include <stdio.h>
#include "queueint.h"
#define max 10

int queue[max];

// void Enqueue(int data);
// int Dequeue();
// void display();
int main(){

    Enqueue(queue,max,4);
    Enqueue(queue,max,3);
    
    display(queue);
    printf("\n Dequeue element %d",Dequeue(queue));
    
    Enqueue(queue,max,7);
    Enqueue(queue,max,2);
    Enqueue(queue,max,5);
    Enqueue(queue,max,9);
    
    display(queue);
    printf("\n Dequeue element %d",Dequeue(queue));
    
    Enqueue(queue,max,3);
    Enqueue(queue,max,9);
    
    display(queue);

    return 0;
}