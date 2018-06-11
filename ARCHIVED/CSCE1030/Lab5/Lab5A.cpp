/*
==============================================================================
Name    	: Lab5A.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : This program uses an enum and if-else statement to calculate
		  what time of day it is.
==============================================================================
*/

#include <iostream>
using namespace std;

enum TimeOfDay {DAY, NIGHT}; //declaring enum for time of day

int main()
{
	TimeOfDay value = NIGHT;  //calling enum based on value
	if(value == NIGHT)
	{
		cout << "Good Night!" << endl;
	}
	else
	{
		cout << "Have a great day!" << endl;
	}


	return 0;
}
