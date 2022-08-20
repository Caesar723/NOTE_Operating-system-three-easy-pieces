#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

volatile int coun=0;
int loop;
int co=0;
void *worker(void *arg){
    for (int i=0;i<loop;i++){
        coun++;
    }
    return NULL;
}

int main(int num,char *argv[]){
    loop=atoi(argv[1]);
    pthread_t p1,p2;
    
    pthread_create(&p1,NULL,worker,NULL);

    pthread_create(&p2,NULL,worker,NULL);

    pthread_join(p1,NULL);

    pthread_join(p2,NULL);


    printf("%d\n",coun);
    return 0;
}
