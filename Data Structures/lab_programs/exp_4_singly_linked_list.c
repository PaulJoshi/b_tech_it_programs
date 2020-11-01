/* Write a menu driven C program to implement a singly linked list and perform the
following operations on it:
    (i) Insertion
        a. at the beginning
        b. at the end
        c. after a specified node.
    (ii) Deletion
        a. at the beginning
        b. at the end
        c. a specified node.
    (iii) Display the linked list.
    (iv) Search an element in the list. */

#include<stdlib.h>
#include<stdio.h>

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
    {
        while(list != NULL)
        {   
            printf("%d\n", list -> data);
            list = list -> next;
        }
    }
}

void *insert_end(struct node *list, int item)
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        temp -> data = item;
        temp -> next = NULL;
        if( list == NULL )
            list = temp;
        else
        {
            while( list -> next != NULL)
                list = list -> next;
            list -> next = temp;
        }
}

struct node *insert_front(struct node *list, int item)
{
    struct node *temp, *head;
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = item;
    temp -> next = list;
    head = temp;
    return (head);
}

void *insert_after(struct node *list, int item, int search_item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> data = item;
    temp -> next = NULL;
    if( list != NULL )
        while( list != NULL )
        {
            if( list -> data == search_item)
            {   
                temp -> next = list -> next;
                list -> next = temp;
                break;
            }
            else
                list = list -> next;
        }
}

struct node *delete_front(struct node *list)
{
    if( list == NULL )
    {
        printf("List is empty\n");
        return(NULL);
    }
    else
    {
        struct node *head, *temp;
        printf("%d removed from the front\n", list -> data);
        temp = list;
        list = list -> next;
        free(temp);
        head = list;
        return(head);
    }
}

void *delete_end(struct node *list)
{ 
    if (list != NULL)
    {
        if (list -> next == NULL)
        { 
            free(list); 
        } 
        else
        {
            struct node *second_last = list;
            while (second_last -> next -> next != NULL) 
                second_last = second_last -> next; 

            printf("%d removed from the end\n", second_last -> next -> data);
            free(second_last -> next); 
            second_last -> next = NULL; 
        }
    }
}

struct node *delete(struct node *list, int search_item)
{
    int flag = 0;
    if (list == NULL)
    {   
        printf("List is empty\n");
        return(NULL);
    }

    else
    {   
        struct node *temp, *back, *head;
        head = list;
        
        if( list -> data == search_item )   // If first item is the search_item
        {   
            temp = list;
            list = list -> next;
            free(temp);
            head = list;
        }
        else
        {
            while( list -> next != NULL )
            {   
                if( list -> data == search_item )
                {   
                    temp = list;
                    back -> next = list -> next;
                    printf("%d removed\n", search_item);
                    free(temp);
                    flag = 1;
                    return(head);
                }
                else
                {
                    back = list;
                    list = list -> next;
                }
            }
            printf("Element not found\n");
        }
        return(head);
    }
}

int search(struct node *list, int search_item)
{ 
    if( list == NULL )
        printf("List is empty\n");
    else
    {
        struct node *temp = list;
        int count = 1;
        while (temp != NULL) 
        { 
            if (temp -> data == search_item) 
                return(count); 
            temp = temp -> next; 
            count++;
        }
        return(-1);
    }
    return(0);
} 

void main()     
{
    int i, choice, new_item, search_item, pos;
    struct node *head;
    head = NULL;

    printf("-------------------------------\n");
    printf("\nOPTIONS\n\n");
    printf("1. Insert at the Beginning\n");
    printf("2. Insert at the End\n");
    printf("3. Insert after Specified node\n");
    printf("4. Delete from Beginning\n");
    printf("5. Delete from the End\n");
    printf("6. Delete a Specified node\n");
    printf("7. Display Linked List\n");
    printf("8. Search an Element\n");
    printf("9. Exit\n");
    printf("-------------------------------\n");
    while(1)
    {   
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &new_item);
                head = insert_front(head, new_item);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &new_item );
                insert_end(head, new_item);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &new_item );
                printf("Enter item to place after: ");
                scanf("%d", &search_item );
                insert_after(head, new_item, search_item);
                break;
            case 4:
                head = delete_front(head);
                break;
            case 5:
                delete_end(head);
                break;
            case 6:
                printf("Enter item to delete: ");
                scanf("%d", &search_item );
                head = delete(head, search_item);
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Enter element to search: ");
                scanf("%d", &search_item );
                pos = search(head, search_item);
                if(pos == -1)
                    printf("Element not found");
                else if (pos > 0)
                    printf("Element found at %d\n", pos);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid Choice");
                break;
        }
    }
}