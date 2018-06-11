#include <iostream>
using namespace std;

int main()
{
	int age, ticket;
	
	cout << "Enter your age to determine ticket price: ";

	cin  >> age;

	if(age <= 8)
	{
	ticket = 6;
	}
	else
	{
	ticket = 12;
	}

	cout << "Your ticket costs $" << ticket << endl;

	return 0;

}
