/********************************
	Name:		Axel Yates		|
	Date:		02/12/18		|
	Class:		CSCE4600-001	|
	Assignment:	Homework #2		|
********************************/

#include "readers-writers-solution.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_OF_READERS 5
#define NUM_OF_READS 5
#define NUM_OF_WRITERS 5
#define NUM_OF_WRITES 5

unsigned int gSharedValue = 0;
pthread_mutex_t gSharedMemoryLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t gReadPhase = PTHREAD_COND_INITIALIZER;
pthread_cond_t gWritePhase = PTHREAD_COND_INITIALIZER;
int gWaitingReaders = 0;
int gReaders = 0;

int main(int argc, char **argv){

	int i;
	int number_of_readers[NUM_OF_READERS];
	int number_of_writers[NUM_OF_WRITERS];

	pthread_t readerThreadIDs[NUM_OF_READERS];
	pthread_t writerThreadIDs[NUM_OF_WRITERS];

	// Feed random number generator
	srandom((unsigned int)time(NULL));
	// Start writers
	for(i = 0; i < NUM_OF_WRITERS; i++){
		number_of_writers[i] = i;
		pthread_create(&writerThreadIDs[i], NULL, writeMain, &number_of_writers[i]);
	}
	// Start readers
	for(i = 0; i < NUM_OF_READERS; i++){
		number_of_readers[i] = i;
		pthread_create(&readerThreadIDs[i], NULL, readMain, &number_of_readers[i]);
	}
	// Wait on writers to finish
	for(i = 0; i < NUM_OF_WRITERS; i++){
		pthread_join(writerThreadIDs[i], NULL);
	}
	// Wait on readers to finish
	for(i = 0; i < NUM_OF_READERS; i++){
		pthread_join(readerThreadIDs[i], NULL);
	}
	return 0;		
}

void *readMain(void *threadArg){

	int id = *((int*)threadArg);
	int i = 0;
	int number_of_readers = 0;	

	for(i = 0; i < NUM_OF_READS; i++){
		// Wait so that reads and writes do not all happen at once
		usleep(1000 * (random() % NUM_OF_READERS + NUM_OF_WRITERS));

		// Begin critical section
		pthread_mutex_lock(&gSharedMemoryLock);
		gWaitingReaders++;
		while (gReaders == 1){
			pthread_cond_wait(&gReadPhase, &gSharedMemoryLock);
		}
		gWaitingReaders--;
		number_of_readers = ++gReaders;	  	
		pthread_mutex_unlock(&gSharedMemoryLock);

		// Read data
		fprintf(stdout, "[r%d] reading %u  [readers: %2d]\n", id, gSharedValue, number_of_readers);

		// End critical section
		pthread_mutex_lock(&gSharedMemoryLock);
		gReaders--;
		if (gReaders == 0){
			pthread_cond_signal(&gWritePhase);
		}	  	
		pthread_mutex_unlock(&gSharedMemoryLock);
	}
	pthread_exit(0);
}

void *writeMain(void *threadArg){

	int id = *((int*)threadArg);
	int i = 0;
	int number_of_readers = 0;

	for(i = 0; i < NUM_OF_WRITES; i++){
		// Wait so that reads and writes do not all happen at once
		usleep(1000 * (random() % NUM_OF_READERS + NUM_OF_WRITERS));

		// Begin critical section
		pthread_mutex_lock(&gSharedMemoryLock);
		while (gReaders != 0){
			pthread_cond_wait(&gWritePhase, &gSharedMemoryLock);
		}
		gReaders = -1;
		number_of_readers = gReaders;
		pthread_mutex_unlock(&gSharedMemoryLock);

		// Write data
		fprintf(stdout, "[w%d] writing %u* [readers: %2d]\n", id, ++gSharedValue, number_of_readers);

		// End critical section
		pthread_mutex_lock(&gSharedMemoryLock);
		gReaders = 0;
		if(gWaitingReaders > 0){
			pthread_cond_broadcast(&gReadPhase);
		}
		else{
			pthread_cond_signal(&gWritePhase);
		}
		pthread_mutex_unlock(&gSharedMemoryLock);
	}	
	pthread_exit(0);
}
