#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int num, char *argv[]){
    printf("pid:%d\n",(int) getpid());
    int rc=fork();
    printf("rc:%d\n",rc);
    if (rc==0){
        printf("child pid:%d\n",getpid());
        char *some[3];
        some[0]="p1";
        some[1]="p3.c";
        some[2]=NULL;
       // execvp("./p1",some);//放入指令
        execvp("wc",some);// 运行字符计数程序

        printf("no print if error return -1");
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


