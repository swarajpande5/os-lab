#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    uid_t uid = getuid();
    uid_t euid = geteuid();

    if(uid == 0 && euid == 0)
        printf("Welcome Root user\n");
    else 
        printf("You are not the root user!\nuid = %d\neuid = %d\n", uid, euid);

    gid_t gid = getgid();
    gid_t egid = getegid();

    printf("gid = %d\negid = %d\n", gid, egid);
}