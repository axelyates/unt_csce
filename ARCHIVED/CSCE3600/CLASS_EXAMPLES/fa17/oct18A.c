#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
int globalVar = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void *printMessage(void *arg);

int main()
{
	pthread_t tid[10];
	int i, status, index[i];
	/* pthread_mutex_init(&mutex, NULL); */
	for (i = 0; i < 10; i++)
	{
		index[i] = i;
		status = pthread_create(&tid[i], NULL, printMessage, index + i);
		if (status != 0)
		{
			perror("pthread create error");
			exit(EXIT_FAILURE);
		}
	}
	for (i = 0; i < 10; i++)
	{
		pthread_join(tid[i], NULL);
	}
	pthread_mutex_destroy(&mutex);
	printf("process : globalVar=%2d\n", globalVar);
	return 0;
}

void *printMessage(void *arg)
{
        int *count;
        count = (int *) arg;
        pthread_mutex_lock(&mutex);
	globalVar++;
	printf("thread %d: globalVar=%2d\n", *count, globalVar);
	pthread_mutex_unlock(&mutex);
	return;
}

