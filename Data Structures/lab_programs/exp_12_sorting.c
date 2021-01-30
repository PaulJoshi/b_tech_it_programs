/* Write a menu driven program to perform
    (i) Bubble Sort
    (ii) Insertion Sort
    (iii) Selection Sort
    (iv) Quick Sort
    (v) Merge Sort */

#include <stdio.h>
#include <stdlib.h>

void display(int a[], int n, int j)
{
    printf("\nIteration %d : ", j);
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    
}

void bubble_sort(int a[], int n)
{
    int i,  j, w = 1, temp;
    display(a, n, w);
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < (n-i)-1; j++)
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        display(a, n, ++w);
    }
}

void insertion_sort(int a[], int n)
{
    int i, k, y, w = 1;
    display(a, n, w);
    for(k = 1; k < n; k++)
    {
        y = a[k];
        
        for(i = k-1; i >= 0 && y < a[i]; i--)
            a[i+1] = a[i];
        a[i+1] = y;
        display(a, n, ++w);
    }
}

void selection_sort(int a[], int n)
{
    int i, j, k, temp;
    for(i = 0; i < n-1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        display(a, n, i+1);
    }
}

void quick_sort(int low, int high, int a[], int n, int d)
{
    int pivot, i, j, temp, k;
    if(low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while(i < j)
        {
            while(a[i] <= a[pivot] && i <= high)
                i++;
            while(a[j] > a[pivot] && j >= low)
                j--;
            if(i<j)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        temp = a[j];
        a[j] = a[pivot];
        a[pivot] = temp;
        display(a, n, d++);
        quick_sort(low, j-1, a, n, d);
        quick_sort(j+1, high, a, n, d++);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m, L[20], R[20];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1  &&  j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if(l >= r)
        return;
    int m = (l+r-1)/2;
    merge_sort(arr, l, m);
    merge_sort(arr, m+1, r);
    merge(arr, l, m, r);
}

void main()
{
    int n, arr[10], i, ch, temp[10];
    printf("\nHow many elements? ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &temp[i]);
    
    printf("\nMENU\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\n5. Quick Sort\n6. Exit");
    while(1)
    {
        printf("\n\nEnter your choice: ");
        scanf("%d", &ch);
        for(i = 0; i < n; i++)
            arr[i] = temp[i];
        switch(ch)
        {
            case 1:
                bubble_sort(arr, n);
                break;
            case 2:
                insertion_sort(arr, n);
                break;
            case 3:
                selection_sort(arr, n);
                break;
            case 4:
                display(arr, n, 1);
                merge_sort(arr, 0, n-1);
                display(arr, n, 2);
                break;
            case 5:
                quick_sort(0, n-1, arr, n, 1);
                break;
            case 6:
                exit(0);   
        }
    }
}