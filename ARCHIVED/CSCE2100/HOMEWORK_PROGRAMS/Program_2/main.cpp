#include <cstdlib>	//necessary includes
#include <stdio.h>
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main(){

	hash read_in_data;		//variable used to read in data
	hash stack;
	string number = "";		//variable used to read in number after "insert, remove, etc."
	int pop_count = 0;		//variable used to keep track of how many times pop was called
	int push_count = 0;		//variable used to keep track of how many times push was called

	while(cin >> read_in_data.input){		//while loop that runs until redirected input file is finished


		if(read_in_data.input == "push"){	//only runs if push is read in

			cout << "pushed" << endl;	//lets user know that push command was recognized
			read_in_data.Push(push_count);	//calls push function, passing in push_count as a variable
			if(push_count == 0){		//only runs if push has been called for the first time

				hash new_hash_table1;	
			
			}
			else if(push_count != 0){	//only runs if push has been called more than once

				hash new_hash_table2;

			}

			push_count++;			//increments push counter by one
		
		}


		if(read_in_data.input == "pop"){	//only runs if pop is read in

			cout << "popped" << endl;	//lets user know that pop command was recognized
			if(pop_count == 0){
			
				read_in_data.Pop(pop_count);	//calls pop function, passing in pop_count as a variable
			
			}
			else if(pop_count == 1){

				stack.Pop(pop_count);		//calls pop funcion, passing in pop_count as a variable

			}

			pop_count++;			//increments pop counter by one

		}

		if(read_in_data.input == "insert"){	//only runs if insert is read in

			cin  >> number;			//stores what number user wishes to insert into variable "number"
			read_in_data.Insert(number);	//calls insert function, passing in number as a variable

		}


		if(read_in_data.input == "search"){	//only runs if search is read in

			cin  >> number;			//stores what number user wishes to search for into variable "number"
			read_in_data.Search(number);	//calls search function, passing in number as a variable

		}


		if(read_in_data.input == "find"){	//only runs if find is read in

			cin >> number;			//stores what number user wishes to find into variable "number"
			read_in_data.Search(number);	//calls find function, passing in number as a variable

		}


		if(read_in_data.input == "print"){	//only runs if print is read in

			read_in_data.Print_Table();	//calls print function

		}

	}//end while loop

	return 0;//end of program
}
