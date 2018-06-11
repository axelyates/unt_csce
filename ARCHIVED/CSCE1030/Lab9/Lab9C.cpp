/* Author: Axel Yates (axelyates@my.unt.edu)
   Date: 11/02/15
   Instructor: Dr. Thompson
   Description: This program will read in one
   character from the keyboard and will convert
   it to lowercase if it is uppercase, convert
   it to uppercase if it is lowercase, tell user
   if they entered a digit, whitespace, or an
   unknown character of somesort. */



//This program reads one character from the keyboard and will
//-convert it to uppercase, if it is lowercase
//-convert it to lowercase, if it is uppercase
//-display a message, if it is not a letter of the alphabet
#include <iostream> //adding necessary includes
#include <cctype>
using namespace std;

int main()
{
	char c; //declaring c as a char

	cout << "Enter a character \n"; //asking user to input their character
	cin.get(c); //setting character as char c

	if(isalpha(c))
	{//check to see if its a letter of alphabet
		if(isupper(c))//check to see if it is uppercase
		{
			cout << "Your character " << c << " is in uppercase. ";
			c = tolower(c);
			cout << "Its lowercase is " << c << "." << endl;
		}	
		else //happens if user entered a lowercase letter
		{
			cout << "Your character " << c << " is in lowercase. ";
			c = toupper(c);
			cout << "Its uppercase is " << c << "." << endl;
		}
	}
	else if(isdigit(c))
	{//check to see if its a digit/number
		cout << "Your character ";
		cout.put(c);
		cout << " is a digit.\n";
	}
	else if(isspace(c))
	{//check to see if its a whitespace character
		cout << "Your character ";
		cout.put(c);
		cout <<  " is a whitespace character.\n";
	}
	else
	{//only happens if user input a character that is not a digit, alphabetic or whitespace character
		cout << "Unknown character ";
		cout.put(c);
		cout << endl;
	}
}
