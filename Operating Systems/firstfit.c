#include <stdio.h>

void main()
{
	int a[10], b[10], a1, b1, flags[10], all[10], i, j;
	for(i = 0; i < 10; i++)
	{
		flags[i] = 0;
		all[i] = -1;
	}

	printf("Enter no. of blocks: ");
	scanf("%d", &a1);
	printf("\nEnter size of each block\n");
	for(i = 0; i < a1; i++)
	{
		printf("Block no %d : ", i);
		scanf("%d", &a[i]);
	}

	printf("\nEnter no. of processes: ");
	scanf("%d", &b1);
	printf("Enter size of each process: \n");
	for(i = 0; i< b1; i++)
	{
		printf("Process no %d : ", i);
		scanf("%d", &b[i]);
	}

	for(i = 0; i < b1; i++)
	{
		for(j = 0; j < a1; j++)
		{
			if (flags[j] == 0 && a[j] >= b[j])
			{
				all[j] = i;
				flags[j] = 1;
				break;
			}
		}
	}

	printf("\n Block no.\t Size \t Process no. \t Size");
	for(i = 0; i < a1; i++)
	{
		printf("\n %d \t\t %d \t", i + 1, a[i]);
		if (flags[i] == 1)
			printf(" %d \t\t %d \n", all[i] + 1, b[all[i]]);
		else
			printf(" Not allocated\n");
	}
}
