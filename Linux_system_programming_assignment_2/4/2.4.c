#include"header.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("wrong argument \n");
		return -1;
	}
	
	struct stat fileStat;
	int ret;
	
	ret = stat(argv[1], &fileStat);
	if(ret == -1)
	{
		printf("Unable read file information\n");
		return -1;
	}
	
	printf("File Size : \t\t%d bytes\n",(int)fileStat.st_size);
	printf("Number of Links : \t%d\n",(int)fileStat.st_nlink);
	printf("File inode : \t\t%d\n",(int)fileStat.st_ino);
	printf("File system number: \t\t%d\n",(int)fileStat.st_dev);
	printf("Number of blocks allocated fior file\t\t%d\n",(int)fileStat.st_blocks);
	printf("File Permissions: \t");

	printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
	printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
	printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");
 
	if(S_ISLNK(fileStat.st_mode))
	{
		printf("It is symbolic link\n");
	}
	else
	{
		printf("It is not symbolic link\n");
	}


	return 0;
}
