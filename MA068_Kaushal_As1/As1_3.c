#include <stdio.h>  
#define MAX 10  
// Defining the structure of stack type  
int top=-1;  
int stack[MAX];  
   
// function to push the element into the stack.  
void push(int num) {  
    if (top==MAX-1)  
        printf("Stack is Full...\n");  
    else {  
        stack[++top] = num;  
          
    }  
}  
   
// function to pop the element from the stack  
int pop() {  
    if (top==-1)  
        printf("Stack is Empty...\n");  
    else {  
     top = top - 1;  
        return stack[top+1];  
    }  
}  
   
// function to print the elements of stack.  
void printStack(){  
// condition to check whether the stack is empty or not.  
 if(top!=-1)  
{  
     int temp = pop();  
     printStack();  
     printf(" %d ", temp);  
     push(temp);  
    }  
}  
// function to insert the element at the bottom of the stack.  
void insertAtBottom(int item) {  
    if (top==-1) {  
        push(item);  
    } else {  
       int top = pop();  
        insertAtBottom(item);  
        push(top);  
    }  
}  
 // function to reverse the order of the stack.  
void reverse() {  
    if (top!=-1) {  
         int top = pop();  
        reverse();  
        insertAtBottom(top);  
    }  
}  
  
// Definition of main() method  
 int main() {  

    push(1);     // calling push() method  
    push(2);   // calling push() method  
    push(3);    // calling push() method  
    push(4);    // calling push() method  
    push(5);    // calling push() method  
   
    printf("Original Stack\n");  
    printStack();  
   
    reverse();  
   
    printf("\nReversed Stack\n");  
    printStack();  // calling printStack() method  
    return 0;  
}  