#include<stdio.h>  
#include<stdlib.h>  
#include<sys/types.h>     
#include<sys/socket.h>  
#include<netinet/in.h>  
#include<string.h>  

int main(int argc, char *argv[])  
{  
      int sockfd, newsockfd, portNum, clien, n;
      char buffer[256];
      struct sockaddr_in serv_addr,cli_addr;
  if (argc < 2)
  {
        fprintf(stderr, "\nno port provided");
        exit(1);
  }

  sockfd = socket(AF_INET,SOCK_STREAM, 0);
  if (sockfd < 0)
        printf("\nprovide a valid port number\n");

  bzero((char *)&serv_addr, sizeof(serv_addr));
  portNum = atoi(argv[1]);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portNum);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0 )
        printf("error on binding");

  while(1)
  {
       listen(sockfd,5);
  }
  clien = sizeof(cli_addr);
  newsockfd=accept(sockfd, (struct sockaddr *) &cli_addr, &clien );

  if (newsockfd < 0)
        printf("=> Error on accepting...\n");

  bzero(buffer, 256);  
  n = read(newsockfd, buffer, 256); 

  if (n < 0)  
        printf("error reading from socket...\n");

  printf("%s\n", buffer);
  n = write(newsockfd, "message received.", 58);

  if (n < 0)
        printf("cannot write from socket...\n");

  return 0;
}
