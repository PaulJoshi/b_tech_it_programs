// Implementation of First Fit algorithm using sorting

#include <stdio.h>

void main()
{
	int bsize[10], psize[10], flag[10], alloc[10], b, p, i, j, temp;
	for(i = 0; i < 10; i++)
	{	
		flag[i] = 0;
		alloc[i] = -1;
	}
	printf("Enter the no of blocks: ");
	scanf("%d", &b);

	printf("\nEnter the size of each block:\n");
	for(i = 0; i < b; i++)
	{	
		printf("Block no %d : ", i + 1);
		scanf("%d", &bsize[i]);
	}

	//sorting (ascending)
	for (i = 0 ; i < b - 1; i++)
	{
		for(j = 0 ; j < b - i - 1; j++)
		{
			if(bsize[j] > bsize[j + 1])
			{
				temp = bsize[j];
				bsize[j] = bsize[j + 1];
				bsize[j+1] = temp;
			}
		}
	}

	printf("\nEnter the no of processes: ");
	scanf("%d", &p);
	printf("\nEnter the size of each process:\n");
	for(i = 0; i < p; i++)
	{	
		printf("Process no %d : ", i + 1);
		scanf("%d", &psize[i]);
	}

	for(i = 0; i < p; i++)
	{	
		for(j = 0; j < b; j++)
		{
			if(flag[j] == 0 && bsize[j] >= psize[i])
			{	flag[j] = 1;
				alloc[j] = i;
				break;
			}
		}
	}

	printf("\nBlock no\tSize\t\tProcess no\tSize");
	for(i = 0; i < b; i++)
	{	
		printf("\n%d\t\t%d\t\t", i + 1, bsize[i]);
		if(flag[i] == 1)
			printf("%d\t\t%d", alloc[i] + 1, psize[alloc[i]]);
		else
			printf("Not allocated");
	}
	printf("\n");
}
