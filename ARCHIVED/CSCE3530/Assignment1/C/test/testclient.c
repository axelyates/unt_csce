#include<stdio.h>  
#include<stdlib.h>  
#include<sys/types.h>     
#include<sys/socket.h>  
#include<netinet/in.h>  
#include<netdb.h>  
#include<string.h>  

int main(int argc, char *argv[])  
{  
      int sockfd,portno,n;
      char buffer[256];
      struct sockaddr_in serv_addr;
      struct hostent *server;

      //while(counter != 5)
      // /{
            if (argc < 3)
      {  
            fprintf(stderr,"Usage %s hostname port...\n",argv[0]);
            exit(1);
      }

      portno = atoi(argv[2]);
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
      if (sockfd < 0)
            printf("\error opening socket...\n");

      bzero((char *) &serv_addr, sizeof(serv_addr));
      server = gethostbyname(argv[1]);

      if (server == NULL)
      {
            fprintf(stderr,"no such host...\n");
            exit(0);
      }

      serv_addr.sin_family = AF_INET;
      bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
      serv_addr.sin_port = htons(portno);

      if (connect(sockfd, &serv_addr,sizeof(serv_addr)) <0 )  
            printf("\error connecting\n");

      printf("your message:");
      fgets(buffer, 256, stdin);
      while(1)
      {
            n = write(sockfd,buffer,strlen(buffer));
      }
      if (n < 0)
            printf("error writing to socket\n");

      n = read(sockfd, buffer, 255);

      if (n < 0)
            printf("error reading from socket\n");

      printf("%s\n", buffer);          

      return 0;
}
