#include<pthread.h>
#include<stdio.h>

int counter ;

// Function to be considered as a thread
void *ThreadProc1(void *p)
{
	unsigned long i = 0;
	counter ++;
	
	printf("Task %d started successfully\n",counter);
	for(i=0;i<0xffffffff;i++);

	printf("Task %d finished successfully\n",counter);

	pthread_exit(NULL);
}

int main()
{
	pthread_t thread1,thread2;
	int ret1;
	int no = 11;
	ret1 = pthread_create(	&thread1,	// Address of pthread_t structure
						NULL,	 	// thread attributes 
						ThreadProc1,	// Function name
						NULL);		// Function parameters
	if(ret1 != 0)
	{
		printf("problem in thread1 creation\n");
	}

	ret1 = pthread_create(	&thread2,	// Address of pthread_t structure
						NULL,	 	// thread attributes 
						ThreadProc1,	// Function name
						NULL);		// Function parameters
	if(ret1 != 0)
	{
		printf("problem in thread1 creation\n");
	}
	// It suspen execution of calling thread till target thread terminates
	pthread_join(	thread1,		// thread id
				NULL);		// Location of thread	

	pthread_join(	thread2,		// thread id
				NULL);		// Location of thread	

	pthread_exit(NULL); 	// Terminate running thread
	return 0;
}
