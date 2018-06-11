#include <cstdlib>	//necessary includes
#include <stdio.h>
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

hash::hash(){	//hash table constructor

	for(int i = 0; i < 10; i++){

		Hash_Table[i] = new item;	//creates a new item and stores it at the ith Hash_Table location
		Hash_Table[i]->name = "empty";	//fills the ith Hash_Table location name with an empty string
		Hash_Table[i]->next = NULL;	//fills the ith Hash_Table location next with a NULL pointer

	}
}
/****************************************************************************/

void hash::Push(int count){	//push function

	if(count == 0){						//only runs if count is = to 0
		for(int i = 0; i < 10; i++){

			Hash_Table[i] = new item;	//creates a new item and stores it at the ith Hash_Table location
			Hash_Table[i]->name = "empty";	//fills the ith Hash_Table location name with an empty string
			Hash_Table[i]->next = NULL;	//fills the ith Hash_Table location next with a NULL pointer
		
		}
		for(int i = 0; i < 10; i++){

			if(i + 1 != 10){
				Hash_Table[i]->next = NULL;	//fills the ith Hash_Table location next with a NULL pointer
			}
			else{

				Hash_Table[i]->next = NULL;	//fills the ith Hash_Table location next with a NULL pointer

			}
		}
	}
	if(count == 1){
		
		for(int i = 5; i < 10; i++){

			Hash_Table[i] = new item;	//creates a new item and stores it at the ith Hash_Table location
			Hash_Table[i]->name = "empty";	//fills the ith Hash_Table location name with an empty string
			Hash_Table[i]->next = NULL;
		}

		for(int i = 5; i < 10; i++){

			if(i + 1 != 10){

				Hash_Table[i]->next = Hash_Table[i+1];	//moves pointer down the table

			}
			else{

				Hash_Table[i]->next = NULL;	//fills the ith Hash_Table location next with a NULL pointer

			}

		}

		for(int i = 5; i < 10; i++){

			if(i + 1 != 10){

				Hash_Table[i]->next = Hash_Table[i+1];	//moves pointer down the table

			}
			else{

				Hash_Table[i]->next = NULL;	//fills the ith Hash_Table location next with a NULL pointer

			}
		}
	}
}
/****************************************************************************/

void hash::Pop(int count){	//test function trying to delete entire hash_table..
				//based on "remove_item" function.
	item* delete_pointer;	//declaring variables
	item* pointer_one;
	item* pointer_two;
	int index = count;

	if(count < 5){		//only runs if count is less than 5
	
		index = 0;	//sets index = to 0
	
	}
	if(count > 4 && count < 10){	//only runs if count is between 5 and 10

		index = 5;	//sets index = to 5

	}


	if(index == 5){		//only runs if index is 5
		while(index < 10){	//runs until index is 10

			delete_pointer = Hash_Table[index];		//whole while loop moves pointer down until it gets to end of table
			Hash_Table[index] = Hash_Table[index]->next;
			delete delete_pointer;
			index++;

		}
	}
	else if(index == 0){	//only runs if index is 0
		while(index < 5){	//runs until index is 5

			delete_pointer = Hash_Table[index];		//whole while loop moves pointer down until it gets to end of table
			Hash_Table[index] = Hash_Table[index]->next;
			delete delete_pointer;
			index++;

		}
	}
}
/****************************************************************************/

void hash::Insert(string number){

	int index = Hash(number);			//declaring variables

	if(Hash_Table[index]->name == "empty"){		//runs if tabled index->name is "empty"

		Hash_Table[index]->name = number;	//sets name = to number
		cout << number << " has been successfully inserted into the Hash Table and returned index: " << index << endl;

	}
	else{

		item* Ptr = Hash_Table[index];		//setting Ptr to Hash_Table[index]
		item* n = new item;			//n stands for a pointer to a new item
		n->name = number;			//setting n->name to number
		n->next = NULL;				//setting n->next to NULL

		while(Ptr->next != NULL){		//will only happen when at the end of the list
		
			Ptr = Ptr->next;		//Ptr traverses list untl it hits the end
			if(Ptr->next == NULL){

				//put something here to link back to head of WHOLE list

			}


		}					//by here Ptr is pointing to the last item in the list
		Ptr->next = n;				//links end of list to newly created item

		cout << number << " has been successfully inserted into the Hash Table and returned index: " << index << endl;
	}
}
/****************************************************************************/

void hash::Print_Table(){	//function to print out the table

	for(int i = 0; i < 10; i++){

		cout << "------------------------" 	<< endl;
		cout << "index = " << i			<< endl;
		cout << Hash_Table[i]->name 		<< endl;
		cout << "------------------------" 	<< endl;

	}
}
/****************************************************************************/

void hash::Search(string name){	//search function

	int index = Hash(name);	//declaring variables
	bool found_name = false;
	string number;

	item* Ptr = Hash_Table[index];
	while(Ptr != NULL){	//while loop that doesn't until Ptr = NULL

		if(Ptr->name == name){

			found_name = true;
			number = Ptr->name;

		}
		Ptr = Ptr->next;

	}//end while loop
	if(found_name == true){

		cout << "The search for " << number << " was successful and returned index " << index << endl;

	}
	else{

		cout << name << " was not found in the Hash Table but returned index " << index << endl;

	}



}
/****************************************************************************/

void hash::Remove_Item(string name){	//function to remove items from Hash_Table

	int index = Hash(name);
	bool test = false;
	item* delete_pointer;
	item* pointer_one;
	item* pointer_two;

	while(test = false){
	//Case 0 - Bucket is empty
	if(Hash_Table[index]->name == "empty"){ 

		index++;

	}

	//Case 1 - only 1 item in bucket and item has matching name
	else if(Hash_Table[index]->name == name && Hash_Table[index]->next == NULL){

		Hash_Table[index]->name = "empty";
		test = true;

	}

	//Case 2 - match is located in 1st item in bucket but there are more items in the bucket
	else if(Hash_Table[index]->name == name){

		delete_pointer = Hash_Table[index];
		Hash_Table[index] = Hash_Table[index]->next;
		delete delete_pointer;
		test = true;

	}

	//Case 3 - bucket contains items but first item is not a match
	else{

		pointer_one = Hash_Table[index]->next;
		pointer_two = Hash_Table[index];

		while(pointer_one != NULL && pointer_one->name != name){

			pointer_two = pointer_one;
			pointer_one = pointer_one->next;

		}//end while loop

		//Case 3.1 - looked through all items in bucket and no match
		if(pointer_one == NULL){

			index++;

		}

		//Case 3.2 - looked through all items in bucket and match is found
		else{

			delete_pointer = pointer_one;
			pointer_one = pointer_one->next;
			pointer_two->next = pointer_one;

			delete delete_pointer;

			test = true;

		}
	}
	}//end while loop
}
/****************************************************************************/

int hash::Hash(string key){

	int hash = 0;
	int index;


	for(int i = 0; i < key.length(); i++){

		hash = hash + (int)key[i];

	}

	index = hash % 10;

	return index;

}
/****************************************************************************/

hash::~hash(){
		/*for(int i = 0; i < 5; i++){

			delete [] Hash_Table[i];

		}*/
}
