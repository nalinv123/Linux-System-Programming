#include"header.h"

int main()
{
	printf("Process 2 running with pid : %d and parent pid : %d\n",getpid(),getppid());
	return 0;
}
