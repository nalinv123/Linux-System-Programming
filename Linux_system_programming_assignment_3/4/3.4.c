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
	char filename[350] = {'\0'}, buffer[512] = {'\0'};
	int fd = 0, fdcreate = 0, iCnt = 0, iRet= 0;
	
	if ((dir = opendir(argv[1])) == NULL)
	{
		printf("Unable to open specified directory\n");
		return -1;
	}
	
	while ((entry = readdir(dir)) != NULL)
	{
		sprintf(filename, "%s/%s", argv[1],entry->d_name);
		
	      	stat(entry->d_name, &file);
	      	
	      	if((strcmp(entry->d_name, ".") == 0) || (strcmp(entry->d_name, "..") == 0))
	      	{
	      		continue;
	      	}
	      	
		if(!(S_ISREG((int)file.st_mode)))
		{
			iCnt++;
		      	if(iCnt == 1)
		      	{
		      		fdcreate = creat("demo", 0777);
		      		if(fdcreate == -1)
		      		{
		      			printf("ERROR : Unable to create new file\n");
		      			closedir(dir);
		      			return -1;
		      		}
		      	}
		      	fd = open(filename, O_RDONLY);
		      	if(fd == -1)
		      	{
		      		printf("ERROR : Unable to open file for reading\n");
		      		close(fdcreate);
		      		closedir(dir);
		      		return -1;
		      	}
		      	
		      	iRet = read(fd, buffer, 10);
		      	if(iRet == -1)
		      	{
		      		printf("ERROR : In reading file\n");
		      		close(fd);
		      		close(fdcreate);
		      		closedir(dir);
		      	}
		      	
		      	iRet = write(fdcreate, buffer, iRet);
		      	if(iRet == -1)
		      	{
		      		printf("ERROR : In writing file\n");
		      		close(fd);
		      		close(fdcreate);
		      		closedir(dir);
		      	}
		      	memset(buffer, 0, sizeof(buffer));
		}
		memset(&file, 0, sizeof(file));
		memset(filename, 0, sizeof(filename));
		close(fd);
	}
	
	close(fdcreate);
	closedir(dir);
	return 0;
}
