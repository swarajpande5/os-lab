#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define PATH "/home/swarajpande/Desktop"

int main()
{
    int changed = chdir(PATH);

    if(changed < 0)
        printf("Directory not changed !\n");
    else 
    {
        printf("Directory changed to Desktop\n");
        execlp("ls", "ls", "-ltr", NULL);
    }
}