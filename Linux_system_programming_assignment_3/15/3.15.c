#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	int fd = 0, iRet = 0;
	
	fd = open(argv[1], O_WRONLY);
	if(fd == -1)
	{
		printf("ERROR : In opening file\n");
		return -1;
	}
	
	iRet = ftruncate(fd, atoi(argv[2]));
	if(iRet == -1)
	{
		printf("ERROR : In truncating file\n");
		return -1;
	}
	
	close(fd);
	
	return 0;
}
