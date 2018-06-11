
/*
 ============================================================================
 Name        : homework5.cpp
 Author      : Mark A. Thompson
 Version     :
 Copyright   : 2015
 Description : This program will build the software infrastructure to allow a
               user to play a simplified version of the game Battleship which
               will display to the screen.
 ============================================================================
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int SIZE = 10;	// number of rows and columns for square board

// enum for game board type with supported values
enum Status {OPEN = ' ', CARRIER = 'C', BATTLESHIP = 'B', SUBMARINE = 'S', DESTROYER = 'D'};

// function prototypes
void printStudentInfo();
void new_line();
void printIntro(int& maxTries);
void initBoard(Status board[][SIZE], int size);
void assignShips(Status board[][SIZE], int size);
void printBoardRow(int i);
void printBoard(Status board[][SIZE], int size);


int main()
{
	Status board[SIZE][SIZE];	// 2D game board implemented as enum type
	int maxTries;			// maximum number of shots available to user

	printStudentInfo();		// display student info
	
	cout << "Max tries = " << maxTries << endl;

	printIntro(maxTries);		// print game information and get max shots

	cout << "Max tries = " << maxTries << endl;
	
	cout << "Initializing board..." << endl;
	initBoard(board, SIZE);		// initialize board

	cout << "Assigning vessels..." << endl;
	assignShips(board, SIZE);	// randomly assign 2 vessels to game board

	printBoard(board, SIZE);	// print updated game board with 2 vessels

	return 0;
}

/*
 ============================================================================
 Function    : printStudentInfo
 Parameters  : nothing
 Return      : nothing
 Description : This function prints out student information
 ============================================================================
 */
void printStudentInfo()
{
	// display student information
	cout << "     +----------------------------------------------+" << endl;
	cout << "     |       Computer Science and Engineering       |" << endl;
	cout << "     |        CSCE 1030 - Computer Science I        |" << endl;
	cout << "     |   Student Name     EUID    euid@my.unt.edu   |" << endl;
	cout << "     +----------------------------------------------+" << endl;
	cout << endl;
	
	return;
}

/*
 ============================================================================
 Function    : new_line
 Parameters  : nothing
 Return      : nothing
 Description : This function discards any remaining characters in the buffer
 ============================================================================
 */
void new_line()
{
	char symbol;	// character to read in

	// loop until get to end-of-line
	do
	{
		cin.get(symbol);	// read character, but do nothing with it
	} while (symbol != '\n');

	return;
}

/*
============================================================================
Function    : printIntro
Parameters  : integer for the number of shots available to user
Return      : none
Description : This function prints an introductory message to the user, and
	      gives details about the game including the number of attempts
	      the user gets based on their chosen level of difficulty.
============================================================================
*/
void printIntro(int& maxTries)
{
	char level;	// difficulty level: Easy, Normal, Hard

	cout << "         W e l c o m e   t o   B a t t l e s h i p         " << endl << endl;;

	// prompt for and read in difficulty level
	do
	{
		cout << "Enter difficulty level (Easy, Normal, Hard) of game (E, N, or H): ";
		cin  >> level;

		// need flush rest of line here
		level = toupper(level);
	} while ((level != 'E') && (level != 'N') && (level != 'H'));

	new_line();	// discard any remaining characters

	// determine maximum number of shots available based on difficulty level
	if (level == 'E')
	{
		maxTries = 30;	// easy
	}
	else if (level == 'N')
	{
		maxTries = 25;	// normal
	}
	else // (level == 'H')
	{
		maxTries = 20;	// hard
	}
	
	// print introductory message
	cout << endl;
	cout << "-----------------------------------------------------------" << endl;
	cout << "This program will randomly choose two ships from your fleet" << endl;
	cout << "made up of the following vessels: Carrier, Battleship, Sub-" << endl;
	cout << "marine, and Destroyer. It will then randomly assign both of" << endl;
	cout << "the vessels to the board that are oriented either vertical-" << endl;
	cout << "ly or horizontally. As a player you will then have " << maxTries << " tries" << endl;
	cout << "to sink both of the computer's vessels!                    " << endl;
	cout << "-----------------------------------------------------------" << endl << endl;;

	return;
}

/*
 ============================================================================
 Function    : initBoard
 Parameters  : enum type for 2D game board array and integer for array size
 Return      : nothing
 Description : This function initializes the game board to its initial values
 ============================================================================
 */
void initBoard(Status board[][SIZE], int size)
{
	// loop through rows
	for (int row = 0; row < size; row++)
	{
		// loop through columns
		for (int col = 0; col < SIZE; col++)
		{
			// assign enum value for ' ' to row-column position
			board[row][col] = OPEN;
		}
	}
}

/*
============================================================================
Function    : assignShips
Parameters  : enum type for 2D game board array and integer for array size
Return      : nothing
Description : This function randomly assigns two different, non-overlapping
              vessels in a random orientation to the game board
============================================================================
*/
void assignShips(Status board[][SIZE], int size)
{
	const int NUM_SHIPS = 2;	// number of ships to place on game board
	int i;				// index to process rows on game board
	int j;				// index to process columns on game board
	int vertical;			// ship orientation: 1 = vertical, 0 = horizontal
	int shipRowPos;			// ship row position
	int shipColPos;			// ship column position
	int ship[NUM_SHIPS];		// array of ships assigned to board
	bool valid;			// flag to determine if ship can be placed at location on board
	int counter = 0;		// counter to handle each ship
	Status shipType;		// variable to hold ship type (i.e., CARRIER, BATTLESHIP, etc.)

	srand(time(0));			// seed random number generator

	// randomly choose first vessel based on ship length: C=5, B=4, S=3, D=2
	ship[counter] = (rand() % 4) + 2;
	counter++;

	// since we cannot select same ship, need while loop to choose second ship
	do
	{
		ship[counter] = (rand() % 4) + 2;
	} while (ship[counter - 1] == ship[counter]);

	// assign ships to game board
	for (int index = 0; index < NUM_SHIPS; index++)
	{
		// loop to attempt to assign ship until position is valid
		do
		{
			valid = true;			// initially assume position is valid

			vertical = rand() % 2;		// random ship orientation: 1 = vertical, 0 = horizontal

			shipRowPos = rand() % size;	// random ship row position
			shipColPos = rand() % size;	// random ship column position

			if (vertical)	// vertical
			{
				// check if vertical ship can be placed on board at this location
				if ((shipRowPos + ship[index]) <= SIZE)
				{
					// need check if ship already in this position first
					for (i = shipRowPos; i < (shipRowPos + ship[index]); i++)
					{
						if (board[i][shipColPos] != OPEN)
						{
							valid = false;	// ship already here
						}
					}
				}
				else
				{
					valid = false;	// ship unable to be placed at this location
				}

				if (valid)
				{
					// determine ship type
					switch (ship[index])
					{
						case 2:	// destroyer
							shipType = DESTROYER;
							break;
						case 3:	// submarine
							shipType = SUBMARINE;
							break;
						case 4:	// battleship
							shipType = BATTLESHIP;
							break;
						case 5:	// carrier
							shipType = CARRIER;
							break;
					}
				
					// now assign ship to game board	
					for (i = shipRowPos; i < (shipRowPos + ship[index]); i++)
					{
						board[i][shipColPos] = shipType;
					}
				}
			}
			else	// horizontal
			{
				// check if horizontal ship can be placed on board at this location
				if ((shipColPos + ship[index]) <= SIZE)
				{
					// need check if ship already in this position first
					for (j = shipColPos; j < (shipColPos + ship[index]); j++)
					{
						if (board[shipRowPos][j] != OPEN)
						{
							valid = false;	// ship already here
						}
					}
				}
				else
				{
					valid = false;	// ship unable to be placed at this location
				}

				if (valid)
				{
					// determine ship type
					switch (ship[index])
					{
						case 2:	// destroyer
							shipType = DESTROYER;
							break;
						case 3:	// submarine
							shipType = SUBMARINE;
							break;
						case 4:	// battleship
							shipType = BATTLESHIP;
							break;
						case 5:	// carrier
							shipType = CARRIER;
							break;
					}
				
					// now assign ship to game board	
					for (j = shipColPos; j < (shipColPos + ship[index]); j++)
					{
						board[shipRowPos][j] = shipType;
					}
				}
			}
		} while (!valid);
	}

	return;
}

/*
 ============================================================================
 Function    : printBoardRow
 Parameters  : integer for current array row
 Return      : nothing
 Description : This function prints the corresponding game board row letter
 ============================================================================
 */
void printBoardRow(int i)
{
	/* based on row integer passed, print out corresponding row letter of board */
	switch (i)
	{
		case 0:	cout << "A | ";
			break;
		case 1:	cout << "B | ";
			break;
		case 2:	cout << "C | ";
			break;
		case 3:	cout << "D | ";
			break;
		case 4:	cout << "E | ";
			break;
		case 5:	cout << "F | ";
			break;
		case 6:	cout << "G | ";
			break;
		case 7:	cout << "H | ";
			break;
		case 8:	cout << "I | ";
			break;
		case 9:	cout << "J | ";
			break;
		default:cout << "Unknown grid row value: " << i << ". Program terminating..." << endl;
			exit(EXIT_FAILURE);
	}

	return;
}

/*
 ============================================================================
 Function    : printBoard
 Parameters  : enum type for 2D game board array and integer for array size
 Return      : nothing
 Description : This function prints the game board to the screen
 ============================================================================
 */
void printBoard(Status board[][SIZE], int size)
{
	// print column and board headers
	cout << "    1 2 3 4 5 6 7 8 9 10" << endl;
	cout << "  +---------------------+" << endl;

	// loop through two-dimensional array to print out corresponding items
	for (int i = 0; i < size; i++)
	{
		printBoardRow(i); // print grid row and left vertical column of board

		// now print board values for each row as characters 
		for (int j = 0; j < SIZE; j++)
		{
			cout << static_cast<char>(board[i][j]) << " ";
		}

		cout << "|" << endl;	// print right vertical column of board
	}

	// print board footer
	cout << "  +---------------------+" << endl;

	return;	
}
