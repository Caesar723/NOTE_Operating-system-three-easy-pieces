#include <stdio.h>
#include <stdlib.h>
#include "udp.h"

int main(){
    int sd=UDP_open(20000);
    char buffer[100];
    struct sockaddr_in addr,addr2;

    int rc=UDP_fillsockaddr(&addr,"machine.cs.wisc.edu",10000);
    char message[100];
    sprintf(message,"hello world");
    rc=UDP_write(sd,&addr,message,100);
    if (rc>0){
        int rc=UDP_read(sd,&addr2,buffer,100);
    }
    printf("%s\n",buffer);
    return 0;
}

