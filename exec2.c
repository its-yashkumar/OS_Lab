// #Exec2.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    printf("We are in Exec2 , process id is = %d\n", getpid());
    printf("Exec2 is excuted\n");
    return 0;
}