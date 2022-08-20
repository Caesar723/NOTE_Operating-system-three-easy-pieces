#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle(int arg){
    printf("stop kill%d\n",arg);
}

int main(){
    signal(SIGHUP,handle);
    while (1);

    return 0;
}
