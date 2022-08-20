#include <stdio.h>
#include <pthread.h>

/* pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; */
pthread_mutex_t mutex;

int count;

void * thread_run(void *arg)
{
    int i;
    printf("hello%#lx\n",pthread_self());
    pthread_mutex_lock(&mutex);
    for (i = 0; i < 3; i++) {
        printf("[%#lx]value of count: %d\n", pthread_self(), ++count);
    }
    pthread_mutex_unlock(&mutex);
    return 0;
}

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&mutex, 0);
    pthread_create(&thread1, NULL, thread_run, 0);
    pthread_create(&thread2, NULL, thread_run, 0);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    pthread_mutex_destroy(&mutex);
    return 0;
}
