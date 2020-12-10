/* Write a menu driven C program to implement a binary tree
and perform the following traversals on it
    (i) In-order
    (ii) Pre order
    (iii) Post-order */

#include<stdio.h>
#include<stdlib.h>

struct binary
{
    int data;
    struct binary *lchild, *rchild;
};

int flag = 0;

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

void inorder(struct binary *root)
{
	if(root != NULL)
	{
		inorder(root -> lchild);
		printf(" %d", root -> data);
		inorder(root -> rchild);
	}
	return;
}

void postorder(struct binary *root)
{
	if(root != NULL)
	{
		postorder(root -> lchild);
		postorder(root -> rchild);
		printf(" %d", root -> data);
	}
	return;
}

void preorder(struct binary *root)
{
	if(root != NULL)
	{
		printf(" %d", root -> data);
		preorder(root -> lchild);
		preorder(root -> rchild);
	}
	return;
}

void main()
{
    int ch, a, b;
    struct binary *root;

    root = 0;
    root = create();

	printf("\n Menu\n\n 1.In-order\n 2.Pre-order\n 3.Post-order\n 4.Exit");

    while(1)
    {
		printf("\n\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
			case 1:
				inorder(root);
				break;

			case 2:
				preorder(root);
				break;
			
			case 3:
				postorder(root);
				break;

			case 4:
				exit(0);
				break;
        }
    }
}