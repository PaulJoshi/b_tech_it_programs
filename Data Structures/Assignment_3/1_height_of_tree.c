// Write a program to find the height of a tree

#include <stdio.h>  
#include <stdlib.h>  
 
struct binary
{
    int data;
    struct binary *lchild, *rchild;
};

struct binary *new(int data)
{
    struct binary *newbinary = (struct binary*)malloc(sizeof(struct binary));
    newbinary -> data = data;
    newbinary -> lchild = NULL;
    newbinary -> rchild = NULL;
    return newbinary;
}  

int tree_height(struct binary *tree)
{ 
    if(tree == NULL)
    {  
        printf("Tree is empty\n");
        return 0;
    }  
    else
    {  
        int lchildHeight = 0, rchildHeight = 0;

        if(tree -> lchild != NULL)
            lchildHeight = tree_height(tree -> lchild);

        if(tree -> rchild != NULL)
            rchildHeight = tree_height(tree -> rchild);

        return (lchildHeight > rchildHeight ? lchildHeight : rchildHeight) + 1;
    }  
}  
   
void main()
{
    struct binary *tree = NULL;
    tree = new(1);
    tree -> lchild = new(2);
    tree -> rchild = new(3);
    tree -> lchild -> lchild = new(4);
    tree -> rchild -> lchild = new(5);
    tree -> rchild -> rchild = new(6);
    tree -> rchild -> rchild -> rchild = new(7);
    tree -> rchild -> rchild -> rchild -> rchild = new(8);

    printf("\nHeight of binary tree: %d\n", tree_height(tree));
}