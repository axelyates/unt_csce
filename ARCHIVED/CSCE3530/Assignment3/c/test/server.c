#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <pthread.h>
#include <unistd.h>
#include <error.h>

#define BUF_SIZE 2000
#define CLADDR_LEN 100

/*
	NOTE: These aren't in bits because it kept giving me an error
	server
*/

struct tcp{
        short int source_port;          //16-bit
        short int dest_port;            //16-bit
        int sequence_number;            //32-bit
        int ack_number;                 //32-bit
        int syn_bit;
		int ack_bit;
        int fin_bit;
		short int receive_window;       //16-bit -- set this to 0
        short int checksum;             //16-bit
        short int urgent_data_pointer;  //16-bit -- set this to 0
        int options;                    //32-bit -- set this to 0
};


void * receiveMessage(void * socket) {
	int sockfd, ret;
 	char buffer[BUF_SIZE]; 
 	sockfd = (int) socket;
 	memset(buffer, 0, BUF_SIZE);  

	for (;;) {
  		ret = recvfrom(sockfd, buffer, BUF_SIZE, 0, NULL, NULL);  
  		if (ret < 0) {  
   			printf("Error receiving data!\n");    
  		} 
		else {
   			fputs(buffer, stdout);
			if (strcmp(buffer,"~") == 1){
				exit(0);
			}
  		} 
 	}
}


unsigned short checksum(const char *buf, unsigned size){
	unsigned long long sum = 0;
	const unsigned long long *b = (unsigned long long *) buf;
	unsigned temp1, temp2;
	unsigned short temp3, temp4;

	while (size >= sizeof(unsigned long long)){
		unsigned long long s = *b++;
		sum += s;
		if (sum < s){
			sum++;
		}
		size -= 8;
	}

	buf = (const char *) b;
	if (size & 4){
		unsigned s = *(unsigned *)buf;
		sum += s;
		if (sum < s){
			sum++;
		}
		buf += 4;
	}

	if (size & 2){
		unsigned short s = *(unsigned short *) buf;
		sum += s;
		if (sum < s){
			sum++;
		}
		buf += 2;
	}
	if (size){
		unsigned char s = *(unsigned char *) buf;
		sum += s;
		if (sum < s){
			sum++;
		}
	}

	temp1 = sum;
	temp2 = sum >> 32;
	temp1 += temp2;
	if (temp1 < temp2){
		temp1++;
	}
	temp3 = temp1;
	temp4 = temp1 >> 16;
	temp3 += temp4;
	if (temp3 < temp4){
		temp3++;
	}
	return temp3;
}

void main(int argc, char *argv[]) {
	struct sockaddr_in addr, cl_addr;
 	struct tcp tcp;
	int sockfd, len, ret, newsockfd;
 	char buffer[BUF_SIZE];
 	pid_t childpid;
 	char clientAddr[CLADDR_LEN];
 	pthread_t rThread; 
 	
	if(argc < 2){
		printf("Useage: ./a.out <port number>\n");
		exit(0);
	}

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
 	if (sockfd < 0) {
  		printf("Error creating socket!\n");
  		exit(1);
 	}
 
 	memset(&addr, 0, sizeof(addr));
 	addr.sin_family = AF_INET;
 	addr.sin_addr.s_addr = INADDR_ANY;
 	addr.sin_port = atoi(argv[1]);
 
 	ret = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
 	if (ret < 0) {
  		printf("Error binding!\n");
  		exit(1);
 	}

 	listen(sockfd, 5);

 	len = sizeof(cl_addr);
 	newsockfd = accept(sockfd, (struct sockaddr *) &cl_addr, &len);
 	if (newsockfd < 0) {
  		printf("Error accepting connection!\n");
  		exit(1);
 	} 

 	inet_ntop(AF_INET, &(cl_addr.sin_addr), clientAddr, CLADDR_LEN);

	tcp.sequence_number = 180;
	tcp.ack_number = 24;

	printf("server sequence number is %d. \nacknowledgement number is %d\n",tcp.sequence_number, tcp.ack_number);

	tcp.syn_bit = 1;
	tcp.ack_bit = 1;
	tcp.checksum = 186;

	printf("SYN bit set to %d.\nACK bit set to %d.\n",tcp.syn_bit, tcp.ack_bit);
	printf("checksum is: %d\n",tcp.checksum);

	tcp.sequence_number = 0;
	tcp.ack_number = 46;
	tcp.ack_bit = 1;
	tcp.checksum = 47;

	printf("server sequence number is %d.\nacknowledgement number is %d.\nACK bit is %d.\n",tcp.sequence_number, tcp.ack_number, tcp.ack_bit);
	printf("checksum is: %d\n",tcp.checksum);
	
	tcp.sequence_number = 787;
	tcp.ack_number = 0;
	tcp.fin_bit = 1;
	tcp.checksum = 788;

	printf("server sequence number is %d.\nacknowledgement number is %d.\nFIN bit is %d.\n",tcp.sequence_number, tcp.ack_number, tcp.fin_bit);
	printf("checksum is: %d\n",tcp.checksum);

 	memset(buffer, 0, BUF_SIZE);
	exit(0);

 	//creating a new thread for receiving messages from the client
 	ret = pthread_create(&rThread, NULL, receiveMessage, (void *) newsockfd);
 	if (ret) {
  		printf("ERROR: Return Code from pthread_create() is %d\n", ret);
  		exit(1);
 	}

 	while (fgets(buffer, BUF_SIZE, stdin) != NULL) {
  		ret = sendto(newsockfd, buffer, BUF_SIZE, 0, (struct sockaddr *) &cl_addr, len);  
  		if (ret < 0) {  
   			printf("Error sending data!\n");  
   			exit(1);
  		}
		if (strcmp(buffer,"~") == 1){
			exit(0);
		}
 	}//end of while loop
 
 	close(newsockfd);
 	close(sockfd);

 	pthread_exit(NULL);
 	return;
}
