#include <stdio.h>

void main()
{
	int n, m, i, j, k, alloc[100][100], max[100][100], avail[3];
	char c;

	printf("Enter the number of processes: ");
	scanf("%d", &n);

	m = 3; // Number of resources

	printf("\nAllocator\n");
	for(i = 0; i < n; ++i)
	{
		c = 'A';
		for(j = 0; j < m; ++j)
		{
			printf("%dth process %c resource = ", i + 1, c);
			scanf("%d", &alloc[i][j]);
			++c;
		}
	}

  	printf("\nMax\n");
	for(i = 0; i < n; ++i)
	{
		c = 'A';
		for(j = 0; j < m; ++j)
		{
			printf("%dth process %c resource = ", i + 1, c);
			scanf("%d", &max[i][j]);
			++c;
		}
	}

  	printf("\nIntial available\n");
	c = 'A';
	for(j = 0; j < m; ++j)
	{
		printf("at %c resource = ", c);
		scanf("%d", &avail[j]);
		++c;
	}

	//display matrices
	printf("\nAllocation Matrix:");
	for(i = 0; i < n; i++)
	{
		printf("\n");
		for(j = 0; j < m; j++)
			printf("%d, ", alloc[i][j]);
	}

	printf("\n\nMAX Matrix:");
	for(i = 0; i < n; i++)
	{
		printf("\n");
		for(j = 0; j < m; j++)
			printf("%d, ", max[i][j]);
	}
	
	printf("\n\nAvailable Resources:");
	for(j = 0; j < m; j++)
		printf("\n%d", avail[j]);

	int f[n], ans[n], ind = 0;

	for(k = 0; k < n; k++)
		f[k] = 0;

	int need[n][m];
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];

	int y = 0;
	for(k = 0; k < n; k++)
		for(i = 0; i < n; i++)
			if (f[i] == 0)
			{
				int flag = 0;
				for(j = 0; j < m; j++)
					if (need[i][j] > avail[j])
					{
						flag = 1;
						break;
					}

				if (flag == 0)
				{
					ans[ind++] = i;
					for(y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					f[i] = 1;
				}
			}

	int flag = 1;

	for(i = 0; i < n; i++)
		if(f[i] == 0)
		{
			flag = 0;
			printf("\nThe following system is not safe");
			break;
		}

	if(flag == 1)
	{
		printf("\n\nFollowing is the SAFE Sequence\n");
		for (i = 0; i < n - 1; i++)
			printf(" P%d ->", ans[i]);
		printf(" P%d\n\n", ans[n - 1]);
	}	
}
