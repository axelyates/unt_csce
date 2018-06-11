/*

    Name:       Axel Yates
    Assignment: Minor 4
    Class:      CSCE3600-001

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int arr_sum(int arr[], int n){
    if(n < 0){
        return 0;
    }
    else{
        return arr[n] + arr_sum(arr, n-1);
    }
}

int main(){

    FILE *fptr;
    char filename[10];
    char ch[1];
    int remain = 0;
    int finish = 0;
    int wait = 0;
    int i = 0;
    int num_of_lines = 0;
    double avgthruput = 0;
    double avgwaittime = 0;
    double avgturntime = 0;

    printf("Enter name of process file: ");
    scanf("%s", filename);
    fptr = fopen(filename, "r");
    if(fptr == NULL){
        printf("error: unable to open file %s. terminating...\n", filename);
        exit(0);
    }
    ch[1] = fgetc(fptr);
    while(ch[1] != EOF){
        ch[1] = fgetc(fptr);
        if(ch[1] == '\n'){
            num_of_lines++;
        }
    }
    int pid[num_of_lines];
    int arrive[num_of_lines];
    int burst[num_of_lines];
    int waiting_time[num_of_lines];
    int temp[num_of_lines];
    for(i = 0; i < num_of_lines; i++){
        pid[i] = i+1;
        arrive[i] = -1;
        burst[i] = -1;
        waiting_time[i] = 0;
    }
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int z = 0;
    int y = 0;  
    int x = 0;
    int n = 0;
    char arrival[5];
    bool arrived = false;
    fclose(fptr);
    fptr = fopen(filename, "r");
    while((read = getline(&line, &len, fptr)) != -1){
        //printf("%s", line);
        for(i = 0; i < strlen(line); i++){
            if(line[i] == 32 && arrived == false){
                do{
                    i++;
                }while(line[i] == 32);
                //this code runs when a number is hit
                while(line[i] != 32){
                    arrive[y] = line[i];
                    i++;
                }
                arrived = true;
            }
            if(line[i] == 32){
                y++;
                do{
                    i++;
                }while(line[i] == 32);
                //this code runs when a number is hit
                while(line[i] != 10){
                    burst[z] = line[i];
                    i++;
                }
            }
        }
        z++;
        arrived = false;
    }
    printf("PID\tarrive\tburst\tremain\tfinish\twait\n");
    printf("--------------------------------------------\n");
    for(i = 0; i < num_of_lines; i++){
        printf("P%d\t%c\t%c\t%d\t%d\t%d\n",pid[i],arrive[i],burst[i],remain,finish,wait);
    }  
    for(i = 0; i < num_of_lines; i++){
        if(burst[i] == 48){
            burst[i] = 0;
        }
        if(burst[i] == 49){
            burst[i] = 1;
        }
        if(burst[i] == 50){
            burst[i] = 2;
        }
        if(burst[i] == 51){
            burst[i] = 3;
        }
        if(burst[i] == 52){
            burst[i] = 4;
        }
        if(burst[i] == 53){
            burst[i] = 5;
        }
        if(burst[i] == 54){
            burst[i] = 6;
        }
        if(burst[i] == 55){
            burst[i] = 7;
        }
        if(burst[i] == 56){
            burst[i] = 8;
        }
        if(burst[i] == 57){
            burst[i] = 9;
        }
    }
    for(i = 0; i < num_of_lines; i++){
        if(arrive[i] == 48){
            arrive[i] = 0;
        }
        if(arrive[i] == 49){
            arrive[i] = 1;
        }
        if(arrive[i] == 50){
            arrive[i] = 2;
        }
        if(arrive[i] == 51){
            arrive[i] = 3;
        }
        if(arrive[i] == 52){
            arrive[i] = 4;
        }
        if(arrive[i] == 53){
            arrive[i] = 5;
        }
        if(arrive[i] == 54){
            arrive[i] = 6;
        }
        if(arrive[i] == 55){
            arrive[i] = 7;
        }
        if(arrive[i] == 56){
            arrive[i] = 8;
        }
        if(arrive[i] == 57){
            arrive[i] = 9;
        }
    }
    //find thruput
    int final_burst = 0;
    for(i = 0; i < num_of_lines; i++){
        final_burst += burst[i];
    }
    avgthruput = ((double)num_of_lines)/(final_burst);
    //find waittime
    int final_wait = arr_sum(burst, num_of_lines-1);
    avgwaittime = (double)final_wait/num_of_lines;
    //find turntime
    int final_turn = 0;
    for(i = 0; i < num_of_lines; i++){
        final_turn = burst[i] + waiting_time[i];
    }
    for(i = 0; i < num_of_lines; i++){
        if(i > 0){
            final_turn += burst[i] + burst[i-1];
        }
    }
    avgturntime = (double)final_turn/num_of_lines;
    printf("average throughput      = %f\n", avgthruput);
    printf("average waiting time    = %f\n", avgwaittime);
    printf("average turnaround time = %f\n", avgturntime);
    fclose(fptr);

    return 0;
}
