#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	int fd = 0, iRet = 0;
	fd = open(argv[1], O_WRONLY);
	if(fd == -1)
	{
		printf("ERROR : Unable to specified file\n");
		return -1;
	}
	
	iRet = lseek(fd, 1000, SEEK_END);
	if(iRet == -1)
	{
		printf("ERROR : In lseek\n");
		close(fd);
		return -1;
	}
	
	write(fd, "Hello", 5);
	
	return 0;
}
