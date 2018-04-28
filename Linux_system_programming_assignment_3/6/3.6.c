#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	struct student obj;
	int fd = 0, iRet= 0;
	
	fd = open(argv[1], O_WRONLY | O_APPEND);
	if (fd == -1)
	{
		printf("ERROR : Unable to open specified file\n");
		return -1;
	}
	
	obj.no = atoi(argv[3]);
	strcpy(obj.name, argv[2]);
	
	write(fd, &obj, sizeof(obj));
	
	read(fd, &obj, sizeof(obj));
	printf("Name : %s and Age : %d\n",obj.name, obj.no);
	
	close(fd);
	return 0;
}
