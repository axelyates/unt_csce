/*
==============================================================================
Name            : Lab7C.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : Asks user for 2 variables and stores them as i and j, then
		  adds 10 to i and 20 to j.
==============================================================================
*/
#include <iostream>
#include <cmath>
using namespace std;

void get_input(int& i, int& j);
/* 	Function: 	get_input
	Parameters: 	an int representing i and
			an int representing j
	Return: 	a cout statement asking user for i and j
	Description: 	This function stores i and j as variables
*/
void process(int& i, int& j);
/* 	Function: 	process
	Parameters: 	an int representing i
			an int representing j
	Return: 	an int that has 10 added to i and 20 added to j
	Description: 	This function adds 10 to the value of i and 
			20 to the value of j
*/

int main()
{
	int i, j; //declaring i and j as variables in main

	get_input(i, j); //calling the function get_int to store values of i and j
	cout << "About to call function process: i = " << i << " j = " << j << endl;

	//call function process to add 10 to i and 20 to j
	process(i, j);

	cout << "Just returned from function process: i = " << i << " j = " << j << endl;

	return 0;
}

void get_input (int& i, int& j) //function get_input that asks user for i and j values
{
	cout << "Enter two values for i and j separated by a single space, then press <Enter>: ";
	cin >> i >> j;
	cout << endl;
	return; // a void function, returns nothing
}

void process (int& i, int& j) //function process that adds 10 to i and 20 to j
{
	i+=10; //adding 10 to i
	j+=20; //adding 20 to j


	return; // a void function, returns nothing
}
