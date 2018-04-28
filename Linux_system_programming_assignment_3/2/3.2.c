#include "header.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	int iRet = 0;
	
	iRet = mkdir(argv[1], 0777);
	if(iRet == -1)
	{
		printf("ERROR : Unable to create directory\n");
		return -1;
	}
	return 0;
}
