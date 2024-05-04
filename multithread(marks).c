#include <pthread.h>
#include <stdio.h>

void* sum1(void* arg){
    int* marks=(int*)arg;
    int sum=0;
    for (int i=0;i<5;i++){
        sum=sum+marks[i];
    }
    return (void*)(intptr_t)sum;
}

int main(){
    int student1[5]={70,87,78,86,59};
    int student2[5]={80,97,88,76,99};
    int result[2];
    pthread_t tid1,tid2;
    int x=pthread_create(&tid1,NULL,sum1,student1);
    pthread_join(tid1,(void*)&result[0]);
    int y=pthread_create(&tid2,NULL,sum1,student2);
    pthread_join(tid2,(void*)&result[1]);

    if(result[0]>result[1]){
        printf("Student 1 has higher marks.");
    }
    else if(result[0]<result[1]){
        printf("Student 2 has higher marks.");
    }
    else{
        pthread_exit(NULL);
    }
    return 0;

}