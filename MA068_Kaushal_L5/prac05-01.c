#include <stdio.h>
#include "intqueue.h"
#define MAX 10
int queue[MAX];

int front=-1;
int rear=-1;
int main() {
    
    enqueue(queue,&front,&rear,MAX,10);
    enqueue(queue,&front,&rear ,MAX,20);
    enqueue(queue,&front,&rear ,MAX,30);
    enqueue(queue,&front,&rear ,MAX,40);
    display(queue,&front,&rear );
    printf("Dequeuing element: %d\n", dequeue(queue,&front,&rear ));
    printf("Dequeuing element: %d\n", dequeue(queue,&front,&rear ));
    display(queue,&front,&rear );
    enqueue(queue,&front,&rear ,MAX,80);
    display(queue,&front,&rear );
   return 0;
}