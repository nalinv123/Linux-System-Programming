#include"header.h"

int main()
{
	int status;
	printf("Parent process runnig with pid : %d\n",getpid());
	if(fork() == 0)
	{
		execl("./process2", NULL, NULL);
	}
	
	if(fork() == 0)
	{
		execl("./process3", NULL, NULL);
	}
	
	if(fork() == 0)
	{
		execl("./process4", NULL, NULL);
	}

	wait(&status);
	printf("Parent process is terminating\n");
	return 0;
}
