#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int num, char *argv[]){
    printf("pid:%d\n",(int) getpid());
    int rc=fork();
    printf("rc:%d\n",rc);
    if (rc==0){
        printf("child pid:%d\n",getpid());
        for (int i=0;i<1000;i++){
            printf("%d",rc);
        };
    }
    else{
        int wc=wait(NULL);
        printf("endChild: %d\n",wc);
        printf("parent pid:%d\n",(int) getpid());

        for (int i=0;i<1000;i++){
            printf("%d",rc);
        };

    }
    return 0;
}

