#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	struct stat file;
	int fd = 0, iRet= 0;
	char filename[50] = {'\0'};
	
	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
	{
		
	}
	
	return 0;
}
