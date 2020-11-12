// Write a program to add the given value K to each elements in the linked list

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

void add_k(struct node *list)
{
    int k;
    if(list == NULL)
        printf("List is empty\n");
    else
    {
        printf("\nEnter value k to add to all elements: ");
        scanf("%d", &k);
        while( list != NULL )
        {
            list -> data = (list -> data) + k;
            list = list -> next;
        }
    }
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

    add_k(head);

    printf("List after adding k is: \n");
    display(head);
}