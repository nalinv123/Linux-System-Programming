#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	int fd = 0;
	char filename[256] = {'\0'};
	
	sprintf(filename, "%s/%s", argv[1], argv[2]);
	
	fd = creat(filename, 0777);
	if(fd == -1)
	{
		printf("ERROR : In creating file\n");
		return -1;
	}
	
	close(fd);
	
	return 0;
}
