#include"header.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("wrong arguments\n");
		return -1;
	}
	
	int fdread, fdwrite, ret;
	char buffer[512] = {'\0'};
	
	fdread = open(argv[1], O_RDONLY);
	if(fdread == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	fdwrite = creat(argv[2], 0777);
	if(fdwrite == -1)
	{
		printf("Unable to creat file\n");
		return -1;
	}
	
	while((ret = read(fdread, buffer, sizeof(buffer))) != 0)
		write(fdwrite, buffer, ret);
	
	printf("\n");
	close(fdread);
	close(fdwrite);
	return 0;
}
