#include"header.h"

int main()
{
	if(fork() == 0)
	{
		execl("./process1", NULL, NULL);
	}
	
	if(fork() == 0)
	{
		execl("./process2", NULL, NULL);
	}

	return 0;
}
