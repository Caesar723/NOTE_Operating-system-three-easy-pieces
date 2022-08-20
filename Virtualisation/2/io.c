#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>


int main(int num,char *argv[]){
    int file=open("file",O_WRONLY | O_CREAT | O_TRUNC,S_IRWXU);
    write(file,"HELLO WORLD",13);
    close(file);


    return 0;
}


