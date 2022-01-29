#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
//#include<sys/ipc.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int k;
    int * arr;
    int buffer[200];
    int shmid;
    shmid=shmget((key_t)2345, 1024, 0666);
    printf("unique key of segment is::::::%d\n", shmid);
    arr=(int *)shmat(shmid,NULL,0);
    printf("process is attached at address:::::::%p\n",arr);
    for(int i=0;i<10;i++){
    printf("Reading the data from shared memory:::::::%d\n",arr[i]);
    }
    return 0;
}