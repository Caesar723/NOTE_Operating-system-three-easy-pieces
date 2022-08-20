#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <pthread.h>

typedef struct thrData{
    char * str;
    int loop;
    int *coun;
}thrData;
void *printLoop(void* data){
    thrData *dat=(thrData *)data;
    for(int i=0;i<dat->loop;i++){
        (*dat->coun)++;
        //printf("%s and %d\n",dat->str,*dat->coun);
    }
    printf("done");
    return NULL;
}

int main(){
    pthread_t p1,p2;
    int rc,coun2=0;

    thrData dat1,dat2;
    dat1.str="5Loop";
    dat1.loop=1e4;
    dat1.coun=&coun2;
    dat2.str="10loop";
    dat2.loop=1e4;

    dat2.coun=&coun2;
    rc=pthread_create(&p1,NULL,printLoop,(void *)&dat1);
    assert(rc==0);

    rc=pthread_create(&p2,NULL,printLoop,(void *)&dat2);
    assert(rc==0);

    rc=pthread_join(p1,NULL);

    rc=pthread_join(p2,NULL);
    printf("%d\n",coun2);
    return 0;
}

