#include"header.h"

int main(int argc, char *argv[])
{
	printf("Parent process running with pid : %d\n",getpid());
	
	if(fork() == 0)
	{
		execl("/Users/nalin/Linux_System_Programming/Linux_system_programming_assignment_4/3/process2",NULL,NULL);
	}
	
	if(fork() == 0)
	{
		execl("/Users/nalin/Linux_System_Programming/Linux_system_programming_assignment_4/3/process3",NULL,NULL);
	}
	
	printf("Parent process terminating\n");
	return 0;
}
