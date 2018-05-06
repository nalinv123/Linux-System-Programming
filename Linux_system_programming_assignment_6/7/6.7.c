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
		signal(SIGHUP, sighup);
		pause();
	}
	else
	{
		sleep(20);
		kill(pid, SIGHUP);
	}

	return 0;
}
