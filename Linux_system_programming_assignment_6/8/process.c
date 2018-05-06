#include"header.h"

void sighup()
{
	printf("Child process handling signal\n");
}

int main(int argc, char *argv[])
{
	signal(SIGTERM, sighup);
	printf("Child pid : %d\n", getpid());
	printf("Waiting for signal\n");
	pause();
	
	return 0;
}
