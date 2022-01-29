#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<semaphore.h>
int count=0;
void * producer();
void * consumer();
int buffer[20];
sem_t s;
int empty=20;
int full=0;
int in=0,out=0;

int main(){
    sem_init(&s,0,1);
    pthread_t pthread1,cthread2;
    pthread_create(&pthread1,NULL,producer,NULL);
    pthread_create(&cthread2,NULL,consumer,NULL);
    pthread_join(pthread1,NULL);
    pthread_join(cthread2,NULL);
    printf("Final value of count is :%d",count);
    return 0;
}

void * producer(void * par){
    int item=0;
    sem_wait(&s);
    do{
    if(empty==0) {
        printf("Buffer is full\n");
        sleep(2);
    }
    else{
    empty--;
    buffer[in]=item;
    in=(in+1)%20;
    item++;
    count++;
    full++;
    printf("Item added to buffer is:%d\n",item);
    sem_post(&s);
    sleep(2);
    }
    }while(1);
   
    pthread_exit(0);
}

void * consumer(void * par){
    int item;
    sem_wait(&s);
    do{
    if(full==20){
        printf("Buffer is Empty");
        sleep(2);
    }
    else
    {
        full--;
        item=buffer[out];
        printf("The item consumed is : %d\n",item);
        out=(out+1) % 20;
        count--;
        empty++;
        sem_post(&s);
    sleep(2);
    }
    }while(1);
    pthread_exit(0);
}
