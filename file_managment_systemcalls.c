#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc,char** argv){
    char buff[]="";
    char fd1=open("/Users/rishav/Desktop/ccodes/f1.txt",O_RDONLY);
    char fd2=open("/Users/rishav/Desktop/ccodes/f2.txt",O_WRONLY);
    if (fd1==-1){
        printf("error");
    }
    while (read(fd1,buff,sizeof(buff))){
        write(fd2,buff,sizeof(buff));
    }
    close(fd1);
    close(fd2);
    
    return(EXIT_SUCCESS);
    }
