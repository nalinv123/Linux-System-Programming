#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 3)
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
	
	while ((entry = readdir(dir)) != NULL)
	{
	      if((strcmp(entry->d_name, argv[2])) == 0)
	      {
	      	  break;
	      }
	}
	
	if(entry == NULL)
	{
		printf("File absent\n");
	}
	else
	{
		printf("File present\n");
	}
	
	closedir(dir);
	return 0;
}
