#include<pthread.h>
#include<stdio.h>

int counter;
pthread_mutex_t lock;
	
// Function to be considered as a thread
void *ThreadProc1(void *p)
{
	pthread_mutex_lock(&lock);
	unsigned long i = 0;
	counter ++;
	
	printf("Task %d started successfully\n",counter);
	for(i=0;i<0xffffffff;i++);

	printf("Task %d finished successfully\n",counter);

	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread1,thread2;
	int ret1;
	int no = 11;
	
	if(pthread_mutex_init(&lock,NULL) != 0)
	{
		printf("Problem in mutex creation\n");
	}

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

	pthread_mutex_destroy(&lock);
	return 0;
}
