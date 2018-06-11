This is a readme file to go with the Assignment 3 client/server TCP-handshake programs

To compile:
	gcc <program name>.c -o <program name> -pthread

example:
	gcc server.c -o server -pthread
	gcc client.c -o client -pthread

To execute:
	./<program name> <cse machine> <port number> 	//if running client program
	./<program name> <port number> 					//if running server program

example:
	./server 4444
	./client cse01 4444

NOTE: You need to run the server first, then the client.
