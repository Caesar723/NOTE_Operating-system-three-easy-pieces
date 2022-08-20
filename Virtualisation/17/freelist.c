#include <stdlib.h>
#include <stdio.h>
#include <sys/mman.h>


typedef struct node_t{
    int size;
    struct node_t* next;
}node_t;

int main(){
    node_t *head=mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_ANON|MAP_PRIVATE,-1,0);
    head->size=4096-sizeof(node_t);
    head->next=NULL;
    printf("%d\n",(int)head->size);
    return 0;
}
