#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void signalHandler(int signum)
{
    printf("Caught signal %d\n", signum);
    exit(1);
}

int main()
{
    signal(SIGINT, signalHandler);

    while(1)
    {
        printf("Sleeping for two seconds each iteration\n");
        sleep(2);
    }

    return 0;
}
