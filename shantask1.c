#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int k;
    int *sharedMem;
    int buffArr[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int shmID;

    shmID = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    printf("Unique key of segment : %d\n", shmID);

    sharedMem = shmat(shmID, NULL, 0);
    printf("Process is attached at address : %p\n", sharedMem);

    for (int i = 0; i < 10; i++)
    {
        *(sharedMem + i) = buffArr[i];
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Data entered by user is : %d\n", *(sharedMem + i));
    }

    return 0;
}