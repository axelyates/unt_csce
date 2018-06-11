/* Compilation: gcc -o server server.c
   Execution  : ./server <port number>
*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <error.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    	int sockfd, newsockfd, portno, clilen, n;
   	struct sockaddr_in serv_addr, cli_addr; 
    	char buffer[256]; 

	if(argc < 2)
	{

		printf("\nPort number is missing...\n");
		exit(0);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
		error(EXIT_FAILURE, 0, "ERROR opening socket");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
		error(EXIT_FAILURE, 0, "ERROR binding");

	printf("\nServer Started and listening to the port %d\n", portno);
    	listen(sockfd, 5);

	while(1)
	{
		//Connecting with the client
		clilen=sizeof(cli_addr);
		newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0)
				error(EXIT_FAILURE, 0, "ERROR on accept");
		printf("\nClient is connected...\n");

		//Receiving the message from the client
		bzero(buffer,256);
		n = read(newsockfd,buffer,255);
	   	if(n < 0)
			error(EXIT_FAILURE, 0, "ERROR reading from socket");
	   	else
	   	{
			printf("\nClient has sent: %s\n", buffer);
		
			//Sending the message to the client
			bzero(buffer,256);
		   	printf("\nEnter server's message: ");
			scanf("%s", buffer);
		   	n = write(newsockfd, buffer, strlen(buffer));

			//Closing the connection
			//close(newsockfd);		
	
		}
	}

	return 0;
}
