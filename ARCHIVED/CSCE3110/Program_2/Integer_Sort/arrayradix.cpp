/***********************
Name: Axel Yates
Course: CSCE3110
Assignment: Program 2-2
***********************/

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int getMax(int A[], int n)
{
    int i;
    int max = A[0];
    for (i = 1; i < n; i++){
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
 
void radixSort(int A[], int n)
{
    int i,digitPlace = 1;
    int result[n];

    int largestNum = getMax(A, n);
 
    while(largestNum/digitPlace >0){
 
        int count[10] = {0};

        for (i = 0; i < n; i++)
            count[ (A[i]/digitPlace)%10 ]++;
 
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];
 
        for (i = n - 1; i >= 0; i--)
        {
            result[count[ (A[i]/digitPlace)%10 ] - 1] = A[i];
            count[ (A[i]/digitPlace)%10 ]--;
        }
 
        for (i = 0; i < n; i++)
            A[i] = result[i];
 
            digitPlace *= 10;
    }
}

void printArray(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    printf("%d ", A[i]);
    cout << endl;
}

int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("integers.txt");
    int value;
    int arr[1000];
    int z = 0;
    while(fin >> value){

        arr[z] = value;
        z++;

    }  
    fin.close();

    int N = sizeof(arr)/sizeof(arr[0]);

    radixSort(arr, N);

    printArray(arr, N);

    return 0;
}
