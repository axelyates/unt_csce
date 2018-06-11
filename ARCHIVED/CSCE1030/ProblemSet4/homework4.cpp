/*
 =============================================================================
 Name        : Homework4.cpp
 Author      : Axel Yates (axelyates@my.unt.edu)
 Version     : 1.0
 Copyright   : 2015
 Description : This function implements a simple cryptosystem that incorporates
	       topics related to file I/O. In particular, this function will 
	       read an input file, encrypt or decrypt the file based on the 
	       requested operation, and write the results to an output file.
 =============================================================================
 */

#include <iostream> //adding all necessary includes
#include <cstdlib> 
#include <fstream>
#include <cctype>
using namespace std;


void display_credentials();
/* 
Function        : display_credentials
Parameters      : void
Return          : outputs the credentials of the program to the screen
Description     : This function displays the program header
*/

void encrypt(ifstream& fin, ofstream& fout, int&);
/* 
Function        : encrypt
Parameters      : ifstream, ofstream, int
Return          : nothing on screen but an encrypted file for user in memory
Description     : This function encrypts a file for user depending on the key they use
*/

void decrypt(ifstream& fin, ofstream& fout, int&);
/* 
Function        : decrypt
Parameters      : ifstream, ofstream, int
Return          : nothing on screen but a decrypted file for user in memory
Description     : This function decrypts a file for user depending on the key they use
*/

int main()
{
	ifstream fin;			//declaring all variables and streams
        ofstream fout;
	int key;			//holds users key
        char response;			//holds response for what user wants to do 'E' or 'D'
       	char plain[33];
	char cipher[33];
	char encrypted[33];
	char decrypted[33];

	display_credentials();		//displays the program header

	while(response != 'D' && response != 'd' && response != 'e' && response != 'E') //asks user until they answer with the recommended input (either upper or lowercase)
	{
	cout << "Would you like to ENCRYPT or DECRYPT a file (E or D)?: ";
	cin  >> response;
	}


	if(response == 'E' || response == 'e') //if user inputs E or e, this happens
                {
			cout << "Enter the name of your input file you want to encrypt: ";
			cin  >> plain;	//reads in users filename for plaintext information to encrypt

			fin.open(plain); //opens users file
			if(fin.fail())	//"just in case" the users plaintext file doesn't open the program will exit
                        {
                                cout << "fin file opening failed." << endl;
                                exit(EXIT_FAILURE);
                        }
			
			cout << "Enter the name of the output file to write the ciphertext: ";
			cin  >> cipher; //reads in users filname to store coded information from plaintext file

			fout.open(cipher); //creates or opens the file from line 78 user specified
			if(fout.fail()) //"just in case" the users cipher file doesn't open the program will end
			{
				cout << "fout file opening failed." << endl;
				exit(EXIT_FAILURE);
			}

			cout << "Enter the numerical key (i.e., an integer) used to encrypt: ";
			cin  >> key; //reads in users key for encryption

			encrypt(fin, fout, key); //calls function to encrypt file

                }
        else if(response == 'D' || response == 'd') //Happens if user inputs 'd' or 'D'
                {
			cout << "Enter the name of your input file you want to decrypt: ";
			cin  >> encrypted; //reads in filename that is encrypted that user would like to decrypt
		
			fin.open(encrypted); //opens encrypted file
			if(fin.fail())	//"just in case" users encrypted file fails to open the program will quit
                        {
                                cout << "fin file opening failed." << endl;
                                exit(EXIT_FAILURE);
                        }

			cout << "Enter the name of the output file to write the plaintext: ";
			cin  >> decrypted; //reads in filename user would like to create or open to store decrypted text
			
			fout.open(decrypted); //opens file from line 106
			if(fout.fail()) //"just in case" users encrypted file fails to open the program will quit
                        {
                                cout << "fout file opening failed." << endl;
                                exit(EXIT_FAILURE);
                        }

			cout << "Enter the numerical key (i.e., an integer) used to decrypt: ";
			cin  >> key; //reads in users key for encryption

			decrypt(fin, fout, key); //calls function to decrypt file

	fin.close();	//closes both files opened from either encrypt or decrypt cases
        fout.close();

	return 0;
}
}
void display_credentials()                      //function to display the credentials
{
    	cout << "+----------------------------------------------+" << endl;
    	cout << "|       Computer Science and Engineering       |" << endl;
    	cout << "|        CSCE 1030 - Computer Science I        |" << endl;
    	cout << "|   Axel Yates  ary0012   axelyates@my.unt.edu |" << endl;
    	cout << "+----------------------------------------------+" << endl;

    	return;
}

void encrypt(ifstream& fin, ofstream& fout, int& key) //function that encrypts file and stores it in specified location
{
			char next;	//declaring necessary variables
			char c;
							
			fin.get(next);
			while(! fin.eof())	//does while not end of file
			{
				if (! isspace(next))	//does as long "next" is not a space
				{
					if (isalpha(next))	//does if "next" is a letter
					{
						if(next >= 'A'&& next <= 'Z') //capital letter
						{
							c = ((next - 65 + key) % 26) + 65;
							fout.put(c);
						}
						else if(islower(next)) //lowercase letter
						{
							c = ((next - 97 + key) % 26) + 97;
							fout.put(c);
						}
					}
					if (isdigit(next))	//does if "next" is a digit/number
					{
						c = ((next - 48 + key) % 10) + 48;
						fout.put(c);
					}
				}
			fin.get(next);			
			}
return;
}

void decrypt(ifstream& fin, ofstream& fout, int& key)
{
			char next;	//declaring necessary variables
			char c;						

			fin.get(next);
			while(! fin.eof())	//does while not at the end of the file
			{
				if (! isspace(next))	//does while "next" is not a space
				{
					if (isalpha(next))	//does if "next" is a letter
					{
						if(next >= 'A' && next <= 'Z') //capital letter
						{
							c = ((next - 65 + 26 - key) % 26) + 65;
							fout.put(c);
						}
						else if(next >= 'a' && next <= 'z') //lowercase letter
						{
							c = ((next - 97 + 26 - key) % 26) + 97;
							fout.put(c);
						}
					}
					if (isdigit(next))	//does if "next" is a digit
					{
							c = ((next - 48 - key + 10 * 10) % 10) + 48;
							fout.put(c);
					}
				}
			fin.get(next);			
			}
	return;
}
