/*
============================================================================
Program Name    : homework2.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : This program uses logic based on users input from a menu
                  to perform certain functions in a necessary loop.
============================================================================
*/

#include <iostream>
using namespace std;


int main()

{
    int const number_of_numbers = 5;
    int selection;
    double min;
    double max;
    double number_1;
    double number_2;
    double number_3;
    double number_4;
    double number_5;

        cout << "+--------------------------------------------+" << endl;       //header
        cout << "|      Computer Science and Engineering      |" << endl;
        cout << "|      CSCE 1030 -   Computer Science I      |" << endl;
        cout << "|  Axel Yates   ary0012   axelyates@unt.edu  |" << endl;
        cout << "+--------------------------------------------+" << endl;

    do {

        cout << "*********************MENU*********************" << endl;
        cout << "| 1. Sum  of 5 Numbers                       |" << endl;
        cout << "| 2. Mean of 5 Numbers                       |" << endl;
        cout << "| 3. Min  of 5 Numbers                       |" << endl;
        cout << "| 4. Max  of 5 Numbers                       |" << endl;
        cout << "| 5. Exit                                    |" << endl;
        cout << "**********************************************" << endl;
        cout << " Please enter your selection: ";
        cin  >> selection;


        switch (selection)
            {
            case 1:
                cout << "You will now be prompted to enter " << number_of_numbers << " numbers." << endl;
                cout << "Enter number 1: ";
                cin >> number_1;
                cout << "Enter number 2: ";
                cin >> number_2;
                cout << "Enter number 3: ";
                cin >> number_3;
                cout << "Enter number 4: ";
                cin >> number_4;
                cout << "Enter number 5: ";
                cin >> number_5;
                cout << "The sum of the 5 numbers is: " << number_1 + number_2 + number_3 + number_4 + number_5 << endl;
                    cout << endl;
                break;

            case 2:
                cout << "You will now be prompted to enter " << number_of_numbers << " numbers." << endl;
                cout << "Enter number 1: ";
                cin >> number_1;
                cout << "Enter number 2: ";
                cin >> number_2;
                cout << "Enter number 3: ";
                cin >> number_3;
                cout << "Enter number 4: ";
                cin >> number_4;
                cout << "Enter number 5: ";
                cin >> number_5;
                cout << "The mean of the 5 numbers is: " << (number_1 + number_2 + number_3 + number_4 + number_5) / 2 << endl;
                    cout << endl;
                break;

            case 3:
                cout << "You will now be prompted to enter "  << number_of_numbers <<  " numbers." << endl;
                cout << "Enter number 1: ";
                cin  >> number_1;
                cout << "Enter number 2: ";
                cin  >> number_2;
                cout << "Enter number 3: ";
                cin  >> number_3;
                cout << "Enter number 4: ";
                cin  >> number_4;
                cout << "Enter number 5: ";
                cin  >> number_5;
                min = number_1;
                    if(number_2 < min)
                        min = number_2;
                    if(number_3 < min)
                        min = number_3;
                    if(number_4 < min)
                        min = number_4;
                    if(number_5 < min)
                        min = number_5;
                    {
                        cout << "The minimum number is: " << min << endl;
                    }
                    cout << endl;
                break;

            case 4:
                cout << "You will now be prompted to enter " << number_of_numbers << " numbers." << endl;
                cout << "Enter number 1: ";
                cin  >> number_1;
                cout << "Enter number 2: ";
                cin  >> number_2;
                cout << "Enter number 3: ";
                cin  >> number_3;
                cout << "Enter number 4: ";
                cin  >> number_4;
                cout << "Enter number 5: ";
                cin  >> number_5;
                max = number_1;
                    if(number_2 > max)
                        max = number_2;
                    if(number_3 > max)
                        max = number_3;
                    if(number_4 > max)
                        max = number_4;
                    if(number_5 > max)
                        max = number_5;
                    {
                        cout << "The maximum number is: " << max << endl;
                    }
                    cout << endl;
                break;

            case 5:
                cout << "Thank you for your input, program is ending." << endl;
                    cout << endl;
                break;

            default:
                cout << "That's not a valid number." << endl;
                    cout << endl;
                break;
            }

        }while (selection != 5);


    return 0;
}
