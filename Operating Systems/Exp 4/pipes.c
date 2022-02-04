#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main()
{
	int fd[2], n, i, length, flag = 0;
	char buffer[100], str[20];
	printf("\nEnter string to check for palindrome : \n");
	scanf("%s", str);
	pid_t p;
	pipe(fd);
	p = fork();
	if(p > 0)
	{
		printf("Passing message to child\n");
		write(fd[1], str, 10);
	}
	else
	{
		printf("Child received data\n");
		n = read(fd[0], buffer, 100);
		length = strlen(buffer);
		for(i = 0; i < length; i++)
        {
			if(buffer[i] != buffer[length - i - 1])
            {
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("\n %s is not a palindrome \n", buffer);
		else
			printf("\n %s is a palindrome \n", buffer);
	}
}
