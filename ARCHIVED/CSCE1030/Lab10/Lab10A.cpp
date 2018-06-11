/*Name: Axel Yates
 Email: axelyates@unt.edu
 Date: 11/16/15
 Instructor: Dr. Thompson
 Description: This program will read in a users input of 8 values and
	      display them in reverse order.*/

#include <iostream> //declaring necessary includes
using namespace std;

int main()
{
	int numlist[8], i; //declaring necessary variables
	
	for(i = 0; i < 8; i++) //for loop to get users input
	{
		cout << "Enter the value #" << i+1 <<": ";
		cin  >> numlist[i];		
	}

	for(i = 7; i >= 0; i--) //for loop to display information
	{
		cout << "Value #" << i+1 <<": " <<  numlist[i] << endl;
	}

	return 0;
}
