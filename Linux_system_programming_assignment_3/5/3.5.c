#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	char buffer[512] = {'\0'};
	int fd = 0, iRet= 0;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR : Unable to open specified file\n");
		return -1;
	}
	
	lseek(fd, atoi(argv[2]), 0);
	
	iRet = read(fd, buffer, 20);
	if(iRet == -1)
	{
		printf("ERROR : In reading file\n");
		close(fd);
		return -1;
	}
	
	write(1, buffer, iRet);
	
	close(fd);
	return 0;
}
