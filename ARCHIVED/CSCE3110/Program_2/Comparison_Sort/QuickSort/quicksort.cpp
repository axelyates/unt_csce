/*****************************************
Name:       Axel Yates
Course:     CSCE 3110
Assignment: Program 2 (Sorting Algorithms)
            Quick Sort version
******************************************/

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <time.h>

using namespace std;

#define THRESHOLD 0
#define MAX 74000

struct node{

    string name;
    double area;
    int population_count;
    double population_density;

    void print_node(double arr[], string array[], int size){
        for (int i=0; i < size; i++){

            cout << array[i] << arr[i] << setprecision(15) << endl;

        }
    }

};
int is_sorted(double a[], int n, int m){

    int i;

    for (i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            return 0;
        }
    }

    return 1;

}
void insertion(double a[], int n){

    for (int i = 1; i < n; i++)
    {
        int j = 0; 
        double save = a[i];
       

        for (j = i; j >= 1 && a[j - 1] > save; j--)
        {
            a[j] = a[j - 1];
        }

        a[j] = save;
    }

}
void swap(double *a, double *b){

    int c = *a;
    *a = *b;
    *b = c;

}
int partition(double a[], int first, int last){

    int pivot, mid = (first + last) / 2;

    /* Largest of two */
    pivot = a[first] > a[mid] ? first : mid;

    /* Smallest of remaining */
    if (a[pivot] > a[last])
    {
        pivot = last;
    }

    swap(&a[pivot], &a[first]);
    pivot = first;

    while (first < last)
    {
        if (a[first] <= a[last])
        {
            swap(&a[pivot++], &a[first]);
        }

        ++first;
    }

    swap(&a[pivot], &a[last]);

    return pivot;

}
void quicksort_r(double a[], int first, int last){

    if (last - first > THRESHOLD)
    {
        int pivot;

        if (is_sorted(a, first, last))
        {
            return;
        }

        pivot = partition(a, first, last);
        quicksort_r(a, first, pivot - 1);
        quicksort_r(a, pivot + 1, last);
    }

}
void quicksort(double a[], int n){

    quicksort_r(a, 0, n - 1);
    insertion(a, n);

}


int main(){

    clock_t start;
    clock_t end;

    node node[MAX];

    stringstream ss;
    char test;
    char temp_array[MAX][75] = {' '};
    int y = 0;
    int z = 0;
    int counter = 0;


    while(cin){

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

    double haha[MAX] = {0};
    string lol[MAX];

    for(int i = 0; i < MAX; i++){

        haha[i] = node[i].population_density;

    }
    for(int i = 0; i < MAX; i++){

        lol[i] = node[i].name;

    }

    start = clock();
    quicksort(haha, MAX);
    end = clock();    


    cout << "Quick Sort ran in " << (float)(end - start) / CLOCKS_PER_SEC << " seconds. " << endl;


    node->print_node(haha, lol, MAX);


    return 0;
}
