#include <iostream>
using namespace std;

int main()
{
	double decimal_number;
	int number_of_decimals;

	cout << "Enter a number with decimal places: ";
	cin  >> decimal_number;
	cout << "You entered: " << decimal_number << endl;
	cout << "Enter how many decimals to display :";
	cin  >> number_of_decimals;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(number_of_decimals);
	cout << decimal_number << endl; 

	


	return 0;
}
