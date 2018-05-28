#include"header.h"

void *ThreadProc(void *vPtr)
{
	printf("Inside Thread \n");
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread1;
	int ret = 0;
	
	printf("Inside main thread \n");
	ret = pthread_create(	&thread1,
				NULL,
				ThreadProc,
				NULL);
				
	if(ret == -1)
	{
		printf("ERROR : Creating Thread \n");
		return -1;
	}
	
	pthread_join(	thread1,
			NULL);

	pthread_exit(0);
	return 0;
}
