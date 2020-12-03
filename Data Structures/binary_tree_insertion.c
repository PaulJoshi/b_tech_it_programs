
#include <stdio.h>  
#include <stdlib.h>  
 
struct binary
{
    int data;
    struct binary *lchild, *rchild;
} *pos = NULL;

void search(struct binary *tree, int search_key)
{
    if (tree != NULL)
    {
        if (tree -> data == search_key)
        {
            printf("Search Key Found");
            pos = tree;
            return;
        }
        else
        {
            search(tree -> lchild, search_key);
            search(tree -> rchild, search_key);
        }
    }
    Printf("Key Not Found");
}

void insert (struct binary *tree, int item)
{
    search(tree, item);
    if(pos == NULL)
        printf("element not found");
    else
    {
        char choice;
        printf("left or right");
        scanf ("%c", &choice);
        if (choice == "l")
        {
            if (pos -> lchild == NULL)
            {
                struct binary *temp = (struct binary *)malloc(sizeof(struct binary));
                temp -> data = item;
                temp -> lchild = NULL;
                temp -> rchild = NULL;
                pos -> lchild = temp;
            }
            else
                printf("Insertion not possible");
        }
        else if (choice == "r")
        {
            if (pos -> lchild == NULL)
            {
                struct binary *temp = (struct binary *)malloc(sizeof(struct binary));
                temp -> data = item;
                temp -> lchild = NULL;
                temp -> rchild = NULL;
                pos -> rchild = temp;
            }
            else
                printf("Insertion not possible");
        }
    }
}