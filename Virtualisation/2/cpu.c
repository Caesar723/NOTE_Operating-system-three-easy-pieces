#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include "common.h"

//double GetTime() {
//    struct timeval t;
//    int rc = gettimeofday(&t, NULL);
//    assert(rc == 0);
//    return (double) t.tv_sec + (double) t.tv_usec/1e6;
//}
// 
//void Spin(int howlong) {
//    double t = GetTime();
//    while ((GetTime() - t) < (double) howlong)
//	; // do nothing in loop
//}


int main(int ar,char *argv[]){
    if (ar!=2){
        fprintf(stderr,"use cpu string\n");
        exit(1);
    }
    char *s=argv[1];
    while (1){
        Spin(1);
            
        printf("%s\n",s);
    }

    return 0;
}
