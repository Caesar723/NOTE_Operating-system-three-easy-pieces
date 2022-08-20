#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int num,char* argv[]){
    char *src="hello";
    //char *cha;  //没有分配内存
   // char *cha=(char* )malloc(strlen(src));//没分配足够的内存
    char *cha=(char* )malloc(strlen(src)+1);

    strcpy(cha,src);
    printf("%s\n",cha);

    return 0;
}
