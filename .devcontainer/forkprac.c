#include <sys/stat.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/file.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include  <unistd.h>
#include <errno.h>
#include <sys/types.h>
int main(){
    fork();
    printf("\nWe are in OS Lab pid is : %d\n",getpid());
}