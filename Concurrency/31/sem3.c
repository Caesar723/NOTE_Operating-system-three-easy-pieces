#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct people{
    sem_t* left;
    sem_t* right;
    int num;
}people;

int Left(int num){return num;}

int Right(int num){return (num+1)%5;}

void getFork(people * p){
    if (p->num!=4){
        sem_wait(p->left);
        sem_wait(p->right);
    }else{


        sem_wait(p->right);
        sem_wait(p->left);
    }
}//破除依赖-防止deadlock


void putFork(people * p){

    sem_post(p->right);
    sem_post(p->left);

}
void * eat(void * s){
    return NULL;
}

int main(){
    sem_t *forks[5];
    people *peoples[5];
    int i;
    for (i=0;i<5;i++){
        forks[i]=malloc(sizeof(sem_t)+1);

        sem_init(forks[i],0,1);
    }
    for (i=0;i<5;i++){
        peoples[i]=malloc(sizeof(people)+1);
        peoples[i]->left=forks[Left(i)];
        peoples[i]->right=forks[Right(i)];
        peoples[i]->num=i;
        printf("left_fork:%d   right_fork:%d   NO:%d\n",Left(i),Right(i),i);
    }
    return 0;
}


