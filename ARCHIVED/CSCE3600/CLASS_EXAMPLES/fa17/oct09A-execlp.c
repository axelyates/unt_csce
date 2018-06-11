#include <stdio.h>
#include <unistd.h>

int main()
{
        char *cmd[] = {"who", "ls", "date"};
        int i;

        printf("0=who 1=ls 2=date : ");
        scanf("%d", &i);
        execlp(cmd[i], cmd[i], (char *)0 );
        printf("execlp failed\n");

        return 0;
}

