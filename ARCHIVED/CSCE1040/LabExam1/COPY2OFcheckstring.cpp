#include <cstdlib>
#include <stdio.h>

using namespace std;

struct String{
	char letter[40];
};


int main(){


	FILE * fp;
	String temp_string_checker[40];

	fp = fopen ("~/pwb0013/public/1040/labs/exam1/string.txt", "r");

	char course;
	char temp_letter[40];
	int i = 0;

	while(fscanf(fp,"%s",temp_letter) != EOF){

		for(int x = 0; x < 40; x++){

			temp_string_checker[i].letter[x] = temp_letter[x];

		}

		printf("temp_string_checker = \n",temp_string_checker[i].letter);


		i++;
	}










































	fclose(fp);
	return 0;
}
