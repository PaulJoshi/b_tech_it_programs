/*Write a menu driven C program to implement the following searching operations:
    ( i ) Linear Search
    ( ii ) Binary Search */

#include <stdio.h>
#include <stdlib.h>

int a[25], beg, item, end, n, num, i, c, mid;

void linear_search()
{
    for( i = 0; i < n; i++ )
    {
        if( a[i] == item )
        {
            printf( "\nItem found at position %d", i + 1 );
            break;
        }
    }
    if( i==n )
    printf( "\nItem not found" );
}

void binary_search()
{
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
        else if( a[mid] > item )
            end = mid - 1;
        else
            beg = mid + 1;
        mid = ( beg + end ) / 2;
    }
    if( beg > end )
        printf( "\nItem not found" );
}

void user_input()
{
    printf( "\nEnter the number of elements in the array: " );
    scanf( "%d", &n );
    printf( "\nEnter the sorted array: " );
    for( i = 0; i < n; i++ )
        scanf( "%d", &a[i] );
    printf( "\nEnter item to search: " );
    scanf( "%d", &item );
}

void main()
{
    printf( "\nMenu\n" );
    printf( "\n1. Linear Search" );
    printf( "\n2. Binary Search" );
    printf( "\n3. Exit" );

    while(1)
    {
        printf( "\n\nEnter your coice: " );
        scanf( "%d", &c );
        if( c == 3 )
            exit(0);
        else
        {
            user_input();
            ( c == 1 ) ? linear_search() : binary_search() ;
        }
    }
}