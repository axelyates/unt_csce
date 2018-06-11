#include <iostream>
#include <string>
using namespace std;

int main()

{
	string usersName;
	string usersNumber;

	cout << "+--------------------------------------------+" << endl;
	cout << "|      Computer Science and Engineering      |" << endl;
	cout << "|      CSCE 1030 -   Computer Science I      |" << endl;
	cout << "|  Axel Yates   ary0012   axelyates@unt.edu  |" << endl;
	cout << "+--------------------------------------------+" << endl;

	cout << "Hello, my name's Axel. What's your name?:" << endl;
	cin  >> usersName;
	cout << "Hello, " << usersName << "! Welcome to CSCE 1030! Please input a positive 4-Digit number:" << endl;
	cin  >> usersNumber;
	cout << "You input: :" << usersNumber << endl;
	cout << "The Thousands column is: " << usersNumber[0] << endl;
	cout << "The Hundreds  column is: " << usersNumber[1] << endl;
	cout << "The Tens      column is: " << usersNumber[2] << endl;
	cout << "The Ones      column is: " << usersNumber[3] << endl;
	



	return 0;
}
