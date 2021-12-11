#include<stdio.h>
#include<unistd.h>

int main()
{	
	int p = fork();
	if(p == -1)
		printf("Fail");
	else if (p == 0)
		printf("Child Process with ID: %d\n", getpid());
	else
		printf("Parent process with ID: %d\n", getpid());
}
