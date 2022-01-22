// #Exec.c
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main (int argc,char *argv[] )
{
printf("process id of Exec.c= %d\n",getpid());
char *args[]={"Hi","Welcome","To","Lab",NULL};
execv("./Exec2",args);
printf("Back to this program Exec\n");
return 0;
}
