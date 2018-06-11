#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
	int a = 42; 		// an integer (a is actually an address to the machine)
	int i = 0;  		// an integer used as an index in for statements
	int N = 0;  		// value will be read into program with scanf
	int *p1 = NULL;		// a pointer to the address of an integer
	char *p2 = NULL;	// a pointer to the address of an character
	int p3[10]; 		// a ptr to the first address of 10 integer location
	int *p4;		// a pointer to the first element of an array
	int *p5[10];	// An array of pointers to integers

	for(i = 0; i < 10; i++) p5[i] = NULL;

	// allocating memory for 10 integers
	for(i = 0; i < 10; i++)
	p5[i] = (int *) malloc(sizeof(unsigned int));
	
	// placing values in the integer locations
	for(i = 0; i < 10; i++)
	*p5[i]=i;
	
	// displaying the results
	for(i = 0; i < 10; i++)
		printf("i=%d p5[i]=%p *p5[i]=%d\n", i, p5[i], *p5[i]);

	p1 = &a;
	printf("a=%d, address of a is %p\n", a, &a);
	printf("p1=&a; results in p1->%p \n\n", p1);

	*p1 = 42;
	printf("a=%d, *p1=%d\n\n", a, *p1);

	for(i = 0; i < 10; i++) p3[i] = i;

	for(i = 0; i < 10; i++)
		printf("%p->%d\n", p3+1, *(p3+i));
		printf("\n\n");

	p1 = (int *) 42; printf("p1=%p\n", p1);

	printf("Enter the number of items: "); 
	scanf("%d", &N);

	p4 = (int *) malloc(N * sizeof(unsigned int)); printf("p4->%p \n", p4);

	for(i = 0; i < N; i++)
  		p4[i] = i*N;

	for(i = 0; i < N; i++)
		printf("%d ", p4[i]);
		printf("\n\n");

	printf("Pointer values for p5[] follow:\n");

	for(i = 0; i < 10; i++)
		printf("i=%d p5[i]=%p\n", i, p5[i]);
		printf("\n\n");

/*	printf("\n\nDereferenced pointer values for p5[] follow:\n");

	for(i = 0; i < 10; i++)
		printf("i=%d p5[i]=%p *p5[i]=%d\n", i, p5[i], *p5[i]);
		printf("\n\n");
*/




	return 0;
}

