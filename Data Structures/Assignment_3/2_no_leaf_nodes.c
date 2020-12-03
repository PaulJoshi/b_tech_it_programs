// Write a program to find the number of no-leaf nodes in a binary tree

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

int count_non_leaf(struct binary* tree)
{
    if (tree == NULL || (tree -> lchild == NULL && tree -> rchild == NULL))
        return 0;

    return 1 + count_non_leaf(tree -> lchild) + count_non_leaf(tree -> rchild);
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

    printf("\nNumber of no-leaf nodes in binary tree: %d\n", count_non_leaf(tree));
}