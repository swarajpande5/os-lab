/*
    Process Synchronization: Reader - Writers Problem
*/

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 16

int buffer[BUFFER_SIZE];
sem_t database, mutex;
int counter, readerCount;
pthread_t readerThread[50], writerThread[50];

void init()
{
    sem_init(&mutex, 0, 1);
    sem_init(&database, 0, 1);
    counter = 0;
    readerCount = 0;
}

void *writer(void *param)
{
    sem_wait(&database);

    int item;
    item = rand() % 5;
    
    buffer[counter] = item;

    printf("Data written by the writer %d is %d\n", (*(int *)param), buffer[counter]);
    counter++;

    sleep(1);
    sem_post(&database);
}

void *reader(void *param)
{
    sem_wait(&mutex);
    readerCount++;
    
    if(readerCount == 1)
        sem_wait(&database);
    
    sem_post(&mutex);
    counter--;
    printf("Data read by the reader %d is %d\n", (*(int *)param), buffer[counter]);

    sleep(1);
    sem_wait(&mutex);
    readerCount--;

    if(readerCount == 0)
        sem_post(&database);
    
    sem_post(&mutex);
}

int main()
{
    init();

    int writerNumber, readerNumber;
    
    printf("Enter number of readers: ");
    scanf("%d", &readerNumber);
    printf("Enter number of writers: ");
    scanf("%d", &writerNumber);

    for(int i = 0; i < writerNumber; i++)
	{
		pthread_create(&writerThread[i], NULL, writer, &i);
	}

	for(int i = 0; i < readerNumber; i++)
	{
		pthread_create(&readerThread[i], NULL, reader, &i);
	}

	for(int i = 0; i < writerNumber; i++)
	{
		pthread_join(writerThread[i], NULL);
	}
	
    for(int i = 0; i < readerNumber; i++)
	{
		pthread_join(readerThread[i], NULL);
	}

    return 0;
}