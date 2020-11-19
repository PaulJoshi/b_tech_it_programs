/* Write a menu driven C program to implement Queue using Singly Linked list. Perform the operations on the Queue
 (i) Insertion (ii) Deletion (iii) Is empty (iv) Display */

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next;
} *front, *rear, *temp;

int count = 0;

void insert(int data)
{
    if (rear == NULL)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear -> next = NULL;
        rear -> data = data;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        rear -> next = temp;
        temp -> data = data;
        temp -> next = NULL;
        rear = temp;
    }
    count++;
}

void delete()
{
    temp = front;
 
    if (temp == NULL)
    {
        printf("\n Queue is empty");
        return;
    }
    else
    {
        if (temp -> next != NULL)
        {
            temp = temp -> next;
            printf("\n deleted value : %d", front -> data);
            free(front);
            front = temp;
        }
        else
        {
            printf("\n deleted value : %d", front -> data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
    }
}

void isempty()
{
    if ((front == NULL) && (rear == NULL))
        printf("\n Queue is empty");
    else
        printf("Queue is not empty and has %d elements\n", count);
}

void display()
{
    temp = front;
 
    if ((temp == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (temp != rear)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    if (temp == rear)
        printf("%d", temp -> data);
}
 
void main()
{
    int item, ch;
    front = rear = NULL;
 
    printf("\n 1 - Insert");
    printf("\n 2 - Delete");
    printf("\n 3 - Isempty");
    printf("\n 4 - Display");
    printf("\n 5 - Exit");
    while (1)
    {
        printf("\n Enter choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                isempty();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice");
                break;
        }
    }
}