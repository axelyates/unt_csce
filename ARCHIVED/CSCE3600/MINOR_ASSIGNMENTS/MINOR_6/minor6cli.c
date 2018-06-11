#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg){
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    srand (time(NULL));
    int s;
    int port;
    int n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    int chance=0, tickets[20];
    char buffer[256];
    for(chance=0; chance < 20; chance++){
        tickets[chance] = 0;
    }
    if (argc < 3){
        printf("usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    port = atoi(argv[2]);
    s = socket(AF_INET, SOCK_STREAM, 0);

    if (s < 0) {
        perror("couldn't open socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL){
        perror("couldn't find host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(s,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("couldn't connect");
        exit(0);
    }
    int x = 0;
    chance = 0;
    for(x = 0; x < 40; x++){
        chance=(rand()%10)+1;
        bzero(buffer,256);
        if(chance<8){
            n = write(s,"BUY",strlen("BUY"));
            printf("[CLIENT]: BUY\n");
            recv(s, buffer, sizeof(buffer), 0);
            printf("[SERVER]: %s\n", buffer);
            printf("[CLIENT]: %s ok\n", buffer);
        }
        else{
            n = write(s,"RETURN",strlen("RETURN"));
            printf("[CLIENT]: RETURN\n");
            recv(s, buffer, sizeof(buffer), 0);
            printf("[SERVER]: %s\n", buffer);
            printf("[CLIENT]: %s ok\n", buffer);
        }

    }

    bzero(buffer,256);
    n = read(s,buffer,255);
    
    close(s);

    return 0;
}
