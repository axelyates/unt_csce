#include <stdio.h>
#include <string.h>
#include <pthread.h>

int done = 0;

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t  c = PTHREAD_COND_INITIALIZER;

void thr_exit()
{
	pthread_mutex_lock(&m);

	done = 1;

	pthread_cond_signal(&c);
	pthread_mutex_unlock(&m);
}

void *child(void *arg)
{
	printf("child\n");
	thr_exit();

	return 0;
}

void thr_join()
{
	pthread_mutex_lock(&m);

	while (done == 0)
	{
		pthread_cond_wait(&c, &m);
	}

	pthread_mutex_unlock(&m);
}

int main(int argc, char *argv[])
{
	printf("parent: begin\n");

	pthread_t p;

	pthread_cond_init(&c, NULL);
	
	int status = pthread_create(&p, NULL, child, NULL);
	if (status != 0)
	{
		// some kind of error...
		printf("ERROR: %s\n", strerror(status));
	}

	thr_join();

	pthread_cond_destroy(&c);

	printf("parent: end\n");

	return 0;
}
