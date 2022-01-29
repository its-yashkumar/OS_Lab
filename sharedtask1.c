#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
//#include<sys/ipc.h>
#include<unistd.h>
#include<string.h>

int main()

{
    int k;
    // void *shardm;
    int * arr;
    int buffer[200];
    int shmid;
    shmid=shmget((key_t)2345, 1024, 0666|IPC_CREAT);
    printf("unique key of segment is::::::%d\n", shmid);
    arr=(int *)shmat(shmid,NULL,0);
    printf("process is attached at address:::::::%p\n",arr);
    // read(0,buffer,100);
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
        // *(arr+i)=buffer[i];
    }


    for(int i=0;i<10;i++){
    printf("data entered is:::::::%d\n",arr[i]);
    }
    return 0;
}