#include"header.h"

int main(int argc, char *argv[])
{
	int fd;
	
	if((mknod("Pipe", S_IFIFO | 0666, 0)) != 0)
	{
		printf("ERROR : Create pipe\n");
		return -1;
	}
	
	fd = open("Pipe", O_WRONLY);
	
	write(fd, "Hello", 5);
	
	close(fd);
	
	return 0;
}
