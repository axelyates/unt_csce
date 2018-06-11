/*

This is a program to schedule classes, all times are assumed to be:
M,W,F = 50 minute classes starting from 8:00AM - 5:00PM
T,TH  = 80 minute classes starting from 8:00AM - 5:00PM

*/

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int main(){

    int num_of_class = 0;
    int num_of_classes = 0;
    int num_of_rooms = 0;
    string temp_class;
    string temp_students;
    string temp_room;
    string temp_capacity;
    string cen;
    string sin;
    string class_room[num_of_classes];
    string students_in_class[num_of_classes];
    string room[num_of_rooms];
    string room_capacity[num_of_rooms];


    while(cin >> cen){
        if(cen == "Classes"){

            while(temp_class != "Rooms"){
            cin >> temp_class;
            cin >> temp_students;
            num_of_classes++;
            }

        }
        if(temp_class == "Rooms"){

            while(!cin.eof()){
            cin >> temp_room;
            cin >> temp_capacity;
            num_of_rooms++;
            }

        }



    }

    num_of_classes = (num_of_classes) - 1;  //makes sure the num_of_classes are correct
    num_of_rooms = (num_of_rooms);          //makes sure the num_of_rooms are correct


    cout << "Num of classes = " << num_of_classes << endl;
    cout << "Num of rooms = " << num_of_rooms << endl;

    while(cin >> sin){
    
        if(sin == "Classes"){

            for(int i = 0; i < num_of_classes; i++){

                cin >> class_room[i];
                cin >> students_in_class[i];
                cout << "Class is " << class_room[i] << endl;
                cout << "Students in class is " << students_in_class[i] << endl;
 
            }

        } 
        if(sin == "Rooms"){
       
            for(int i = 0; i < num_of_rooms; i++){

                cin >> room[i];
                cin >> room_capacity[i];
                cout << "Room is " << room[i] << endl;
                cout << "Room capacity is " << room_capacity[i] << endl;

            }
       
        }

    }//end of while loop
/*
    cout << "       |Monday|Tuesday|Wednesday|Thursday|Friday|" << endl;
    cout << "       |~~~~~~|~~~~~~~|~~~~~~~~~|~~~~~~~~|~~~~~~|" << endl;
    cout << "8:00 AM|
    cout << "9:00 AM|
    cout << "10:00AM|
    cout << "11:00AM|
    cout << "12:00PM|
    cout << "1:00 PM|

    This is a temporary template for the start of what the output could look like
*/













}
