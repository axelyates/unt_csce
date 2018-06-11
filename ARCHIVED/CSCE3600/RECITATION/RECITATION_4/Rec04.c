#include <stdio.h>
#include <stdlib.h>



int main(){

    int i; //indexing through a for loop
    int j; //indexing through a for loop
    int n; //number of processes
    int waits = 0; //cumulative wait time for all processes
    int turns = 0; //cumulative turnaround time for all processes
    float avgwait; //average wait
    float avgturn; //average turnaround time


    printf("Enter number of processes: ");
    scanf("%d", &n);

    int* burst = malloc(n * sizeof(int)); //burst time for each process
    int* wait = malloc(n * sizeof(int)); //holds the wait time for each process
    int* turn = malloc(n * sizeof(int)); //hold the turnaround time for each process

    for(i = 0; i < n; i++){

        printf("Enter the burst time of process #%d: ", i);
        scanf("%d", &burst[i]);

    }
    wait[0] = 0;
    for(i = 0; i < n-1; i++){
        wait[i+1] = burst[i] + wait[i];


    }
//wait is now 0, 24, 27

    for(i = 0; i < n; i++){

        waits = waits + wait[i];
    }
    avgwait = (float)waits/(float)n;
    

    for(i = 0; i < n; i++){

        turn[i+1] = turn[i] + burst[i];

    }
//turn is now 24, 27, 30
    for(i = 0; i < n; i++){

        turns = turns + turn[i+1];
    }
    avgturn = (float)turns/(float)n;



    printf("process burst wait turn\n");    
    for(i = 0; i < n; i++){

        printf("p%d     %d      %d      %d\n",i, burst[i], wait[i], turn[i+1]); 

    }
    printf("avg waiting time = %f\n", avgwait);
    printf("avg turnaround time = %f\n", avgturn);
    
    free(burst);
    free(wait);
    free(turn);




    return 0;
}
