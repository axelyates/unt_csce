/*
===============================================================================
Name            : Lab6C.cpp
Author          : Axel Yates (axelyates@my.unt.edu)
Version         : 1.0
Copyright       : 2015
Description 	: Program that computes and returns the factorial of a positive
		  integer (n), that is the product of all positive integers
		  from 1 to n.
===============================================================================
*/
#include <iostream>
using namespace std;

int get_factorial(int n);	//function header
/*
Function	: get_factorial
Parameters	: n is the parameter for the function
Return		: an int that holds the factorial of an inputted number
Description	: This function computes a factorial of an inputted number
*/



int main ()
{

	int m;			//declaring m as a variable 			
	int factorial;		//declaring factorial as a variable


	cout << "Enter number: ";
	cin  >> m;

	factorial = get_factorial(m); //returing get_factorial function and inputting m

	cout << "The factorial is: " << factorial << endl; //reading to user the factorial of inputted number

	return 0;
}

	int get_factorial(int n) 
	{

	int factorial_two = 1;	//setting factorial_2 = to 1
	int i;			//declaring i as a variable

	for (i=1; i<=n; i++)	//creating a for loop to get factorial of factorial_two
	factorial_two*=i;

	return factorial_two;
	}
