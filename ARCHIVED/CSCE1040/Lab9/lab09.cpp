
/*********************************************************************
**      PROGRAM:        Lab 09                                      **
**      AUTHOR:         Axel Yates                                  **
**      CLASS:          CSCE-1040                                   **
**      SECTION:        002                                         **
*********************************************************************/

#include <iostream>	//necessary includes
#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <cstring>

using namespace std;

int accounts[9];	//global array of accounts

void deposit(int num, int value);		//function to add numbers into specified account from account array
void withdraw(int num, int value);		//function to subratct numbers from specified account from account array 
void balance(int num);				//function to print balance of specified account from account array
void transfer(int num1, int num2, int value);	//function to transfer numbers from one account to another from specified accounts from account array


int main(){

	string selection;	//declaring variables
	int account_number1;
	int account_number2;
	int value;


	while(selection != "exit"){	//while function runs until user enters "exit"
	printf("bank>");
	cin >> selection;		//reads in users selection
		if(selection == "deposit"){	//runs if user inputs "deposit" 
			cin >> account_number1;	//reads in account number
			cin >> value;		//reads in value
			deposit(account_number1, value);	//passes account number and value to deposit function
		}
		else if(selection == "withdraw"){	//runs if user inputs "withdraw"
			cin >> account_number1;		//reads in account number
			cin >> value;			//reads in value
			withdraw(account_number1, value);	//passes account number and value to withdraw function
		}
		else if(selection == "balance"){	//runs uf user inputs "balance"
			cin >> account_number1;		//reads in account number
			balance(account_number1);	//passes account number to balance function
		}
		else if(selection == "transfer"){	//runs if user inputs "transfer"
			cin >> account_number1;		//reads in first account number
			cin >> account_number2;		//reads in second account number
			cin >> value;			//reads in value
			transfer(account_number1, account_number2, value);//passes account numbera and value to transfer function
		}
		else if(selection == "exit"){		//runs if user enters "exit"

			break;				//breaks out of loop and program

		}
		else{
			cout << "Error! Command not recognized." << endl;	//runs if user fatfingers an input
		}
	};

	return 0;
}


void deposit(int num, int value){	//function to add value to specified account

	accounts[num] += value;		//adds value to specified account within the account array

	return;
}

void withdraw(int num, int value){	//function to subtract value from specified account

	if(accounts[num] - value >= 0){	//runs if enough "value" within the specified account
		accounts[num] -= value;	//subtracts value from specified account within the account array
	}
	else{	//runs if specified account within the account array minus specified value is less than zero.
		cout << "Error! Not enough funds!" << endl;	//notifies user of error
	}
	return;
}

void balance(int num){	//function to display the number within the specified account within the account array

	cout << accounts[num] << endl;	//displays the number within the specified account within the account array

	return;
}

void transfer(int num1, int num2, int value){	//function to transfer a value from one account within the account array to another

	if(accounts[num1] - value >= 0){	//runs if account wont be zero after the deduction
		accounts[num1] -= value;	//subracts value from first account
		accounts[num2] += value;	//adds value from first account to second account
	}
	else{
		cout << "Error! Funds exceeded on transfer request!" << endl;	//runs if account would be zero after the deduction
	}

	return;
}
