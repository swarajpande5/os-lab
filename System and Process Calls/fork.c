#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int x = 1;
    pid_t pid = fork();

    if(pid == 0)
        printf("Child Process: x = %d\n", ++x);
    else 
        printf("Child Process: x = %d\n", --x);
    
    return 0;
}