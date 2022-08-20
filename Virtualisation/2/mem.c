#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"


int main(int argc, char *argv[]){
    assert(1==1);//false is raise error
                 //
    int *p=malloc(sizeof(int));
    
    printf("start:%u p:%d\n",(char *) p,*p);
//    *p=0;
    for (int i=0;i<5;i++){
        Spin(1);
        *p=*p+i; 
        printf("pid:%d p:%d\n",getpid(),*p);

    }
    return 0;
}
