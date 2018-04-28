#include"header.h"

int main()
{
	printf("Process 2 running with pid : %d\n",getpid());
	if(fork() == 0)
	{
		execl("process3",NULL,NULL);
	}
	
	return 0;
}
