
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(){
    struct stat buf;
    int status = stat("foo.txt", &buf);
    if(status){
        printf("Error failed\n");
        exit(1);
    }
    printf("File st_uid %d \n",buf.st_uid);
    printf("\nFile st_blksize %ld \n",buf.st_blksize);
    printf("\nFile st_gid %d \n",buf.st_gid);
    printf("\nFile st_blocks %ld \n",buf.st_blocks);
    printf("\nFile st_size %ld \n",buf.st_size);
}   
    
   
	