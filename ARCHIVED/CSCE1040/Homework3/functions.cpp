/*
        Name:                   Axel Yates 
	Email:			axelyates@my.unt.edu
        Class Section:          002 
        Lab Section:            308 
        Purpose of Program:       
*/ 

#include <cstring>	//necessary includes
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "list.h"

using namespace std;

List::List(){		//function to construct the list
	head = NULL;	//points head to null
	curr = NULL;	//points curr to null
	temp = NULL;	//points temp to null
}	//end list function


void List::add(char addData){		//function to add a link to the linked list
	node* new_node = new node;	//creates a new node called new_node
	new_node->next = NULL;		//sets next portion of node to NULL
	new_node->data = addData;	//sets data portion of node to whatever user entered to add to list
	bool duplicate = false;		//sets a variable called duplicate fto false

	if(head != NULL){		//only runs if something is in head of list

		curr = head;		//sets current pointer to the head of the list
		temp = NULL;		//sets temporary pointer to NULL

		while(curr != NULL){						//runs while current pointer is pointing to NULL (first while loop)
			if(addData == curr->data){				//only runs if data user input is equal to data within node that current is pointing to
				cout << "DUPLICATE: " << addData << endl;	//notifies user that the input they entered is already in the list
				duplicate = true;				//sets duplicate boolean to true
			}
			if(curr == NULL){				//only runs if current pointer is pointing to NULL
				break;					//breaks out of function
			}
			temp = curr->next;				//points the temporary pointer to the node after where current is pointing to
			curr = temp;					//sets current to point to wherever temporary is pointing to
		}//end first while loop
		if(addData != head->data){				//only runs if data user input is not at the head of list
			curr = head;					//sets current pointer to head of list
			while(curr != NULL){				//traverses list to find insert location (second while loop)
				if(curr->data >= new_node->data){	//only runs if data in node that current is pointing to is greater than or equal to the data the user input
					break;				//breaks out of function
				}
				else{					//only runs if data in the node that current is pointing to is less than the data the user input
					temp = curr;			//sets temporary pointer to current pointer
					curr = curr->next;		//moves current pointer to next item in list
				}
			}//end second while loop
			if(curr == head){				//only runs if current pointer and head pointer are pointing to the same place
				new_node->next = head;			//sets the next pointer of new_node to head pointer
				head = new_node;			//sets head to the  new node
				cout << "ADDED: " << addData << endl;	//notifies user that input has been added
			}
			else if(duplicate == false){			//only runs if duplicate is false
				new_node->next = curr;			//sets next pointer in new_node to current pointer
				temp->next = new_node;			//sets next pointer in temporary pointer to new_node
				cout << "ADDED: " << addData << endl;	//notifies user that input has been added
			}
			
		}
		else if(addData != curr->data){				//only runs if data user input is not in the current pointers data
			while(curr != NULL){				//traverses list to find insert location (third while loop)
				if(curr->data >= new_node->data){	//only runs if data in current pointer is greater than or equal to data in new_node
					break;				//breaks out of function
				}
				else{					//only runs if data in current pointer is less than data in new_node
					temp = curr;			//sets temporary pointer equal to current pointer
					curr = curr->next;		//sets current pointer to the next node in the list
				}
			}//end third while loop
			if(curr == head){				//only runs if current and head are pointing to the same place
				new_node->next = head;			//sets next pointer in new_node to the head pointer
				head = new_node;			//sets head equal to new_node
				cout << "ADDED: " << addData << endl;	//notifies user that input has been added
			}
			else{						//only runs if current and head are not pointing to the same place
				new_node->next = curr;			//sets next pointer in new_node to the current pointer
				temp->next = new_node;			//sets next pointer in temporary pointer to new_node
				cout << "ADDED: " << addData << endl;	//notifies user that input has been added
			}
		}
	}
	else{						//only runs if nothing is in list
		head = new_node;			//sets head of list to the newly created node
		cout << "ADDED: " << addData << endl;	//notifies user their input has been added to list
	}

	return;
}
void List::remove(char delData){			//function that removes a node from list
        node* delPtr = NULL;				//creates a new pointer to delete necessary pointer and sets it to NULL
        temp = head;    				//sets temp pointer to point to beginning of list
        remove_head = head->next;			//sets a variable in case user removes head of list
	curr = head;    				//sets curr pointer to point to beginning of list
        while(curr != NULL && curr->data != delData){   //only runs while curr is pointing to end of list
                temp = curr;				//sets temporary pointer to current pointer
                curr = curr->next;			//sets current pointer to next node in list
        }
        if(curr == NULL){       						//only runs if current pointer is pointing to NULL
                cout << "ERROR: Not found for Removal: " << delData << endl; 	//notifies user that data wasn't in list
                delete delPtr;  						//deletes the unnecessary delPtr
        }
        else{									//runs if curr is pointing to what we want to delete
                delPtr = curr;  						//sets delete pointer to what we want to delete
		curr = curr->next;      					//advances current pointer to next pointer
               	temp->next = curr;      					//patches the gap between curr and temp pointers
		if(delPtr == head){						//only runs if user deletes head of list
			head = remove_head;					//base case that patches gap if user removes head of list
		}
		delete delPtr;          					//deletes the pointer storing data we want to delete
                cout << "Removal successful: " << delData << endl;		//notifies user that node was deleted
        }

	return;	//end add function
}
void List::print(){						//function that prints out current list of nodes
        
	print_list = head;					//sets print_list node to the head of the list
	if(print_list == NULL){					//only runs if print_list is pointing to NULL
		cout << "NO NAMES IN LIST" << endl;		//notifies user that there are no names in the list
	}
        while(print_list != NULL){    				//only runs while print_list is not pointing to NULL
        	cout << "      " << print_list->data << endl;	//prints out list of nodes
        	print_list = print_list->next;			//print_list now points to next node in list
	}
	return;	//end print function
}
void List::search(char searchData){							//function that searches through linked list
	
	search_list = head;								//sets search_list pointer to head of list
	if(search_list == NULL){							//only runs if search_list is pointing to NULL
		cout << "FALSE: " << searchData << endl;				//notifies user that their input was not in the list
	}
	else if(search_list->data == searchData){					//only runs if data in search_list equals users input data
		cout << "TRUE: " << searchData << endl;					//notifies user that their input was in the list
	}
	else if(search_list->data != searchData){					//only runs if users data was not found in data in search_list
		while(search_list->next != NULL){					//runs while search_list is not pointing at NULL
			
			search_list = search_list->next;				//sets search_list to the next node
			
			if(search_list->data == searchData){				//only runs if data in search_list is equal to users input data
				cout << "TRUE: " << searchData << endl;			//notifies user that their input was in the list
				break;
			}
			if(search_list->next == NULL && search_list->data != searchData){//only runs if search_list points to NULL and the data in search_list isn't what the user input
			cout << "FALSE: " << searchData << endl;			//notifies user that their input was not in the list
			}
		}
	}
	else{										//base case for everything else
		cout << "FALSE: " << searchData << endl;				//notifies user that their input was not in the list
		return;
	}

	return;	//end search function
}
void List::commands(){		//function that prints out menu for user

        printf("ADD\n");	//prints out menu
        printf("REMOVE\n");
        printf("PRINT\n");
        printf("SEARCH\n");
        printf("COMMANDS\n");
        printf("EXIT\n");	//end of menu

	return;	//end commands function
}
void List::delete_list(){	//function that deletes the linked list to free memory

	if(head != NULL){			//only runs if head does not equal NULL
		while(head->next != NULL){	//only runs while head is not pointing to null
			head = head->next;	//sets head equal to next node
			delete head;		//deletes head
		}//end while loop
	}
	return;	//end delete function
}
