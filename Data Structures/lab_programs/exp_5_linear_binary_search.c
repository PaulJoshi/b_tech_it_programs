/*Write a menu driven C program to implement the following searching operations:
    ( i ) Linear Search
    ( ii ) Binary Search */

#include <stdio.h>
#include <stdlib.h>

int a[25], beg, mid, end, item, n, i, c, temp;

void linear_search()
{
    printf( "Enter item to search: " );
    scanf( "%d", &item );
    for( i = 0; i < n; i++ )
    {
        if( a[i] == item )
        {
            printf( "\nItem found at position %d", i + 1 );
            break;
        }
    }
    if( i == n )
        printf( "\nItem not found" );
}

void binary_search()
{
    printf( "Enter item to search: " );
    scanf( "%d", &item );
    end = n - 1;
    beg = 0;
    mid = ( beg + end ) / 2;
    while( beg <= end )
    {
        if( item == a[mid] )
        {
            printf( "\nItem found at position %d", mid + 1 );
            break;
        }
        else if( item < a[mid] )
            end = mid - 1;
        else
            beg = mid + 1;
        mid = ( beg + end ) / 2;
    }
    if( beg > end )
        printf( "\nItem not found" );
}

void sort()
{
    for (int i = 0; i < n; i++)  
        for (int j = i+1; j < n; j++)   
           if(a[i] > a[j])
           {    
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
           }
    printf("\nSorted Array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void user_input()
{
    printf( "\nEnter the number of elements in the array: " );
    scanf( "%d", &n );
    printf( "Enter the array: " );
    for( i = 0; i < n; i++ )
        scanf( "%d", &a[i] );
    sort();
}

void main()
{
    user_input();
    printf( "\nMenu\n" );
    printf( "\n1. Linear Search" );
    printf( "\n2. Binary Search" );
    printf( "\n3. Exit" );

    while(1)
    {
        printf( "\n\nEnter your choice: " );
        scanf( "%d", &c );
        ( c == 3 ) ? exit(0) : ( c == 1 ) ? linear_search() : binary_search() ;
    }
}