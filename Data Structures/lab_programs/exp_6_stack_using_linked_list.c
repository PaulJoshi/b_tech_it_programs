/* Write a menu driven C program to implement stack using Singly Linked list. Perform the operations on the stack
 (i) Push (ii) Pop (iii) Is empty (iv) Display */

#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *next;
} *top;

int count = 0;

void push(int data)
{
    struct node *temp;
    if (top == NULL)
    {
        top = (struct node *)malloc(sizeof(struct node));
        top -> next = NULL;
        top -> data = data;
    }
    else
    {
        temp =(struct node *)malloc(sizeof(struct node));
        temp -> next = top;
        temp -> data = data;
        top = temp;
    }
    count++;
}

void pop()
{
    struct node *temp;
    temp = top;
 
    if (temp == NULL)
    {
        printf("\nStack is empty");
        return;
    }
    else
        temp = temp -> next;
    printf("\n%d popped", top -> data);
    free(top);
    top = temp;
    count--;
}

void isempty()
{
    if (top == NULL)
        printf("\nStack is empty");
    else
        printf("\nStack is not empty with %d elements", count);
}

void display()
{
    struct node *temp;
    temp = top;
 
    if (temp == NULL)
    {
        printf("Stack is empty");
        return;
    }
 
    while (temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
}
 
void main()
{
    int item, ch;
 
    printf("\n1 - Push");
    printf("\n2 - Pop");
    printf("\n3 - Isempty");
    printf("\n4 - Display");
    printf("\n5 - Exit");
 
    top = NULL;
 
    while (1)
    {
        printf("\nEnter choice : ");
        scanf("%d", &ch);
 
        switch (ch)
        {
            case 1:
                printf("Enter data : ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                isempty();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default :
                printf("Invalid Option");
                break;
        }
    }
}