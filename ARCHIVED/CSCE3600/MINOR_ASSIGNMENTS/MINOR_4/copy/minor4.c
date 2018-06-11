/*

    Name:       Axel Yates
    Assignment: Minor 4
    Class:      CSCE3600-001

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    FILE *fptr;
    char filename[10];
    char line_len[20];
    char line_line[20];
    char ch[1];
    int remain = 0;

    int i = 0;
    int num_of_lines = 0;
    int avgthruput = 0;
    int avgwaittime = 0;
    int avgturntime = 0;


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
    //char line_num[num_of_lines];
    int pid[num_of_lines]; 
    int arrive[num_of_lines];
    int burst[num_of_lines];
    int burst2[num_of_lines];
    for(i = 0; i < num_of_lines; i++){

        pid[i] = i+1; 
        arrive[i] = 0;
        burst[i] = 0;
        //burst2[i] = 0;


    }
    
    int finish = 0;
    int wait = 0;
    i = 0;
    fclose(fptr);



    fptr = fopen(filename, "r");
    int x = 0; //counter for pid
    int y = 0; //counter for arrive
    int z = 0; //counter for burst
    char burst_check = ' '; //to check if burst is more than one number long
    char arrive_check = ' '; //to check if arrive is more than one number long

    ch[1] = fgetc(fptr);
    while(ch[1] != EOF){

        ch[1] = fgetc(fptr);
        if(arrive_check != ' ' && arrive_check != '\n' && ch[1] != ' ' && ch[1] != '\n'){

            //this runs if PART2 has already run and there is another number after ch
            arrive_check == ' ';
            

        }
        if(ch[1] >= 0 && ch[1] != ' ' && ch[1] != 'P' && ch[1] != 'p' && ch[1] != '\n'){

            //at this point, ch is PID


            if(ch[1] != ' ' | ch[1] != '\n'){

                ch[1] = fgetc(fptr);
                while(ch[1] == ' ' | ch[1] == '\n'){

                    ch[1] = fgetc(fptr);

                }

            } 

                if(ch[1] >= 0 && ch[1] != ' ' && ch[1] != 'P' && ch[1] != 'p' && ch[1] != '\n'){

                arrive[y] = ch[1];
                y++;
                arrive_check = ch[1];

                if(ch[1] != ' ' | ch[1] != '\n'){

                    ch[1] = fgetc(fptr);
                    while(ch[1] == ' ' | ch[1] == '\n'){

                        ch[1] = fgetc(fptr);

                    }
                }
                    if(ch[1] >= 0 && ch[1] != ' ' && ch[1] != 'P' && ch[1] != 'p' && ch[1] != '\n'){
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("outside ch is: %c\n", ch[1]);
                
                    switch(ch[1]){

                        case '0':
                            burst[z] = 0;
                            z++;
                            break;
                        case '1':
                            burst[z] = 1;
                            z++;
                            if(ch[1] != ' ' | ch[1] != '\n'){

                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("inside ch is: %c\n", ch[1]);

                                ch[1] = fgetc(fptr);
                                printf("second inside ch is: %c\n", ch[1]);
                                if(ch[1] != ' ' | ch[1] != '\n'){
                            
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("beginning ch is: %c\n", ch[1]);
                                printf("beginning burst[z-1] = %d\n",burst[z-1]);
                                printf("z = %d\n",z);
                                printf("z-1 = %d\n",z-1);
                                    switch(ch[1]){

                                        case '0':
                                            burst[z-1] = 10;
                                            break;
                                        case '1':
                                            burst[z-1] = 11;
                                            break;
                                        case '2':
                                            burst[z-1] = 12;
                                            break;
                                        case '3':
                                            burst[z-1] = 13;
                                            break;
                                        case '4':
                                            burst[z-1] = 14;
                                            break;
                                        case '5':
                                            burst[z-1] = 15;
                                            break;
                                        case '6':
                                            burst[z-1] = 16;
                                            break;
                                        case '7':
                                            burst[z-1] = 17;
                                            break;
                                        case '8':
                                            burst[z-1] = 18;
                                            break;
                                        case '9':
                                            burst[z-1] = 19;
                                            break;

                                    }
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("end ch is: %c\n", ch[1]);
                                printf("end burst[z-1] = %d\n",burst[z-1]);


                                    ch[1] = fgetc(fptr);
                                }
                                        ch[1] = fgetc(fptr);

                            }
                            break;
                        case '2':
                            burst[z] = 2;
                            z++;
                            if(ch[1] != ' ' | ch[1] != '\n'){

                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("inside ch is: %c\n", ch[1]);

                                //ch[1] = fgetc(fptr);
                                if(ch[1] != ' ' | ch[1] != '\n'){
                            
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("beginning ch is: %c\n", ch[1]);
                                printf("beginning burst[z-1] = %d\n",burst[z-1]);
                                printf("z = %d",z);
                                printf("z-1 = %d",z-1);
                                    switch(ch[1]){

                                        case '0':
                                            burst[z-1] = 20;
                                            break;
                                        case '1':
                                            burst[z-1] = 21;
                                            break;
                                        case '2':
                                            burst[z-1] = 22;
                                            break;
                                        case '3':
                                            burst[z-1] = 23;
                                            break;
                                        case '4':
                                            burst[z-1] = 24;
                                            break;
                                        case '5':
                                            burst[z-1] = 25;
                                            break;
                                        case '6':
                                            burst[z-1] = 26;
                                            break;
                                        case '7':
                                            burst[z-1] = 27;
                                            break;
                                        case '8':
                                            burst[z-1] = 28;
                                            break;
                                        case '9':
                                            burst[z-1] = 29;
                                            break;

                                    }
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("end ch is: %c\n", ch[1]);
                                printf("end burst[z-1] = %d\n",burst[z-1]);


                                    ch[1] = fgetc(fptr);
                                }
                                        ch[1] = fgetc(fptr);

                            }
                            break;
                        case '3':
                            burst[z] = 3;
                            z++;
                            if(ch[1] != ' ' | ch[1] != '\n'){

                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("inside ch is: %c\n", ch[1]);

                                //ch[1] = fgetc(fptr);
                                if(ch[1] != ' ' | ch[1] != '\n'){
                            
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("beginning ch is: %c\n", ch[1]);
                                printf("beginning burst[z-1] = %d\n",burst[z-1]);
                                printf("z = %d",z);
                                printf("z-1 = %d",z-1);
                                    switch(ch[1]){

                                        case '0':
                                            burst[z-1] = 30;
                                            break;
                                        case '1':
                                            burst[z-1] = 31;
                                            break;
                                        case '2':
                                            burst[z-1] = 32;
                                            break;
                                        case '3':
                                            burst[z-1] = 33;
                                            break;
                                        case '4':
                                            burst[z-1] = 34;
                                            break;
                                        case '5':
                                            burst[z-1] = 35;
                                            break;
                                        case '6':
                                            burst[z-1] = 36;
                                            break;
                                        case '7':
                                            burst[z-1] = 37;
                                            break;
                                        case '8':
                                            burst[z-1] = 38;
                                            break;
                                        case '9':
                                            burst[z-1] = 39;
                                            break;

                                    }
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("end ch is: %c\n", ch[1]);
                                printf("end burst[z-1] = %d\n",burst[z-1]);


                                    ch[1] = fgetc(fptr);
                                }
                                        ch[1] = fgetc(fptr);

                            }
                            break;
                        case '4':
                            burst[z] = 4;
                            z++;
                            if(ch[1] != ' ' | ch[1] != '\n'){

                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("inside ch is: %c\n", ch[1]);

                                //ch[1] = fgetc(fptr);
                                if(ch[1] != ' ' | ch[1] != '\n'){
                            
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("beginning ch is: %c\n", ch[1]);
                                printf("beginning burst[z-1] = %d\n",burst[z-1]);
                                printf("z = %d",z);
                                printf("z-1 = %d",z-1);
                                    switch(ch[1]){

                                        case '0':
                                            burst[z-1] = 40;
                                            break;
                                        case '1':
                                            burst[z-1] = 41;
                                            break;
                                        case '2':
                                            burst[z-1] = 42;
                                            break;
                                        case '3':
                                            burst[z-1] = 43;
                                            break;
                                        case '4':
                                            burst[z-1] = 44;
                                            break;
                                        case '5':
                                            burst[z-1] = 45;
                                            break;
                                        case '6':
                                            burst[z-1] = 46;
                                            break;
                                        case '7':
                                            burst[z-1] = 47;
                                            break;
                                        case '8':
                                            burst[z-1] = 48;
                                            break;
                                        case '9':
                                            burst[z-1] = 49;
                                            break;

                                    }
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("end ch is: %c\n", ch[1]);
                                printf("end burst[z-1] = %d\n",burst[z-1]);


                                    ch[1] = fgetc(fptr);
                                }
                                        ch[1] = fgetc(fptr);

                            }
                            break;
                        case '5':
                            burst[z-1] = 5;
                            //z++;
                            if(ch[1] != ' ' | ch[1] != '\n'){

                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("inside ch is: %c\n", ch[1]);

                                ch[1] = fgetc(fptr);
                                if(ch[1] != ' ' | ch[1] != '\n'){
                            
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("beginning ch is: %c\n", ch[1]);
                                printf("beginning burst[z-1] = %d\n",burst[z-1]);
                                printf("z = %d",z);
                                printf("z-1 = %d",z-1);
                                    switch(ch[1]){

                                        case '0':
                                            burst[z-1] = 50;
                                            break;
                                        case '1':
                                            burst[z-1] = 51;
                                            break;
                                        case '2':
                                            burst[z-1] = 52;
                                            break;
                                        case '3':
                                            burst[z-1] = 53;
                                            break;
                                        case '4':
                                            burst[z-1] = 54;
                                            break;
                                        case '5':
                                            burst[z-1] = 55;
                                            break;
                                        case '6':
                                            burst[z-1] = 56;
                                            break;
                                        case '7':
                                            burst[z-1] = 57;
                                            break;
                                        case '8':
                                            burst[z-1] = 58;
                                            break;
                                        case '9':
                                            burst[z-1] = 59;
                                            break;

                                    }
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("end ch is: %c\n", ch[1]);
                                printf("end burst[z-1] = %d\n",burst[z-1]);


                                    ch[1] = fgetc(fptr);
                                }
                                        ch[1] = fgetc(fptr);

                            }

                            break;
                        case '6':
                            burst[z] = 6;
                            z++;
                            if(ch[1] != ' ' | ch[1] != '\n'){

                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("inside ch is: %c\n", ch[1]);

                                //ch[1] = fgetc(fptr);
                                if(ch[1] != ' ' | ch[1] != '\n'){
                            
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("beginning ch is: %c\n", ch[1]);
                                printf("beginning burst[z-1] = %d\n",burst[z-1]);
                                printf("z = %d",z);
                                printf("z-1 = %d",z-1);
                                    switch(ch[1]){

                                        case '0':
                                            burst[z-1] = 60;
                                            break;
                                        case '1':
                                            burst[z-1] = 61;
                                            break;
                                        case '2':
                                            burst[z-1] = 62;
                                            break;
                                        case '3':
                                            burst[z-1] = 63;
                                            break;
                                        case '4':
                                            burst[z-1] = 64;
                                            break;
                                        case '5':
                                            burst[z-1] = 65;
                                            break;
                                        case '6':
                                            burst[z-1] = 66;
                                            break;
                                        case '7':
                                            burst[z-1] = 67;
                                            break;
                                        case '8':
                                            burst[z-1] = 68;
                                            break;
                                        case '9':
                                            burst[z-1] = 69;
                                            break;

                                    }
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("end ch is: %c\n", ch[1]);
                                printf("end burst[z-1] = %d\n",burst[z-1]);


                                    ch[1] = fgetc(fptr);
                                }
                                        ch[1] = fgetc(fptr);

                            }

                            break;
                        case '7':
                            burst[z] = 7;
                            z++;
                            if(ch[1] != ' ' | ch[1] != '\n'){

                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("inside ch is: %c\n", ch[1]);

                                //ch[1] = fgetc(fptr);
                                if(ch[1] != ' ' | ch[1] != '\n'){
                            
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("beginning ch is: %c\n", ch[1]);
                                printf("beginning burst[z-1] = %d\n",burst[z-1]);
                                printf("z = %d",z);
                                printf("z-1 = %d",z-1);
                                    switch(ch[1]){

                                        case '0':
                                            burst[z-1] = 70;
                                            break;
                                        case '1':
                                            burst[z-1] = 71;
                                            break;
                                        case '2':
                                            burst[z-1] = 72;
                                            break;
                                        case '3':
                                            burst[z-1] = 73;
                                            break;
                                        case '4':
                                            burst[z-1] = 74;
                                            break;
                                        case '5':
                                            burst[z-1] = 75;
                                            break;
                                        case '6':
                                            burst[z-1] = 76;
                                            break;
                                        case '7':
                                            burst[z-1] = 77;
                                            break;
                                        case '8':
                                            burst[z-1] = 78;
                                            break;
                                        case '9':
                                            burst[z-1] = 79;
                                            break;

                                    }
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("end ch is: %c\n", ch[1]);
                                printf("end burst[z-1] = %d\n",burst[z-1]);


                                    ch[1] = fgetc(fptr);
                                }
                                        ch[1] = fgetc(fptr);

                            }

                            break;
                        case '8':
                            burst[z] = 8;
                            z++;
                            if(ch[1] != ' ' | ch[1] != '\n'){

                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("inside ch is: %c\n", ch[1]);

                                //ch[1] = fgetc(fptr);
                                if(ch[1] != ' ' | ch[1] != '\n'){
                            
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("beginning ch is: %c\n", ch[1]);
                                printf("beginning burst[z-1] = %d\n",burst[z-1]);
                                printf("z = %d",z);
                                printf("z-1 = %d",z-1);
                                    switch(ch[1]){

                                        case '0':
                                            burst[z-1] = 80;
                                            break;
                                        case '1':
                                            burst[z-1] = 81;
                                            break;
                                        case '2':
                                            burst[z-1] = 82;
                                            break;
                                        case '3':
                                            burst[z-1] = 83;
                                            break;
                                        case '4':
                                            burst[z-1] = 84;
                                            break;
                                        case '5':
                                            burst[z-1] = 85;
                                            break;
                                        case '6':
                                            burst[z-1] = 86;
                                            break;
                                        case '7':
                                            burst[z-1] = 87;
                                            break;
                                        case '8':
                                            burst[z-1] = 88;
                                            break;
                                        case '9':
                                            burst[z-1] = 89;
                                            break;

                                    }
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("end ch is: %c\n", ch[1]);
                                printf("end burst[z-1] = %d\n",burst[z-1]);


                                    ch[1] = fgetc(fptr);
                                }
                                        ch[1] = fgetc(fptr);

                            }

                            break;
                            case '9':
                            burst[z] = 9;
                            z++;
                            if(ch[1] != ' ' | ch[1] != '\n'){

                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("inside ch is: %c\n", ch[1]);

                                //ch[1] = fgetc(fptr);
                                if(ch[1] != ' ' | ch[1] != '\n'){
                            
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("beginning ch is: %c\n", ch[1]);
                                printf("beginning burst[z-1] = %d\n",burst[z-1]);
                                printf("z = %d",z);
                                printf("z-1 = %d",z-1);
                                    switch(ch[1]){

                                        case '0':
                                            burst[z-1] = 90;
                                            break;
                                        case '1':
                                            burst[z-1] = 91;
                                            break;
                                        case '2':
                                            burst[z-1] = 92;
                                            break;
                                        case '3':
                                            burst[z-1] = 93;
                                            break;
                                        case '4':
                                            burst[z-1] = 94;
                                            break;
                                        case '5':
                                            burst[z-1] = 95;
                                            break;
                                        case '6':
                                            burst[z-1] = 96;
                                            break;
                                        case '7':
                                            burst[z-1] = 97;
                                            break;
                                        case '8':
                                            burst[z-1] = 98;
                                            break;
                                        case '9':
                                            burst[z-1] = 99;
                                            break;

                                    }
                                //ch should be 1 at this point..subsequently if there's another number after, it'll hit the next loop
                                printf("end ch is: %c\n", ch[1]);
                                printf("end burst[z-1] = %d\n",burst[z-1]);


                                    ch[1] = fgetc(fptr);
                                }
                                        ch[1] = fgetc(fptr);

                            }

                            break;


                    }

                    burst[z] = ch[1];

                    z++;
                    ch[1] = fgetc(fptr);

                }
            }
        }
    }


    printf("burst[0] = %d\n",burst[0]);
    printf("burst[1] = %d\n",burst[1]);
    printf("burst[2] = %d\n",burst[2]);



    printf("PID\tarrive\tburst\tremain\tfinish\twait\n");
    printf("--------------------------------------------\n");
    for(i = 0; i < num_of_lines; i++){

        printf("P%d\t%c\t%d\t%d\t%d\t%d\n",pid[i],arrive[i],burst[i],remain,finish,wait);

    }  

    printf("average throughput      = %d\n", avgthruput);
    printf("average waiting time    = %d\n", avgwaittime);
    printf("average turnaround time = %d\n", avgturntime);


    fclose(fptr);



    return 0;
}
