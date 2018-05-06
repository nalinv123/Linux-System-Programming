#include"header.h"

int main()
{
	int i, status;
	pid_t pid;
	
	if(fork() == 0)
	{
		printf("In child process\n");
		/*for(i = 0; i < 1000000; i++)
		{
		}*/
		sleep(100);
	}
	else
	{
		printf("In parent process\n");
		printf("parent process waiting\n");
		pid = wait(&status);
		printf("Child process is terminated with pid : %d and status : %d\n", pid, status);
	}
	
	return 0;
}
