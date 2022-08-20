#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int done=1;

pthread_cond_t c=PTHREAD_COND_INITIALIZER;

pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;

void Exit(){
    
    pthread_mutex_lock(&lock);
    done=0;//在父线程create之后，如果子线程先提前调用了signal，父线程再调用wait，就会一直wait，所以要有条件判断
    pthread_cond_signal(&c);
    pthread_mutex_unlock(&lock);
}

void join(){

    pthread_mutex_lock(&lock);//如果没有锁，在调用wait（）之前可能会上下文切换，然后子线程调用了signal，之后再切换回来调用wait（），就会有问题
    while (done){
        printf("wait");
        pthread_cond_wait(&c,&lock);
    }


    pthread_mutex_unlock(&lock);

}

void * do_thi(){
    pthread_mutex_lock(&lock);
    for (int i=0;i<10;i++){
        printf("%d\n",i);
    }
    pthread_mutex_unlock(&lock);
    Exit();
    printf("exit");
    return NULL;
}
int main(){
    pthread_t t;
    pthread_create(&t,NULL,do_thi,NULL);
    join();
    printf("end");
    return 0;
}
