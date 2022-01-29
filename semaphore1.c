#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<semaphore.h>

void * method1();
void * method2();
int shared=1;
sem_t s;

int main(){
    sem_init(&s,0,1);
    pthread_t pthread1,cthread2;
    pthread_create(&pthread1,NULL,method1,NULL);
    pthread_create(&cthread2,NULL,method2,NULL);
    pthread_join(pthread1,NULL);
    pthread_join(cthread2,NULL);
    printf("Final value of shared variable is :%d\n",shared);
    return 0;
}
void * method1(){
    int x1;
    sem_wait(&s);
    x1=shared;
    printf("Thread1 reads the value as :%d\n",x1);
    x1++;
    printf("Local value of Thread1 is :%d\n",x1);
    sleep(1);
    shared=x1;
    printf("Value of shared variable updated by Thread1 is :%d\n",shared);
    sem_post(&s);
}
void * method2(){
    int x2;
    sem_wait(&s);
    x2=shared;
    printf("Thread2 reads the value as :%d\n",x2);
    x2--;
    printf("Local value of Thread2 is :%d\n",x2);
    sleep(1);
    shared=x2;
    printf("Value of shared variable updated by Thread2 is :%d\n",shared);
    sem_post(&s);
}
