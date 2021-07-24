#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int count = 0;
    while(1)
    {
        if(count == 10)
        {
            printf("\nExiting Program\n");
            exit(0);
        }
        
        printf("%d\t", count);
        count++;
    }

    return 0;
}