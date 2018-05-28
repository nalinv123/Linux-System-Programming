#include"header.h"

void *ThreadProc1(void *vPtr)
{
	printf("Inside Thread1\n");
		
	pthread_exit(NULL);
}

void *ThreadProc2(void *vPtr)
{
	printf("Inside Thread2\n");
		
	pthread_exit(NULL);
}

void *ThreadProc3(void *vPtr)
{
	printf("Inside Thread3\n");
		
	pthread_exit(NULL);
}

void *ThreadProc4(void *vPtr)
{
	printf("Inside Thread4\n");
		
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[4];
	int i = 0;
	void *(*vPtr[4])(void *) = {ThreadProc1, ThreadProc2, ThreadProc3, ThreadProc4};
	
	printf("Inside main thread \n");
	
	for(;i < 4;i++)
	{
		pthread_create(	&threads[i],
				NULL,
				vPtr[i],
				NULL);
	}
	
	for(i = 0; i < 4; i++)
	{
		pthread_join(	threads[i],
			NULL);
	}

	printf("Main thread waiting is finished and it is terminating \n");
	pthread_exit(0);
	return 0;
}
