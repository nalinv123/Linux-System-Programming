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
	
	while((ret = read(fd, buffer, sizeof(buffer))) != 0)
		write(1, buffer, ret);
	
	printf("\n");
	close(fd);
	return 0;
}
