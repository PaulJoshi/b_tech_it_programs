// Write a recursive program to insert an element into a linked list in which elements stored in ascending order

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head, *list;

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

void sort(struct node* list)
{
    struct node *check, *head;
    head = list;
    int temp;
    if(list != NULL)
    while(list -> next != NULL)
    {
        check = list -> next;
        while(check != NULL)
        {
            if((list -> data) > (check -> data))
            {
                temp = list -> data;
                list -> data = check -> data;
                check -> data = temp;
             }
            else
                check = check -> next;
        }
        list = list -> next;
    }
}

struct node *add_item(struct node *list)
{
    struct node *temp;
    int item;
    printf("\nEnter Item to insert (0 to stop): ");
    scanf("%d", &item);
    if(item != 0)
    {
        temp = (struct node*)malloc(sizeof(struct node*));
        temp -> data = item;
        temp -> next = NULL;
        if(list == NULL)
        {
            head=temp;
            list=temp;
            sort(head);
            display(head);
            add_item(list);
        }
        else
        {
            list -> next=temp;
            sort(head);
            display(head);
            add_item(list -> next);
        }
    }
    return(head);
}

int item;
void main()
{
    list = NULL;
    head = NULL;
    printf("\nInsertion using Recursion\n");
    head = add_item(list);
    printf("\nLinked List: \n");
    display(head);
}