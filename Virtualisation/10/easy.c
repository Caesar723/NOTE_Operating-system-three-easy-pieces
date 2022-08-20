#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct __Node_t {
    int value;
    struct __Node_t *next;
}Node_t;

int deleteNode(){
    Node_t *tmp=head;
    int val=tmp->head;
    head=head->next;
    free(tmp);
    return val;
}

pthread_mutex_t m;


