#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>

int main()
{
	DIR *dir;
	struct dirent *entry;
	struct stat file;
	int fd;
	char filename[50] = {'\0'};
	
	dir = opendir("/home/nalin/Desktop");
	if(dir == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	
	fd = creat("demo", 0666);
	if(fd == -1)
	{
		printf("Unable to create file\n");
		closedir(dir);
		return -1;
	}
	
	write(fd, "list of files name\n", 19);
	while((entry = readdir(dir)) != NULL)
	{
		sprintf(filename, "/home/nalin/Desktop/%s", entry->d_name);
		stat(filename, &file);
		
		if(S_ISREG(file.st_mode))
		{
			sprintf(filename, "%s\n", entry->d_name);
			write(fd, filename, strlen(filename));
		}
	}
	
	close(fd);
	closedir(dir);
	return 0;
}
