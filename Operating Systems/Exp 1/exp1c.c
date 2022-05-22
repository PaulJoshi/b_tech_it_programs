#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{	
	int p = fork();
	if(p == -1)
		printf("Fail");
	else if (p == 0)
		execlp("./first", "first", NULL);
	else
	{
		wait(NULL);
		printf("Hello\n");
	}
}
