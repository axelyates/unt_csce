#include <iostream>
#include <stdio.h>

using namespace std;

/*
	Name: Axel Yates
	Date: 02/24/2016
	Section: 002
	Lab: 5
*/
int liar_liar(int);					//function prototype

int main(){

	int n = 1;					//starts n off as equal to the number 1
	printf("123456789012345678901234567890");	//prints hardcoded numbers
	



	do{
	liar_liar(n);					//calling of the recursive liar_liar function
	int temp_n = liar_liar(n);			//sets a temporary variable for value returned by liar_liar function
	printf("\nLiar-Liar(%2d) = %12d ",n,temp_n);	//prints out number used for liar liar function and the result of that number after function has run
	n++;						//increments n by 1 so the loop can end
	}while(n <= 23);				//makes sure the recursive function doesn't run forever

	printf("\n");					//ends program with a new line.
	return 0;
}

int liar_liar(int n){					//recursive function that calculates liar liar numbers
	if(n == 1 || n == 2){				//returns a -1 if n is equal to 1 or 2
	return -1;
	}
	else{						//runs if n is not equal to 1 or 2
	return (2*(liar_liar(n-1)+liar_liar(n-2)));	//returns liar_liar number
	}
}

