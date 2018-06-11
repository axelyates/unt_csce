#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int i = 0;
    int temp = 0;
    int size = 0;
    int counter = 0; // this is for convenience
    //int size2 = malloc(sizeof(&argv[1][0]));
    //printf("size2 is: %d",size2);
    float user_input[atoi(&argv[1][0])];
    float avg;

    if(argc == 1){ //user entered no cmd line arguments

        printf("usage: ./a.out array_size\n");
        exit(EXIT_FAILURE);

    }
    else{

        for(i = 0; i < atoi(&argv[1][0]); i++){

            printf("Enter a floating point number: ");
            scanf("%f",&user_input[i]);            
            counter++;

        }
        for(i = 0; i < counter; i++){

            avg = avg + user_input[i];

        }
        avg = avg / counter;

    }
    printf("avg is: %f\n", avg);



    return 0;
}
