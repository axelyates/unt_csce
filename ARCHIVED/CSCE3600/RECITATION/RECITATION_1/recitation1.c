/*

    Name: Axel Yates (euid: ary0012)
    Class: CSCE3600 Recitation
    Date: 09/11/17

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int    counter;
	int    retcode;
	double *dbl_ptr;
	FILE   *fp;

	srand(time(NULL));

	// Part 1
	// request a piece of memory using malloc
	dbl_ptr = (double*) malloc(10 * sizeof(double));
        if (!dbl_ptr)
	{
		printf("Memory allocation error!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Memory allocation successful.\n");
	}

	// Part 2 
	for (counter = 0; counter < 10; counter++)
	{
		// generate random numbers and place into our allocated array of 10 doubles
	        dbl_ptr[counter] = rand() % 1000;
        }

	// Part 3
	// open an empty file called rec01.txt for writing, make it a binary file
	fp = fopen("rec01.txt", "wb");
        if (fp == NULL)
	{
		printf("Unable to open file!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Opened file successfully for writing.\n");
	}

	// Part 4
	// write all 10 elements of the array to the binary file using fwrite
	retcode = fwrite(dbl_ptr, sizeof(float), 10, fp);
        if (retcode != 10)
	{
		printf("Write error!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Write was successful.\n");
	}

	// close the file
	// release the allocated memory
        fclose(fp);
        free(dbl_ptr);

	// Part 5
	// request a piece of memory using malloc
	dbl_ptr = (double*) malloc(10 * sizeof(double));
        if (!dbl_ptr)
	{
		printf("Memory allocation error!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Memory allocation successful.\n");
	}

	// Part 6
	// open the binary file called rec01.txt for reading
	fp = fopen("rec01.txt", "rb");
        if (fp == NULL)
	{
		printf("Unable to open the file!\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Opened file successfully for reading.\n");
	}

	// Part 7
	// read the contents of the binary file into the allocated memory using fread
	retcode = fread(dbl_ptr, sizeof(float), 10, fp);
        if (retcode != 10)
	{
		printf("Read error!\n");
		exit(EXIT_FAILURE);
	}
	else 
	{
		printf( "Read was successful.\n" );
	}

	// close the file
        fclose(fp);

	// Part 8
	printf("The numbers read from file are:\n");
	for (counter = 0; counter < 10; counter++)
	{
		// print each element of the array to the screen
	        printf("%f\n", dbl_ptr[counter]);
        }

	// release the allocated memory
        free(dbl_ptr);
	return 0;
}
