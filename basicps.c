#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int i=0;
void * producer();
void * consumer();
int main(){
    pthread_t pthread1,cthread2;
    pthread_create(&pthread1,NULL,producer,NULL);
    pthread_create(&cthread2,NULL,consumer,NULL);
    pthread_join(pthread1,NULL);
    pthread_join(cthread2,NULL);
    return 0;
}
void * producer(void * par){
    do
    {
        printf("I am in producer i is : %d\n",i);
        i++;
        sleep(1);
   } while (1);
   pthread_exit(0);
}
void * consumer(void * par){
    do
    {
        printf("Inside consumer i value is %d\n",i);
        i++;
        sleep(1);
    } while (1);
    pthread_exit(0);
}