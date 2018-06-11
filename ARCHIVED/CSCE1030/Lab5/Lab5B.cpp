/*
============================================================================
Name    	: Lab5B.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : This program calculates the season based on users input.
============================================================================
*/


#include <iostream>
using namespace std;

int main()
{
	int users_input;        //declaring variable for users input
	cout << "Enter what month of the year it is (January = 1, February = 2, March = 3....): ";
	cin  >> users_input;

	switch(users_input)    //switching on users input to display the season of year
	{
		case 12:
		case 1:
		case 2:
		{
		cout << "It's Winter!" << endl;
		break;
		}

		case 3:
		case 4:
		case 5:
		{
		cout << "It's Spring!" << endl;
		break;
		}

		case 6:
		case 7:
		case 8:
		{
		cout << "It's Summer!" << endl;
		break;
		}

		case 9:
		case 10:
		case 11:
		{
		cout << "It's Fall!" << endl;
		break;
		}
		default:    //including default in case user inputs incorrect number
		{
		cout << "That's not correct!" << endl;
		}

	}

	return 0;
}
