/*
==============================================================================
Name            : Lab8C.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : This function opens a file and outputs the square root of 
		  the numbers in that file into a different file
==============================================================================
*/
#include <iostream>  //declaring the includes
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	int num;	//declaring variables
	float root;
	ifstream in_stream;
	ofstream out_stream;
	
	in_stream.open("Lab8C.in");	//opening "Lab8C.in"
	if(in_stream.fail())		//setting a "just in case" if the file fails to open
	{
		cout << "ERROR: Unable to open file: Lab8C.in" << endl;
		exit(EXIT_FAILURE);
	}

	out_stream.open("Lab8C.out");	//opening "Lab8C.out"
	if(out_stream.fail())		//setting a "just in case" if the file fails to open
	{
		cout << "ERROR: Unable to open file: Lab8C.out" << endl;
		exit(EXIT_FAILURE);
	}

	while(in_stream >> num)		//creating a while loop to calculate square root of numbers in "Lab8C.in"
	{
		root = sqrt(num);	//declaring root as the variable for the square root function

//		out_stream.width(15);		//commenting out the width
		out_stream.setf(ios::fixed);
		out_stream.setf(ios::showpoint);
//		out_stream.precision(5);	//commenting out the precision
		out_stream.setf(ios::left); 
		out_stream << setprecision(5) << setw(15) << root << endl; //declaring everything I commented out in one line that is now left justified and easier to manage
//		out_stream << root << endl; //commenting out the square root function so there are no doubles
	}

	in_stream.close();	//closing both files
	out_stream.close();

	return 0;
}
