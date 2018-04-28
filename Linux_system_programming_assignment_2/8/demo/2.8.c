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
	
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}
	
	printf("files in the directory : \n");	
	
	while ((entry = readdir(dir)) != NULL)
	{
	      printf("Name: %s\n", entry->d_name);
	}
	
	closedir(dir);
	return 0;
}
