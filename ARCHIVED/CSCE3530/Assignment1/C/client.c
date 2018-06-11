/* Compilation: gcc -o client client.c
   Execution  : ./client <port number> <server address>
*/

#include <stdio.h>                      
#include <sys/socket.h>         
#include <netinet/in.h>
#include <netdb.h>
#include <error.h>
#include <unistd.h> 
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];

    if (argc < 2){

        printf("Usage: ./client <port number> <server address>\n");
        printf("*if on the same machine as server, use \"localhost\" as server address*\n");
        exit(0);

    }

    portno = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){

        error(EXIT_FAILURE, 0, "ERROR opening socket");

    }
    server = gethostbyname(argv[2]); //IP address of server
    //server = gethostbyname("localhost"); //Both in the same machine [IP address 127.0.0.1] <-- given usecase, this statement is null
	
    if (server == NULL){

        printf("\nERROR, no such host...\n");
        exit(0);

    }

    //Connecting with the server
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);
    if(connect(sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0){

        error(EXIT_FAILURE, 0, "ERROR connecting the server...");

    }

    while(buffer != "bye"){
    //Sending the message to the server
    printf("\nEnter client's message: ");
    bzero(buffer,256);
    scanf("%s", buffer);
    if(strcmp("bye",buffer) == 0){
        printf("they're equal\n");
    }
    n = write(sockfd, buffer, strlen(buffer));
    printf("test0\n");
    if (n < 0){

        error(EXIT_FAILURE, 0, "ERROR writing to socket");
	
    }
    printf("test1\n");
    //Receiving the message from the client
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0){

        error(EXIT_FAILURE, 0, "ERROR reading from socket");

    }
    else{

        printf("Server has sent: %s\n", buffer);

    }
    }//end of while loop
    //Closing the connection
    close(sockfd);		

    return 0;	
} 
