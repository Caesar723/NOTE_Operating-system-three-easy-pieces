#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(){
    int f=open("foo",O_CREAT | O_WRONLY | O_TRUNC);
    return 0;
}

