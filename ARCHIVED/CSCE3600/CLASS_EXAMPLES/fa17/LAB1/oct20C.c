#include <stdio.h>      /* Input/Output */
#include <pthread.h>    /* POSIX Threads */
#include <string.h>     /* String handling */
#include <semaphore.h>  /* Semaphore */

/* prototype for thread routine */
void handler ( void *ptr );

sem_t mutex;
int counter; /* shared variable */

int main()
{
    int i[2] = {0, 1};
    pthread_t thread_a;
    pthread_t thread_b;
    
    sem_init(&mutex, 0, 1); 
                                 
    pthread_create (&thread_a, NULL, (void *) &handler, (void *) &i[0]);
    pthread_create (&thread_b, NULL, (void *) &handler, (void *) &i[1]);
    
    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);

    sem_destroy(&mutex); /* destroy semaphore */
}

void handler ( void *ptr )
{
    int x; 
    x = *((int *) ptr);
    printf("Thread %d: Waiting to enter critical region...\n", x);
    sem_wait(&mutex);       /* down semaphore */
    /* START CRITICAL REGION */
    printf("Thread %d: Now in critical region...\n", x);
    printf("Thread %d: Counter Value: %d\n", x, counter);
    printf("Thread %d: Incrementing Counter...\n", x);
    counter++;
    printf("Thread %d: New Counter Value: %d\n", x, counter);
    printf("Thread %d: Exiting critical region...\n", x);
    int value;
    sem_getvalue(&mutex, &value);
    printf("semaphore value=%d\n", value);
    /* END CRITICAL REGION */    
    sem_post(&mutex);       /* up semaphore */
    sem_getvalue(&mutex, &value);
    printf("semaphore value=%d\n", value);
    
    pthread_exit(0); /* exit thread */
}
