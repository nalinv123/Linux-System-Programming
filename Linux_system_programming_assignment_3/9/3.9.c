#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	struct stat file;
	int fd = 0, iRet= 0, iCnt = 0, fdopen = 0, iRet2 = 0;
	DIR *dir = NULL;
	struct dirent *entry = NULL;
	char filename[50] = {'\0'}, buffer[512] = {'\0'};
	
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
			iCnt++;
			if(iCnt == 1)
			{
				fd = creat("AllCombine", 0777);
				
				if (fd == -1)
				{
					printf("ERROR : Unable to create specified file\n");
					break;
				}
			}
			
			fdopen = open(filename, O_RDONLY);
			if(fdopen == -1)
			{
				printf("ERROR : Unable to open file\n");
				break;
			}
			
			while((iRet = read(fdopen, buffer, sizeof(buffer))) != 0)
			{
				write(fd, buffer, iRet);
				memset(buffer, 0, sizeof(buffer));
			}
			
			close(fdopen);
		}
		
		memset(&file, 0, sizeof(file));
		memset(filename, 0, sizeof(filename));
	}
	
	closedir(dir);
	close(fd);
	
	return 0;
}
