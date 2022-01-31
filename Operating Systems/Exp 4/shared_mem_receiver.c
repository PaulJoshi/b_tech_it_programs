#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
	void *shared_memory;
	char buff[100], s[50];
	int shmid, n, i, flag = 0;
	shmid = shmget((key_t)1122, 1024, 0666);
	printf("Key of shared memory is %d\n", shmid);
	shared_memory = shmat(shmid, NULL, 0);
	printf("Process attached at %p \n", shared_memory);
	printf("Data read from shared memory is : %s", (char *)shared_memory);
	strcpy(s, ((char *)shared_memory));
	n = strlen(s) - 1;
	printf("Length : %d", n);
    for(i = 0; i < n; i++)
    {
        if(s[i] != s[n - i - 1])
        {
            flag = 1;
            break;
        }
    }
    if(flag)
        printf("\n %s is not a palindrome \n", s);
    else
        printf("\n %s is a palindrome \n", s);
}
