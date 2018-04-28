#include"header.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("ERROR : Insufficient arguments\n");
		return -1;
	}
	
	struct stat file;
	int fd = 0, iRet= 0, iCnt = 0, iRet2 = 0;
	DIR *dir = NULL;
	struct dirent *entry = NULL;
	char filename[50] = {'\0'};
	
	dir = opendir(argv[1]);
	if(dir == NULL)
	{
		printf("ERROR : Unable to open specified directory\n");
		return -1;
	}
	
	memset(&file, 0, sizeof(file));
	
	while((entry = readdir(dir)) != NULL)
	{
		if(((strcmp(entry->d_name, ".")) == 0) || ((strcmp(entry->d_name, "..")) == 0))
		{
			continue;
		}
		
		sprintf(filename, "%s/%s", argv[1], entry->d_name);
		printf("%s\n", filename);
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
			
			iRet = write(fd, &file, sizeof(file));
				
			if(iRet == -1)
			{
				printf("ERROR : In writing file\n");
				break;
			}
			
			memset(&file, 0, sizeof(file));
		}
	}
	
	closedir(dir);
	close(fd);
	
	if(entry == NULL)
	{
		fd = open("AllCombine", O_RDONLY);
		if(fd == -1)
		{
			printf("ERROR : In opening file\n");
			return -1;
		}
		
		iRet = read(fd, &file, sizeof(file));
		if(iRet == -1)
		{
			printf("ERROR : In reading file\n");
			perror("Error");
			close(fd);
			return -1;
		}
		
		while((iRet = read(fd, &file, sizeof(file))) != 0)
		{
			printf("File Size : \t\t%d bytes\n",(int)file.st_size);
			printf("Number of Links : \t%d\n",(int)file.st_nlink);
			printf("File inode : \t\t%d\n",(int)file.st_ino);
			printf("File system number: \t\t%d\n",(int)file.st_dev);
			printf("Number of blocks allocated fior file\t\t%d\n",(int)file.st_blocks);
			printf("File Permissions: \t");

			printf( (S_ISDIR(file.st_mode)) ? "d" : "-");
			printf( (file.st_mode & S_IRUSR) ? "r" : "-");
			printf( (file.st_mode & S_IWUSR) ? "w" : "-");
			printf( (file.st_mode & S_IXUSR) ? "x" : "-");
			printf( (file.st_mode & S_IRGRP) ? "r" : "-");
			printf( (file.st_mode & S_IWGRP) ? "w" : "-");
			printf( (file.st_mode & S_IXGRP) ? "x" : "-");
			printf( (file.st_mode & S_IROTH) ? "r" : "-");
			printf( (file.st_mode & S_IWOTH) ? "w" : "-");
			printf( (file.st_mode & S_IXOTH) ? "x" : "-");
			printf("\n\n");
			printf("------------------------------------------------\n\n");
			
			memset(&file, 0, sizeof(file));
		}
		
		close(fd);
	}
	
	return 0;
}
