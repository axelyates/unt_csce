/*
============================================================================
Name 		: homework5.cpp
Author 		: Axel Yates
Version 	: 1.0
Copyright 	: 2015
Description 	: The program creates a battleship board and places 2 random
		  ships on the board.
============================================================================
*/

#include <iostream>	//declaring necessary includes
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;

enum ships {CARRIER = 'C', BATTLESHIP = 'B', DESTROYER = 'D', SUBMARINE = 'S'};

const int NUM_OF_ROWS = 10;		//declaring necessary const variables and board
const int NUM_OF_COLS = 10;
char board[NUM_OF_ROWS][NUM_OF_COLS];

void display();
/*
============================================================================
Function 	: display
Parameters 	: VOID
Return 		: returns a board displayed to the user
Description 	: This function iterates through a 2D array and sets the
		  border for the battleship game
============================================================================
*/
void place_ship(int&);
/*
============================================================================
Function 	: place_ship
Parameters 	: VOID
Return 		: retuns a portion of the 2D array filled with a random ship
Description 	: This function iterates through a 2D array and sets a
		  random section of it to a variable representing a ship
============================================================================
*/
void create_board();
/*
============================================================================
Function 	: create_board
Parameters 	: VOID
Return 		: returns a 2D array filled with spaces
Description 	: This function iterates through a 2D array and fills every
		  position with a ' '. (space)
============================================================================
*/

int main()
{
	char selection;	//variable for users selection of difficulty
	srand(time(NULL));	//used for random numbers later

    	cout << "+----------------------------------------------+" << endl;	//program header displayed
    	cout << "|       Computer Science and Engineering       |" << endl;
    	cout << "|        CSCE 1030 - Computer Science I        |" << endl;
    	cout << "|   Axel Yates  ary0012   axelyates@my.unt.edu |" << endl;
	cout << "+----------------------------------------------+" << endl;
	cout << endl;
	cout << "    W e l c o m e  t o  B a t t l e s h i p" << endl;
	cout << endl;


	do
	{
		cout << "Enter difficulty level (Easy, Normal, Hard) of game (E, N, or H): ";	//ask user for desired difficulty
		cin  >> selection;
	}while(selection != 'e'&& selection != 'E'&& selection !='n'&& selection != 'N'&& selection != 'h'&& selection != 'H');


	if(selection == 'e' || selection == 'E')	//only happens if user selects e or E
	{
		cout << "----------------------------------------------------------------\n";	//easy difficulty header
		cout << "This program will randomly choose two ships from your fleet\n";
		cout <<	"made up of the following vessels: Carrier, Battleship, Submarine,\n";
		cout <<	"and Destroyer. It will then randomly assign both of the vessels \n";
		cout <<	"to the board that are oriented either vertically or horizontally.\n"; 
		cout << "As a player you will then have 30 tries to sink both of the \n";
		cout <<	"computer's vessels!\n";
		cout << "----------------------------------------------------------------\n";
		cout << endl;
		cout << "Initializing board...\n";
		cout << "Assigning vessels...\n";
	}
	
	else if(selection == 'n' || selection == 'N')	//only happens if user selects n or N
	{
		cout << "----------------------------------------------------------------\n";	//normal difficulty header
		cout << "This program will randomly choose two ships from your fleet\n";
		cout <<	"made up of the following vessels: Carrier, Battleship, Submarine,\n";
		cout <<	"and Destroyer. It will then randomly assign both of the vessels \n";
		cout <<	"to the board that are oriented either vertically or horizontally.\n"; 
		cout << "As a player you will then have 25 tries to sink both of the \n";
		cout <<	"computer's vessels!\n";
		cout << "----------------------------------------------------------------\n";
		cout << endl;
		cout << "Initializing board...\n";
		cout << "Assigning vessels...\n";
	}
	
	else if(selection == 'h' || selection == 'H')	//only happens if user selects h or H
	{
		cout << "----------------------------------------------------------------\n";	//hard difficulty header
		cout << "This program will randomly choose two ships from your fleet\n";
		cout <<	"made up of the following vessels: Carrier, Battleship, Submarine,\n";
		cout <<	"and Destroyer. It will then randomly assign both of the vessels \n";
		cout <<	"to the board that are oriented either vertically or horizontally.\n"; 
		cout << "As a player you will then have 20 tries to sink both of the \n";
		cout <<	"computer's vessels!\n";
		cout << "----------------------------------------------------------------\n";
		cout << endl;
		cout << "Initializing board...\n";
		cout << "Assigning vessels...\n";
	}

	int ship_size1 = rand() % 2 + 2;	// randomly sets size of ship1
	int ship_size2 = rand() % 2 + 4;	// randomly sets size of ship2
	create_board();				//function that creates the board
	place_ship(ship_size1);			//function that places the first ship
	place_ship(ship_size2);			//function that places the second ship
	display();				//function that outputs the display


	return 0;
}

void place_ship(int& ship_size)
{
	bool ship_placed = false;
	do					//creating do-while loop for function
	{
		int row = rand() % (NUM_OF_ROWS - 1);				//declaring necessary variables
		int column = rand() % (NUM_OF_COLS - 1);
		bool can_place = true;
		bool direction = rand() % 2;
		
		if(direction == 1) //horizontal
		{

			for(int i = 0; i < ship_size; i++)	//iterates through ship_size
			{
				if(column + i == NUM_OF_COLS || board[row][column + i] != ' ') //checks if ship is in bound
				{
					can_place = false;
				}
			}

			if(can_place == true)	//only happens if can_place is true and direction is 1
			{
				for(int i = 0; i < ship_size; i++)	//iterates through ship size and sets array to certain ship
				{
					if(ship_size == 2)
					{
						board[row][column + i] = DESTROYER;
					}
					if(ship_size == 3)
					{
						board[row][column + i] = SUBMARINE;
					}
					if(ship_size == 4)
					{
						board[row][column + i] = BATTLESHIP;
					}
					if(ship_size == 5)
					{
						board[row][column + i] = CARRIER;
					}
				}	
				ship_placed = true;
			}
		}
		else if(direction == 0) //vertical
		{
		
			for(int i = 0; i < ship_size; i++)	//iterates through ship_size
			{
				if(row + i == NUM_OF_ROWS || board[row + i][column] != ' ')	//checks if ship is in bound
				{
					can_place = false;
				}
			}
			
			if(can_place == true)	//only happens if can_place is true and direction is 0
			{

				for(int i = 0; i < ship_size; i++) //iterates through ship size and sets array to certain ship
				{
					if(ship_size == 2)
					{
						board[row + i][column] = DESTROYER;
					}
					if(ship_size == 3)
					{
						board[row + i][column] = SUBMARINE;
					}
					if(ship_size == 4)
					{
						board[row + i][column] = BATTLESHIP;
					}
					if(ship_size == 5)
					{
						board[row + i][column] = CARRIER;
					}
				}
				
				ship_placed = true;

			}
		}

	}while(ship_placed == false);	//exits loop on place ship

	return;
}


void display() //creates display and board borders
{
	char row_tag = 'A';

	cout << "     1  2  3  4  5  6  7  8  9  10\n";	//outputs to top of board
	cout << "   +-------------------------------+\n";

	for (int i = 0; i < NUM_OF_ROWS; i++)		//iterates through array to set width of all spaces
	{
		cout << static_cast<char>(row_tag + i) << " |";
		for (int j = 0; j < NUM_OF_COLS; j++)
		{
			cout << setw(3) <<  board[i][j];
		}
		cout << "  |" << endl;
	}

	cout << "   +-------------------------------+\n";	//outputs to bottom of board
	return;
}

void create_board()	//creates the actual board
{
	for (int i = 0; i < 10; i++)	//iterates through the 2D array to create the board
        {
                for (int j = 0; j < 10; j++)
                {
			board[i][j] = ' ';
                }
        }
        return;
}
