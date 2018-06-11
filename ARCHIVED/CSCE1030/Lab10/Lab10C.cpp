/*Name: Axel Yates
 Email: axelyates@unt.edu
 Date: 11/16/15
 Instructor: Dr. Thompson
 Description: 	This program will read in 10 numbers from the user
		and then sort them in reverse order from biggest to
		smallest.*/
        
#include <iostream> //declaring necessary includes
using namespace std;

const int SIZE = 10; //declaring SIZE as a constant

void bubblesort(int arr[], int length);
/* Function: 	bubblesort
Parameters: 	an int array
		an int named length
Return: 	swapped version of users list
Description: 	This function swaps the users list into reverse ascending order.
*/

int main()
{
	int arr[SIZE]; //declaring SIZE as part of the array arr

	for(int i = 0; i < SIZE; i++) //for loop to ask user for integers to fill array
	{
		cout <<  "Enter an integer: ";
		cin  >> arr[i];
	}
	
	bubblesort(arr, SIZE); //passes variables into function

	for(int a : arr) //for loop to show what "a" is to user
	{
		cout << a << " ";
	}
	
	cout << endl;

	return 0;
}

void bubblesort(int arr[], int length) //function that sorts and swaps users input into descending order
{
	for(int i = length - 1; i > 0; i--)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[j] < arr[j+1]) //swap part of the function
			{
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}

	}
	return;
}

