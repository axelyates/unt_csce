#include"stdio.h"  
#include"stdlib.h"  
#include"sys/types.h"  
#include"sys/socket.h"  
#include"string.h"  
#include"netinet/in.h"  
#include"netdb.h"
#include"pthread.h"
  
#define PORT 4444 
#define BUF_SIZE 2000 
  
void * receiveMessage(void * socket) {
 int sockfd, ret;
 char buffer[BUF_SIZE]; 
 sockfd = (int) socket;
 memset(buffer, 0, BUF_SIZE);  
 for (;;) {
  ret = recvfrom(sockfd, buffer, BUF_SIZE, 0, NULL, NULL);  
  if (ret < 0) {  
   printf("Error receiving data!\n");    
  } else {
   printf("server: ");
   fputs(buffer, stdout);
   //printf("\n");
  }  
 }
}

int main(int argc, char**argv) {  
 struct sockaddr_in addr, cl_addr;  
 int sockfd, ret;  
 char buffer[BUF_SIZE]; 
 char * serverAddr;
 pthread_t rThread;

 if (argc < 2) {
  printf("usage: client < ip address >\n");
  exit(1);  
 }


		printf("argv[1] = %s\n",argv[1]);

	if(!strcmp(argv[1],"CSE01")){
		serverAddr = "129.120.151.94";
	}
	if(!strcmp(argv[1],"CSE02")){
		serverAddr = "129.120.151.95";
	}
	if(!strcmp(argv[1],"CSE03")){
		serverAddr = "129.120.151.96";
	}
	if(!strcmp(argv[1],"CSE04")){
		serverAddr = "129.120.151.97";
	}
	if(!strcmp(argv[1],"CSE05")){
		serverAddr = "129.120.151.98";
	}
	if(!strcmp(argv[1],"CSE06")){
		serverAddr = "129.120.151.99";
	}

 
 sockfd = socket(AF_INET, SOCK_STREAM, 0);  
 if (sockfd < 0) {  
  printf("Error creating socket!\n");  
  exit(1);  
 }  
 printf("Socket created...\n");   

 memset(&addr, 0, sizeof(addr));  
 addr.sin_family = AF_INET;  
 addr.sin_addr.s_addr = inet_addr(serverAddr);
 addr.sin_port = PORT;     

 ret = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));  
 if (ret < 0) {  
  printf("Error connecting to the server!\n");  
  exit(1);  
 }  
 printf("Connected to the server...\n");  

 memset(buffer, 0, BUF_SIZE);
 printf("Enter your messages one by one and press return key!\n");

 //creating a new thread for receiving messages from the server
 ret = pthread_create(&rThread, NULL, receiveMessage, (void *) sockfd);
 if (ret) {
  printf("ERROR: Return Code from pthread_create() is %d\n", ret);
  exit(1);
 }

 while (fgets(buffer, BUF_SIZE, stdin) != NULL) {
  ret = sendto(sockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &addr, sizeof(addr));  
  if (ret < 0) {  
   printf("Error sending data!\n\t-%s", buffer);  
  }
 }

 close(sockfd);
 pthread_exit(NULL);
 
 return 0;    
}  
