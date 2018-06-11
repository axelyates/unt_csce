/*
==============================================================================
Name            : Lab8A.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : This file creates 99 random numbers in a file called "random.txt"
==============================================================================
*/
#include <iostream>	//declaring necessary includes
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

int main()
{
	ofstream outfile;//creating the ofstream called "outfile"
	
	srand(time(0));	//declaring the random function
	
	outfile.open("random.txt");	//opening "random.txt"
		if (outfile.fail())	//setting a "just in case" if the file fails to open
			{
				cout << "file opening fail\n";
				exit(EXIT_FAILURE);
			}
for (int i = 0; i < 100; i++)		//creating necessary for loop to calculate the random numbers and stop them at 99
	{
	outfile << rand() % 100 << endl;
	}
	
	outfile.close(); //closing the file

	return 0;
}
