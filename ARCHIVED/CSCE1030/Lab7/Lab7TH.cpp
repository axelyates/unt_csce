/*
==============================================================================
Name            : Lab7TH.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : 
==============================================================================
*/
#include <iostream>
#include <cmath>
using namespace std;

void get_a_b_c(double&, double&, double&);
/* 	Function: 	get_a_b_c
	Parameters: 	3 double variables
	Return: 	3 double variables that store the values of a, b, and c
	Description: 	This function gets a, b, and c
*/

double bb_4ac();
/* 	Function: 	bb_4ac
	Parameters: 	Nothing
	Return: 	A double representing the value of b * b - 4 * a * c
	Description: 	This function computes b*b - 4 * a * c
*/


int main()
	{
	cout << "returning function: " << bb_4ac() << endl; //returing the bb_4ac function
	return 0;
	}


double bb_4ac() //
	{
		double a, b, c; //coefficients of a quadratic equation
		get_a_b_c(a, b, c); //calling a, b, and c from function get_a_b_c
		
		return b*b - 4*a*c; //returning the value of b*b-4*a*c
	}

void get_a_b_c(double& a, double& b, double& c) 		//function get_a_b_c
	{
		cout << "Enter a value for a: " << endl;	//asking user for a and storing in variable a
		cin  >> a;
		cout << "Enter a value for b: " << endl;	//asking user for b and storing in variable b
		cin  >> b;
		cout << "Enter a value for c: " << endl;	//asking user for c and storing in variable c
		cin  >> c;
		return;
	}
