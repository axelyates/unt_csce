/********************************************|
|                                            |
|   Name: Axel Yates                         |
|   Course: CSCE 3110                        |
|   Assignment: Program 3 - Syntax Checker   |
|                                            |
*********************************************/

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

bool Pair(char opening,char closing){


    if(opening == '(' && closing == ')') {

        return true; //if we get a match of () this returns true

    }
    else if(opening == '{' && closing == '}'){ 

        return true; //if we get a match of {} this returns true

    }
    else if(opening == '[' && closing == ']'){

        return true; //if we get a match of [] this returns true

    }

    return false;
}

bool isBalanced(char expression){

    stack<char> S;

    if(expression == '(' || expression == '{' || expression == '['){
			
        S.push(expression);

    }
    else if(expression == ')' || expression == '}' || expression == ']'){

	if(S.empty() || !Pair(S.top(),expression)){

	    return false;

        }
	else{
			
            S.pop();

	}
    }
	
    return S.empty() ? true:false;
}

int main(){

    char curve[100];
    char curly[100];
    char straight[100];
    char c[10000];
    bool ignore = false;
    bool match = true;
    int i = 0;
    int x = 0;
    int y = 0;
    int z = 0;
    int counter = 0;
    int line_number = 1;

    stack<char> stack;

    while(cin || match == false){

        cin >> c[i];

        if(c[i] == '(' && ignore == false){

            curve[x] = c[i];
            x++;

        }
        if(c[i] == '{' && ignore == false){

            curly[y] = c[i];
            y++;
        
        }
        if(c[i] == '[' && ignore == false){

            straight[z] = c[i];
            z++;


        }
        
        if(c[i] == ')' && curve[x-1] != '(' && x-1 != -1 && ignore == false){

            cout << "Syntax ERROR: Missing " << c[i] << "." << endl;
            cout << "Line number: " << line_number << "." << endl;
            match = false;

        }
        if(c[i] == '}' && curly[y-1] != '{' && y-1 != -1 && ignore == false){

            cout << "Syntax ERROR: Missing " << c[i] << "." << endl;
            cout << "Line number: " << line_number << "." << endl;
            match = false;

        }
        if(c[i] == ']' && straight[z-1] != '[' && z-1 != -1 && ignore == false){

            cout << "Syntax ERROR: Missing " << c[i] << "." << endl;
            cout << "Line number: " << line_number << "." << endl;
            match = false;

        }
        if(c[i] == ')' && curve[x-1] == '(' && ignore == false){

            curve[x] = ' ';
            if(x-1 != -1){

                x--;

            }

        }
        if(c[i] == '}' && curly[y-1] == '{' && ignore == false){

            curly[y] = ' ';
            if(y-1 != -1){

                y--;

            }

        }
        if(c[i] == ']' && straight[z-1] == '[' && ignore == false){

            straight[z] = ' ';
            if(z-1 != -1){

                z--;

            }

        }
        if((c[i] == '\'' || c[i] == '\"') && ignore == true){

            ignore = false;
            counter = 1;

        }
        if((c[i] == '\'' || c[i] == '\"') && ignore == false && counter == 0){

            ignore = true;

        }

        counter = 0;

        if(match == false){

            break;

        }
        if(c[i] == 10){

            line_number++;

        }

        i++;

    }//end of while loop

    if(match == true && x != 0){

        cout << "Syntax ERROR: Missing )." << endl;
        return 0;

    }
    if(match == true && y != 0){

        cout << "Syntax ERROR: Missing }." << endl;
        return 0;

    }
    if(match == true && z != 0){

        cout << "Syntax ERROR: Missing ]." << endl;
        return 0;

    }

    if(match == true && x == 0 && y == 0 && z == 0){

        cout << "Hurray! All parenthesis are balanced!" << endl;

    };

    return 0;
}
