/* Author: Axel Yates (axelyates@my.unt.edu)
 Date: 11/02/15
 Instructor: Dr. Thompson
 Description: This program will read the entire contents
              of a file and duplicate it to another file
              that the user has specified.*/

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void get_stream(ifstream& in_s, ofstream& out_s);
/* Function: get_stream
Parameters: An ifstream representing users declared input 
	    filename and an ofstream representing users 
	    declared output filename
Return: An ifstream representing users declared input
	filename and an ofstream representing users
	declared output filename both open
Description: This function opens both the users input
	     and output files */



int main()
{
	char c;
	ifstream in_s; //declaration of the stream of type input
	ofstream out_s; // declaration of the stream of type output

	get_stream(in_s, out_s); //calls function get_stream

	cout << "Here are the entire contents of the input file \n";

	while(in_s.get(c)) //happens while there is another character to get in file in_s
	{
		out_s.put(c);
	}

	cout << "\nI am done with writing the contents of the file \n";

	in_s.close(); //close the file
	out_s.close(); //close the file

	return 0;
}

void get_stream(ifstream& in_s, ofstream& out_s)
{
	char input_file[15]; //declaring necessary variables
	char output_file[15];
	cout << "Please input the file name\n"; //get the file name
	cin  >> input_file;
	cout << "Please input the output file name:\n"; //get the output file name
	cin  >> output_file;

	in_s.open(input_file); //connect to the input file and test
	if(in_s.fail())
	{
		cout << "Input file opening failed. \n";
		exit(EXIT_FAILURE); //exit if cannot open file
	}
	out_s.open(output_file); //connect to the output file and test
	if(out_s.fail())
	{
		cout << "Output file opening failed. \n";
		exit(EXIT_FAILURE); //exit if cannot open file
	}
}
