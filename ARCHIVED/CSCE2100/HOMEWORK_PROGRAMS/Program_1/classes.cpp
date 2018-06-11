#include <stdio.h>
#include <iostream>

using namespace std;

class Student{

	public:
	string students_in_courses[20]; //array to iterate through students in file
	string final_students[20];      //saves students to a final list
	string students_in_certain_course[20];
	string final_students_in_certain_course[20][20];
	string final_students_in_final_course[20][20];

        };
class Course{

	public:
	string courses[20];     //array to iterate through courses in file
	string course;          //temp string to hold current course file is reading
	string final_classes[20];       //saves course to a final list

        };

