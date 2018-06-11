/*********************************************************************
**  	PROGRAM:  	Lab 08			                    **
**  	AUTHOR:  	Axel Yates                                  **
**   	CLASS:  	CSCE-1040                                   **
**	SECTION:	002					    **
*********************************************************************/


#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

using namespace std;

int main(int argc, char* argv[])
{

	int selection = 0;
	int x = 0;
	int z = 0;
	int sum = 0;
	int temp[argc];
	int rows = atoi(argv[1]);
	int cols = atoi(argv[2]);
	int middle_row = (rows/2);
	int middle_col = (cols/2);
	int **matrix = new int*[rows];
	for(int i = 0; i < rows; ++i){
		matrix[i] = new int[cols];
	}
	
	for(int y = 3; y < argc; y++){
		int z = atoi(argv[y]);
		temp[x] = z;
		x++;
	}
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				matrix[i][j] = temp[z];
				z++;
			}
		}


	cout << "1. Print out the matrix" << endl;
	cout << "2. Sum all of the elements" << endl;
	cout << "3. Show the upper half" << endl;
	cout << "4. Show middle row" << endl;
	cout << "5. Show middle column" << endl;
	cout << "6. Exit" << endl;
	cin  >> selection;
	cout << endl;

	switch (selection){
	
	case 1:

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				cout << setw(3) << matrix[i][j] << " ";
			}
			cout << endl;
		}
	
	break;

	case 2:

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				sum+=matrix[i][j];  
			}
		}

		cout << "Sum of all the elements is: " << sum << endl;


	break;

	case 3:

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < i; j++){
				cout << " " << " ";
			}
			for(int k = i; k < cols; k++){
				cout <<  matrix[i][k] << " ";
			}
			cout << endl;
		}

	break;
	
	case 4:

			for(int j = 0; j < cols; j++){
				cout <<  matrix[middle_row][j] << " ";
			}
			cout << endl;	

	break;

	case 5:

			for(int i = 0; i < rows; i++){
				cout << matrix[i][middle_col] << " " << endl;
			}

	break;
	}
	return 0;

}
