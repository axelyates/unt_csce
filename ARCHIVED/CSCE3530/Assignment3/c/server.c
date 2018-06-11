/* 
	Compilation: gcc server.c -o server
   	Execution  : ./server 5000
*/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <error.h>
#include <string.h>
#include <stdlib.h>

struct tcp{

	short int source_port;			//16-bit
	short int dest_port;			//16-bit
	int sequence_number;			//32-bit
	int ack_number;					//32-bit
	short int receive_window;		//16-bit -- set this to 0
	short int checksum;				//16-bit
	short int urgent_data_pointer;	//16-bit -- set this to 0
	int options;					//32-bit -- set this to 0

};



int main(int argc, char *argv[]){

    int sockfd, newsockfd, portno, clilen, n;
   	struct sockaddr_in serv_addr, cli_addr; 
    char buffer[256]; 

	if(argc < 2){
		printf("\nUseage: ./a.out <port number>\n");
		exit(0);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0){
		error(EXIT_FAILURE, 0, "ERROR opening socket");
	}
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	if(bind(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0){
		error(EXIT_FAILURE, 0, "ERROR binding");
	}
	printf("\nServer Started and listening to the port %d\n", portno);
    listen(sockfd, 5);


		//Connecting with the client
		clilen=sizeof(cli_addr);
		newsockfd = accept(sockfd,(struct sockaddr *) &cli_addr, &clilen);
		if (newsockfd < 0){
			error(EXIT_FAILURE, 0, "ERROR on accept");
		}
		printf("\nClient is connected...\n");

		/*
			Client is now connected:
			
			step 1: find the source port, destination port, and header length
			step 2: connect client to server - print that out to console
			
			client creates connection request:
				step 3: assign an initial client sequence number with a zero ack number - print that out to console
				step 4: set the syn bit to 1 - print that out to console
				step 5: compute checksum and populate field - print that out to console
			
			server responds to connection request:
				step 6: assign an initial server sequence number with an ack number equal to init client sequence number + 1 - print that out to console
				step 7: set the syn and ack bit to 1 - print that out to console
				step 8: compute checksum and populate field - print that out to console
			
			client responds back with ack number:
				step 9: assign a sequence number as init client sequence number + 1 with an ack number equal to init server sequence number + 1 - print that out to console
				step 10: set he ack bit to 1 - print that out to console
				step 11: compute checksum and populate field - print that out to console
		*/

	while(1){

		//Receiving the message from the client
		bzero(buffer,256);
		n = read(newsockfd,buffer,255);
	   	if(n < 0){
			error(EXIT_FAILURE, 0, "ERROR reading from socket");
	   	}
		else{
			printf("\nClient has sent: %s\n", buffer);
		
			//Sending the message to the client
			bzero(buffer,256);
		   	printf("\nEnter server's message: ");
			scanf("%s", buffer);
		   	n = write(newsockfd, buffer, strlen(buffer));

			//Closing the connection
			//close(newsockfd);		
	
		}

















	}//end of while loop

	return 0;
}
