/* Write a menu driven C program to implement a binary binary using linked list
and perform the following operations on it
    (i) Insert a new node.
    (ii) Delete a specified node.
    (iii) Search a specified node. */

#include<stdio.h>
#include<stdlib.h>

struct binary
{
	int data;
	struct binary *lchild, *rchild;
};

void insertion(struct node*root, int value, int element)
{
    struct node*temp;
  char x;

  printf("Enter the element under which to insert :-");
        scanf("%d",&c);

if(root == NULL){
        printf("Tree is empty\n");
    }
    else{

        if(root->data == value){
            flag=1;
            printf("l for left r for right");
            scanf("%s",&x);
            if (x=='l'||x=='L')
                {
                    if (root->left==NULL)

{
temp=(struct node *)malloc(sizeof(struct node));

temp->data=element;

root->left=temp;
printf("insertion of %d is done as %d left child ",element,value);
}

else if(root->left!=NULL)
    {
        printf("such postion cant be find out");
    }
         }
             if (x=='r'||x=='R')
                {   flag=1;
                    if (root->right==NULL)

{
temp=(struct node *)malloc(sizeof(struct node));

temp->data=element;

root->right=temp;
printf("insertion of %d is done as %d right child ",element,value);
}
}
else if(root->right!=NULL)
    {
        printf("such postion cant be find out");
    }


        } }

        if(flag == 0 && root->left != NULL){
        insertion(root->left, value,element);
        }

        if(flag == 0 && root->right != NULL){
        insertion(root->right, value,element);
        }
    }


struct binary *delete(struct binary *ptr, int item)
{
	struct binary *p1,*p2;
	if(!ptr)
	{
		printf("\nNode not found ");
		return(ptr);
	}
	else
	{
		if(ptr -> data < item)
			ptr -> rchild = delete(ptr -> rchild, item);
		else if (ptr -> data > item)
		{
			ptr -> lchild = delete(ptr -> lchild, item);
			return ptr;
		}
		else
		{
			if(ptr -> data == item)    
			{
				if(ptr -> lchild == ptr -> rchild) 
				{
					free(ptr);
					return(NULL);
				}
				else if(ptr -> lchild == NULL)
				{
					p1 = ptr -> rchild;
					free(ptr);
					return p1;
				}
				else if(ptr -> rchild == NULL)
				{
					p1=ptr -> lchild;
					free(ptr);
					return p1;
				}
				else
				{
					p1=ptr -> rchild;
					p2=ptr -> rchild;
					while(p1 -> lchild != NULL)
						p1=p1 -> lchild;
					p1 -> lchild = ptr -> lchild;
					free(ptr);
					return p2;
				}
			}
		}
	}
	return(ptr);
}

struct binary *search(struct binary *tree)
{
	int num, i;
	struct binary *ptr;
	ptr = tree;
	printf("\nEnter the element to be searched :");
	scanf(" %d", &num);
	fflush(stdin);
	while(ptr)
	{
		if(num > ptr -> data)
		    ptr = ptr -> rchild; else if(num < ptr -> data)
		    ptr = ptr -> lchild; else
		    break;
	}
	if(ptr)
		printf("\nElement %d which was searched is found and is = %d", num, ptr -> data);
	else
	   printf("\nElement %d does not exist in the binary tree", num);
	return(tree);
}

void main()
{
	struct binary *tree;
	int choice, item, item_no;
	tree = NULL;
	printf("\n1. Insert");
	printf("\n2. Delete");
	printf("\n3. Search");
	printf("\n4. Exit ");
	while(1)		
	{	printf("\n\n Enter choice: ");
		scanf(" %d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter new element: ");
				scanf("%d", &item);
				tree = insert(tree, item);
				printf("\ntree is %d", tree -> data);
				break;
			case 2:
				printf("\nEnter the element to be deleted : ");
				scanf(" %d", &item_no);
				tree = delete(tree, item_no);
				break;
			case 3:
				tree = search(tree);
				break;
			case 4:
				exit(0);
			default :
				printf("\nInvalid input ");
		}
	}
}