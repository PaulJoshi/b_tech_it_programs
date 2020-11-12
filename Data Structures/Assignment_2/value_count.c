// Write a program to find the number of occurences of given data in a linked list

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

void count_occurence(struct node* list) 
{
    int count = 0, search_item;
    printf("\nEnter value to count: ");
    scanf("%d", &search_item);
    while (list != NULL)
    { 
        if (list -> data == search_item) 
            count++; 
        list = list -> next; 
    } 
    printf("%d occurs %d times\n\n", search_item, count);
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

    count_occurence(head);
}