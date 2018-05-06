#include"header.h"

int main(int argc, char *argv[])
{
	int arr[2] = {0};
	char buffer[512] = {'\0'};
	int ret = 0;
	
	pipe(arr);
	
	if(fork() == 0)
	{
		ret = read(arr[0], buffer, sizeof(buffer));
		write(1, buffer, ret);
		printf("\n");
		close(arr[0]);
	}
	else
	{
		write(arr[1], "Hello", 5);
		close(arr[1]);
	}

	return 0;
}
