#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int main(int argc,char** argv){
    int wstatus;
    int a=fork();
    if(a==0){
        printf("Child1 process ID is %d its parent is %d\n",getpid(),getppid());
        int result=10+2;
        printf("Child1 result od arithmatic operation addition is :%d",result);
        int c=fork();
        if(c==0){
            printf("Child.1 processs ID is %d its parent is %d \n",getpid(),getppid());
            int result=10-2;
            printf("Child.1 result of arthmatic operation subtraction is: %d\n",result);
        }
        else{
            int d=fork();
            if(d==0){
                printf("Child.2 process ID is %d its parent is %d \n",getpid(),getppid());
                int result=4*5;
                printf("Child.2 result of arthmatic operation multiplication is %d\n",result);
            }
            else{
                waitpid(d,wstatus,0);
            }
        }

    }
    else{
        int b=fork();
        if(b==0){
            printf("Child2 process ID is %d its parent is %d\n",getpid(),getppid());
            int result=35/5;
            printf("\nChild2 result of arthmatic operation division is :%d\n",result);
        }
        else{
            waitpid(b,wstatus,0);
        }
    }
    return(EXIT_SUCCESS);
}