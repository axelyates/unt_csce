#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/*
fork() returns the process identifier (pid) of the child process within the parent, and
fork() returns 0 within the child
*/



int main()
{
        pid_t pid;         /* could be int */
        int i;
        pid = fork();
        printf("PID=%d\n", pid);

        if( pid > 0 )
        {
                /* parent */
                for( i=0; i < 10; i++ )
                        printf("\t\t\tPARENT %d\n", i);
        }
        else if (pid == 0)
        {
                /* child */
                for( i=0; i < 10; i++ )
                        printf("CHILD %d\n", i );
        }
	else
	{
		printf("fork failed\n");
	}

        return 0;
}

