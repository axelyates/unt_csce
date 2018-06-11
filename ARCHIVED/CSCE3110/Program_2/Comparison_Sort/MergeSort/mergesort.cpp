/*****************************************
Name:       Axel Yates
Course:     CSCE 3110
Assignment: Program 2 (Sorting Algorithms)
            Merge Sort version
******************************************/

#include <stdio.h>  //necessary includes
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <time.h>
#include <algorithm>

#define MAX 74002

 
using namespace std;

struct node{    //structure for use in handling input

    string name; //declaring variables
    int area;
    int population_count;
    int population_density;

    //function to print out the list
    void print_node(int arr[], string array[], int size){
        for (int i=0; i < size; i++){

            cout << array[i] << double (arr[i]) << setprecision(15) << endl;

        }
    }

};
//beginning of the merge sort algorithm
void merge(int arr[], int l, int m, int r)
{
    int i;
    int j;
    int k;
    int n1 = m - l + 1;
    int n2 = r - m;


    int L[n1], R[n2]; //creating temporary array
 
    for (i = 0; i < n1; i++){ //copying data to temporary arrays

        L[i] = arr[l + i];

    }
    for (j = 0; j < n2; j++){

        R[j] = arr[m + 1+ j];

    } 
    //actual merging back together
    i = 0; //index of first array
    j = 0; //index of second array
    k = l; //index of merged array
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    //cleaning up
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    //cleaning up
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}

//end of merge sort algorithm







 
int main()
{
    clock_t start; //for use when outputting runtime
    clock_t end;

    node node[MAX];

    stringstream ss;
    char test;
    char temp_array[MAX][75] = {' '};
    int y = 0;
    int z = 0;
    int counter = 0;


    while(cin){//runs while input is there to be "cinned"

            if(test == '\n'){

                z = 0;

            }

            cin >> noskipws >> test;
            temp_array[y][z] = test;
            if(test == '|'){

                node[y].name = temp_array[y];
                counter++; //this increments every time a '|' is hit

            }

            if(counter == 3){

                cin >> node[y].population_density;
                y++;
                counter = 0;
                z = 0;

            }

            z++;
    }//end while loop

    int pop_density[MAX] = {0};
    string name[MAX];

    for(int i = 0; i < MAX; i++){

        pop_density[i] = double (node[i].population_density);

    }
    for(int i = 0; i < MAX; i++){

        name[i] = node[i].name;

    }

    int arr_size = sizeof(pop_density)/sizeof(pop_density[0]);

    start = clock();
    mergeSort(pop_density, 0, arr_size - 1);
    end = clock();

    cout << "Merge Sort ran in " << (float)(end - start) / CLOCKS_PER_SEC << " seconds. " << endl;

    node->print_node(pop_density, name, MAX);

    return 0;
}
