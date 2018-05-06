#include"header.h"

void sighup()
{
	printf("Child process handling signal\n");
}

int main(int argc, char *argv[])
{
	pid_t pid;
	
	if((pid = fork()) == 0)
	{
		execl("./process", NULL, NULL);
	}
	else
	{
		printf("In parent process\n");
		printf("Child pid : %d\n", pid);
		printf("Parent pid : %d\n", getpid());
	}

	return 0;
}
