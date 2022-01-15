#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
    fork();
    printf("Hello World\n");
    printf("Process Id %d\n",getpid());
}