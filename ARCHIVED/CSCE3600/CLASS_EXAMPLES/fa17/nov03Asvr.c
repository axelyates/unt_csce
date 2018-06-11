#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <arpa/inet.h>   /* inet(3) functions */

#define MAXLINE 4096

void dg_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen);

int main(int argc, char **argv)
{
	int sockfd;
	struct sockaddr_in servaddr,cliaddr;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(9877);

	bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

	dg_echo(sockfd, (struct sockaddr *) &cliaddr, sizeof(cliaddr));
}

void dg_echo(int sockfd, struct sockaddr *pcliaddr, socklen_t clilen)
{
	int n;
	socklen_t len;
	char mesg[MAXLINE];

	for( ; ; )
	{
		len = clilen;
		n = recvfrom(sockfd, mesg, MAXLINE, 0, pcliaddr, &len);

		printf("rcvd from client: %s\n", mesg);

		sendto(sockfd, mesg, n, 0, pcliaddr, len);
	}
} 

