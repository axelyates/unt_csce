#include <iostream>
#include <cstdlib>
#include <iomanip>
/*
        Name:                   Axel Yates
        Email:                  axelyates@my.unt.edu
        Class Section:          002
        Lab Section:            308
*/





using namespace std;

int main(int argv, char *argc[]){

	int width;
	int length;

	if(argv >= 1){

		width = atoi(argc[1]);
		length = atoi(argc[2]);
	
	}

	cout << "This program will calculate the area of a rectangle" << endl;
	cout << endl;

	cout << "What is the Width?  " << width;
	//cin  >> argv;

	cout << "What is the Length?  " << length;
	//cin  >> argc;
	cout << endl;

	cout << "Here is the rectangle's data: " << endl;
	cout << "    Width: " << width << endl;
	cout << "    Length: " << length << endl;
	cout << endl;

	cout << "AREA: " << (width * length) << endl;



	return 0;
}
