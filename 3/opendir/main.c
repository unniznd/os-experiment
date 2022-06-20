#include <stdio.h>
#include <dirent.h>

int main()
{
	struct dirent *de; 
	DIR *dr = opendir(".");

	if (dr == NULL) 
	{
		printf("Could not open current directory\n" );
		return 0;
	}

    printf("Folder and files in current working directory\n");

	while ((de = readdir(dr)) != NULL)
			printf("%s\n", de->d_name);

	closedir(dr);	
	return 0;
}
