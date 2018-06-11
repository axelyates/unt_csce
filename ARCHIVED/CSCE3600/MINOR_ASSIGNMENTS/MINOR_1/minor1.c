/*
    Name:           Axel Yates (ary0012)
    Class:          CSCE3600-001
    Date:           09/12/17
    Description:    This is a program that searches a file for occurences of a certain word given by user

    **NOTE**    There are instances of arrays that act as linked lists for certain parts of the program
                mainly in regards to how the longest character line and total lines are handled.
*/

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>


/*

    This is a function that counts up the amount
    of characters the longest line has

*/
int charcount(FILE *const fp){

    int c;
    int count = 0;
    int old_count = 0;

    for(;;){

        c = fgetc(fp);
        if(c == '\n'){

            if(old_count < count){

                old_count = count;
                count = 0;

            }
            else{

                count = 0;

            }

        }
        else if(c == EOF){

            break;

        }
        count++;
    }

    return old_count;
}
/*

    This is a function that counts up the amount
    of total lines in the file

*/
int get_lines(FILE *const fp){

    int lines;
    int c;

    for(;;){

        c = fgetc(fp);
        if(c == '\n'){

            lines++;

        }
        else if(c == EOF){

            break;

        }

    }


    return lines-1;
}





int main(int argc, char *argv[]){

    FILE *fp; //variable that references file called by user
    int i = 0; //initializing i to 0; this is used throughout the program in for loops
    int characters_longest_line = 0; //variable that holds current line for longest character
    int total_lines = 0; //variable that holds total number of lines
    char whole_line[81]; //variable that holds the whole line
    int list_of_line_numbers[sizeof(int)]; //this is a list of all the line numbers that have matching words
    int super_duper_long_line = 0; //funny way to name longest line :)

    //if statement that runs if user didn't input correct number of command-line arguments
    if(argc != 3){

        printf("argc is not equal to 4\n");
        exit(EXIT_FAILURE);

    }
    //opens the file user provided
    fp = fopen(argv[1],"r");
    //if statement that runs if program cannot open file
    if(fp == NULL){

        printf("Cannot open file\n");
        exit(1);

    }

    total_lines = get_lines(fp); //getting total lines from function get_lines
    fclose(fp); //closing file to reset
    fp = fopen(argv[1],"r"); //reopening file to use next function
    characters_longest_line = charcount(fp); //getting longest line from function charcount
    fclose(fp); //closing file to reset
    fp = fopen(argv[1],"r"); //reopening file to use rest of program

    char * test; //variable to hold strtok for whole_line
    char * s; //variable to hold space deliniating strtook
    int line_number = 0; //variable to hold line number -- initialized to 0
    int test_line = 0; //veriable to hold a test_line -- initialized to 0
    char * test_whole_line[81]; //variable to hold a test hole line
    char final_whole_line[81]; //variable for the final whole line
    char * final_real_whole_line[81]; //variable for the final real whole line (this one is used)

    //while loop that gets the line number and stores them in a list of line numbers
    while(fgets(whole_line, sizeof(whole_line), fp) != NULL){

        test = strtok(whole_line, "\n");
        s = strtok(test, " ");
        test_line++;
        while(s != NULL){

            if(strcmp(s, argv[2]) == 0){

                list_of_line_numbers[line_number] = test_line;
                line_number++;
                

            }
            s = strtok(NULL, " ");

        }

    }
    fclose(fp); //closing file to reset
    fp = fopen(argv[1],"r"); //reopening file to use for rest of program
    
    printf("Total Number of Occurences of \"%s\" in File: %d \n", argv[2], line_number);
    printf("--------------------------------------------------------------------------\n");
    char line[81]; //variable that holds line
    int new_line_counter = 1; //variable counter that counts the lines
    int q = 0; //variable that itirates through the list of line numbers
    
    /*
        what the below code does is iterate through the list of line numbers to find a match
        between the line it is currently on and the line number from earlier in the program
        that has a "hit" of being a match for what the user is looking for within the document
    */

    while(fgets(line, sizeof(line), fp)){

        if(list_of_line_numbers[q] == new_line_counter){

            printf("Line %d: %s", new_line_counter, line);
            q++;

        }
        if('\n'){

            new_line_counter++;

        }

    } 

    printf("--------------------------------------------------------------------------\n");
    printf("Total Lines in File: %d\n", total_lines);    
    printf("Characters Longest Line: %d\n", characters_longest_line);
    fclose(fp); //closing the file to reset
    fp = fopen(argv[1], "r"); //reopening the file for use with next section of code


    //this whole section of code is a type of copy of the above code, only it gets the longest line
    char lineline[81];
    int new_line_counter_counter = 1;
    while(fgets(lineline, sizeof(lineline), fp)){

        if(super_duper_long_line == new_line_counter_counter){

            printf("Longest Line: %s", lineline);

        }
        if('\n'){

            new_line_counter_counter++;

        }

    } 

    fclose(fp); //closing the file for good

    return 0;
}
