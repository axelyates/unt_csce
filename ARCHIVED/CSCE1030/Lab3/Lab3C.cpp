#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	
	int base; 
	int height;
	float area;

	printf("\n %s", "Input the base of the triangle: ");
	
	scanf("%d", &base);

	printf("\n %s", "Input the height of the triangle: ");

	scanf("%d", &height);

	area=0.5 * base * height;

	printf("\nHere is the Area of the triangle: %e \n", area);




	return 0;
}




