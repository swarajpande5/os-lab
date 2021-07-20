/*
	Process Synchronization: Dining Philosopher Problem
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <pthread.h>

pthread_t philosopher[50];
pthread_mutex_t chopsticks[50];

int n;

void *thinkEat(int i)
{
    printf("%d Thinking...\n", i+1);

    pthread_mutex_lock(&chopsticks[i]);
    pthread_mutex_lock(&chopsticks[(i+1)%n]);

    printf("%d Eating...\n", i+1);
    sleep(1);

    pthread_mutex_unlock(&chopsticks[i]);
    pthread_mutex_unlock(&chopsticks[(i+1)%n]);

    printf("%d Finished Eating\n", i+1);

    return NULL;
}

int main()
{
    printf("Enter number of philosophers: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++)
	{
		pthread_mutex_init(&chopsticks[i], NULL);
	}

	for(int i=0;i<n;i++)
	{
		pthread_create(&philosopher[i], NULL, (void *)thinkEat, (void *)i);
	}

	for(int i=0;i<n;i++)
	{
		pthread_join(philosopher[i],NULL);
	}

	for(int i=0; i<n; i++)
	{
		pthread_mutex_destroy(&chopsticks[i]);
	}

    return 0;
}