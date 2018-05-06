#include"header.h"

void sighup()
{
	printf("Child process handling signal\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	pid_t pid1, pid2;
	int status = 0;
	
	if((pid1 = fork()) == 0)		//receiver
	{
		signal(SIGHUP, sighup);
		pause();
	}
	
	if((pid2 = fork()) == 0)		//sender	
	{
		sleep(20);
		kill(pid1, SIGHUP);
		exit(0);
	}

	signal(SIGCHLD, SIG_IGN);
	wait(&status);
	return 0;
}
