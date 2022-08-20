#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int counter=0;

void * add(void * s){
    sem_t *sem=(sem_t*) s;
    for(int i=0;i<1e2;i++){
        
        sem_wait(sem);
        counter++;
        sem_post(sem);
    }
    return NULL;
}

int main(){
    sem_t s;
    sem_init(&s,0,1);
    int i;
    pthread_t *ts[10];
    for (i=0;i<10;i++){
        pthread_t* t=malloc(sizeof(pthread_t)+1);
        pthread_create(t,NULL,add,(void *)&s);
        ts[i]=t;
    }
    for (i=0;i<10;i++){
        pthread_join(*ts[i],NULL);
    }

    printf("%d\n",counter); 
    return 0;
}
