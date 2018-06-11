/*Name: Axel Yates
 Email: axelyates@unt.edu
 Date: 11/29/15
 Instructor: Dr. Thompson
 Description: This program will create a dynamic array based on users input
	      of the size they want and take in that many numbers, then display
	      them in reverse order.*/
#include <iostream>
using namespace std;

int main()
{
	int size;	//declaring necessary variables
	int *numlist;
	numlist = new int[size];

	cout << "Enter size of desired list: ";	//asking user for size of list
	cin  >> size;

	for(int i = 0; i < size; i++)	//for loop asking user for value based on size of list
	{
		cout << "Enter value #" << i+1 << ": ";
		cin  >> *(numlist + i);
	}

	for(int i = size; i > 0; i--)	//for loop displaying users list in reverse order
	{
		cout << "Value #" << i << ": ";
		cout << numlist[i-1] << endl;
	}

	delete numlist;	//deleting no longer used variable

	return 0;
}
