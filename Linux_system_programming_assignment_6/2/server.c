#include"header.h"

int main(int argc, char *argv[])
{
	key_t key;
	char *shm, ch = '\0', *s;
	int id;
	
	key = ftok("/", 0);
	
	id = shmget(key, SHMSIZE, IPC_CREAT | 0666);
	
	shm = shmat(id, NULL, 0);
	
	s = shm;
	for(ch = 'a'; ch <= 'z'; ch++)
	{
		*s = ch;
		s++;
	}
	
	*s = NULL;
	
	while(*s != '*')
	{
		sleep(1);
	}
	
	shmdt(shm);
	return 0;
}
