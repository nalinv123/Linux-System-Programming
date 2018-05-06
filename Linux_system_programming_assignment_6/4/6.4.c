#include"header.h"

int main(int argc, char *argv[])
{
	int fd = 0;
	char *addr = NULL;
	struct stat sb;
	off_t offset, pa_offset;
	size_t length;
	ssize_t s;
	
	fd = open("demo", O_RDONLY);
	if(fd == -1)
	{
		printf("ERROR : In opening file\n");
		return -1;
	}
	
	addr = mmap(	NULL,		//address to where to map file 
			1, 		//
			PROT_READ, 	//permission to access mapped region
			MAP_PRIVATE, 	//Type of map
			fd, 		//fd of open file
			0);		
	if(addr == MAP_FAILED)
	{
		printf("ERROR : In mapping file\n");
		printf("ERROR NO : %d\n", errno);
		printf("ERROR DESCRIPTION : %s\n", strerror(errno));
		close(fd);
	}
	
	write(1, addr, strlen(addr));
	printf("\n");
	
	munmap(addr, 1);
	close(fd);

	return 0;
}
