#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    DIR *dp=opendir("..");
    char* name;

    while ((name=readdir(dp)->d_name)!=NULL){
        printf("%s\n",name);
    }
    return 0;
}

