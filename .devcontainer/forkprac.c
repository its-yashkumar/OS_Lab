#include <stdio.h>
#include <sys/types.h>
#include <unistd.h> 
#include <stdlib.h>
int main(){
    fork();
    printf("\nWe are in OS Lab pid is : %d\n",getpid());
}