#include"header.h"

int main(int argc, char *argv[])
{
	int fd, ret;
	char buffer[512];
	
	fd = open("Pipe", O_RDONLY);
	
	ret = read(fd, buffer, sizeof(buffer));
	
	write(1, buffer, ret);
	
	return 0;
}
