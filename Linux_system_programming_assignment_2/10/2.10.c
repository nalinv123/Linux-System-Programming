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
	int iMax = 0;
	char filename[50] = {'\0'};
	
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}
	
	while ((entry = readdir(dir)) != NULL)
	{
		//sprintf(filename, "%s%s", argv[1],entry->d_name);
	      	stat(entry->d_name, &file);
	      
		if(S_ISREG(file.st_mode))
		{
		      	if(iMax < file.st_size)
		      	{
		      		iMax = file.st_size;
		      		sprintf(filename, "%s%s", argv[1],entry->d_name);
		      		//strcpy(filename, entry->d_name);	
		      	}
		}
	}
	
	printf("Largest file : %s\n",filename);
	
	closedir(dir);
	return 0;
}
