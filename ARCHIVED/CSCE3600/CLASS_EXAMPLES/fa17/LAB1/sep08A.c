#include <stdio.h>

int main()
{
	int number;
	char animal[37];

	printf("Enter the animal name: ");
	scanf("%s", animal);

	printf("How many %s do we have: ", animal);
	scanf("%d", &number);

	printf("Wow! We have %d %s", number, animal);
	(number > 1) ? printf("s on the farm!\n") : printf(" on the farm!\n");

	return 0;
}
