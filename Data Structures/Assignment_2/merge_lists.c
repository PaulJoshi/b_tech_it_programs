// Write a program to merge two linked lists without duplicate elements

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

void remove_duplicates(struct node *head)
{
    struct node *ptr1, *ptr2, *dup;
    ptr1 = head;

    while (ptr1 != NULL && ptr1 -> next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2 -> next != NULL)
        {
            if (ptr1 -> data == ptr2 -> next -> data)
            {
                dup = ptr2 -> next;
                ptr2 -> next = ptr2 -> next -> next;
                free(dup);
            }
            else
                ptr2 = ptr2 -> next;
        }
        ptr1 = ptr1 -> next;
    }
}

void merge(struct node *a, struct node *b)
{
    if( a != NULL && b!= NULL )
    {
        if (a -> next == NULL)
            a -> next = b;
        else
            merge(a -> next, b);
    }
    else
    {
        printf("Either a or b is NULL\n");
    }
    remove_duplicates(a);
}

void main()
{
    struct node *prev, *a, *b, *temp;
    int n, i;
    printf ("\nEnter number of elements in a: ");
    scanf("%d", &n);
    a = NULL;
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        temp = malloc(sizeof(struct node));
        scanf("%d", &temp -> data);
        temp -> next = NULL;
        if(a == NULL)
            a = temp;
        else
            prev -> next = temp;
        prev = temp;
    }
    printf ("\nEnter number of elements in b: ");
    scanf("%d", &n);
    b = NULL;
    printf("Enter elements: ");
    for(i = 0; i < n; i++)
    {
        temp = malloc(sizeof(struct node));
        scanf("%d", &temp -> data);
        temp -> next = NULL;
        if(b == NULL)
            b = temp;
        else
            prev -> next = temp;
        prev = temp;
    }
    merge(a,b);

    printf("\nThe merged list is: \n");
    display(a);
}