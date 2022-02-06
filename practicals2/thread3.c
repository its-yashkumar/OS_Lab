#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>

void *thread(void *varGP)
{
    int *ptr = (int *)varGP;
    pthread_exit((void *)ptr);
}

void *thread2(void *varGP)
{
    int *ptr = (int *)varGP;
    *ptr = 0;
    pthread_exit((void *)31);
}

int main()
{
    int i = 42;
    pthread_t threadID;
    pthread_t threadID2;

    pthread_create(&threadID, NULL, thread, (void *)&i);
    pthread_create(&threadID2, NULL, thread2, (void *)&i);
    pthread_join(threadID, (void **)&i);
    pthread_join(threadID2, NULL);

    printf("%d\n", i);

    return 0;
}