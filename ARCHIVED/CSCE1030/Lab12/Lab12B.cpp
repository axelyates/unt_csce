/*Name: Axel Yates
 Email: axelyates@unt.edu
 Date: 11/29/15
 Instructor: Dr. Thompson
 Description: This program will create an int pointer and add 7 to users input*/
#include <iostream>
using namespace std;

int main()
{
	int *p1;	//declaring necessary variables

	p1 = new int;

	cout << "Enter an integer: ";	//Asking user for input and adding 7 to input
	cin  >> *p1;
	*p1 = *p1 + 7;
	cout << "Your input + 7 = " << *p1 << endl;

	delete p1;	//deleting no longer used variable


	return 0;
}
