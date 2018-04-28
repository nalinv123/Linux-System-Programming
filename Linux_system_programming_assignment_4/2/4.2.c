#include"header.h"

int main()
{
	pid_t pid;
	
	printf("Process 1 running with pid : %d\n",getpid());
	
	if(fork() == 0)
	{
		execl("process2", NULL, NULL);
	}
	
	return 0;
}
