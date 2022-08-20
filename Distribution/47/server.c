#include "udp.h"

int main(){
    int sd=UDP_open(10000);
    
    while(1){
        struct sockaddr_in a;
        char buffer[100];
        int rc=UDP_read(sd,&a,buffer,100);
        if (rc>0){
            printf("%s\n",buffer);
            char reply[100];
            sprintf(reply,"reply");
            rc=UDP_write(sd,&a,reply,100);

        }        

    }
    return 0;
}
