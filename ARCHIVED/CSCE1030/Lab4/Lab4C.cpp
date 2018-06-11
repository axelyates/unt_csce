#include <iostream>
using namespace std;

int main ()
{
	int x;
	int count = 0;
	double sum = 0;
	double average;

	cout << "Enter twenty grades seperated by a single space, then press <Enter>: ";

	while (count < 20 )
	{
		cin >> x;
		sum = sum + x;
		count ++;
	}
	cout << endl;

	average = sum/20;
	cout << "The average is: " << average << endl;


	return 0;
}
