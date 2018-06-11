#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int first = 3; 
	int second = 4;
	int *array = (int *)malloc(first * second * sizeof(unsigned int));
	int i;
	int j;
	int counter = 0;

	for (i = 0; i <  first; i++)
		for (j = 0; j < second; j++)
			*(array + i*second + j) = ++counter;
 
    	for (i = 0; i <  first; i++)
      		for (j = 0; j < second; j++)
        		printf(" %d\n ", *(array + i*second + j));

	free(array);
	array = NULL;

	return 0;
}
