// This program demonstrates a simple C++ Class
/*
        Name:                   Axel Yates
        Email:                  axelyates@my.unt.edu
        Class Section:          002
        Lab Section:            308
*/







#include <iostream>
#include "rectang.h"   // contains Rectangle class declaration

using namespace std;

int main (void)
{
   Rectangle Box;
   float Wide, Long;

   std::cout << "\nThis program will calculate the area of a rectangle.\n";
   std::cout << "\nWhat is the  WIDTH? ";
   std::cin >> Wide;

   std::cout << "What is the LENGTH? ";
   std::cin >> Long;

   Box.SetData(Wide, Long);

   Box.CalcArea();

   std::cout << "\nHere is the rectangle's data:\n";
   std::cout << "      Width: " << Box.GetWidth() << "\n";
   std::cout << "     Length: " << Box.GetLength() << "\n\n";
   std::cout << "       AREA: " << Box.GetArea() << "\n\n";
}
