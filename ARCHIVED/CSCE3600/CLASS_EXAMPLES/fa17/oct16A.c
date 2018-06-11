#include <stdio.h>
#include <pthread.h>

void * update_val(void *arg);

int main() {
	int i, *retval, val[10];
	pthread_t tid[10];

	for (i = 0; i < 10; i++)
	{
		val[i] = i;
		pthread_create(&tid[i], NULL, update_val, val + i);
	}

	for (i = 0; i < 10; i++)
	{
		pthread_join(tid[i], (void **) &retval);
		printf("Thread %d: %d %d\n", i, val[i], *retval);
	}


	return 0;
}

void * update_val(void *arg)
{
	int i, *count;
	count = (int *) arg;
	for (i = 0; i < 10; i++)
		*count += 1;

	pthread_exit(count);
}
