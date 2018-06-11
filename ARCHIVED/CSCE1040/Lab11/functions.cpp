
/*
        Name:                   Axel Yates
        Email:                  axelyates@my.unt.edu
        Class Section:          002
        Lab Section:            308
        Purpose of Program:
*/

#include <cstring>      //necessary includes
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "lab11.h"

using namespace std;

void Bank::deposit(int num, int value){       //function to add value to specified account

        accounts[num] += value;         //adds value to specified account within the account array

        return;
}

void Bank::withdraw(int num, int value){      //function to subtract value from specified account

        if(accounts[num] - value >= 0){ //runs if enough "value" within the specified account
                accounts[num] -= value; //subtracts value from specified account within the account array
        }
        else{   //runs if specified account within the account array minus specified value is less than zero.
                cout << "Error! Not enough funds!" << endl;     //notifies user of error
        }
        return;
}

void Bank::balance(int num){  //function to display the number within the specified account within the account array

        cout << accounts[num] << endl;  //displays the number within the specified account within the account array

        return;
}

void Bank::transfer(int num1, int num2, int value){   //function to transfer a value from one account within the account array to another

        if(accounts[num1] - value >= 0){        //runs if account wont be zero after the deduction
                accounts[num1] -= value;        //subracts value from first account
                accounts[num2] += value;        //adds value from first account to second account
        }
        else{
                cout << "Error! Funds exceeded on transfer request!" << endl;   //runs if account would be zero after the deduction
        }

        return;
}

Bank::Bank(){

	for(int i = 0; i <= 10; i++){
		accounts[i] = 0;
	}

}

