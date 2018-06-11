/*Name: Axel Yates
 Email: axelyates@unt.edu
 Date: 11/29/15
 Instructor: Dr. Thompson
 Description: This program creates a struct containing variables necessary
	      to calculate users interest based on input.*/
#include <iostream>
#include <cmath>
using namespace std;

struct Loan{	//creating Loan struct with necessary variables in it.
	int ID; 
	float amount;
	float rate;
	int term;
	};
float payment(Loan loan1);
/* 	Function: payment
	Parameters: a type named Loan representing a struct declared earlier in function
	Return:     a float representing the users monthly payment
	Description: This function computes the users monthly payment based on input.
*/

int main()
{
	Loan loan1;	//delcaring necessary variables
	float monthly_payment;

	cout << "Enter the ID of this loan: ";	//asking user for input to be used in payment function
	cin  >> loan1.ID;

	cout << "Enter the amount of this loan: ";
	cin  >> loan1.amount;

	cout << "Enter the annual interest rate of this loan in % (e.g., 5.4): ";
	cin  >> loan1.rate;

	cout << "Enter the term (number of months, length of loan): ";
	cin  >> loan1.term;

	monthly_payment = payment(loan1);  //passing variables to function

	cout << "The monthly payment for loan " << loan1.ID << " is: " << monthly_payment << endl; //displaying users loan ID and monthly payment

	return 0;

}

float payment(Loan loan1)
{
	loan1.rate = (loan1.rate / 1200);	//to convert % yearly rate to monthly fraction
	return loan1.amount*loan1.rate*(pow((loan1.rate+1), loan1.term)/(pow((loan1.rate+1), loan1.term) - 1)); //calculating users monthly payment
}
