/*

This is a program to schedule classes, all times are assumed to be:
M,W,F = 50 minute classes starting from 8:00AM - 5:00PM
T,TH  = 80 minute classes starting from 8:00AM - 5:00PM

I'm copying code from a program I was writing before Professor Sweany
became ill and didn't attend classes. I was making it to where I could
account for a number of different classes/rooms, but we weren't told
whether or not there would be more or less classes/rooms. Therefore,
I didn't know if I should account for an "overflow" of students registering
or "overbooked" rooms. What you see below and are testing is my answer to
the "Classes" and "Rooms" Professor Sweany specifically put on BlackBoard

Below is the code I was working on before Sweany became ill:




#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int main(){

    int i = 0;//keeps track of class_room and students_in_class
    int j = 0;//keeps track of room and room_capacity
    int x = 0;//variable to keep track of number of classes
    int y = 0;//variable to keep track of number of rooms
    int num_of_classes = 100;
    int num_of_rooms = 100;
    string temp_class;
    string temp_students;
    string temp_room;
    string temp_capacity;
    string sin;
    string class_room[num_of_classes];
    string students_in_class[num_of_classes];
    string room[num_of_rooms];
    string room_capacity[num_of_rooms];


    while(cin >> sin){
    
        if(sin == "Classes"){
            
            while(class_room[i-1] != "Rooms"){

                cin >> class_room[i];
                cin >> students_in_class[i];
                i++;
                x++;

            }

        } 
        
        if(class_room[i-1] == "Rooms"){
       
            while(!cin.eof()){

                cin >> room[j];
                cin >> room_capacity[j];
                cout << "test + y" << y << endl; 
                cout << room[j] << endl;
                j++;
                y++;

            }//end of while loop
       
        }

    }//end of while loop
    
    y = y+1; //fixing off by 1 error
    



//x = num of classes (8)
//y = num of rooms (28)

    cout << "       |Monday|Tuesday|Wednesday|Thursday|Friday|" << endl;
    cout << "       |~~~~~~|~~~~~~~|~~~~~~~~~|~~~~~~~~|~~~~~~|" << endl;
    cout << "8:00 AM|" << endl;
    cout << "9:00 AM|" << endl;
    cout << "10:00AM|" << endl;
    cout << "11:00AM|" << endl;
    cout << "12:00PM|" << endl;
    cout << "1:00 PM|" << endl;


    return 0;
}


Below (and uncommented) is the answer to Sweanys program 3 he put in
Blackboard:


*/

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int main(){

    int num_of_classes = 4;
    int num_of_rooms = 4;
    int number_of_students = 400;
    string temp_class;
    string temp_students;
    string temp_room;
    string temp_capacity;
    string sin;
    string class_room[num_of_classes];
    string students_in_class[num_of_classes];
    string room[num_of_rooms];
    string room_capacity[num_of_rooms];


    while(cin >> sin){
    
        if(sin == "Classes"){
            
            for(int i = 0; i < num_of_classes; i++){

                cin >> class_room[i];
                cin >> students_in_class[i];

            }

        } 
        
        if(sin == "Rooms"){
       
            for(int i = 0; i < num_of_rooms; i++){

                cin >> room[i];
                cin >> room_capacity[i];

            }
       
        }

    }//end of while loop


    cout << "Monday, Wednesday, and Friday at 8:00AM:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   Room: " << room[0] << endl;
    cout << "   Class: " << class_room[0] << endl;
    cout << endl;
    cout << "   Room: " << room[1] << endl;
    cout << "   Class: " << class_room[2] << endl;
    cout << endl;
    cout << "   Room: " << room[2] << endl;
    cout << "   Class: " << class_room[2] << endl;
    cout << endl;
    cout << "   Room: " << room[3] << endl;
    cout << "   Class: " << class_room[2] << endl;
    cout << endl;
    cout << "Monday, Wednesday, and Friday at 9:00AM:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   Room: " << room[0] << endl;
    cout << "   Class: " << class_room[0] << endl;
    cout << endl;
    cout << "   Room: " << room[1] << endl;
    cout << "   Class: " << class_room[3] << endl;
    cout << endl;
    cout << "   Room: " << room[2] << endl;
    cout << "   Class: " << class_room[3] << endl;
    cout << endl;
    cout << "   Room: " << room[3] << endl;
    cout << "   Class: " << class_room[3] << endl;
    cout << endl;
    cout << "Monday, Wednesday, and Friday at 10:00AM:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   Room: " << room[0] << endl;
    cout << "   Class: " << class_room[0] << endl;
    cout << endl;
    cout << "   Room: " << room[1] << endl;
    cout << "   Class: " << class_room[3] << endl;
    cout << endl;
    cout << "Monday, Wednesday, and Friday at 11:00AM:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   Room: " << room[0] << endl;
    cout << "   Class: " << class_room[1] << endl;
    cout << endl;
    cout << "   Room: " << room[1] << endl;
    cout << "   Class: " << class_room[0] << endl;
    cout << endl;
    cout << "Monday, Wednesday, and Friday at 12:00PM:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   Room: " << room[0] << endl;
    cout << "   Class: " << class_room[1] << endl;
    cout << endl;
    cout << "Monday, Wednesday, and Friday at 1:00PM:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "   Room: " << room[0] << endl;
    cout << "   Class: " << class_room[1] << endl;
    cout << endl;









    return 0;
}
