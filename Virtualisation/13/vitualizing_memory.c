#include <stdio.h>

#include <stdlib.h>


int main(int num,char *argv[]){
    printf("code %p\n",(void*) main);
    
    printf("heap %p\n",(void*) malloc(1));
    int a=723;
    printf("stack %p\n",(void*) &a);
    return 0;
}
