#include"header.h"

void sighandler()
{
	printf("Child process handling signal\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	signal(SIGUSR1, sighandler);
	
	for(;;)
		pause();

	return 0;
}
