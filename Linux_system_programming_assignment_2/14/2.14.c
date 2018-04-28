#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("wrong arguments\n");
		return -1;
	}
	
	DIR *dir;
	struct dirent *entry;
	struct stat file;
	int ret = 0;
	char filename[50] = {'\0'};
	
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}
	
	while ((entry = readdir(dir)) != NULL)
	{
		sprintf(filename, "%s/%s", argv[1],entry->d_name);
		//printf("%s\n",filename);
		stat(filename, &file);
		
		if(S_ISREG(file.st_mode))
		{
			if((int)file.st_size == 0)
		      	{
		      		ret = unlink(filename);
		      		if(ret == -1)
		      		{
		      			printf("Unable to unlink\n");
		      		}
		      	}
		}
	}
	
	closedir(dir);
	return 0;
}
