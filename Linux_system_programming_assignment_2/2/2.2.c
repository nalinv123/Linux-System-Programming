#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("ERROR : Insufficient arguments \n");
		return -1;
	}

	int fd = 0;
	
	if(strcmp(argv[2], "read") == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if(fd == -1)
		{
			printf("ERROR: Unable to open file\n");
			return -1;
		}
		printf("File is opened with read mode and file descriptor : %d\n", fd);
	}
	else if(strcmp(argv[2], "write") == 0)
	{
		fd = open(argv[1], O_WRONLY);
		if(fd == -1)
		{
			printf("ERROR: Unable to open file\n");
			return -1;
		}
		printf("File is opened with write mode and file descriptor : %d\n", fd);
	}
	else if(strcmp(argv[2], "readwrite") == 0)
	{
		fd = open(argv[1], O_RDWR);
		if(fd == -1)
		{
			printf("ERROR: Unable to open file\n");
			return -1;
		}
		printf("File is opened with read write mode and file descriptor : %d\n", fd);
	}

	close(fd);
	return 0;
}
