/********************************
	Name:		Axel Yates		|
	Date:		02/12/18		|
	Class:		CSCE4600-001	|
	Assignment:	Homework #2		|
********************************/

#ifndef PS1_PRIORITY_READERS_AND_WRITERS_H_
#define PS1_PRIORITY_READERS_AND_WRITERS_H_

int main(int argc, char **argv);
void *readMain(void *threadArgument);
void *writeMain(void *threadArgument);

#endif
