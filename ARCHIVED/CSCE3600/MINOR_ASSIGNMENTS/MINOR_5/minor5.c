/*
Name:       Axel Yates
Assignment: Minor 5
Class:      CSCE3600-001
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NITEMS 10       // number of items in shared buffer

//global pthread condition variables

pthread_cond_t shared_buffer_full = PTHREAD_COND_INITIALIZER; 
                            /* this is to handle when shared buffer is full subsequently,
                            nothing else can be added to the buffer until a key is removed from
                            the buffer*/


pthread_cond_t shared_buffer_empty = PTHREAD_COND_INITIALIZER;
                            /* this is to handle when shared buffer is empty subsequently,
                            nothing can be read/echoed back to the screen until a key is added to 
                            the buffer*/

// shared variables
char shared_buffer[NITEMS]; // echo buffer
int shared_count;       // item count

pthread_mutex_t mutex;      // pthread mutex
unsigned int prod_index = 0;    // producer index into shared buffer
unsigned int cons_index = 0;    // consumer index into shard buffer

// function prototypes
void * producer(void *arg);
void * consumer(void *arg);

int main(){

    pthread_t prod_tid;
    pthread_t cons_tid1;
    pthread_t cons_tid2; 

    // initialize pthread variables
    pthread_mutex_init(&mutex, NULL);
    int pthread_cond_init(pthread_cond_t *shared_buffer_full, const pthread_condattr_t *attr);   
    int pthread_cond_init(pthread_cond_t *shared_buffer_empty, const pthread_condattr_t *attr);   
 
    // start producer thread
    pthread_create(&prod_tid, NULL, producer, NULL);

    // start consumer threads
    pthread_create(&cons_tid1, NULL, consumer, NULL);
    pthread_create(&cons_tid2, NULL, consumer, NULL);
   

    //stuff is happening here
 
    // wait for threads to finish
    pthread_join(prod_tid, NULL);
    pthread_join(cons_tid1, NULL);
    pthread_join(cons_tid2, NULL);
            
    // clean up
    pthread_mutex_destroy(&mutex);
    int pthread_cond_destroy(pthread_cond_t *shared_buffer_full);   
    int pthread_cond_destroy(pthread_cond_t *shared_buffer_empty);
    
    return 0;
}

// producer thread executes this function
void * producer(void *arg){

    char key;

    while (1){

        // read input key
        scanf("%c", &key);

        while (1){

            // acquire mutex lock
            pthread_mutex_lock(&mutex);

            // if buffer is full, release mutex lock and check again
            if (shared_count == NITEMS){

                pthread_mutex_unlock(&mutex);

            }
            else{

                break;

            }
        

        }

        // store key in shared buffer
        shared_buffer[prod_index] = key;

        // update shared count variable
        shared_count++;

        // update producer index
        if (prod_index == NITEMS - 1){

            pthread_cond_signal(&shared_buffer_empty);
            prod_index = 0;

        }
        else{

            prod_index++;

        }        
        // release mutex lock
        pthread_mutex_unlock(&mutex); 
    }

    return NULL;
}

// consumer thread executes this function
void * consumer(void *arg){

    char key;

    int id = (int)pthread_self();

    while (1){

        while (1){

            // acquire mutex lock
            pthread_mutex_lock(&mutex);

            // if buffer is empty, release mutex lock and check again
            if (shared_count == 0){

                pthread_mutex_unlock(&mutex);

            }
            else{

                break;

            }
        }

        // read key from shared buffer
        key = shared_buffer[cons_index];
        
        // echo key
        printf("consumer %d %c\n", id, key);

        // update shared count variable
        shared_count--;

        // update consumer index
        if (cons_index == NITEMS - 1){

             pthread_cond_wait(&shared_buffer_full, &mutex);
             cons_index = 0;
        
        }
        else{

            cons_index++;

        }    
        // release mutex lock
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}
