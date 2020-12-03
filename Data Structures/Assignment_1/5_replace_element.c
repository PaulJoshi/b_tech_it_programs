#include<stdio.h>

void main()
{   
    int A[10], bad, good, n, i, pos;

    printf("\nEnter number of elements in the array: ");
    scanf("%d", &n);
    printf("\nEnter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &A[i]);
    
    printf("\nEnter element to be replaced:");
    scanf("%d", &bad);
    printf("\nEnter element to replace with:");
    scanf("%d", &good);

    for(i = 0; i < n; i++)
        if(A[i] == bad)
            break;
    if(i < n)
    {
        A[i] = good;
        printf("\nElement Replaced. Array is:\n ");
        for(i = 0; i < n; i++)
            printf("%d ", A[i]);
    } else printf("\nElement not found");   
}