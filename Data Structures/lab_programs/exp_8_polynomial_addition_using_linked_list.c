// Write a menu driven C program to perform polynomial addition using linked list

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node * next;
};

struct node *new(struct node *head)
{
    int flag = 1, coeff, pow;
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    head = temp;
    while (flag)
    {
        printf("\nEnter Coefficient: ");
        scanf("%d", &coeff);
        temp -> coeff = coeff;

        printf("\nEnter Power: ");
        scanf("%d", &pow);

        temp -> pow = pow;
        temp -> next = NULL;

        printf("\nAdd more terms?(Y = 1/N = 0): ");
        scanf("%d", &flag);
        if(flag)
        {
            temp -> next = (struct node *)malloc(sizeof(struct node));
            temp = temp -> next;
            temp -> next = NULL;
        }
    }
    return(head);
}

void display(struct node *list)
{
    while(list != NULL)
    {
        printf("%dx^%d", list -> coeff, list -> pow);
        list = list -> next;
        if(list != NULL)
            printf(" + ");
    }
}

struct node *add(struct node *result, struct node  *poly_1, struct node  *poly_2)
{
    struct node *temp;;
    temp = (struct node *)malloc(sizeof(struct node));
    temp -> next = NULL;
    result = temp;

    while(poly_1 && poly_2) {
        if (poly_1 -> pow > poly_2 -> pow) {
            temp -> pow = poly_1 -> pow;
            temp -> coeff = poly_1 -> coeff;
            poly_1 = poly_1 -> next;
        }
        else if (poly_1 -> pow < poly_2 -> pow) {
            temp -> pow = poly_2 -> pow;
            temp -> coeff = poly_2 -> coeff;
            poly_2 = poly_2 -> next;
        }
        else {
            temp -> pow = poly_1 -> pow;
            temp -> coeff = poly_1 -> coeff + poly_2 -> coeff;
            poly_1 = poly_1 -> next;
            poly_2 = poly_2 -> next;
        }

        if(poly_1 && poly_2) {
            temp -> next = (struct node *)malloc(sizeof(struct node));
            temp = temp -> next;
            temp -> next = NULL;
        }
    }

    while(poly_1 || poly_2)
    {
        temp -> next = (struct node *)malloc(sizeof(struct node));
        temp = temp -> next;
        temp -> next = NULL;
 
        if(poly_1)
        {
            temp -> pow = poly_1 -> pow;
            temp -> coeff = poly_1 -> coeff;
            poly_1 = poly_1 -> next;
        }
        if(poly_2)
        {
            temp -> pow = poly_2 -> pow;
            temp -> coeff = poly_2 -> coeff;
            poly_2 = poly_2 -> next;
        }
    }
 
    printf("\nAdded expression is: ");
    return(result);
}

void main()
{
    int ch;
    struct node *poly_1, *poly_2, *poly_3;

    printf("\n1 - Enter first expression");
    printf("\n2 - Enter second expression");
    printf("\n3 - Sum of expressions");
    printf("\n4 - Sum of Exit");

    while(1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                poly_1 = new(poly_1);
                display(poly_1);
                break;

            case 2:
                poly_2 = new(poly_2);
                display(poly_2);
                break;

            case 3: 
                poly_3 = add(poly_3, poly_1, poly_2);
                display(poly_3);
                break;

            case 4: 
                exit(0);
                break;
            
            default:
                printf("Invalid Option");
                break;
        }
    }
}