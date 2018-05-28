#include"header.h"

void *ThreadProc(void *vPtr)
{
	pthread_t thread = pthread_self();
	printf("Thread ID : %ld\n", thread);
		
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t thread1, thread2;
	int ret1 = 0;
	
	printf("Inside main thread \n");
	ret1 = pthread_create(	&thread1,
				NULL,
				ThreadProc,
				NULL);
				
	if(ret1 == -1)
	{
		printf("ERROR : Creating Thread \n");
		return -1;
	}
	
	pthread_join(	thread1,
			NULL);

	pthread_exit(0);
	return 0;
}
