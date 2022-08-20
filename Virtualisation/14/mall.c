#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int num,char * argv[]){
    
    double* d=(double *)malloc(sizeof(double));
    *d=1.4;
    printf("%f\n",*d);

    printf("%d\n",sizeof(int));

    int a[10];
    printf("%d\n",sizeof(a));

    char* b="hello";
    printf("%d\n",strlen(b));

    char* c=(char*) malloc(strlen(b)+1);//加1为字符串结束时留出空间
    free(c);
    free(d);
    return 0;
}
