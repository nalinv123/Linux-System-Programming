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
	
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}
	
	printf("files in the directory : \n");	
	
	while ((entry = readdir(dir)) != NULL)
	{
	      printf("Name: %s\t", entry->d_name);
	      stat(entry->d_name, &file);
	      if (S_ISREG(file.st_mode))
		{
			printf("Regular file\n");
		}
		else if (S_ISDIR(file.st_mode))
		{
			printf("Directory\n");
		}
		else if (S_ISCHR(file.st_mode))
		{
			printf("Character special file\n");
		}
		else if (S_ISBLK(file.st_mode))
		{
			printf("Block special file\n");
		}
		else if (S_ISFIFO(file.st_mode))
		{
			printf("FIFO\n");
		}
		else if (S_ISLNK(file.st_mode))
		{
			printf("Symbolic link\n");
		}
		else if (S_ISSOCK(file.st_mode))
		{
			printf("Socket\n");
		}
		else
		{
			printf("File type is unknown");
		}
	}
	
	closedir(dir);
	return 0;
}
