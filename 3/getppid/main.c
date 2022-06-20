#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    pid_t status = fork();
    if(status == 0){
        printf("In child process. Process id is %u\n", getppid());
    }
    else if(status > 0){
        printf("In parent process. Process id is %u\n", getppid());
    }
    else{
        printf("Process creation failed!\n");
    }
    return 0;
}