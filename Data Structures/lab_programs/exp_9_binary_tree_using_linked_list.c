/* Write a menu driven C program to implement a binary tree using linked list
and perform the following operations on it
    (i) Insert a new node.
    (ii) Delete a specified node.
    (iii) Search a specified node. */

#include <stdio.h>
#include <stdlib.h>

struct binary
{
    int data;
    struct binary *lchild, *rchild;
};

int flag = 0;
int countloop = 0;

struct binary *create()
{
    int item;
    struct binary *newbinary;
    newbinary = (struct binary *)malloc(sizeof(struct binary));
	if (flag == 0)
	{
		printf("\nEnter root element: ");
		flag = 1;
	}
    scanf("%d", &item);
    if (item == -1)
        return 0;
    else
        newbinary -> data = item;
    printf("Enter the lchild of %d (-1 to exit) : ", item);
    newbinary -> lchild = create();
    printf("Enter the rchild of %d (-1 to exit) : ", item);
    newbinary -> rchild = create();
    return newbinary;
}

void search(struct binary *root, int value)
{
    if (root == NULL)
        printf("Tree is empty\n");
    else
    {
        if (root -> data == value)
        {
            flag = 1;
            return;
        }
        if (flag == 0 && root -> lchild != NULL)
            search(root -> lchild, value);
        if (flag == 0 && root -> rchild != NULL)
            search(root -> rchild, value);
    }
}

void insertion(struct binary *root, int value, int element)
{
    struct binary *temp;
    char x;

    if (root == NULL)
        printf("Tree is empty\n");
    else
    {
        if (root -> data == value)
        {
            flag = 1;
            printf("l for lchild r for rchild. Enter your choice: ");
            scanf("%s", &x);
            if (x == 'l' || x == 'L')
            {
                if (root -> lchild == NULL)
                {
                    temp = (struct binary *)malloc(sizeof(struct binary));
                    temp -> data = element;
                    root -> lchild = temp;
                    printf("\nInserted %d at %d lchild", element, value);
                }
                else if (root -> lchild != NULL)
                    printf("Position not found");
            }
            if (x == 'r' || x == 'R')
            {
                if (root -> rchild == NULL)
                {
                    temp = (struct binary *)malloc(sizeof(struct binary));
                    temp -> data = element;
                    root -> rchild = temp;
                    printf("\nInserted %d at %d rchild", element, value);
                }
                else if (root -> rchild != NULL)
                    printf("Position not found");
            }
        }
    }

    if (flag == 0 && root -> lchild != NULL)
        insertion(root -> lchild, value, element);

    if (flag == 0 && root -> rchild != NULL)
        insertion(root -> rchild, value, element);
}

void deletion(struct binary *root, int value)
{
    countloop++;
    struct binary *temp;
    char x;

    if (root == NULL)
        printf("Tree is empty\n");
    else
    {

        if ((root -> data == value) && countloop == 1)
        {
            flag = 1;
            if ((root -> lchild == NULL) && (root -> rchild == NULL))
            {
                temp = root;
                root = 0;
                printf("\n%d deleted\n", temp -> data);
                free(temp);
                return;
            }
            else
            {
                printf("Deletion only allowed at leaf nodes!\n");
                return;
            }
        }

        if (root -> lchild != NULL)
        {
            if (root -> lchild -> data == value)
            {
                flag = 1;
                temp = root -> lchild;
                if (temp -> lchild == NULL && temp -> rchild == NULL)
                {

                    root -> lchild = NULL;
                    printf("\n%d deleted", temp -> data);
                    free(temp);
                    return;
                }
                else
                {
                    printf("Deletion not possible");
                    return;
                }
            }
        }

        if (root -> rchild != NULL)
        {
            if (root -> rchild -> data == value)
            {
                flag = 1;
                temp = root -> rchild;
                if (temp -> rchild == NULL && temp -> rchild == NULL)
                {
                    root -> rchild = NULL;
                    printf("%d deleted", temp -> data);
                    free(temp);
                    return;
                }
                else
                {
                    printf("Deletion not possible");
                    return;
                }
            }
        }

        if (flag == 0 && root -> lchild != NULL)
            deletion(root -> lchild, value);
        if (flag == 0 && root -> rchild != NULL)
            deletion(root -> rchild, value);
    }
}

void main()
{
    int ch, a, b;
    struct binary *root;

    root = 0;
    root = create();

	printf("\n Menu\n\n 1.Insert\n 2.Delete\n 3.Search\n 4.Exit");

    while (1)
    {
		printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
			case 1:
				flag = 0;
				printf("Enter where to insert: ");
				scanf("%d", &a);
				printf("Enter element to insert: ");
				scanf("%d", &b);
				insertion(root, a, b);
				if (flag == 0)
					printf("Value %d does not exist", a);
				break;

			case 2:
				flag = 0;
				printf("Enter element to delete: ");
				scanf("%d", &a);
				countloop = 0;
				deletion(root, a);
				if (flag == 0)
					printf("Value %d does not exist ", a);
				break;
			
			case 3:
				flag = 0;
				printf("Enter element to search: ");
				scanf("%d", &a);
				search(root, a);
				if (flag == 1)
					printf("Value %d exists ", a);
				else
					printf("Value %d not found ", a);
				break;

			case 4:
				exit(0);
				break;
        }
    }
}