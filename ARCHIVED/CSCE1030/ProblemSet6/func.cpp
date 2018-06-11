#include "prgm.h"

void display(DblPtr *matrix) //creates display and board borders 
{ 
        char row_tag = 'A'; 
 
        cout << "     1  2  3  4  5  6  7  8  9  10\n"; //outputs to top of board 
        cout << "   +-------------------------------+\n"; 
 
        for (int i = 0; i < 10; i++)            //iterates through array to set width of all spaces 
        { 
                cout << static_cast<char>(row_tag + i) << " |"; 
                for (int j = 0; j < 10; j++) 
                { 
                        cout << setw(3) <<  matrix[i][j]; 
                } 
                cout << "  |" << endl; 
        } 
 
        cout << "   +-------------------------------+\n";       //outputs to bottom of board 
        return; 
} 
 
void fill(DblPtr *matrix)                                       // function to fill out spaces to the entire board (shows blank) 
{ 
 
        for (int i = 0; i < 10; i++) 
        { 
                for (int j = 0; j < 10; j++) 
                { 
                        matrix[i][j] = ' '; 
                } 
        } 
 
        return; 
} 

void show_board(bool reveal, DblPtr *matrix)                    // function to actually display the board as opposed to just creating it
{
        char row_tag = 'A';

        cout << "     1  2  3  4  5  6  7  8  9  10\n"; //outputs to top of board
        cout << "   +-------------------------------+\n";
        if(reveal == false)
        {
                for (int i = 0; i < 10; i++)            //iterates through array to set width of all spaces
                {
                        cout << static_cast<char>(row_tag + i) << " |";
                        for (int j = 0; j < 10; j++)
                        {
                                if(matrix[i][j] == HIT || matrix[i][j] == MISS)
                                {
                                        cout << setw(3) <<  matrix[i][j];
                                }
                                else
                                {
                                        cout << setw(3) << ' ';
                                }

                        }
                        cout << "  |" << endl;
                }
        }
        else
        {
                for (int i = 0; i < 10; i++)            //iterates through array to set width of all spaces
                {
                        cout << static_cast<char>(row_tag + i) << " |";
                        for (int j = 0; j < 10; j++)
                        {
                                cout << setw(3) <<  matrix[i][j];
                        }
                        cout << "  |" << endl;
                }
        }
        cout << "   +-------------------------------+\n";       //outputs to bottom of board
        return;
}
bool is_game_won(DblPtr *matrix)                                //checks to see if the game is won or not
{
        for (int i = 0; i < 10; i++)
        {
                for (int j = 0; j < 10; j++)
                {
                        if(matrix[i][j] != OPEN && matrix[i][j] != HIT && matrix[i][j] != MISS)
                        {
                                return false;
                        }
                }
        }
        return true;
}
void place_ship(int& ship_size, DblPtr *matrix)                                                 // function to place the ships
{
        bool ship_placed = false;
        do                                      //creating do-while loop for function
        {
                int NUM_OF_ROWS = 10;
                int NUM_OF_COLS = 10;
                int row = rand() % (NUM_OF_ROWS - 1);                           //declaring necessary variables
                int column = rand() % (NUM_OF_COLS - 1);
                bool can_place = true;
                bool direction = rand() % 2;

                if(direction == 1) //horizontal
                {

                        for(int i = 0; i < ship_size; i++)      //iterates through ship_size
                        {
                                if(column + i == NUM_OF_COLS || matrix[row][column + i] != ' ') //checks if ship is in bound
                                {
                                        can_place = false;
                                }
                        }

                        if(can_place == true)   //only happens if can_place is true and direction is 1
                        {
                                for(int i = 0; i < ship_size; i++)      //iterates through ship size and sets array to certain ship
                                {
                                        if(ship_size == 2)
                                        {
                                                matrix[row][column + i] = DESTROYER;
                                        }
                                        if(ship_size == 3)
                                        {
                                                matrix[row][column + i] = SUBMARINE;
                                        }
                                        if(ship_size == 4)
                                        {
                                                matrix[row][column + i] = BATTLESHIP;
                                        }
                                        if(ship_size == 5)
                                        {
                                                matrix[row][column + i] = CARRIER;
                                        }
                                }
                                ship_placed = true;
                        }
                }
                else if(direction == 0) //vertical
                {

                        for(int i = 0; i < ship_size; i++)      //iterates through ship_size
                        {
                                if(row + i == NUM_OF_ROWS || matrix[row + i][column] != ' ')    //checks if ship is in bound
                                {
                                        can_place = false;
                                }
                        }

                        if(can_place == true)   //only happens if can_place is true and direction is 0
                        {

                                for(int i = 0; i < ship_size; i++) //iterates through ship size and sets array to certain ship
                                {
                                        if(ship_size == 2)
                                        {
                                                matrix[row + i][column] = DESTROYER;
                                        }
                                        if(ship_size == 3)
                                        {
                                                matrix[row + i][column] = SUBMARINE;
                                        }
                                        if(ship_size == 4)
                                        {
                                                matrix[row + i][column] = BATTLESHIP;
                                        }
                                        if(ship_size == 5)
                                        {
                                                matrix[row + i][column] = CARRIER;
                                        }
                                }

                                ship_placed = true;

                        }
                }

        }while(ship_placed == false);   //exits loop on place ship

        return;
}
