#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

/*Function that swaps values at two pointers*/
void swap(char *x, char *y){

    char temp;
    temp = *x;
    *x = *y;
    *y = temp;

}

/*Function to pring permutations of string*/
void permute(char *a, int l, int r){

    int i;
    if(l == r){

        printf("%s\n", a);

    }
    else{

        for(i = l; i <= r; i++){

            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i)); //backtracking

        }

    }

}


int main(){

    char* str = new char[1000]();
    cout << "Enter the string to permutate: ";
    scanf ("%s", str);

    int n = strlen(str);
    permute(str, 0, n-1);


    return 0;
}
