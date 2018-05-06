#include"header.h"

int main(int argc, char *argv[])
{
	key_t key;
	char *shm, ch = '\0', *s, buffer[100] = {'\0'};
	int i = 0, fd;
	
	key = ftok("/", 0);
	
	fd = shmget(key, SHMSIZE,0666);
	
	shm = shmat(fd, NULL, 0);
	
	s = shm;
	for(; *s != NULL; s++)
	{
		buffer[i] = *s;
		i++;
	}
	
	printf("Data from shared memory : %s\n", buffer);
	*s = '*';
	
	shmdt(shm);
	return 0;
}
