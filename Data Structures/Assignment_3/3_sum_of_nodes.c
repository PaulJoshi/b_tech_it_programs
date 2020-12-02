// Write a program to find the sum of contents of all nodes in the tree

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

int sum_of_nodes(struct binary *tree, int sum)
{
    if(tree == NULL)
        return(sum);
    else
    {
        sum += tree -> data;
        sum = sum_of_nodes(tree -> lchild, sum);
        sum = sum_of_nodes(tree -> rchild, sum);
    }
}

void main()  
{
    struct binary *tree = NULL;
    int sum = 0;

    tree = new(1);  
    tree -> lchild = new(2);  
    tree -> rchild = new(3);  
    tree -> lchild -> lchild = new(4);  
    tree -> rchild -> lchild = new(5);  
    tree -> rchild -> rchild = new(6);  
    tree -> rchild -> rchild -> rchild = new(7);  
    tree -> rchild -> rchild -> rchild -> rchild = new(8);  

    printf("Sum of nodes of binary tree: %d", sum_of_nodes(tree, sum));
} 