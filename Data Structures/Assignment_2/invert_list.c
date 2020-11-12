// Write a program to invert the given linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *list)
{
    if( list == NULL )
        printf("List is empty\n");
    else
        while(list != NULL)
        {   
            printf("%d\n", list -> data);
            list = list -> next;
        }
}

struct node* invert(struct node* list)
{
    struct node* prev = NULL;
    struct node* next = NULL;
    while (list != NULL)
    {
        next = list -> next;
        list -> next = prev;
        prev = list;
        list = next;
    }
    return(prev);
}

void main()
{
    struct node *list, *temp, *head, *prev;
    int n, i, k;
    list = (struct node *)malloc(sizeof(struct node));
    
    printf ("\nEnter number of elements: ");
    scanf("%d", &n);
    head = NULL;
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        temp = malloc(sizeof(struct node));
        scanf("%d", &temp -> data);
        temp -> next = NULL;
        if(head == NULL)
            head = temp;
        else
            prev -> next = temp;
        prev = temp;
    }

    head = invert(head);
    
    printf("\nInverted Linked List is: \n");
    display(head);
}