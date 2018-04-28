#include"header.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("wrong arguments\n");
		return -1;
	}
	
	int fd, ret;
	
	fd = open(argv[1], O_WRONLY|O_APPEND);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	ret = write(fd, "hello", 5);
	if(ret == -1)
	{
		printf("write fail\n");
		return -1;
	}
	
	close(fd);
	return 0;
}
