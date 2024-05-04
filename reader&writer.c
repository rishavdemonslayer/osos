#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1;
int readcount = 0;

void *writer(void *wno)
{   
    sem_wait(&wrt);
    cnt = cnt*4;
    printf("Writer %d modified cnt to %d\n",(*((int *)wno)),cnt);
    sem_post(&wrt);

}
void *reader(void *rno)
{   
    
    pthread_mutex_lock(&mutex);
    readcount++;
    if(readcount == 1) {
        sem_wait(&wrt); 
    }
    pthread_mutex_unlock(&mutex);
   
    printf("Reader %d: read cnt as %d\n",*((int *)rno),cnt);
    pthread_mutex_lock(&mutex);
    readcount--;
    if(readcount== 0) {
        sem_post(&wrt); 
    }
    pthread_mutex_unlock(&mutex);
}
int main(int argc, char** argv) {
  pthread_t read[10],write[5];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt,0,1);
    int i;
    int a[10] = {1,2,3,4,5,6,7,8,9,10}; 

    for( i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for( i = 0; i < 5; i++) {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for( i = 0; i < 10; i++) {
        pthread_join(read[i], NULL);
    }
    for( i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);
    return (EXIT_SUCCESS);
}