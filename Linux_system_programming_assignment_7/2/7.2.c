#include"header.h"

void *ThreadProc1(void *vPtr)
{
	int i = 1;
	printf("Inside Thread 1\n");
	
	for(; i <= 500; i++)
	{
		printf("Thread 1 : %d\n",i);
	}
	
	pthread_exit(NULL);
}

void *ThreadProc2(void *vPtr)
{
	int i = 500;
	printf("Inside Thread 2\n");
	
	for(; i > 0; i--)
	{
		printf("Thread 2 : %d\n",i);
	}
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread1, thread2;
	int ret1 = 0, ret2 = 0;
	
	printf("Inside main thread \n");
	ret1 = pthread_create(	&thread1,
				NULL,
				ThreadProc1,
				NULL);
				
	if(ret1 == -1)
	{
		printf("ERROR : Creating Thread \n");
		return -1;
	}
	
	ret2 = pthread_create(	&thread1,
				NULL,
				ThreadProc2,
				NULL);
				
	if(ret2 == -1)
	{
		printf("ERROR : Creating Thread \n");
		return -1;
	}
	
	pthread_join(	thread1,
			NULL);
	
	pthread_join(	thread2,
			NULL);

	pthread_exit(0);
	return 0;
}
