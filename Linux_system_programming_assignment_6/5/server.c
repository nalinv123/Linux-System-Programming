#include"header.h"

struct Message
{
	int no;
	char data[256];
};

int main(int argc, char *argv[])
{
	key_t key;
	int id;
	struct Message message;
	message.no = 0;
	strcpy(message.data, "hello");
	
	key = ftok("/", 0);
	
	id = msgget(key, IPC_CREAT | 0666);
	
	if((msgsnd(id, &message, MSGSIZE, 0)) == -1)
	{
		printf("ERRRO : Send Message failed\n");
		return -1;
	}
	
	return 0;
}
