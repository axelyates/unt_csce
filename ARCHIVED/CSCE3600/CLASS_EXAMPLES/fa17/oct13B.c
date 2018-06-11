#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int glbvar = 6;
int main() {
	int locvar = 88;
	pid_t pid;
	printf("Before fork()\n");
	if( (pid = fork()) == 0 ) {
		/* child */
		glbvar++; 
		locvar++;
	}
	else if ( pid > 0 ) {
		/* parent */
		sleep(2);
	}
	else
		perror("fork error");
	printf("pid=%d, glbvar=%d, locvar=%d\n", getpid(), glbvar, locvar);
	return 0;
} /* end main */

