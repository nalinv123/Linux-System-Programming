#include "header.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	int fd1 = 0, fd2 = 0, iRet1 = 0, iRet2 = 0;
	char buffer1[512] = {'\0'}, buffer2[512] = {'\0'};
	
	fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1)
	{
		printf("ERROR : Unable to open 1st file\n");
		return -1;
	}
	
	fd2 = open(argv[2], O_RDONLY);
	if(fd2 == -1)
	{
		printf("ERROR : Unable to open 2nd file\n");
		close(fd1);
		return -1;
	}
	
	while(((iRet1 = read(fd1, buffer1, sizeof(buffer1))) != 0) && ((iRet2 = read(fd2, buffer2, sizeof(buffer2))) != 0))
	{
		if(iRet1 == iRet2)
		{
			if((strcmp(buffer1, buffer2) != 0))
			{
				break;
			}
		}
		else
		{
			break;
		}
		
		memset(buffer1, 0, iRet1);
		memset(buffer2, 0, iRet2);
	}
	
	if((iRet1 == 0))
	{
		printf("Files are equal\n");
	}
	else if(((iRet1 != 0) || (iRet2 != 0)))
	{
		printf("Files are not equal\n");
	}
	
	close(fd1);
	close(fd2);
	return 0;
}
