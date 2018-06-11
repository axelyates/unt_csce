#include <stdio.h>
#include <stdlib.h> /* needed to access numeric conversion functions */
int main(int argc, char *argv[])
{
	if (argc != 4) {
		printf("usage: %s i|f operand1 operand2\n", argv[0]);
		printf("--> i = integer division, f = double division\n");
		exit(EXIT_FAILURE);
	}

	if (argv[1][0] == 'i') {
		printf("%s/%s = %d\n", argv[2], argv[3], atoi(argv[2])/atoi(argv[3]));  }
	else if (argv[1][0] == 'f') {
		printf("%s/%s = %lf\n", argv[2], argv[3], atof(argv[2])/atof(argv[3]));  }
	else {
		printf("usage: %s i|f operand1 operand2\n", argv[0]);
	 	printf("--> i = integer division, f = double division\n");
	}
	return 0;
}
