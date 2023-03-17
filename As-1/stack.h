#include <stdio.h>

void push(int *stack,int *top,int MAX,int data){

	if(*top == MAX-1){
		printf("Stack is Full\n");
		return ;
	}
	*top=*top+1;
	stack[*top]=data;
}

int pop(int *stack,int *top){

	if(*top==-1){
		printf("Stack is Empty\n");
	return 0;
	}
	int element = stack[*top];
    *top = *top - 1;
	//printf("\n in pop top =%d",*top);
    return element;
 
}
void display(int *stack,int *top){
    
	if(*top==-1){
		printf("Stack is Empty\n");
		return ;		
	}
	int temp=*top;
	while(temp!=-1){
	
		printf("| %d |\n",stack[temp--]);		
			
	}
	printf("-----");
		 printf("top =%d",*top);
}
// void sortStack(int *stack,int *top,int MAX){
// 	int tmpTop=-1, tmpStack[MAX];
// 	while (*top >= 0) {
//          int element = pop(stack, top);
//          while (tmpTop >= 0 && tmpStack[tmpTop] > element) {
//              push(stack, top,MAX,pop(tmpStack, &tmpTop));
//          }
//          push( tmpStack, &tmpTop,MAX,element);
//      }
// 	 printf("Stack soreted");

// }

// void push(int element, int stackArray[], int *top,int MAX) {
//     if (*top >= MAX - 1) {
//         printf("Stack overflow!\n");
//         return;
//     }
//     *top = *top + 1;
//     stackArray[*top] = element;
// }

// int pop(int stackArray[], int *top) {
//     if (*top < 0) {
//         printf("Stack underflow!\n");
//         return -1;
//     }
//     int element = stackArray[*top];
//     *top = *top - 1;
//     return element;
// }

// void display(int stackArray[], int top) {
//     if (top < 0) {
//         printf("Stack is empty!\n");
//         return;
//     }
//     printf("Stack elements are:\n");
//     for (int i = top; i >= 0; i--) {
//         printf(" | %d |\n", stackArray[i]);
//     }
//     printf("-----\n");
// }

// void sortStack(int stackArray[],int *top,int MAX) {
//     int tmpTop=-1;
// 	while (*top >= 0) {
//         int element = pop(stackArray, &top);
//         while (tmpTop >= 0 && tmpStack[tmpTop] > element) {
//             push(pop(tmpStack, &tmpTop), stackArray, &top,MAX);
//         }
//         push(element, tmpStack, &tmpTop,MAX);
//     }
// }


// void reverseStack(int* stack, int* top) {
//     if (isEmpty(top)) {
//         int temp = pop(stack, top);
//         reverseStack(stack, top);
//         insertAtBottom(top,temp);
//     }
// }


// void insertAtBottom(int top,int item,int* stack){
//     if(isEmpty(top)){
//         push(stack,top,item);
//     }
// }

// void push(int *stack,int *top, int max, char val)
// {
// 	if((*top)==max-1)
// 	{
// 		printf("Overflow\n");		
// 	}else
// 	{	stack[++(*top)] = val;
// 	}
// }

// int pop(int *stack,int *top)
// {
// 	if(top==-1)
// 	{
// 		printf("Underflow\n");
// 		return 0;
// 	}
// 	return stack[(*top)--];
// 	//printf("Poped Element : %d \n",stack[top--]);
// }

// void display(int *stack,int top)
// {
// 	if(top==-1)
// 	{
// 		printf("Underflow\n");
// 		return;
// 	}
// 	printf("\n");
// 	for(int i=top;i>=0;i--)
// 	{
// 		printf("%d ",stack[i]);
// 	}
// 	printf("\n");
// }
// int isEmpty(int top)
// {
//    return (top==-1);
    
// }