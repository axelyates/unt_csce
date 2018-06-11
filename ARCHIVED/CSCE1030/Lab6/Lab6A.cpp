/*
==============================================================================
Name            : Lab6A.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : A program to print out numbers -2 to 8.
==============================================================================
*/

#include <iostream>
using namespace std;

int main()
{
	int i; //declaring i as an integer

	for(i = -2; i < 9; i++) //creating a loop to constantly display what "i" is until it reaches (but doesn't get to) 9.
	{

		cout << i << ".";

	}

	cout << endl;

	return 0;
}
