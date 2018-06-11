#include <iomanip>
#include <string>
#include <iostream>

using namespace std;



int main(){

	int max_x = 14;
	int max_y = 14;
	int graph[max_x][max_y] =

	{

		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}

	};


	for(int i = 0; i < max_x; i++){
		for(int j = 0; j < max_y; j++){

			cout << graph[i][j] << endl;

		}

	}






	return 0;
}
