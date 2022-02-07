#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t chopstick[5];

void *philosopher(void *);
void eat(int);

int main()
{
	int i, n[5];
	pthread_t T[5];
	
	for(i = 0; i < 5; i++)
		sem_init(&chopstick[i], 0, 1);
		
	for(i = 0; i < 5; i++)
	{
		n[i]=i;
		pthread_create(&T[i], NULL, philosopher, (void *)&n[i]);
	}
	for(i = 0; i < 5; i++)
		pthread_join(T[i], NULL);
}

void *philosopher(void *num)
{
	int phil = *(int *)num;


	printf("philosopher %d wants to eat \n", phil);
	printf("philosopher %d tries to pick left chopstick\n", phil);
	sem_wait(&chopstick[phil]);
	printf("philosopher %d  picks the left chopstick\n", phil);
	printf("philosopher %d tries to pick right chopstick\n", phil);
	sem_wait(&chopstick[(phil+1)%5]);
	printf("philosopher %d  picks the right chopstick\n", phil);
	eat(phil);
	sleep(2);
	printf("Philosopher %d has finished eating\n", phil);

	sem_post(&chopstick[(phil+1)%5]);
	printf("philosopher %d  leaves the right chopstick\n", phil);
	sem_post(&chopstick[phil]);
	printf("philosopher %d  leaves the left chopstick\n", phil);

}

void eat(int phil)
{
	printf("\nPhilosopher %d is eating", phil);
}
