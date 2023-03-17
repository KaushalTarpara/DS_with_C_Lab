/*
 * C Program to Implement Queues using Stacks
 */
#include <stdio.h>
#include <stdlib.h>

int st1[100], st2[100];
int top1 = -1, top2 = -1;
int count = 0;
  

    
 
/*Function to push the element on to the stack*/
void push1(int data)
{
    st1[++top1] = data;
}
 
/*Function to pop the element from the stack*/
int pop1()
{
    return(st1[top1--]);
}
 
/*Function to push an element on to stack*/
void push2(int data)
{
    st2[++top2] = data;
}
 
/*Function to pop an element from th stack*/
 
int pop2()
{
    return(st2[top2--]);
}
 
/*Function to add an element into the queue using stack*/
void enqueue()
{
    int data, i;
 
    printf("Enter data into queue");
    scanf("%d", &data);
    push1(data);
    count++;
}
 
/*Function to delete an element from the queue using stack*/
 
void dequeue()
{
    int i;
 
    for (i = 0;i <= count;i++)
    {
        push2(pop1());
    }
    pop2();
    count--;
    for (i = 0;i <= count;i++)
    {
        push1(pop2());
    }
}
 
/*Function to display the elements in the stack*/
 
void display()
{
    int i;
    printf("\nQueue : ");
    for (i = 0;i <= top1;i++)
    {
        printf(" %d -- ", st1[i]);
    }
}
void main()
{
    int ch;
 
  enqueue();
   enqueue();
    enqueue();

     display();

     dequeue();
      dequeue();
       display();
   }
 