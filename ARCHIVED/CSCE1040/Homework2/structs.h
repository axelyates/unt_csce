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

struct Student{						//student struct
        char student_id[6];                             //variable that holds students unique ID number
        char name[11];                                  //variable that holds students name
        char major[31];                                 //variable that holds students major
        char grade[5];                                  //variable that holds students grae
};

struct Course{						//course struct
        char course_id[9];                              //variable that holds course id
        char course_title[31];                          //variable that holds course title
        char department[31];                            //variable that holds course department
        Student enrolled_students[10];                  //variable that holds enrolled students
        int num_of_enrolled_students;                   //variable that keeps track of number of enrolled students
        int grades[10][5];                              //variable that holds students grade
};

