#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int sum = 0;
void *sum_runner(void *arg)
{
    int *limit_ptr = (int *)arg;
    int limit = *limit_ptr;
    for (int i = 0; i <= limit; i++)
    {
    sum += i;
    }
    pthread_exit(0);
    }
    int main(int argc, char **argv)
    {
    if (argc < 2)
    {
    printf("Usage: %s <num>\n", argv[0]);
    exit(-1);
}
int limit = atoll(argv[1]);
pthread_t tid;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_create(&tid, &attr, sum_runner, &limit);
pthread_join(tid, NULL);
printf("Sum is %d\n", sum);
}