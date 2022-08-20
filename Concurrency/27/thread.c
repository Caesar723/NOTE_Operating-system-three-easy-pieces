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
    
    printf("loop:%d,%s\n",dat->loop,(dat->str));
    return (void *)dat;
}

int main(){
    pthread_t p2;
    int rc;
    thrData *dat1=malloc(sizeof(thrData)+1),*dat2;
    dat1->str="5Loop";
    dat1->loop=5;


    rc=pthread_create(&p2,NULL,printLoop,dat1);
    printf("%d\n",rc);
    assert(rc==0);

    rc=pthread_join(p2,(void**) &dat2);
    printf("loop:%d,%s\n",dat2->loop,(dat2->str));

    dat1->str="caesar";

    printf("loop:%d,%s\n",dat2->loop,(dat2->str));
    free(dat1);
    return 0;
}
