/*
    Process Synchronization: Sleeping Barber Problem
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdbool.h>

sem_t barberReady, accessWRseats, customerReady;
int n, numberOfFreeWRSeats;
pthread_t customerThread[100];
int numberOfCustomers;

void init()
{
    sem_init(&barberReady, 0, 0);
    sem_init(&accessWRseats, 0, 1);
    sem_init(&customerReady, 0, 0);

    numberOfFreeWRSeats = n;
}

void *barber(void *params)
{
    int haircuts = numberOfCustomers - 1;

    while(true)
    {
        sem_wait(&customerReady);
        sem_wait(&accessWRseats);
        numberOfFreeWRSeats++;

        sem_post(&barberReady);
        numberOfCustomers--;

        printf("Cutting hair, waiting for next customer...\n");
        sem_post(&accessWRseats);
        printf("Barber: Chairs left = %d\n", numberOfFreeWRSeats);
    }

    printf("Shop closed.\n");
}

void *customer(void *params)
{
    int haircuts = 1;
    while(haircuts > 0)
    {
        sem_wait(&accessWRseats);

        if(numberOfFreeWRSeats > 0)
        {
            numberOfFreeWRSeats--;
            printf("Customer taking a seat\n");
            sem_post(&customerReady);

            haircuts--;
            sleep(1);
            sem_post(&accessWRseats);
            sem_wait(&barberReady);

            printf("Customer %d getting a haircut\n", *(int *)params);
        }

        else 
        {
            sem_post(&accessWRseats);
            printf("Customer %d didn't get a haircut, number of free WR seats = %d\n", *(int *)params, numberOfFreeWRSeats);
        }
    }
}

int main()
{
    printf("Enter number of waiting room seats: ");
    scanf("%d", &n);

    init();

    printf("Enter number of customers: ");
    scanf("%d", &numberOfCustomers);

    for(int i = 0; i < numberOfCustomers; i++)
    {
        if(i == 0)
            pthread_create(&customerThread[i], NULL, barber, &i);
        else 
            pthread_create(&customerThread[i], NULL, customer, &i);
    }

    for(int i = 0; i < numberOfCustomers; i++)
        pthread_join(customerThread[i], NULL);

    return 0;
}