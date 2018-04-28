#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	struct stat file;
	int iRet = 0, iRet2 = 0;
	DIR *dir = NULL;
	struct dirent *entry = NULL;
	char filename[50] = {'\0'};
	
	dir = opendir(argv[1]);
	if(dir == NULL)
	{
		printf("ERROR : Unable to open specified directory\n");
		return -1;
	}
	
	while((entry = readdir(dir)) != NULL)
	{
		if(((strcmp(entry->d_name, ".")) == 0) || ((strcmp(entry->d_name, "..")) == 0))
		{
			continue;
		}
		
		sprintf(filename, "%s/%s", argv[1], entry->d_name);
		iRet2 = stat(filename, &file);
		if(iRet2 == -1)
		{
			printf("Error : In getting file information\n");
			perror("Error");
			break;
		}
		
		if((S_ISREG(file.st_mode)))
		{
			iRet2 = truncate(filename, 1049);
			if(iRet2 == -1)
			{
				printf("ERROR : In truncating file\n");
				break;
			}
		}
		
		memset(&file, 0, sizeof(file));
		memset(filename, 0, sizeof(filename));
	}
	
	closedir(dir);
	
	return 0;
}
