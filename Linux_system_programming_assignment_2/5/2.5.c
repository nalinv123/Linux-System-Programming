#include"header.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("wrong arguments\n");
		return -1;
	}
	
	int fd, cnt, ret;
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	char *buffer = (char *)malloc(atoi(argv[2]));
	if(buffer == NULL)
	{
		printf("Error : In memory allocation\n");
		close(fd);
		return -1;
	}
	
	ret = read(fd, buffer, atoi(argv[2]));
	if(ret == -1)
	{
		printf("read fail\n");
		return -1;
	}
	
	write(1, buffer, ret);
	close(fd);
	return 0;
}
