#include <stdio.h>
#include <pthread.h>

void * worker(void *arg)
{
	printf("Hello world from worker!\n");
	pthread_exit(NULL);
}

int main()
{
	int i;
	pthread_t OtherThreads[4];

	for (i = 0; i < 4; i++)
	{
		pthread_create(&OtherThreads[i], NULL, worker, NULL);
	}

	// move printf from here to below to wait for threads to finish

	for (i = 0; i < 4; i++)
	{
		pthread_join(OtherThreads[i], NULL);
	}

	printf("Hello world from main!\n");

	return 0;
}
