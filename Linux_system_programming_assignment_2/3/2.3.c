#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Insufficient arguments \n");
		return -1;
	}
	
	if((strcasecmp(argv[2],"read")) == 0)
	{
		if(access(argv[1],R_OK) < 0)
		{
			printf("Cannot open in read mode \n");
			return -1;
		}
		printf("Can open in read mode\n");
	}
	else if((strcasecmp(argv[2],"write")) == 0)
	{
		if(access(argv[1],W_OK) < 0)
		{
			printf("Cannot open in write mode \n");
			return -1;
		}
		printf("Can open in write mode\n");
	}

	return 0;
}
