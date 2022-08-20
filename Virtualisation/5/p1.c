#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int c=7;
int main(int num, char *argv[]){
    printf("pid:%d\n",(int) getpid());
    int a=2;
    int rc=fork();
    printf("rc:%d\n",rc);
    int b=3;
    if (rc==0){
        printf("%d\n",wait(NULL));
        printf("child pid:%d\n",getpid());
        for (int i=0;i<1000;i++){
            printf("%d",rc);
        };
        a=4;
        b=5;
        c=8;
        
    }
    else{
        
        printf("\n%d\n",getpgid(rc));  
        while(getpgid(rc)!=-1){// do not need wait but have the same function1:W


        }
        //wait(NULL);

        printf("\n%d\n",kill(rc,0));  
        printf("parent pid:%d\n",(int) getpid());

        //for (int i=0;i<1000;i++){
         //   printf("%d",rc);
        //}
        printf("\n%d  %d   %d\n",a,b,c);

    }
    return 0;
}
