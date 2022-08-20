#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct sem_t{
    pthread_mutex_t *lock;
    pthread_cond_t *cond;
    int count,done;
    pthread_mutex_t *cl;
}sem_t;

void sem_init(sem_t *sem,int val){
    pthread_mutex_t *lock=malloc(sizeof(pthread_mutex_t)+1);
    pthread_mutex_t *cl=malloc(sizeof(pthread_mutex_t)+1);
    pthread_cond_t *cond=malloc(sizeof(pthread_cond_t)+1);
    pthread_mutex_init(lock,NULL);
    pthread_mutex_init(cl,NULL);
    pthread_cond_init(cond,NULL);
    sem->cl=cl;
    sem->lock=lock;
    sem->cond=cond;
    sem->count=val;
}

void sem_wait(sem_t * sem){
    pthread_mutex_lock(sem->lock);
    
    while (sem->count<1 ){
        pthread_cond_wait(sem->cond,sem->lock);
    }
    sem->count--;
    pthread_mutex_unlock(sem->lock);
}

void sem_post(sem_t *sem){
    
    pthread_mutex_lock(sem->lock);
    sem->count++;
    pthread_cond_signal(sem->cond);
    pthread_mutex_unlock(sem->lock);
}
//################################################################

int counter=0;

void * add(void * s){
    sem_t *sem=(sem_t*) s;
    for(int i=0;i<1e4;i++){
        sem_wait(sem);
        counter++;
        sem_post(sem);
        
    }
    return NULL;
}

int main(){
    sem_t s;
    sem_init(&s,1);
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

