#include"header.h"

struct Message
{
	int no;
	char data[256];
};

int main(int argc, char *argv[])
{
	key_t key;
	char buffer[100] = {'\0'};
	int i = 0, fd;
	struct Message message;
	
	key = ftok("/", 0);
	
	fd = msgget(key,0666);
	
	if((msgrcv(fd, &message, MSGSIZE, 0, 0)) == -1)
	{
		printf("ERROR : Message receive failed\n");
	}
	
	printf("Message from message queue : %s\n",message.data);
	
	return 0;
}
