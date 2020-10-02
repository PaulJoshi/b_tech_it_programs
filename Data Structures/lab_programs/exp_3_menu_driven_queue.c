/* Write a menu driven C program to implement queue using one dimensional array.
Perform the operations on the Queue (i) Insertion (ii) Deletion (iii) Is empty (iv) Is full
(v) Display */

#include<stdio.h>
#include<stdlib.h>
 
int queue_arr[10];
int rear = -1;
int front = -1;

int isEmpty()
{
    if( front == -1 || front == rear + 1 )
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear == 10-1)
        return 1;
    else
        return 0;
}

void insert()
{
    int item;
    if(isFull())
    {
        printf("\nQueue Overflow\n");
        return;
    }
    printf("Input the element for adding in queue : ");
        scanf("%d", &item);
    if(front == -1)
        front = 0;
    rear = rear + 1;
    queue_arr[rear] = item;
}

void del()
{
    int item;
    if(isEmpty())
    {
        printf("Queue Underflow\n");
        return;
    }
    item = queue_arr[front];
    front = front + 1;
    printf("Deleted element is  %d\n", item);
}

void display()
{
    int i;
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is :\n");
    for(i = front; i <= rear; i++)
        printf("%d  ", queue_arr[i]);
    printf("\n");
}

void main()
{
    int choice;
    printf("\n1.Insert\n");
    printf("2.Delete\n");
    printf("3.Check if empty\n");
    printf("4.Check if full\n");
    printf("5.Display all elements of the queue\n");
    printf("6.Quit\n");
    while(1)
    {
        
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                if(isEmpty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 4:
                if(isFull())
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;
            case 5:
                display();
                break;
            case 6:
                exit(1);
            default:
                printf("\nWrong choice\n");
        }
    }
}