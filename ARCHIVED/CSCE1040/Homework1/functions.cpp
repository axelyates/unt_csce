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


#include <string.h>						//necessary includes
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "function_prototypes.h"
using namespace std;

void case1(Course courses[], int &num_of_courses){		//runs if user selects 1 at prompt

	
	printf("ENTER COURSE ID>");                             //prompts user to enter course ID
	gets(courses[num_of_courses].course_id);                //course ID variable that gets and stores a string from user

	printf("ENTER COURSE NAME>");                           //prompts user to enter course name
	gets(courses[num_of_courses].course_title);             //course name variable that gets and stores a string from use

	printf("ENTER DEPARTMENT NAME>");                       //prompts user to enter name of department
	gets(courses[num_of_courses].department);               //department name variable that gets and stores a string from user

	courses[num_of_courses].num_of_enrolled_students = 0;   //declaring that the number of enrolled students is 0

	printf("%s has been added\n",courses[num_of_courses].course_id);        //notifying user that their input has been added successfully
	num_of_courses++;                                       //increments the number of courses
        return;
}

void case2(Student students[], int &num_of_students){		//runs if user selects 2 at prompt

        bool error = false;					//setting boolean value to false

	students[num_of_students].student_id[0] = 73;		//sets every student id to "ID00_\0" before adding another student
	students[num_of_students].student_id[1] = 68;
	students[num_of_students].student_id[2] = 48;
	students[num_of_students].student_id[3] = 48;		//skipping 4 because that's what increments when a new student is added
	students[num_of_students].student_id[5] = '\0';
        
	printf("ENTER STUDENT NAME> ");                         //prompts user to enter student name
	gets(students[num_of_students].name);                    //student name variable that gets and stores a string from the user

        for(int i = 0; i < num_of_students; i++){               //for loop that ultimately adds a new student to program
                if(strcmp(students[num_of_students].name, students[i].name) == 0){        //if statement that checks to see if users input is already enrolled as a student
                        printf("***ERROR***: %s already enrolled as %s \n",students[num_of_students].name,students[i].student_id); //notifies user their input is already in the system
			error = true;                           //changes error variable to true
                	if(error == true){                                      //if statement that only runs if boolean variable "error" is true
                        	error = false;                                  //changes error variable back to false
                        	return;
                	}
                }

        }
	if((error == false) && (num_of_students < 9)){		//runs if number of students is less than 9 and error is false

		students[num_of_students].student_id[4] = (num_of_students) + (49);	//adds 1 to student_id based on how many sudents are in the system
	}
	else if((error == false) && (num_of_students >= 9)){	//runs if number of students is more than or equal to 9 and error is false
		students[num_of_students].student_id[3] = 49;	//sets ID to ID010 for the tenth plus student
		students[num_of_students].student_id[4] = (num_of_students - 10) + (49);	//sets ID to ID011..ID012, increasing with the number of students that are added
	}

        printf("ENTER STUDENT MAJOR> ");                //prompts user to enter students major
        gets(students[num_of_students].major);           //student major variable that gets and stores a string from the user

        printf("Added: %s %s \n",students[num_of_students].name,students[num_of_students].student_id);        //notifies user that their input was successfully entered
        num_of_students++;                              //increments the number of students

        return;
}

void case3(Student students[], Course courses[], char selected_student[], char selected_course[], int &num_of_courses, int &num_of_students){

	printf("ENTER STUDENT NAME> ");                         //prompt asking user to input students name
        gets(selected_student);                                 //selected student variable that gets and stores a string from user
        
	Student *cs;                                            //temporary variable of Student type that holds users input for correct student
        for(int j = 0; j < num_of_students; j++){               //for loop that iterates through the current students
                if(strcmp(students[j].name, selected_student) == 0){             //if statement that compares users input to an iterative number of students
                        cs = &students[j];                       //stores the correct iterative student into a temporary variable
                }
        }

        printf("ENTER COURSE ID> ");                            //prompt asking user to input students course ID
        gets(selected_course);                                  //selected course variable that gets and stores a string from user

        Course *cc;                                             //temporary variable of Course type that holds users input for a correct course
        for(int i = 0; i < num_of_courses; i++){                //for loop that iterates through the current courses

                if(strcmp(courses[i].course_id, selected_course) == 0){ //if statement that compares users input to an iterative number of courses
                        cc = &courses[i];                       //stores the correct iterative course into a temporary variable
                }
        }

        int student_found;                                      //variable that holds value of if the student was found or not
        student_found = 0;                                      //setting value to 0 indicating student not currently found
	for(int k = 0; k < cc->num_of_enrolled_students; k++){  //for loop that iterates through the number of enrolled students
                if(strcmp(cs->name, cc->enrolled_students[k].name) == 0 ){                      //if statement that compares enrolled students to student entered by user
                        student_found = 1;                      //changes student found to 1, or true, if user selected a student who is already enrolled in a course
                        printf("\n***ERROR***: %s already enrolled in %s \n",selected_student,selected_course);   //notifying user that student they entered is already enrolled in selected course
                }
        }
        if(student_found == 0){                                 //if statement that runs if student is not found to be in selected course
                cc->enrolled_students[cc->num_of_enrolled_students] = *cs;                      //adding temporary correct student variable value to permanent variable
                cout << "Added to " << selected_course << " -- " << selected_student << endl;   //notifying user that selected student was added to selected course
                cc->num_of_enrolled_students++;                 //incrementing number of enrolled students by one
        }
        
	return;
}

void case4(Course courses[], int &num_of_courses, char selected_course[], char selected_student[]){

        printf("ENTER COURSE ID> ");                            //prompts user to enter course id
        gets(selected_course);                                  //selected course variable that gets and stores a string from user
        for(int i = 0; i < num_of_courses; i++){                //for loop that iterates through current number of courses
                if(strcmp(selected_course, courses[i].course_id) == 0){         //compares users input with every iterative course in loop
                        printf("ENTER STUDENT NAME>");                          //prompts user to enter student name
                        gets(selected_student);                                 //selected student variable that gets and stores a string from user
                        for(int j = 0; j < courses[i].num_of_enrolled_students; j++){                           //for loop that iterates through current number of enrolled students
                                if(strcmp(selected_student, courses[i].enrolled_students[j].name) == 0){        //compares enrolled students with users selection
                                        int temp_grade = 0;
                                        do{                                                                     //do-while loop that runs until user enters the enter key
                                                printf("ENTER GRADE> ");                                        //prompts user to enter a grade
                                                cin >> temp_grade;
                                                if(temp_grade != -1){						//runs if user did not type in value (-1)
                                                        courses[i].grades[j][0] = temp_grade;			//stores temp_grade variable to students grade variable
                                                }
                                                j++;								//increments which grade system is accessing
                                        }while(temp_grade != -1);						//case to end the do-while loop
                                        printf("ADDED GRADES: %s %s",selected_student, selected_course);	//notifies user their input was entered
                                        for(int k = 0; k < j; k++){
                                                printf(" %d ",courses[i].grades[k][0]);
                                                        }
                                                }
                                        }
                                }
                        }
	printf("\n");
	return;
}

void case5(Course courses[], int &num_of_courses){								//runs if user enters 5 in menu

        printf("COURSES");                                    							//heading for course output
        printf("\n-------\n");
        for(int i = 0; i < num_of_courses; i++){        							//for loop that iterates through number of courses
                printf("%-25s %-25s %-25s \n",courses[i].course_id,courses[i].course_title,courses[i].department);	//prints out courses
        }
        return;
}

void case6(Student students[], int &num_of_students){		//runs if user selects 6 at the menu

        printf("STUDENTS");                                   //heading for student output
        printf("\n--------\n");
        int temp = 0;                                           //temporary variable that eventually references a specific student
        for(int i = 0; i < num_of_students; i++){		//for loop incrememnting through the number of students
		printf("%-13s %-13s %-13s \n",students[i].student_id,students[i].name,students[i].major);	//prints out students
	}

        return;
}

void case7(Student students[], Course courses[], int &num_of_courses, int &num_of_students, char selected_course[]){	//runs if user selects 7 at the menu

        printf("ENTER COURSE ID> ");                            //prompts user to enter course id
        gets(selected_course);                                  //selected course variable that gets and stores a string from user
        Course *cc;                                             //temporary variable of Course type that holds users input for a correct course
        for(int i = 0; i < num_of_courses; i++){                //for loop that iterates through the current courses

                if(strcmp(courses[i].course_id, selected_course) == 0){ //if statement that compares users input to an iterative number of courses
                        cc = &courses[i];                       //stores the correct iterative course into a temporary variable
                }
        }


	for(int i = 0; i < num_of_courses; i++){                //for loop that iterates through the number of courses
		if( strcmp(courses[i].course_id, selected_course) == 0){                //compares users selection with all current courses
			for(int j = 0; j < cc->num_of_enrolled_students; j++){		//for loop that iterates though number of enrolled students
					printf("%s %s \n",students[i].student_id, students[i].name);	//prints out students ID and name
			}
		}
	}

	return;
}


void case8(Course *courses, Student *students, int &num_of_courses, char *selected_course, char *selected_student){	//runs if user selects 8 from the menu

        printf("ENTER COURSE ID> ");                            //prompts user to enter course id
        gets(selected_course);                                  //selected course variable that gets and stores a string from user

        printf("ENTER STUDENT ID> ");                           //prompts user to enter student id
        gets(selected_student);                                 //selected student variable that gets and stores a string from user

        printf("AVERAGE: ");                                    //outputs average
        for(int i = 0; i < num_of_courses; i++){                //for loop that iterates through the current courses
                int temp_grade = 0;                             //variable that holds a temporary grade
                int counter = 0;                                //variable that acts as a counter for loop
                for(int j = 0; j < courses[i].num_of_enrolled_students; j++){                           //for loop that iterates through enrolled students
                        if(strcmp(selected_student, students[j].student_id) == 0){       		//if statement that compares users entered student with enrolled student
                                for(int k = 0; k < courses[i].grades[j][0]; k++){			//for loop taht iterates though grades
                                        printf(" %d ",courses[i].grades[j][0]);				//outputs grades to the screen
                                        temp_grade = (temp_grade + courses[i].grades[j][0]);
                                        counter++;
                                        j++;
                                        }
                	float average = (temp_grade / counter);						//creates the average for users grades
                	printf("= %.1f \n",average);
                        }
                }
        }
        return;
}


void flush_stdin(void){                                                         //This function clears the current stdin whenever called
	int ch;
	while(((ch = getchar()) !='\n') && (ch != EOF));
}

