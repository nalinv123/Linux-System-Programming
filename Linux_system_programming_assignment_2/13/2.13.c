#include"header.h"

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Insufficient arguments\n");
		return -1;
	}

	DIR *dir;
	struct dirent *entry;
	struct stat file;
	char sourcefilename[100] = {'\0'};
	char destinationfilename[100] = {'\0'};
	int fdread, fdwrite, ret;
	char buffer[512] = {'\0'};
	
	dir = opendir(argv[1]);
	if(dir == NULL)
	{
		printf("Unable to open directory\n");
		return -1;
	}
	
	while((entry = readdir(dir)) != NULL)
	{
		sprintf(sourcefilename, "%s/%s", argv[1], entry->d_name);
		//printf("%s\n",sourcefilename);
		stat(sourcefilename, &file);
		
		if(S_ISREG(file.st_mode))
		{
			sprintf(destinationfilename, "%s/%s", argv[2], entry->d_name);
			//printf("%s\n",destinationfilename);
			fdread = open(sourcefilename, O_RDONLY);
			if(fdread == -1)
			{
				printf("Unable to open file\n");
				closedir(dir);
				return -1;
			}
			
			fdwrite = creat(destinationfilename, 0666);
			if(fdwrite == -1)
			{
				printf("Unable to create file\n");
				closedir(dir);
				return -1;
			}
			
			while((ret = read(fdread, buffer, sizeof(buffer))) != 0)
			{
				write(fdwrite, buffer, ret);
			}
		}
	}
	
	close(fdread);
	close(fdwrite);
	closedir(dir);

	return 0;
}
