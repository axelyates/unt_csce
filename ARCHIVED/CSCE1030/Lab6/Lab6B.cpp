/*
==============================================================================
Name            : Lab6B.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : This program uses type casting to change Fahrenheit to 
		  celcius.
==============================================================================
*/
#include <iostream>
using namespace std;

int main()
{
	int t_in_fah, t_in_cel; //declaring t_in_fah as temperature in fahrenheit and t_in_cel as temperature in celcius.
	cout << "Enter a temperature in Fahrenheit:\n"; //getting the temperature in fahrenheit from the user.
	cin  >> t_in_fah;

	t_in_cel = static_cast<float>(5)/9*(t_in_fah - 32); //using static cast to change 5 to a float so that it's divisible by 9.
	cout << "The temperature in Celcius is: " << t_in_cel << endl;  //outputting the temperature in celcius


	return 0;
}
