// Implement Merge Sort Algorithm

#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1, n2 = r - m, left[20], right[20];

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];
    
    int i = 0, j = 0, k = l;
    while(i < n1  &&  j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r - 1) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void main()
{
    int n, arr[10], i, ch;

    printf("\nHow many elements? ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, 0, n-1);

    printf("\nMerge Sorted:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}