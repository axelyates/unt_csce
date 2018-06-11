#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int *x, *y;

	x = (int *) calloc(10, sizeof(int));
	for (i = 0; i < 10; i++)
	{
		x[i] = i;
	}

	x = realloc(x, 5 * sizeof(int));

/*	for (i = 10; i < 20; i++)
	{
		x[i] = i;
	} */

	for (i = 0; i < 20; i++)
	{
		printf("%d\n", x[i]);
	}

	return 0;
}
	
