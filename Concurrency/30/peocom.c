#define MAX (10)
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int buffer[MAX];
int getIndex=0,putIndex=0;
int count=0;

pthread_cond_t cput=PTHREAD_COND_INITIALIZER;
pthread_cond_t cget=PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

int get(){
    int ge=buffer[ getIndex];
    getIndex=( getIndex+1)%MAX;
    count--;
    return ge;
}

void put(int val){
    buffer[putIndex]=val;
    putIndex=(putIndex+1)%MAX;
    count++;
}

void* consumer(void * loop){
    for (int i=0;i<(int )loop;i++){
        pthread_mutex_lock(&lock);
        while(count==0){
             pthread_cond_wait(&cget,&lock);
        }
        printf("%d\n",get());
        pthread_cond_signal(&cput);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
void* producer(void * loop){
    
    for (int i=0;i<(int)loop;i++){
        pthread_mutex_lock(&lock);
        while(count==MAX){
            pthread_cond_wait(&cput,&lock);
        }
        put(i);
        printf("put%d\n",i);
        pthread_cond_signal(&cget);
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main(){
    pthread_t *ts[2];
    pthread_t con;
    int i;
    
    printf("start\n");
    for(i=0;i<2;i++){

        pthread_t *t=malloc(sizeof(pthread_t)+1);

        pthread_create(t,NULL,consumer,(void *)5);
        ts[i]=t;
    }
    printf("producer\n");

    pthread_create(&con,NULL,producer,(void *)10);

    for(i=0;i<2;i++){
        pthread_join(*ts[i],NULL);
    }
    pthread_join(con,NULL);
    printf("end");
    return 0;
}

