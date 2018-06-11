/*
============================================================================
Name 		: main.cpp
Author 		: Axel Yates
Version 	: 1.0
Copyright 	: 2015
Description 	: The program creates a battleship board and places 2 random
		  ships on the board.
============================================================================
*/
#include "prgm.h"

int main()
{
	Torpedo torpedo;
	torpedo.carrier_hit = 0;
	torpedo.battleship_hit = 0;
	torpedo.submarine_hit = 0;
	torpedo.destroyer_hit = 0;
	char selection;								//variable for users selection of difficulty
	int num_of_attacks;
	int num_of_rows = 10; 
	int num_of_columns = 10;
	srand(time(NULL));							//used for random numbers later

	DblPtr *matrix = new DblPtr[num_of_rows];				//creating dynamic array
        for (int i = 0; i < num_of_rows; i++)
        {
                matrix[i] = new char[num_of_columns];
        }


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


	if(selection == 'e' || selection == 'E')						//only happens if user selects e or E
	{
		num_of_attacks = 30;
	}
	
	else if(selection == 'n' || selection == 'N')						//only happens if user selects n or N
	{
		num_of_attacks = 25;
	}
	
	else if(selection == 'h' || selection == 'H')						//only happens if user selects h or H
	{
		num_of_attacks = 20;
	}

	cout << "---------------------------------------------------------------- 			\n";
	cout << "This program will randomly choose two ships from your fleet      			\n";
	cout <<	"made up of the following vessels: Carrier, Battleship, Submarine,			\n";
	cout <<	"and Destroyer. It will then randomly assign both of the vessels  			\n";
	cout <<	"to the board that are oriented either vertically or horizontally.			\n"; 
	cout << "As a player you will then have " << num_of_attacks << " tries to sink both of the      \n";
	cout <<	"computer's vessels!                                              			\n";
	cout << "---------------------------------------------------------------- 			\n";
	cout << 										       endl;
	cout << "Initializing board...						  			\n";
	cout << "Assigning vessels...						  			\n";

	fill(matrix);
	int ship_size1 = rand() % 2 + 2;	// randomly sets size of ship1
	int ship_size2 = rand() % 2 + 4;	// randomly sets size of ship2
	place_ship(ship_size1, matrix);		// function that places the first ship
	place_ship(ship_size2, matrix);		// function that places the second ship
	show_board(false, matrix);


	bool game_won = false;			// creates bool to flag if game is won or not

	do
	{
		torpedo.row = 'A';		// creating necessary variables for users attack coordinates
		int row_index = 0;
		torpedo.column = 0;
		int column_index = 0;

		do				// does until user inputs correct coordinates
		{	
			cout << "You have " << num_of_attacks << " attacks left!" << endl;	// asking user for coordinates
			cout << "Enter attack coordinates (e.g., B7): ";
			cin  >> torpedo.row;
			cin  >> torpedo.column;
	
			
			torpedo.row = (tolower(torpedo.row));					// sets users X coordinate to lowercase
			
			row_index = static_cast<int>(torpedo.row) - 97;				// sets x coordinate to a number for array
			column_index = (torpedo.column - 1);					// sets y coordinate to correct number
			
			if(row_index >= 10 || row_index < 0)
			{
				cout << "Improper coordinate, try again." << endl;
			}
			else if(column_index >= 10 || column_index < 0)
			{
				cout << "Improper coordinate, try again." << endl;
			}
		


		}
		while(!(row_index >= 0 && row_index < num_of_rows && column_index >= 0 && column_index < num_of_columns));

	
		if(matrix[row_index][column_index]  == CARRIER)					// checks to see if user hit carrier
		{
			matrix[row_index][column_index] = HIT;					// creates an X to indicate a hit
			torpedo.carrier_hit++;							// increases hit counter on carrier
			
			if(torpedo.carrier_hit == 5)						// checks if carrier hit counter is full, thus sinking the ship
			{
				cout << "You sunk my CARRIER!!" << endl;
			}
			else									// outputs if carrier is not "sunk"
			{
				cout << "You hit my CARRIER!!" << endl;
			}
			num_of_attacks--;							// decrements number of attacks user has left
		}
		else if(matrix[row_index][column_index] == BATTLESHIP)				// checks to see if user hit battleship
		{
			matrix[row_index][column_index] = HIT;					// creates an X to indicate a hit
			torpedo.battleship_hit++;						// increases hit counter on battleship
			
			if(torpedo.battleship_hit == 4)						// checks if battleship hit counter is full, thus sinking the ship
			{
				cout << "You sunk my BATTLESHIP!!" << endl;			// outputs if battleship is "sunk"
			}
			else
			{
				cout << "You hit my BATTLESHIP!!" << endl;			// outputs if battleship is not "sunk"
			}
			num_of_attacks--;							// decrements number of attacks user has left
		}
		else if(matrix[row_index][column_index] == SUBMARINE)				// checks to see if user hit submarine
		{
			matrix[row_index][column_index] = HIT;					// creates an X to indicate a hit
			torpedo.submarine_hit++;						// increases hit counter on submarine
			
			if(torpedo.submarine_hit == 3)						// checks if submarine hit counter is full, thus sinking the ship
			{
				cout << "You sunk my SUBMARINE!!" << endl;			// outputs if submarine is "sunk"
			}
			else
			{
				cout << "You hit my SUBMARINE!!" << endl;			// ouputs if submarine is not "sunk"
			}
			num_of_attacks--;							// decrements number of attacks user has left
		}
		else if(matrix[row_index][column_index] == DESTROYER)				// checks to see if user hit destroyer
		{
			matrix[row_index][column_index] = HIT;					// creates an X to indicate a hit
			torpedo.destroyer_hit++;						// increases hit counter on destroyer
			
			if(torpedo.destroyer_hit == 2)						// checks if destroyer hit counter is full, thus sinking the ship
			{
				cout << "You sunk my DESTROYER!!" << endl;			// outputs if destroyer is "sunk"
			}
			else
			{
				cout << "You hit my DESTROYER!!" << endl;			// outputs if destroyer is not "sunk"
			}
			num_of_attacks--;							// decrements number of attacks user has left
		}
		else if(matrix[row_index][column_index] == OPEN)				// checks to see if user hit open water
		{
			matrix[row_index][column_index] = MISS;					// creates an O to indicate a miss
			cout << "Sorry, that was a miss." << endl;				// outputs if user missed a ship
			num_of_attacks--;							// decrements number of attacks user has left
		}
		else if(matrix[row_index][column_index] == HIT || matrix[row_index][column_index] == MISS)
		{
			cout << "You already made that choice. Please, try again." << endl;
		}

		game_won = is_game_won(matrix);
		show_board(false, matrix);

	}
	while(num_of_attacks > 0 && game_won != true);						// does until game won or lost

	cout << setw(3) << "FINAL RESULTS" << endl;						// outputs the final results header

	show_board(true, matrix);								// shows user the final board, 

	if(game_won)										// does this if game is won
	{
		cout << "Congratulations! You sunk both ships with " << num_of_attacks << " tries left!" << endl;
	}
	else											// does this if user ran out of attacks
	{
		cout << "No more attacks! Better luck next time!" << endl;
	}


	for (int i = 0; i < num_of_rows; i++)							// deletes the board
	{
		delete [] matrix[i];
	}

	delete [] matrix;



	return 0;
}
