#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	char *cmd[] = {"who", "ls", "date"};
	int i;
	while( 1 ) {
		printf("0=who 1=ls 2=date : ");
		scanf("%d", &i);
		if(fork() == 0) {
			/* child */
			execlp( cmd[i], cmd[i], (char *)0 );
			printf("execlp failed\n");
			exit(1);
		}
		else {
			/* parent */
			wait( (int *)0 );
			printf("child finished\n");
		}
	} /* while */
} /* main */

