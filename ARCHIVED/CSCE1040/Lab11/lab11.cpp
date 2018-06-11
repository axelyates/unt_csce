
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
#include "lab11.h"

using namespace std;

int main(){

	Bank Bank;
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
			Bank.deposit(account_number1, value);	//passes account number and value to deposit function
		}
		else if(selection == "withdraw"){	//runs if user inputs "withdraw"
			cin >> account_number1;		//reads in account number
			cin >> value;			//reads in value
			Bank.withdraw(account_number1, value);	//passes account number and value to withdraw function
		}
		else if(selection == "balance"){	//runs uf user inputs "balance"
			cin >> account_number1;		//reads in account number
			Bank.balance(account_number1);	//passes account number to balance function
		}
		else if(selection == "transfer"){	//runs if user inputs "transfer"
			cin >> account_number1;		//reads in first account number
			cin >> account_number2;		//reads in second account number
			cin >> value;			//reads in value
			Bank.transfer(account_number1, account_number2, value);//passes account numbera and value to transfer function
		}
		else if(selection == "quit"){		//runs if user enters "exit"

			break;				//breaks out of loop and program

		}
		else{
			cout << "Error! Command not recognized." << endl;	//runs if user fatfingers an input
		}
	};

	return 0;
}

