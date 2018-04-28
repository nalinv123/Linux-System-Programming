#include"header.h"

int main()
{
	int fd, ret;
	char buffer[512] = {'\0'};
	int iCnt = 0, iCount = 0;
	char arr[100] = {'\0'};
	
	fd = open("demo", O_RDONLY);
	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}
	
	while((ret = read(fd, buffer, sizeof(buffer))) != 0)
	{
		for(iCnt = 0; iCnt < ret; iCnt++)
		{
			if((buffer[iCnt] >= 'A') && (buffer[iCnt] <= 'Z'))
			{
				iCount++;
			}
		}
		memset(buffer, 0, sizeof(buffer));
		if(ret < sizeof(buffer))
		{
			break;
		}
	}

	close(fd);
	//printf("No of capital letters : %d\n", iCount);
	
	fd = open("count", O_WRONLY | O_APPEND);
	if(fd == -1)
	{
		printf("Unable to open count file\n");
		return -1;
	}
	
	sprintf(arr, "No of capital letters : %d\n", iCount);
	write(fd, arr, strlen(arr));
	
	close(fd);
	
	return 0;
}
