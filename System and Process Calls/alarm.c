#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int count = 3;

void handle()
{
    printf("Hello!\n");
    count--;
    alarm(1);
}

int main()
{
    signal(SIGALRM, handle);
    alarm(1);

    while(count)
    {

    }
    
    printf("Done\n");
    return 0;
}