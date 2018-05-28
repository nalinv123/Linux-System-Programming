#include"header.h"

void *ThreadProc(void *vPtr)
{
	int *i = (int *)vPtr;
	
	printf("Value : %d\n",*i);
		
	pthread_exit((void *)i);
}

int main(int argc, char *argv[])
{
	pthread_t thread1, thread2;
	int ret1 = 0, ret2 = 10;
	int *no;
	
	printf("Inside main thread \n");
	ret1 = pthread_create(	&thread1,
				NULL,
				ThreadProc,
				(void *)&ret2);
				
	if(ret1 == -1)
	{
		printf("ERROR : Creating Thread \n");
		return -1;
	}
	
	pthread_join(	thread1,
			(void *)&no);
			
	printf("value returned from thread : %d\n", *no);

	pthread_exit(0);
	return 0;
}
