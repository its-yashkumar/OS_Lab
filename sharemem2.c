#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
//#include<sys/ipc.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int k;
    void *shardm;
    char buffer[200];
    int shmid;
    shmid=shmget((key_t)2345, 1024, 0666);
    printf("unique key of segment is::::::%d\n", shmid);
    shardm=shmat(shmid,NULL,0);
    printf("process is attached at address:::::::%p\n",shardm);
    printf("Reading the data from shared memory:::::::%s", (char *)shardm);
    return 0;
}