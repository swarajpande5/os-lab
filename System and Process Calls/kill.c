#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    pid_t child = fork();
    printf("child = %d\n", child);

    for(int i = 0; i < 1000; i++)
    {
        if(i == 100)
            kill(6785, SIGKILL);
        
        printf("%d\n", i);
    }

    return 0;
}