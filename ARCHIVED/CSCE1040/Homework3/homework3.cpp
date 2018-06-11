/*
        Name:                   Axel Yates
        Email:                  axelyates@my.unt.edu
        Class Section:          002
        Lab Section:            308
*/

#include <stdio.h>	//necessary includes
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include "list.h"

using namespace std;


int main()
{
	string selection;	//variable to hold users selection from list
	char selection2;	//variable to hold users desired character to maneuver
	List List;		//constructs the list and variables

	printf("ADD\n");	//prints out the list
	printf("REMOVE\n");
	printf("PRINT\n");
	printf("SEARCH\n");
	printf("COMMANDS\n");
	printf("EXIT\n");	//end of printing list
	do{			//begin do-while loop
	printf("\ncmd>");	//prints out "cmd>" until user enters a desired action
	cin  >> selection;
	transform(selection.begin(), selection.end(), selection.begin(), ::toupper);//sets anything user enters to its uppercase equivalent

	if(selection == "ADD"){		//runs if user types in: add
		cin  >> selection2;	//reads in users character to add to list
		List.add(selection2);	//passes users character to the add function
	}

	if(selection == "REMOVE"){	//runs if user types in: remove
		cin  >> selection2;	//reads in users character to remove from list
		List.remove(selection2);//passes users character to the remove function
	}

	if(selection == "PRINT"){	//runs if user types in: prints
		List.print();		//calls the print function
	}

	if(selection == "SEARCH"){	//runs if user types in: search
		cin >> selection2;	//reads in users character to search from list
		List.search(selection2);//passes users character to the search function
	}
	
	if(selection == "COMMANDS"){	//runs if user types in: commands
		List.commands();	//calls the commands function
	}


	if(selection == "EXIT"){	//runs if user types in: exit
		cout << "\nGOODBYE!" <<endl;//notifies user program is ending and says a friendly goodbye
		List.delete_list();	//calls delete function to delete any remaining parts of the users list
		cout << endl;
	}

	}while(selection != "EXIT");//end do-while loopo

	return 0;
}
