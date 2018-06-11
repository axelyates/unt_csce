#include <stdio.h>
#include <stdlib.h>
#include <iostream>


void swap(int *, int *); // prototype

int main()
{
	int a = 1, b = 2;

	printf("Before swap: a=%d b=%d\n", a, b);
	swap(&a, &b);
	printf(" After swap: a=%d b=%d\n", a, b);

	return 0;
}

void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
	printf("Inside swap: a=%d b=%d\n", *x, *y);

	return;
}
