#include"header.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("wrong arguments\n");
		return -1;
	}
	
	int fd, ret;
	char buffer[512] = {'\0'};
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	ret = read(fd, buffer, 5);
	if(ret == -1)
	{
		printf("read fail\n");
		return -1;
	}
	
	write(1, buffer, ret);
	close(fd);
	return 0;
}
