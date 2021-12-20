#include <stdio.h>
#include <stdlib.h>

struct process
{
	int pid;
	int at;
	int wt;
	int tat;
	int bt;
	int ct;
} p[20], temp;
int n;

void swap(int i, int j)
{
	temp = p[i];
	p[i] = p[j];
	p[j] = temp;
}

void atSort()
{
	int i, j;
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < n - i - 1; j++)
			if(p[j].at > p[j + 1].at)
				swap(j, j + 1);
}

void pidSort()
{
	int i, j;
	for(i = 0; i < n - 1; i++)
		for(j = 0; j < n - i - 1; j++)
			if(p[j].pid > p[j + 1].pid)
				swap(j, j + 1);
}

void main()
{
	int z, i;

	printf("Enter the number of processes: ");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++)
	{
		p[i].pid = i + 1;
		printf("Enter the arrival time of process %d: ", i + 1);
		scanf("%d", &p[i].at);
		printf("Enter the burst time of process %d: ", i + 1);
		scanf("%d", &p[i].bt);
	}
	atSort();

	p[0].ct = p[0].at + p[0].bt;
	p[0].tat = p[0].ct - p[0].at;
	p[0].wt = p[0].tat - p[0].bt;

	for(i = 1; i < n; i++)
	{
		if(p[i].at <= p[i - 1].ct)
			p[i].ct = p[i - 1].ct + p[i].bt;
		else
			p[i].ct = p[i].at + p[i].bt;
		p[i].tat = p[i].ct - p[i].at;
		p[i].wt = p[i].tat - p[i].bt;
	}

	pidSort();
	printf("\nFCFS:\n");
	printf("Process ID\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
	for(i = 0; i < n; i++)
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
}
