#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct counter{
    int val;
    pthread_mutex_t *lock;
    int S;
    int loop;
}counter;
void a(counter* m,int num){

        pthread_mutex_lock(m->lock);
        m->val=m->val+ num;
        pthread_mutex_unlock(m->lock);
}
void *add(void* c){
    counter *m=(counter*)c;
    int localC=0;
    for (int i=0;i<m->loop;i++){
        localC++;
        if (localC>m->S){
            a(m,localC);
            localC=0;
        }
        
    }
    a(m,localC);
    return NULL;
}
  

counter* init(){
    
    counter* c=(counter *)malloc(sizeof(counter)+1);
    c->val=0;
    c->S=500;
    c->loop=10000;
    pthread_mutex_t *lock=(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)+1);
    
    
    pthread_mutex_init(lock,NULL);
    c->lock=lock;

    return c;
}
void destroy(counter *c ){
    
    pthread_mutex_destroy(c->lock);
    free(c);

}
int main(){
    counter *c=init();
    pthread_t* ts[4];
    int i;
    for(i=0;i<4;i++){
        ts[i]=(pthread_t *)malloc(sizeof(pthread_t)+1);

        pthread_create(ts[i],NULL,add,(void*)c);
    }

    for(i=0;i<4;i++){

        pthread_join(*ts[i],NULL);
    }
    printf("%d\n",c->val);
    destroy(c);
    
    return 0;
}
