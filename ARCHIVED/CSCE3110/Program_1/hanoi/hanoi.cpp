#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

void hanoi(int, char, char, char);

int main(){

    int num;
    int moves;

    cout << "Enter the number of disks: ";
    scanf("%d", &num);
    cout << "The moves required are:" << endl;

    hanoi(num, 'A', 'C', 'B');

    moves = (pow(2,num)) - 1;

    cout << "The total number of moves are: " << moves << endl;


    return 0;
}

void hanoi(int num, char frompeg, char topeg, char otherpeg){

    if(num == 1){

        cout << "Move disk 1 from peg " << frompeg << " to peg " << topeg << endl;
        return;

    }
    hanoi(num - 1, frompeg, otherpeg, topeg);
    cout << "Move disk " << num << " from peg " << frompeg << " to peg " << topeg << endl;
    hanoi(num - 1, otherpeg, topeg, frompeg);

}
