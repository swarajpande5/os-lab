#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if(pid == 0)
        printf("-Child Process\n");
    else 
    {
        printf("-Parent Process\n");
        wait(NULL);
        printf("-Child Process Terminated\n");
    }

    printf("-End\n");

    return 0;
}