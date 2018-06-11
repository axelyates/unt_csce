/*
==============================================================================
Name            : Lab8B.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : This file takes numbers from a file called input.txt and 
		  takes whatever numbers are in there and outputs the square
		  and the sum, also calculates the average.
==============================================================================
*/
#include <iostream>	//declaring the necessary includes
#include <cmath>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	int x, count = 0;	//declaring all variables needed for function and setting the necessary ones to 0
	float sum = 0, avg;
	char input_file[15];

	ifstream in_s;		//declaring the input and output file names
	ofstream fout;

	cout << "Please input the file name\n";
	cin  >> input_file;	//getting name of input file from user

	in_s.open(input_file);	//using input file from user for program and opening it
	if(in_s.fail())		//setting a "just in case" if the file fails to open
	{
		cout << "Input file opening failed.\n";
		exit(EXIT_FAILURE);
	}
	
	fout.open("output.txt");//opening "output.txt" from computers memory
	if(fout.fail())		//setting a "just in case" if the file fails to open
	{
		cout << "Output file opening failed.\n";
		exit(EXIT_FAILURE);
	}
	
		fout << "\t x \t\t x^2 \t\t Current Sum \n";
		fout << "\t === \t\t === \t\t ===========\n";
	while(in_s >> x)	//creating necessary while loop to calculate sum
	{
		sum = sum + x;
		fout << "\t " << x << "\t\t " << pow(x,2) << "\t\t " << sum << "\n";
		count++;
	}
	
	avg = sum/count;	//calculating the average
	fout << "\n \t The average of these " << count << " numbers is: " << avg << endl;

	in_s.close();		//closing both files
	fout.close();

	return 0;
}
