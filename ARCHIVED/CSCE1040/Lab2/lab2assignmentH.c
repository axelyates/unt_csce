#include <stdio.h>
#include <cstdlib>
#include "lab2Student.h"
using namespace std;

int main()
{
	FILE * fp;
	Student student_arr[20];

	fp = fopen("/home/pwb0013/public/1040/labs/two/student_data.txt", "r");

	char course;
	char first_name2[20] = {0};
	char last_name2[20] = {0};
	int exam1_2 = 0;
	int exam2_2 = 0;
	int exam3_2 = 0;
	float mean_2 = 0;

	int i = 0;

	fscanf(fp,"%s", &course);

	printf("%s \n", &course);
	while(fscanf(fp,"%s %s %d %d %d", first_name2, last_name2, &exam1_2, &exam2_2, &exam3_2) != EOF){

		for(int x = 0; x < 20; x++){student_arr[i].first_name[x] = first_name2[x];}
		for(int x = 0; x < 20; x++){student_arr[i].last_name[x] = last_name2[x];}
		student_arr[i].exam1 = exam1_2;
		student_arr[i].exam2 = exam2_2;
		student_arr[i].exam3 = exam3_2;

		mean_2 = ((exam1_2 + exam2_2 + exam3_2)/3.0);
		student_arr[i].mean = mean_2;


		printf("%s %s %d %d %d %.2f\n", student_arr[i].first_name, student_arr[i].last_name, student_arr[i].exam1, student_arr[i].exam2, student_arr[i].exam3, student_arr[i].mean);

		i++;
	}


	fclose(fp);
	return 0;
}



