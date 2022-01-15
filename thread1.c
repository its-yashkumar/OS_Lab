#include<pthread.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int global=0;
void *threadfun(void * vargp){
    int id;
   
    static int s;
    sleep(1);
    printf("happy festival : 1\n");
    id=(int)vargp;
    global++;s++;
    printf("id\t\t%d\n",id);
    printf("global\t\t%d\n",global);
    printf("s\t\t%d\n\n",s);
}
void *threadfun2(void * vargp){
    sleep(3);
    printf("Inside thread function :: 2\n");
}

int main(){
    clock_t t;
    t=clock();
    pthread_t tid;
    printf("Before threading the task\n");
    for(int i=0;i<3;i++){
    pthread_create(&tid,NULL,threadfun,(void * )i);
    pthread_join(tid,NULL);
    // if(i==2){
    // pthread_create(&tid,NULL,threadfun2,NULL);
    // pthread_join(tid,NULL);
    // }
    }
     t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time %lf\n",time_taken);
    printf("After threading");
    pthread_exit(NULL);
    exit(0);
   

}