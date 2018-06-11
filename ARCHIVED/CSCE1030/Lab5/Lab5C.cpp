/*
============================================================================
Name   	 	: Lab5C.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : This program uses logic based on the pow function to
		  calculate the power of one number raised to another.
============================================================================
*/

#include <iostream>
#include <cmath>   //including this for pow function
using namespace std;

int main()
{
	int i = 0, p = 1; //intial declaration of variables
	int a = 2, b = 4;

	p = pow(2, 4);   //using pow function to calculate 2^4
	cout << a << " to the power of " << b << " is = " << p << endl;

	i = 0;
	p = 1;
	a = 3, b = 3;

	p = pow(3, 3);  //using pow function to calculate 3^3
	cout << a << " to the power of " << b << " is = " << p << endl;

	i = 0;
	p = 1;
	a = 5, b = 4;

	p = pow(5, 4); //using pow function to calculate 5^4
	cout << a << " to the power of " << b << " is = " << p << endl;


	return 0;
}
