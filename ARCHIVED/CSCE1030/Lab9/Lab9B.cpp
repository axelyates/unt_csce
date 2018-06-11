/* Author: Axel Yates (axelyates@my.unt.edu)
 Date: 11/02/15
 Instructor: Dr. Thompson
 Description: This program reads the entire contents
 of a file and will display that to the screen so long
 as the program does not reach the end of the file. When
 program reaches the end of the file it will exit. */


//this program reads the entire contents of an input file and will
//display it with the same format.
#include<iostream> //declaring necessary includes
#include<fstream>
#include<cstdlib>
using namespace std;

void get_stream(ifstream& in_s);
/* Function: get_stream
Parameters: An ifstream representing the users filename
Return: An open file declared by user
Description: This function asks for user to input a filename
             and opens that file. Displays a message if any
             problems occur opening the file */

int main()
{
	char c; //declaring c as a char
	ifstream in_s; //declaration of the stream of type input
	
	get_stream(in_s); //calling function get_stream

	cout << "Here are the entire contents of the input file \n";

	while(!in_s.eof()) //does this while not at the end of file stored in in_s
	{
		in_s.get(c);
		cout << c;
	}

	cout << "\nI am done with writing the contents of the file \n";

	in_s.close(); //close the file
	return 0;
}

void get_stream(ifstream& in_s)
{
	char input_file[15];
	cout << "Please input the file name\n"; //get the file name
	cin  >> input_file;

	in_s.open(input_file); //connect to the input file and test
	if(in_s.fail())
	{
		cout << "Input file opening failed. \n";
		exit(EXIT_FAILURE); //exit if cannot open file
	}
}
