#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
    pid_t status = fork();
    if(status == 0) {
        printf("In child process\n");
        printf("Exiting from child process\n");
        exit(0);
    }
    printf("In parent process\n");

    printf("Process id is %u\n", getppid());
    printf("Exiting from parent process\n");
    return 0;
}