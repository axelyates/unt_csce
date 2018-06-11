#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define NUM1 10000

void doit()
{
	double x = 0;
	int i;

	for (i = 0; i < NUM1; i++)
	{
		x += sin(i);
	}
}

void f()
{
	int i;

	for (i = 0; i < 1000; i++)
	{
		doit();
	}
}

void g()
{
	int i;

	for (i = 0; i < 5000; i++)
	{
		doit();
	}
}

int main()
{
	double s = 0;
	int i;
        #pragma omp parallel for

	for (i = 0; i < 1000 * NUM1; i++)
	{
		s += sqrt(i);
	}

	f();
	g();

	printf("Done\n");

	exit(0);
}
