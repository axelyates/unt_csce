/*
 =============================================================================
 Name        : Homework3.cpp
 Author      : Axel Yates (axelyates@my.unt.edu)
 Version     : 1.0
 Copyright   : 2015
 Description : This function outputs credentials of the program along with a
	       menu to prompt the user to input certain values to get certain
	       results, of which are, sum, mean, min, and max values of any
	       given numbers. It also displays a nice message when user inputs
	       the number 5 and exits the program.
 =============================================================================
 */

#include <iostream>
#include <fstream>
using namespace std;

void display_credentials();
/* 
Function        : display_credentials
Parameters      : void
Return          : outputs the credentials of the program to the screen
Description     : This function displays the program header
*/


void display_menu();
/* 
Function        : display_menu
Parameters      : void
Return          : outputs the users menu to the screen
Description     : This function displays the menu on the screen for the user.
*/


double sum_mean(int);
/* 
Function        : sum_mean
Parameters      : an int containing the selection variable
Return          : a statement saying what the users sum is, or what the users mean is, depending on users input
Description     : This function either adds users numbers together and outputs the result, or adds users togehter
		  and outputs the mean.
*/


double min_max(int);
/* 
Function        : min_max
Parameters      : an int containing the selection variable
Return          : a statement saying what the users mininmum number or maximum numbers are depending on users input
Description     : This function either calculates users minimum number or maximum number and outputs the result
		  depending on the users input.
*/


int selection; //Declaring the variable "selection"




int main()
{
	do {
        display_credentials();			//displaying the credentials function
        display_menu();				//displaying the menu function

        cout << "Enter your selection: ";
        cin  >> selection;

        if (selection == 1) 			//calls sum function if user inputs the number 1
	{
            sum_mean(selection);
        }
        else if (selection == 2) 		//calls mean function if user inputs the number 2
	{
            sum_mean(selection);
        }
        else if (selection == 3) 		//calls the min function if user inputs the number 3
	{
            min_max(selection);
        }
        else if (selection == 4) 		//calls the max function if user inputs the number 4
	{
            min_max(selection);
        }
        else if (selection == 5)		//ends the program if the user inputs the number 5
            cout << "Thanks! Have a great day!" << endl;
        else if (selection > 5 || selection < 1)//inputs a nice statement if user inputs a number out of bounds
            cout << "That's not a valid number, try again." << endl;

        }while(selection != 5);			//tells program to quit if user inputs the number 5
    return 0;

}

void display_credentials()			//function to display the credentials
{
    cout << "+----------------------------------------------+" << endl;
    cout << "|       Computer Science and Engineering       |" << endl;
    cout << "|        CSCE 1030 - Computer Science I        |" << endl;
    cout << "|   Axel Yates  ary0012   axelyates@my.unt.edu |" << endl;
    cout << "+----------------------------------------------+" << endl;

    return;
}

void display_menu()				//function to display users menu
{
    cout << "***************** M E N U *****************" << endl;
    cout << "| 1. Sum  of numbers                      |" << endl;
    cout << "| 2. Mean of numbers                      |" << endl;
    cout << "| 3. Min  of numbers                      |" << endl;
    cout << "| 4. Max  of numbers                      |" << endl;
    cout << "| 5. Exit                                 |" << endl;
    cout << "*******************************************" << endl;


    return;
}

double sum_mean(int selection)			//function for the sum and mean

{
    if (selection == 1)				//calls the sum function
    {
        int quantity, counter = 0, num = 1;	//declaring all the int variables of the function
        double num1 = 0, sum = 0;		//declaring all the double variables of the function

        cout << "Enter the positive quantity of numbers to read in(SUM): ";
        cin >> quantity;
        while (counter < quantity)		//loops user through function until the number read in as "quantity" is greater than counter (which increments every cycle)
        {
            counter++;
            cout << "Enter Number " << num++ << ": ";
            cin >> num1;
            sum = sum + num1;
        }
	cout << "The sum of your numbers is: " << sum << endl;
        return sum;
    }

    else if (selection == 2)			//calls the mean function
    {
            double num1 = 0, sum = 0, mean = 0;	//declaring all the double variables of the function
            int counter = 0, quantity, num = 1;	//declaring all the int variables of the function

            cout << "Enter the positive quantity of numbers to read in(MEAN): ";
            cin >> quantity;
            while (counter < quantity)		//loops user through function until the number read in as "quantity" is greater than counter (which increments every cycle)
            {
                counter++;
                cout << "Enter Number " << num++ << ": ";
                cin >> num1;
                sum = num1 + sum;
                mean = (sum)/quantity;
            }
	cout << "The mean of your numbers is: " << mean << endl;
        return mean;
    }
    return 0;
}

double min_max(int selection)			//function for the min and max
{
    if (selection == 3)				//calls the min function
    {
	int quantity, num = 1, counter = 0;	//delcaring all the int variables of the function
	double num1 = 0, minnum = 0;		//declaring all the double variables of the function

        cout << "Enter the positive quantity of numbers to read in (MIN): ";
	cin  >> quantity;
	for(counter = 0; counter < quantity; counter++) //loops user through function until the number read in as "quantity" is surpassed.
	{
	cout << "Enter number " << num++ << ": ";
	cin  >> num1;


		if(counter == 0)
		{
		minnum = num1;
		}
		else if(minnum > num1)
		{
		minnum = num1;
		}
	}
	cout << "The min of your numbers is: " << minnum << endl;
	return minnum;
    }
    else if (selection == 4)			//calls the max function
    {
        double num1 = 0, max = 0;		//declaring all the double variables of the function
        int counter = 0, quantity, num = 1;	//declaring all the int variables of the function

        cout << "Enter the positive quantity of numbers to read in(MAX): ";
        cin >> quantity;
        for(counter = 0; counter < quantity; counter++) //loops user through function until the number read in as "quantity" is surpassed.
	{
	cout << "Enter number " << num++ << ": ";
	cin  >> num1;

		if(counter == 0)
		{		
		max = num1;
		}
		else if(max < num1)
		{
		max = num1;
		}
	}
	cout << "The max of your numbers is: " << max << endl;
	return max;
     }
    return 0;
}
