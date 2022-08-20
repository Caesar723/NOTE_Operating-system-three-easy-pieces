#include <netdb.h>
#include <unistd.h>
#include <strings.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>


int UDP_open(int port){
    int sd;
    if ((sd=socket(AF_INET,SOCK_DGRAM,0))==-1) return -1;
    struct sockaddr_in myaddr;
    bzero(&myaddr,sizeof(myaddr));
    myaddr.sin_family=AF_INET;
    myaddr.sin_port=htons(port);
    myaddr.sin_addr.s_addr=INADDR_ANY;
    if(bind(sd,(struct sockaddr*) &myaddr,sizeof(myaddr))==-1){
        close(sd);
        return -1;
    }
    return sd;

}

int UDP_write(int sd, struct sockaddr_in *addr,char *buffer,int n){
    int addrLen=sizeof(struct sockaddr_in);
    return sendto(sd,buffer,n,0,(struct sockaddr*)addr,addrLen );
}


int UDP_read(int sd, struct sockaddr_in *addr,char *buffer, int n ){
    int len=sizeof(struct sockaddr_in);
    return recvfrom(sd,buffer,n,0,(struct sockaddr *)addr,(socklen_t*)&len);
}

int UDP_fillsockaddr(struct sockaddr_in * addr,char *hostname,int port){
    bzero(addr,sizeof(struct sockaddr_in));
    addr->sin_family=AF_INET;
    addr->sin_port=htons(port);
    struct in_addr *inaddr;
    struct hostent *hostEntry;
    if((hostEntry=gethostbyname(hostname))==NULL)return -1;
    inaddr=(struct in_addr *)hostEntry->h_addr;
    addr->sin_addr=*inaddr;
    return 0;
}

