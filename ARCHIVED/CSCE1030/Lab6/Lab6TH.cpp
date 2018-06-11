/*
==============================================================================
Name            : Lab6TH.cpp
Author          : Axel Yates
Version         : 1.0
Copyright       : 2015
Description     : Calculates cross area, side area, and total area based on
		  users input.
==============================================================================
*/
#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159; //This variable is defined globally


double cross_area(double r); //Function prototype for function cross_area
/* 
Function        : cross_area
Parameters      : a double representing radius
Return          : a double that representing the cross area
Description     : This function converts radius to inches then multiplies by PI and raises to the power of 2.
*/


double side_area(double r, double h); //Function prototype for function side_area
/* 
Function        : side_area
Parameters      : a double representing radius and a double representing the height
Return          : a double representing the side area
Description     : This function converts radius and height to inches and then multiplies them both by PI and 2.
*/

double total_area(double& r, double& h); //Function prototype for function total_area
/* 
Function	: total_area
Parameters	: a double representing radius and a double representing height (both of which are converted to be the products
		  of the two functions: side_area and cross_area
Return		: a double representing the total area 
Description	: This function adds the side area and cross area together to get the total araea.
*/

int main()
{
	double h, r; //Variables local to the main function

	cout << "Enter the radius and the height of the cylinder in cm <Enter> ";
	cin >> r >> h;
	cout << endl;
	cout << "You have entered r= " << r << " and h= " << h << "." << endl;
	cout << "Since I am planning to use inches, I will convert r and h to inches." << endl;

	cout << "Cross section area of the cylinder is " << cross_area(r) << " square inches." << endl; //line calls cross_area function
	cout << "Side area of the cylinder is " << side_area(r,h) << " square inches.\n";		//line calls side_area function
	cout << "Total surface area of the cylinder is " << total_area(r,h) << " square inches." <<endl;//calls total area function

	return 0;
}

double cross_area(double r) //function to calculate the cross area
{
	//Cross section area includes the disks at the bottom and the top
	double cross_area;
	r = r * 0.3937; // Converting r to inches
	cross_area = 2 * PI * pow(r,2);
	return cross_area;

}

double side_area(double r, double h) //function to calculate the side area
{
	double side_area; //Variable local to side_area function
	r = r * 0.3937; //Converting r to inches
	h = h * 0.3937; //Converting h to inches
	side_area = 2 * PI * r * h;
	return side_area;
}

double total_area(double& r, double& h) //function to add functions cross_area and side_area
{
	double total_area; //Variable local to total_area function
	total_area = cross_area(r) + side_area(r,h);
	return total_area;
}
