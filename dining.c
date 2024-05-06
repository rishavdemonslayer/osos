#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (phnum+4)%N
#define RIGHT (phnum+1)%N

int state[N];
int phil[N] = {0,1,2,3,4};
sem_t mutex;
sem_t S[N];

void test(int phnum){
    if(state[phnum] == HUNGRY && state[LEFT] != THINKING && state[RIGHT] != THINKING){
        state[phnum] = EATING;
        printf("Philosopher %d takes fork %d and %d\n",phnum+1,LEFT+1,phnum+1);
        printf("Philosopher %d is eating\n",phnum+1);
        sem_post(&S[phnum]);
    }
}
void take_fork(int phnum){
    sem_wait(&mutex);
    state[phnum] = HUNGRY;
    printf("Philosopher %d is hungry\n",phnum+1);
    usleep(rand()%100000);
    test(phnum);
    sem_post(&mutex);
    sem_wait(&S[phnum]);

}
void put_fork(int phnum){
    sem_wait(&mutex);
    state[phnum] = THINKING;
    printf("Philosopher %d puts fork %d and %d\n",phnum+1,LEFT+1,phnum+1);
    printf("Philosopher %d is thinking\n",phnum+1);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}
void *philosopher(void *num){
    int *cycles = (int *)num;
    int i;
    for(i =0 ;i<*cycles;i++){
        take_fork(*phil);
        put_fork(*phil);
    }
    return NULL;
}
int main(int argc,char **argv){
    int cycles = 5,i;
    pthread_t thread_id[N];
    sem_init(&mutex,0,1);
    for(i=0;i<N;i++){
        sem_init(&S[i],0,0);
    }
    for(i=0;i<N;i++){
        pthread_create(&thread_id[i],NULL,philosopher,&cycles);
        printf("Philosopher %d is thinking\n",i+1);
    }
    for(i=0;i<N;i++){
        pthread_join(thread_id[i],NULL);
    }
    return EXIT_SUCCESS;
}