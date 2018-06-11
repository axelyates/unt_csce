#include <iostream>     //declaring necessary includes 
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;

typedef char* DblPtr;													// creating necessary struct and enum and typedef
enum Status {OPEN = ' ', HIT = 'X', MISS = 'O', CARRIER = 'C', BATTLESHIP = 'B', DESTROYER = 'D', SUBMARINE = 'S'};
struct Torpedo{
        char row;
        int column;
        int carrier_hit;
        int battleship_hit;
        int submarine_hit;
        int destroyer_hit;
              };
void show_board(bool, DblPtr *matrix);
/*
============================================================================
Function        : show_board
Parameters      : boolean and the DblPtr *matrix representing the board
Return          : returns a 2D array either showing what is on the board or
		  showing what the user has attacked with depending on the
		  spot in the program.
Description     : This function iterates through a 2D array and fills every
                  position with a ' '. (space). OR shows that user has made
		  certain attacks.
============================================================================
*/
void display(DblPtr *matrix);
/*
============================================================================
Function        : display
Parameters      : DblPtr *matrix representing the board
Return          : returns a board displayed to the user
Description     : This function iterates through a 2D array and sets the
                  border for the battleship game
============================================================================
*/
void place_ship(int&, DblPtr *matrix);
/*
============================================================================
Function        : place_ship
Parameters      : int and DblPtr *matrix representing ships 1 and 2 and the
		  board.
Return          : retuns a portion of the 2D array filled with a random ship
Description     : This function iterates through a 2D array and sets a
                  random section of it to a variable representing a ship
============================================================================
*/
void fill(DblPtr *matrix);
/*
============================================================================
Function        : fill
Parameters      : DblPtr *matrix representing the board
Return          : returns a 2D array filled with spaces
Description     : This function iterates through a 2D array and fills every
                  position with a ' '. (space)
============================================================================
*/
bool is_game_won(DblPtr *matrix);
/*
============================================================================
Function        : is_game_won
Parameters      : DblPtr *matrix represetnting the board
Return          : returns a boolean, either true or false, depending on if
		  the game is won or not.
Description     : This function iterates through a 2D array if there are no
		  misses, hits or open spaces it returns false, and if there 
		  are misses, hits or open spaces it returns true.
============================================================================
*/
