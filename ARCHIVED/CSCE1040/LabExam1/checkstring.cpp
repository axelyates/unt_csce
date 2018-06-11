#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <iomanip>

using namespace std;

struct String{

	char temp_input_checker[40];

};


int main(){

	int count = 0;
	String letter[40];
	char temp_checker[20];

	ifstream input_text;
	input_text.open("string.txt");

	if(input_text.fail()){
		printf("input file failed to open");
	}

	if(input_text.is_open()){

		do{
		int i = 0;
			input_text >> letter[i].temp_input_checker;

			if(letter[i].temp_input_checker[0] == 'A'){

				printf("VALID %-30s\n",letter[i].temp_input_checker);

			}
			else if(letter[i].temp_input_checker[0] == 'B'){

				printf("INVALID %-30s\n",letter[i].temp_input_checker);

			}
			else if(letter[i].temp_input_checker[0] == 'A' && letter[i].temp_input_checker[5] == 'B'){

				printf("INVALID %-30s\n",letter[i].temp_input_checker);

			}
			else if(letter[i].temp_input_checker[0] == 'B'){

				printf("INVALID %-30s\n",letter[i].temp_input_checker);

			}
			else if(letter[i].temp_input_checker[2] == 'B' && letter[i].temp_input_checker[3] == 'B'){

				printf("INVALID %-30s\n",letter[i].temp_input_checker);

			}
			else if(letter[i].temp_input_checker[10] == 'B'){

				printf("INVALID %-30s\n",letter[i].temp_input_checker);

			}
			else if(letter[i].temp_input_checker[2] == 'B' && letter[i].temp_input_checker[3] == 'B'){

				printf("INVALID %-30s\n",letter[i].temp_input_checker);

			}

		i++;
		}while(! input_text.eof());
	}
	input_text.close();

	return 0;
}
