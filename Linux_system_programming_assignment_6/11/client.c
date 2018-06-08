/*#include"header.h"

int main(int argc, char *argv[])
{
	int sockfd = 0, iRet = 0;
	struct sockaddr socketaddr;
	
	sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
	if(sockfd == -1)
	{
		printf("ERROR : In socket creation\n");
		return -1;
	}
	
	socketaddr.sa_family = AF_UNIX;
	strncpy(socketaddr.sa_data, "./mysocket", sizeof(socketaddr));
	
	iRet = connect(sockfd, &socketaddr, sizeof(socketaddr));
	if(iRet == -1)
	{
		printf("ERROR : In connecting socket\n");
		perror("ERROR");
		close(sockfd);
		return -1;
	}
	
	iRet = write(sockfd, "hello", 5);
	if(iRet == -1)
	{
		printf("ERROR : In writing socket\n");
		perror("ERROR");
		close(sockfd);
		return -1;
	}
	
	close(sockfd);
	
	return 0;
}*/

// Client side C/C++ program to demonstrate Socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080
  
int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
  
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }
    send(sock , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    return 0;
}
