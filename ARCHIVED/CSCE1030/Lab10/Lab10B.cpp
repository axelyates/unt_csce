/*Name: Axel Yates
 Email: axelyates@unt.edu
 Date: 11/16/15
 Instructor: Dr. Thompson
 Description: This program will read in 5 grades from the user and then
	      store them in an array, then output the grades to the screen.*/

#include <iostream> //declaring necessary includes
using namespace std;

void get_grade();
/* Function: 	get_grade
Parameters: 	VOID
Return: 	Returns users 5 grades to the screen
Description: 	This function asks user for 5 grades then  displays users 
		5 grades on the screen.
*/

int main()
{


	get_grade(); //function to get the users grades then display them to the screen.
	


	return 0;
}

void get_grade()
{
	int grades[5]; //declaring necessary variables
	int i, grade;


	cout << "Enter 5 grades between 0 and 100" << endl;;
	for(i = 0; i < 5; i++) //for loop to get grades from user
	{
	cout << "Enter grade#"<<i+1<<": ";
	cin >> (grades[i]);
	}
	
	for(i = 0; i < 5; i++) //for loop to display grades to screen.
	{
		cout << "grades["<<i<<"] = " << grades[i] << endl;
	}

	return;
}
