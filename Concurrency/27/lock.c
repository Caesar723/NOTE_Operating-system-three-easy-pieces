#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <pthread.h>

typedef struct thrData{
    char * str;
    int loop;
    int * counter;
    pthread_mutex_t *lock;

}thrData;


void Lock(pthread_mutex_t *lock){
    int rc = pthread_mutex_lock(lock);
    assert(rc==0);
}

void UnLock(pthread_mutex_t *lock){
    int rc = pthread_mutex_unlock(lock);
    assert(rc==0);
}

void *printLoop(void* data){
    thrData *dat=(thrData *)data;
    
    for (int i=0;i<dat->loop;i++){
        Lock(dat->lock);
        (*dat->counter)++;
        UnLock(dat->lock);
        printf("%d:%s\n",*dat->counter,dat->str);
    }
    return NULL;
}
int main(){
    pthread_t p2,p1;
    int rc,coun=0;
    thrData *dat1=malloc(sizeof(thrData)+1),*dat2=malloc(sizeof(thrData)+1);
    pthread_mutex_t lock;
    rc=pthread_mutex_init(&lock,NULL);

    assert(rc==0);

    dat1->str="5Loop";
    dat1->loop=30;
    dat1->counter=&coun;
    dat1->lock=&lock;

    dat2->str="9Loop";
    dat2->loop=30;
    dat2->counter=&coun;
    dat2->lock=&lock;

    rc=pthread_create(&p1,NULL,printLoop,dat1);
    assert(rc==0);

    rc=pthread_create(&p2,NULL,printLoop,dat2);
    assert(rc==0);
    rc=pthread_join(p2,NULL);

    rc=pthread_join(p1,NULL);
    printf("%d\n",coun);
    free(dat1);
    free(dat2);
    pthread_mutex_destroy(&lock);
    return 0;
}

