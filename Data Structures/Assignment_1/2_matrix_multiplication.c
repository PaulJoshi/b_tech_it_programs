#include <stdio.h>
void main()
{
  int m, n, p, q, i, j, k, sum = 0;
  int first[10][10], second[10][10], multiply[10][10];
 
  printf("Enter number of rows of first matrix\n");
  scanf("%d", &m);
  printf("Enter number of columns of first matrix\n");
  scanf("%d", &n);
  printf("Enter elements of first matrix\n");
 
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &first[i][j]);
 
  printf("Enter number of rows of first matrix\n");
  scanf("%d", &p);
  printf("Enter number of columns of first matrix\n");
  scanf("%d", &q);
 
  if (n != p)
    printf("The multiplication isn't possible.\n");
  else
  {
    printf("Enter elements of second matrix\n");
 
    for (i = 0; i < p; i++)
      for (j = 0; j < q; j++)
        scanf("%d", &second[i][j]);
 
    for (i = 0; i < m; i++) {
      for (j = 0; j < q; j++) {
        for (k = 0; k < p; k++) {
          sum += first[i][k]*second[k][j];
        }
        multiply[i][j] = sum;
        sum = 0;
      }
    }
 
    printf("Product of the matrices:\n");
 
    for (i = 0; i < m; i++) {
      for (j = 0; j < q; j++)
        printf("%d\t", multiply[i][j]);
      printf("\n");
    }
  }
}