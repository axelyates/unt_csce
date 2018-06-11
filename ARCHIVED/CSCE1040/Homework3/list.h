/*
        Name:                   Axel Yates 
	Email:			axelyates@my.unt.edu
        Class Section:          002 
        Lab Section:            308 
*/ 

#ifndef LIST_H
#define LIST_H

class List{				//defines class called List
private:				//private variables
	
	struct node{
		char data;		//variable to hold data inside each node (data of each node)
		node* next;		//creates a node pointer inside of each node (points to the next node in list)
	};

	node* head;			//variable used to point to the beginning of a linked list
	node* remove_head;		//variable used in remove function that sets head to the next node if head gets deleted
	node* curr;			//variable to hold a "current" pointer that is used to point to the node a user is currently on
	node* temp;			//variable to hold a temp pointer
	node* search_list;		//variable used in search function
	node* print_list;		//variable used in print function to help print linked list, gets set to head and ran through linked list if it exists

public:					//public functions
	
	List();				//constructor function
	void add(char addData);		//adds a node, and places a certain value inside
	void remove(char delData);	//deletes a node
	void search(char searchData);	//searches through linked list to find user entered value
	void print();			//prints out the current linked list
	void commands();		//prints out all of the commands user has access to
	void delete_list();		//function that deletes the linked list the user created to free memory,only runs when user exits program
};

#endif /* LIST_H */
