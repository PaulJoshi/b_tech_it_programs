// Implementation of First Fit algorithm using sorting

#include <stdio.h>

void main()
{
	int bsize[10], psize[10], bno, pno, flags[10], all[10], i, j;
	for(i = 0; i < 10; i++)
	{
		flags[i] = 0;
		all[i] = -1;
	}

	printf("Enter no. of blocks: ");
	scanf("%d", &bno);
	printf("\nEnter size of each block\n");
	for(i = 0; i < bno; i++)
	{
		printf("Block no %d : ", i);
		scanf("%d", &bsize[i]);
	}

	printf("\nEnter no. of processes: ");
	scanf("%d", &pno);
	printf("Enter size of each process: \n");
	for(i = 0; i< pno; i++)
	{
		printf("Process no %d : ", i);
		scanf("%d", &psize[i]);
	}

	for(i = 0; i < pno; i++)
	{
		for(j = 0; j < bno; j++)
		{
			if (flags[j] == 0 && bsize[j] >= psize[j])
			{
				all[j] = i;
				flags[j] = 1;
				break;
			}
		}
	}

	printf("\n Block no.\t Size \t Process no. \t Size");
	for(i = 0; i < bno; i++)
	{
		printf("\n %d \t\t %d \t", i + 1, bsize[i]);
		if (flags[i] == 1)
			printf(" %d \t\t %d \n", all[i] + 1, psize[all[i]]);
		else
			printf(" Not allocated\n");
	}
}
