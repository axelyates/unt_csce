/*
    Name:       Axel Yates (ary0012)
    Assignment: Recitation 5
    Date:       10/16/17
    Class:      CSCE3600-001
*/


#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){

    char *name;
    pid_t pid;
    pid = fork();
    if(pid == 0){
    /*child*/

        printf("child: %d. started\n",getpid());
        printf("child: parent = %d\n",getppid());
        printf("child: ...\n");
        sleep(25);
        printf("wah wah wah /*child is awake :)*/\n");

    }
    else if(pid > 0){
    /*parent*/

        printf("parent: %d started\n",getpid());
        printf("parent: parent = %d\n",getppid());

    }
    else{
    /*error*/

        perror("fork");
        exit(1);


    }
    /*outside if elseif else*/

    name = (pid == 0) ? "child" : "parent";

    printf("%s: terminating...\n",name);

    return 0;
}
