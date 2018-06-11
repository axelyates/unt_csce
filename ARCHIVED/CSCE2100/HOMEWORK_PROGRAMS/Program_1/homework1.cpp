/********************************
Name:		Axel Yates	|
Class:		CSCE 2100	|
Section:	001		|
Date:		10/02/2016	|
Copyright:	2016		|
********************************/

#include <stdio.h>
#include <iomanip>
#include <string>
#include <iostream>
#include <cstdlib>
#include "classes.cpp"

using namespace std;

int main(){

	Student student;
	Course course;

	string final_course_holder[20][20];
	string course_holder[20][20];
	string class_time[20];
	string student_a;
	string student_b;
	string final_course;
	int counter = 0;
	int time_slot[10];
	int c = 0;
	int d = 0;
	int f = 0;
	int m = 0;		//value holder for course
	int q = 0;
	int r = -1;
	int s = 0;
	int t = 0;
	int u = 0;
	int v = 0;
	int x = 0;		//value holder for final_classes array
	int y = 0;		//value holder for final_students array
	bool check = true;
	
	while(cin >> course.course){
		if(course.course.length() < 7){
			for(int i = 0; i < 1; i++){

				r++;
				course.courses[i] = course.course;
				course.final_classes[x] = course.courses[i];
				x++;
				student.students_in_certain_course[m] = course.courses[i];

				for(int n = 0; n < 1; n++){
					for(int o = 0; o < 1; o++){

						t = 0;
						student.final_students_in_certain_course[r][t] = student.students_in_certain_course[m];

					}
				}
				m++;
			}
		}
		else{
			for(int j = 0; j < 1; j++){

				student.students_in_courses[j] = course.course;
				student.final_students[y] =  course.course;
				y++;

				for(int n = 0; n < 1; n++){
					for(int o = 0; o < 1; o++){

						t++;
						student.final_students_in_certain_course[r][t] = student.students_in_courses[j];
						
					}
				}
			}
		}
	}

	while(check == true){
		for(int a = 0; a < 11; a++){
			for(int b = 0; b < 11; b++){
				student_a = student.final_students_in_certain_course[0][a];
				student_b = student.final_students_in_certain_course[f+1][b];

				if(student_a == student_b && student_a.length() > 7){

					class_time[c] = student.final_students_in_certain_course[0][0];
					c++;
					time_slot[0] = 1;
					check = false;

				}
				if(student_a.length() == 0 && student_b.length() == 0){

					class_time[c] = student.final_students_in_certain_course[0][0] + student.final_students_in_certain_course[f+1][0];
					check = false;

				}
			}
		}
		
		f++;
		if(f == 7){

			check = false;

		}
	}
	check = true;
	f = 1;
	while(check == true){
		for(int a = 0; a < 11; a++){
			for(int b = 0; b < 11; b++){
				student_a = student.final_students_in_certain_course[1][a];
				student_b = student.final_students_in_certain_course[f+1][b];

				if(student_a == student_b && student_a.length() > 7){

					class_time[c] = student.final_students_in_certain_course[1][0];
					c++;
					time_slot[1] = 2;
					check = false;

				}
				if(student_a.length() == 0 && student_b.length() == 0){

					class_time[c] = student.final_students_in_certain_course[1][0] + student.final_students_in_certain_course[f+1][0];
					check = false;

				}


			}
		}
		
		f++;
		if(f == 7){

			check = false;

		}
	}
	check = true;
	f = 2;
	while(check == true){
		for(int a = 0; a < 11; a++){
			for(int b = 0; b < 11; b++){
				student_a = student.final_students_in_certain_course[2][a];
				student_b = student.final_students_in_certain_course[f+1][b];

				if(student_a == student_b && student_a.length() > 7){

					class_time[c] = student.final_students_in_certain_course[2][0];
					c++;
					time_slot[2] = 3;
					check = false;

				}
				if(student_a.length() == 0 && student_b.length() == 0){

					class_time[c] = student.final_students_in_certain_course[2][0];// + student.final_students_in_certain_course[f+1][0];
					time_slot[2] = 3;
					check = false;
				
				}

			}



		}
		
		f++;
		if(f == 7){

			check = false;

		}
	}
	check = true;
	f = 3;
	while(check == true){
		for(int a = 0; a < 11; a++){
			for(int b = 0; b < 11; b++){
				student_a = student.final_students_in_certain_course[3][a];
				student_b = student.final_students_in_certain_course[f+1][b];

				if(student_a == student_b && student_a.length() > 7){

					class_time[c] = student.final_students_in_certain_course[3][0];
					c++;
					time_slot[3] = 4;
					check = false;

				}
				if(student_a.length() == 0 && student_b.length() == 0 && counter == 0){

					counter = 1;
					class_time[c] = class_time[c] + student.final_students_in_certain_course[3][0] + student.final_students_in_certain_course[f+1][0];
					time_slot[3] = 4;
					check = false;
					break;

				}
			}

		}

			f++;
			if(f == 7){

				check = false;

			}
	}//end while loop


	cout << endl;
	c = 0;
	cout << " _______________________________________________" << endl;
	cout << "|Time Slot | Classes Scheduled per Time Slot    |" << endl;
	cout << "|    " << time_slot[c] << "     |" << "        " << class_time[c] << setw(25) << "     " << endl;
	c++;
	cout << "|    " << time_slot[c] << "     |" << "        " << class_time[c] << setw(25) << "     " << endl;
	c++;
	cout << "|    " << time_slot[c] << "     |" << "        " << class_time[c] << setw(25) << "     " << endl;
	c++;
	cout << "|    " << time_slot[c] << "     |" << "        " << class_time[c] << setw(25) << "     " << endl;
	c++;
	cout << "|    " << time_slot[c] << "     |" << "        " << class_time[c] << setw(25) << "     " << endl;
	c++;
	cout << "|_______________________________________________|" << endl;
	cout << endl;


	return 0;
}
