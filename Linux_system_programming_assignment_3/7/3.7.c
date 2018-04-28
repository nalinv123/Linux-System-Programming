#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	struct student obj;
	int fd = 0, iRet= 0;
	
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR : Unable to open specified file\n");
		return -1;
	}
	
	while(read(fd, &obj, sizeof(obj)))
	{
		printf("Name : %s and Age : %d\n",obj.name, obj.no);
		memset(&obj, 0, sizeof(obj));
	}
	
	close(fd);
	return 0;
}
