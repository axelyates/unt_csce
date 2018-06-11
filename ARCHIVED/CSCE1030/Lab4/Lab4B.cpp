#include <iostream>
using namespace std;

int main()
{
	int user_input;

	cout << "Please enter an integer: ";
	cin  >> user_input;
	cout << "You entered: " << user_input << endl;
	if(user_input >= 0)
	{
	user_input = (user_input - 5) / 16;
	}
	else
	{
	user_input = (user_input + 5);
	user_input = user_input * user_input;
	}

	cout << "Your new number is: " << user_input << endl;



	return 0;
}

