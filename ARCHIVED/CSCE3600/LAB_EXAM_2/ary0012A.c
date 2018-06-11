/*
Name: Axel Yates (ary0012)
Assignment: Lab Exam 2
Date: 11/13/2017
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int i = 0;
    while (++i < 10){
        pid_t pid = fork();

        
        if(pid == 0){
            //child
            char buffer[1];
            sprintf(buffer, "%d", i);
            int fd[1];
            pipe(fd);
            write(fd[1],buffer, 1); // write buffer into pipe
            close(fd[1]);
            dup2(fd[0],0);
            execlp("cat", "cat", (char *)0);
            perror("execlp failed");
            exit(EXIT_FAILURE);
        }

        //only parent can get here
        waitpid(pid, NULL, 0);

    }
    printf("\n");

    return 0;
}
