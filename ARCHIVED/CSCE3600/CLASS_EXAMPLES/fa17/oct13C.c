#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

void printpos(char *msg, int fd);

int main()
{
	int fd; /* file descriptor */
	pid_t pid;
	char buf[10]; /* for file data */

	if ((fd=open("file1", O_RDONLY)) < 0)
	{
		perror("open");
	}

	read(fd, buf, 10); /* move R-W ptr */
	printpos("Before fork", fd );

	if( (pid = fork()) == 0 )
	{
		/* child */
		printpos("Child before read", fd);
		read(fd, buf, 10);
		printpos("Child after read", fd);
	}
	else if( pid > 0 )
	{
		/* parent */
		wait((int *)0);
		printpos("Parent after wait", fd);
	}
	else
	{
		perror("fork");
	}
}

/* Print position in file */
void printpos(char *msg, int fd) {
	long int pos;
	if( (pos = lseek( fd, 0L, SEEK_CUR) ) < 0L )
		perror("lseek");
	printf("%s: %ld\n", msg, pos);
}

