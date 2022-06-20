
#include<stdio.h>
#include<stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int fd1 = open("foo.txt", O_RDONLY);
    
	if (fd1 < 0)
	{
       
		printf("Error opening file\n");
		exit(1);
	}
    
	
	// Using close system Call
	if (close(fd1) < 0)
	{
		printf("Error closing file\n");
		exit(1);
	}
	printf("closed the fd.\n");
}
