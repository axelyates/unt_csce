/*
    Name:       Axel Yates (ary0012)
    Assignment: Recitation 5
    Date:       10/16/17
    Class:      CSCE3600-001
*/


#include <stdlib.h>
#include <unistd.h>

int main(){

    pid_t pid;
    pid = fork();
    if(pid == 0){
    /*child*/

        exit(1);

    }
    else if(pid > 0){
    /*parent*/

        sleep(3);
        system("ps -e -o pid,ppid,stat,user,cmd | grep $USER");

    }
    else{
    /*error*/
    perror("fork");
    exit(1);


    }





    return 0;
}
