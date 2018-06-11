#include <stdio.h>
#include <string.h>    //strlen
#include <stdlib.h>    //strlen
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/un.h>
#include <arpa/inet.h> //inet_addr
#include <unistd.h>    //write
#include <sys/select.h> 
#include <time.h>
#include <fcntl.h>

const char message[] = "hello, world\n";

int test(int tickets[], int test, int end);

int test(int tickets[], int test, int end){
    int x = 0;
    for(x = 0; x < end; x++){
        if(tickets[x] == test){
            return 1;
        }
    }
    return 0;
}



int main(int argc , char *argv[]){
     
    char buf[1024];             //buffer for messages to others
    char message[512];
    int s;                      //listen socket
    int ns;                     //socket for first connection
    int ns2;                    //socket for second connection
    socklen_t len;              //len of sockaddr
    int maxfd;                  //descriptors up to maxfd-1 polled
    int nread;                  //# of chars on read()
    int nready;                 //# of descriptors ready
    struct sockaddr_in server, client;
    fd_set fds;                 //set of file dscriptors to poll
    int status = 0;
    srand(time(NULL));
    int i = 0;
    int num_of_tickets = 20;
    int ticket[num_of_tickets];
    char msg[7];

    if(argc != 2){
        printf("ussage : %s port\n",argv[0]);
        exit(0);
    }

    int port;
    port = atoi(argv[1]);   //port specified by user and captured at command line

    //create socket
    if((s = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("could not create socket\n");
    }

    //create the address of the server
    memset(&server, 0, sizeof(struct sockaddr_un));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);

    //bind socket to address
    status = bind(s, (struct sockaddr *)&server, sizeof(server));
    if(status != 0){
        perror("bind failed");
        exit(1);
    }

    //listen for connections
    status = listen(s, 2);
    if(status != 0){
        perror("couldn't listen");
        exit(1);
    }
    int received = 0;
    bzero(message, 255);

    while(1){
       //accept a connection
        int sclient = 0;
        int len = sizeof(client);
        ns = accept(s, (struct sockaddr *)&client, &len);
        if(ns == -1){
            perror("couldn't establish connection with child socket");
            close(s);
            break;
        }

        //here it waits for the second connection

        ns2 = accept(s, (struct sockaddr *)&client, &len);
        if(ns2 == -1){
            perror("couldn't establish connection with child socket");
            close(s);
            break;
        }

        //both connections established so print table
        printf("[SERVER]: Database Table:\n");
        printf("-------------------------\n");
        for(i = 0; i < num_of_tickets; i++){
            ticket[i] = ((rand()%89999)+10000);
            while(test(ticket, ticket[i], i) == 1){
                ticket[i] = ((rand()%89999) + 10000);
            }
            printf("[Tkt#  %d] %d  : AVAIL\n",i,ticket[i]);
        }
        printf("-------------------------\n");

        socklen_t clilen = sizeof(client);


        maxfd = (ns > ns2 ? ns : ns2) + 1;
        while(received < 20){
            bzero(message, 255);
            FD_ZERO(&fds);
            FD_SET(ns, &fds);
            FD_SET(ns2, &fds);
        

            int temp;
            temp = ticket[i];
            snprintf(msg, sizeof(msg), "%d", temp);

            //wait for buy/return
            nready = select(maxfd, &fds, (fd_set *) 0, (fd_set *) 0, (struct timeval *) 0);
            i++;

            //if either device has some input, read it and copy it to the other
            if(FD_ISSET(ns, &fds)){
                nread = read(ns, message, sizeof(message));
                printf("[CLIENT 1]: %s\n", message); //outputs buy or return from client 1
                send(ns, msg, sizeof(msg), 0);
                received++;
            }
            if(FD_ISSET(ns2, &fds)){
                nread = read(ns2, message, sizeof(message));
                printf("[CLIENT 2]: %s\n", message); //outputs buy or return from client 2
                send(ns2, msg, sizeof(msg), 0);
                received++;
            }
            if(received == 20){
                close(ns);
                close(ns2);
                printf("[SERVER]: Database Table:\n");
                printf("-------------------------\n");
                for(i = 0; i < num_of_tickets; i++){
                    printf("[Tkt #  %d] %d  : SOLD\n",i,ticket[i]);
                }
                printf("-------------------------\n");
                exit(0);
            }
            bzero(message, 255);
        }//end of second while loop 
        break; 
    } //end of first while(1) loop
    


    return 0;
}
