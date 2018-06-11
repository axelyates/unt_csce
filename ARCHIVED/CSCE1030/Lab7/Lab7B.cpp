/*
==============================================================================
Name            : Lab7B.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : Calculates Root of users inputted number and returns value
		  to a certain number of decimal points. Uses overloaded
		  functions on purpose
==============================================================================
*/
#include <iostream>
#include <cmath>
using namespace std;

void display(double value, int precision);
/* 	Function: 	display
	Parameters:	Users value and the precision
	Return:		The function returns users value to their specified decimal places
	Description: 	This function sets users input to a certain number of decimal places
			depending on what the user specified
*/
void display(double value, double root, int precision);
/* 	Function: 	display
	Parameters: 	Two doubles and an int
	Return:		Square root of users value to users specified decimal places
	Description: 	This function returns the square root of users input and sets to users
			specified decimal places
*/


int main()
{
	double value;	//double storing users value
	double root;	//double storing root
	int precision;	//int using precision to set decimal to users desired places
	
	cout << "Enter a positive number: " << endl;	//asking user for a number and storing as value
	cin  >> value;
	cout << "How many decimal places would you like?: " << endl; //asking user for decimals and storing as precision
	cin  >> precision;
	root = sqrt(value);


	display(value, precision);	//calling function display(double, int)
	display(value, root, precision);//calling function display(double, double, int)



	return 0;
}

void display(double value, int precision)	//function for 
{
	

	cout.setf(ios::fixed);		//sets decimals equal to what user inputted in main
	cout.setf(ios::showpoint);
	cout.precision(precision);
	cout << "The value is: " << value << endl;
	
	return;
}


void display(double value, double root, int precision) //function for display(double, double, int)
{
	

	cout.setf(ios::fixed);		//sets decimals equal to what user inputted in main
	cout.setf(ios::showpoint);
	cout.precision(precision);
	cout << "The value is: " << value << " and the square root of it is: " << root << endl;


	return;
}
