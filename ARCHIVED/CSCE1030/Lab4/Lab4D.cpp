#include <iostream>
using namespace std;

int main()
{
	int x;
	int count = 0;
	int N;
	double sum = 0;
	double average;
	
	
	cout << "Enter number of values to be read in <Enter>: ";
	cin  >> N;
	do
	{
	cout << "Enter a grade <Enter>: ";
	cin  >> x; 
	sum = sum + x;
	count++;
	}while (count < N);

	if(N==0)
	{
		cout << "N cannot be 0, no average will be computed.\n";
	}
	else
	{
		average = sum/N;
		cout << "The average of these " << N << " grades is: " << average << endl;
	}

	return 0;
}
