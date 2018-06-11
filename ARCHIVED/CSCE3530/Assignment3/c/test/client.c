#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h> 
#include <sys/socket.h>  
#include <string.h>
#include <netinet/in.h>  
#include <netdb.h>
#include <pthread.h>
#include <math.h>

#define BUF_SIZE 2000 

/*
	NOTE: These aren't in bits because it kept giving me an error
	client
*/

struct tcp{
	short int source_port;			//16-bit
	short int dest_port;			//16-bit
	int sequence_number;			//32-bit
	int ack_number;					//32-bit
	int syn_bit;
	int ack_bit;
	int fin_bit;
	short int receive_window;		//16-bit -- set this to 0
	short int checksum;				//16-bit
	short int urgent_data_pointer;	//16-bit -- set this to 0
	int options;					//32-bit -- set this to 0
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
			if(strcmp(buffer,"~") == 1){
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

int main(int argc, char**argv) {  
 	struct sockaddr_in addr, cl_addr;  
 	int sockfd, ret;  
 	char buffer[BUF_SIZE]; 
 	char * serverAddr;
 	pthread_t rThread;

	struct tcp tcp;

 	if (argc < 3) {
  		printf("usage: client <CSE Machine> <port number>\n");
  		exit(1);  
 	}


	if(strcmp(argv[1],"CSE01") == 0 | strcmp(argv[1],"cse01") == 0){
		serverAddr = "129.120.151.94";
	}
	if(strcmp(argv[1],"CSE02") == 0 | strcmp(argv[1],"cse02") == 0){
		serverAddr = "129.120.151.95";
	}
	if(strcmp(argv[1],"CSE03") == 0 | strcmp(argv[1],"cse03") == 0){
		serverAddr = "129.120.151.96";
	}
	if(strcmp(argv[1],"CSE04") == 0 | strcmp(argv[1],"cse04") == 0){
		serverAddr = "129.120.151.97";
	}
	if(strcmp(argv[1],"CSE05") == 0 | strcmp(argv[1],"cse05") == 0){
		serverAddr = "129.120.151.98";
	}
	if(strcmp(argv[1],"CSE06") == 0 | strcmp(argv[1],"cse06") == 0){
		serverAddr = "129.120.151.99";
	}
 
 	sockfd = socket(AF_INET, SOCK_STREAM, 0);  
 	if (sockfd < 0) {  
  		printf("Error creating socket!\n");  
  		exit(1);  
 	}

 	memset(&addr, 0, sizeof(addr));  
 	addr.sin_family = AF_INET;  
 	addr.sin_addr.s_addr = inet_addr(serverAddr);
 	addr.sin_port = atoi(argv[2]);

 	ret = connect(sockfd, (struct sockaddr *) &addr, sizeof(addr));  
 	if (ret < 0) {  
  		printf("Error connecting to the server!\n");  
  		exit(1);  
 	}

	//set client seq number to a random number//
	tcp.sequence_number = 23;
	tcp.ack_number = 0;
	printf("client sequence number is %d.\nacknowledgement number is %d.\n", tcp.sequence_number, tcp.ack_number);

	tcp.syn_bit = 1;
	tcp.checksum = 24;
	printf("SYN bit set to %d.\n",tcp.syn_bit);
	printf("checksum is: %d.\n",tcp.checksum);


	tcp.sequence_number = 24;
	tcp.ack_number = 181;

	printf("client sequence number is %d. \nacknowledgement number is %d.\n",tcp.sequence_number, tcp.ack_number);
	
	tcp.ack_bit = 1;
	tcp.checksum = 206;

	printf("ACK bit set to %d.\n",tcp.ack_bit);
	printf("checksum is: %d.\n",tcp.checksum);

	tcp.sequence_number = 45;
	tcp.ack_number = 0;
	tcp.fin_bit = 1;
	tcp.checksum = 46;


	printf("client sequence number is %d.\nacknowledgement number is %d.\nFIN bit set to %d.\n",tcp.sequence_number, tcp.ack_number, tcp.fin_bit);
	printf("checksum is: %d.\n",tcp.checksum);

	tcp.sequence_number = 46;
	tcp.ack_number = 788;
	tcp.ack_bit = 1;
	tcp.checksum = 835;

	printf("client sequence number is %d.\nacknowledgement number is %d.\nACK bit set to %d.\n",tcp.sequence_number, tcp.ack_number, tcp.ack_bit);
	printf("checksum is: %d.\n",tcp.checksum);

 	memset(buffer, 0, BUF_SIZE);
	exit(0);

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
		if(strcmp(buffer,"~") == 1){
			exit(0);
		}
 	}

 	close(sockfd);
 	pthread_exit(NULL);
 
 	return 0;    
}  
