#include"header.h"

int main()
{
	if(fork() == 0)
	{
		execl("./process", NULL, NULL);
	}

	return 0;
}
