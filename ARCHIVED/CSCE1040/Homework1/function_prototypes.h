/*
        Name:                   Axel Yates 
	Email:			axelyates@my.unt.edu
        Class Section:          002 
        Lab Section:            308 
        Purpose of Program:     This program is a gradebook that adds courses, students, and grades to memory.  
                                It also adds students to courses and grades to students. Also, it prints lists 
                                of all courses and students in memory depending on user selection. Finally, it 
                                calculates the average of grades entered for a selected student. 
*/ 

#include "structs.h"

void flush_stdin();	//clears stdin input

void case1(Course *courses, int &num_of_courses);	//function for adding a new course
void case2(Student *students, int &num_of_students);	//function for adding a new student
void case3(Student *students, Course *courses, char *selected_student, char *selected_course, int &num_of_courses, int &num_of_students);	//function for adding a student to a course
void case4(Course *courses, int &num_of_courses, char *selected_course, char *selected_student);	//function for adding grades to a student in a course
void case5(Course *courses, int &num_of_courses);	//function for printing a list of all courses
void case6(Student *students, int &num_of_students);	//function for printing a list of all students
void case7(Student *students, Course *courses, int &num_of_courses, int &num_of_students, char *selected_course);	//function for printing a list of all students in a course
void case8(Course *courses, Student *students, int &num_of_courses, char *selected_course, char *selected_student);	//function to compute the average for a student in a course

