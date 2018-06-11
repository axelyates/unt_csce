/*Name: Axel Yates
 Email: axelyates@unt.edu
 Date: 11/29/15
 Instructor: Dr. Thompson
 Description: This program will assign values to pointers i, c, and f which will
	      in turn apply those values to variables num, ch, and val.*/

#include <iostream>
using namespace std;

int main()
{
	int num, *i;	//declaring necessary variables
	char ch, *c;
	float val, *f;

	i = &num;	//setting variables
	c = &ch;
	f = &val;
	
	*i = 1;		//changing values of variables
	*c = 'A';
	*f = 1.23;
	
	cout << "num is " << num << endl;	//displaying value of variables
	cout << "ch is " << ch << endl;
	cout << "val is " << val << endl;

	return 0;
}
