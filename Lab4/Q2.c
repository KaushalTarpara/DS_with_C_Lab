#include <stdio.h>

#include <stdlib.h>

void main()
{
int queue[5], front = -1, rear = -1, choice = 0, i = 0;
	while(choice != 4)
	{
		//clrscr();
		printf("\n MAIN MENU (Basic Operations on Queue)");
		printf("\n 1. INSERT (ADD)");
		printf("\n 2. DELETE (REMOVE)");
		printf("\n 3. DISPLAY");
		printf("\n 4. EXIT");
		printf("\n Enter your choice (from 1 to 4): ");
		scanf("%d", &choice);
		switch(choice)
		{
                case 1:
                                        if(rear == 4)
                                        {
                                            printf("\n Queue is full (queue overflow)");
                                        }
                                        else
                                        {
                                            printf("\n Enter an element to insert at the rear end of the queue: ");
                                            rear = rear + 1;
                                            scanf("%d", &queue[rear]); 
                                            if(front == -1)
                                            {
                                                 front = 0;
                                            }
                                        }				
                                         break;
                case 2:
                                if(front == -1)
                                {
                                    printf("\n Queue is empty (queue underflow).");
                                }
                                else
                                {
                                        printf("\n Element deleted from the queue is %d", queue[front]);
                                        if(front == rear)
                                        {
                                            front = -1;
                                            rear = -1;
                                        }
                                        else
                                        {
                                            front = front + 1;
                                        }
                                }
                                break;
                case 3:
                                if(front == -1)
                                {
                                    printf("\n Queue is empty (queue underflow).");
                                }
                                else
                                {
                                    printf("\n Elements in the queue are: ");	
                                    for(i = front; i <= rear; i++)
                                    {
                                        printf("\n %d", queue[i]);
                                    }
                                }
                                break;
                case 4:
                                break;
                default:
                               printf("\n Invalid choice");
        }
                        printf("\n Press any key to continue...");
                    //	getch();
    }
}
