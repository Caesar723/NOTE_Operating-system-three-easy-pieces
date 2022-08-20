#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <pthread.h>

typedef struct thrData{
    char * str;
    int loop;
}thrData;
void *printLoop(void* data){
    thrData *dat=(thrData *)data;
    for(int i=0;i<dat->loop;i++){
        printf("%s\n",dat->str);
    }
    return NULL;
}

int main(){
    pthread_t p1,p2;
    int rc;
    thrData dat1,dat2;
    dat1.str="5Loop";
    dat1.loop=5;
    dat2.str="10loop";
    dat2.loop=10;

    rc=pthread_create(&p1,NULL,printLoop,(void *)&dat1);
    printf("%d\n",rc);
    assert(rc==0);

    rc=pthread_create(&p2,NULL,printLoop,(void *)&dat2);
    printf("%d\n",rc);
    assert(rc==0);

    for(int i=0;i<5;i++){
        printf("%s\n","main thread");
    }
    rc=pthread_join(p2,NULL);
    return 0;
}
