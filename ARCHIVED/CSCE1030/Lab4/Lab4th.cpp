#include <iostream>
using namespace std;


int main()

{
    char letter_grade;
    int num_of_a = 0;
    int num_of_b = 0;
    int num_of_c = 0;
    int num_of_d = 0;
    int num_of_f = 0;

    cout << "+--------------------------------------------+" << endl;       //header
    cout << "|      Computer Science and Engineering      |" << endl;
    cout << "|      CSCE 1030 -   Computer Science I      |" << endl;
    cout << "|  Axel Yates   ary0012   axelyates@unt.edu  |" << endl;
    cout << "+--------------------------------------------+" << endl;


    do {
        cout << "Please enter a valid letter grade (A, B, C, D, or F. Enter X to quit):  ";
        cin >> letter_grade;
        cout << endl;


        switch (letter_grade)
        	{
            		case 'A':
                	{
                    		num_of_a++;
                    		break;
                	}
            		case 'B':
                	{
                    		num_of_b++;
                    		break;
                	}
            		case 'C':
                	{
                    		num_of_c++;
                    		break;
                	}
            		case 'D':
                	{
                    		num_of_d++;
                    		break;
                	}
            		case 'F':
                	{
                    		num_of_f++;
                    		break;
                	}
            		case 'X':
			{
				break;
			}

			default:
                	{
                    		cout << "That wasn't a correct grade! Try again!" << endl;
                    		cout << endl;
				break;
                	}
        	}
        }
	while ('X' != letter_grade);


    cout << "You had " << num_of_a << " A(s)!" << endl;
    cout << "You had " << num_of_b << " B(s)!" << endl;
    cout << "You had " << num_of_c << " C(s)!" << endl;
    cout << "You had " << num_of_d << " D(s)!" << endl;
    cout << "You had " << num_of_f << " F(s)!" << endl;
    cout << endl;

    return 0;
}
