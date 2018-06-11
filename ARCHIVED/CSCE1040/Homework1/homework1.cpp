/*
	Name: 			Axel Yates
	Email:			axelyates@my.unt.edu
	Class Section:		002
	Lab Section:		308
	Purpose of Program:	This program is a gradebook that adds courses, students, and grades to memory. 
				It also adds students to courses and grades to students. Also, it prints lists
				of all courses and students in memory depending on user selection. Finally, it
				calculates the average of grades entered for a selected student.
*/
#include <stdio.h>
#include <iostream>					//necessary includes
#include <iomanip>
#include "function_prototypes.h"

using namespace std;

int main()
{
	int selection = 0;				//variable that holds users selection from menu
	int num_of_courses = 0;				//variable that keeps track of the number of courses
	int num_of_students = 0;			//variable that keeps track of the number of students
	char selected_student[11];			//variable that keeps track of selected student
	char selected_course[31];			//variable that keeps track of selected course
	Course courses[10];				//variable that references the course struct
	Student students[25];				//variable that references the student struct
	
	printf("1. Add a new course\n");					//user selects if they want to add a new course to program
	printf("2. Add a new student\n");					//user selects if they want to add a new student to program
	printf("3. Add a student to a course\n");				//user selects if they want to add a student to a course
	printf("4. Add grades for a student in a course\n");		//user selects if they want to add grades to student in a course
	printf("5. Print a list of all courses\n");			//user selects if they want to print a list of all added courses
	printf("6. Print a list of all students\n");			//user selects if they want to see a list of all added students
	printf("7. Print a list of all students in a course\n");		//user selects if they want to see all users enrolled in a course
	printf("8. Compute the average for a student in a course\n");	//user selects if they want to compute the average for students in a course
	printf("9. Exit\n");						//user selects if they want to end the program
	while(selection != 9){							//while loop that continually asks user for input until they choose 9 to exit
	printf("\ncmd>");								//prompt that displays asking user for input
	cin  >> selection;							//variable to take in user input

	flush_stdin();								//function call that clears the users input from stack

	switch(selection)							//beginning of switch statement
	{
		case 1:								//runs if variable "selecction" is equal to 1
			case1(courses, num_of_courses);
		
		break;

		case 2:								//runs if variable "selecction" is equal to 2
			case2(students, num_of_students);
			
		break;

		case 3:								//runs if variable "selecction" is equal to 3
			case3(students, courses, selected_student, selected_course, num_of_courses, num_of_students);

		break;
	
		case 4:								//runs if variable "selecction" is equal to 4
			case4(courses, num_of_courses, selected_course, selected_student);

		break;

		case 5:								//runs if variable "selecction" is equal to 5
			case5(courses, num_of_courses);

		break;

		case 6:								//runs if variable "selecction" is equal to 6
			case6(students, num_of_students);

		break;

		case 7:								//runs if variable "selecction" is equal to 7
			case7(students, courses, num_of_courses, num_of_students, selected_course);

		break;

		case 8:								//runs if variable "selecction" is equal to 8
			case8(courses, students, num_of_courses, selected_course, selected_student);

		break;

		case 9:								//runs if variable "selecction" is equal to 9
			printf("Good-bye -- Thank you for flying with CSCE1040\n");		
		
		break;
	}

	} 									//ending of while loop
	return 0;
}
