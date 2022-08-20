#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    while (1){
        fd_set read;
        FD_ZERO(&read);

        int i;
        for(i=0;i<10;i++){
            FD_SET(i,&read);
        }
        int rc=select(11,&read,NULL,NULL,NULL);
        for(i=0;i<10;i++){
            if (FD_ISSET(i,&read)){
                printf("%d\n",i);
            }
        }
    }
    return 0;
}
