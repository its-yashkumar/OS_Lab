#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>

void *thread(void *varGP)
{
    pthread_exit((void *)42);
}

int main()
{
    int i;
    pthread_t threadID;

    pthread_create(&threadID, NULL, thread, NULL);
    pthread_join(threadID, (void **)&i);

    printf("%d\n", i);

    return 0;
}