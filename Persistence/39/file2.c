#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
    int f=open("foo",O_CREAT | O_WRONLY | O_TRUNC);
    write(1,"1",1);
    return 0;
}

