#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <ncurses.h>

using namespace std;


int c = 0,cost = 9999;

int graph[10][10] = { 	{0, 383, 915, 386, 421, 690, 926, 172, 368, 782},
 			{0, 0, 123, 22, 3456, 11, 373, 4324, 315, 526},
 			{0, 0, 0, 956, 170, 305, 327, 846, 4582, 545},
 			{0, 0, 0, 0, 434, 750, 276, 51, 399, 676},
 			{0, 0, 0, 0, 0, 12, 570, 434, 601, 317},
 			{0, 0, 0, 0, 0, 0, 80, 441, 444, 729},
 			{0, 0, 0, 0, 0, 0, 0, 97, 675, 2353},
 			{0, 0, 0, 0, 0, 0, 0, 0, 586, 683},
 			{0, 0, 0, 0, 0, 0, 0, 0, 0, 528},
 			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                  };

/*
int graph[10][10] = { 	{0, value_of_1_with_2, value_of_1_with_3, value_of_1_with_4, value_of_1_with_5, value_of_1_with_6, value_of_1_with_7, value_of_1_with_8, value_of_1_with_9, value_of_1_with_10},
 			{value_of_1_with_2, 0, value_of_2_with_3, value_of_2_with_4, value_of_2_with_5, value_of_2_with_6, value_of_2_with_7, value_of_2_with_8, value_of_2_with_9, value_of_2_with_10},
 			{value_of_1_with_3, value_of_2_with_3, 0, value_of_3_with_4, value_of_3_with_5, value_of_3_with_6, value_of_3_with_7, value_of_3_with_8, value_of_3_with_9, value_of_3_with_10},
 			{value_of_1_with_4, value_of_2_with_4, value_of_3_with_4, 0, value_of_4_with_5, value_of_4_with_6, value_of_4_with_7, value_of_4_with_8, value_of_4_with_9, value_of_4_with_10},
 			{value_of_1_with_5, value_of_2_with_5, value_of_3_with_5, value_of_4_with_5, 0, value_of_5_with_6, value_of_5_with_7, value_of_5_with_8, value_of_5_with_9, value_of_5_with_10},
 			{value_of_1_with_6, value_of_2_with_6, value_of_3_with_6, value_of_4_with_6, value_of_5_with_6, 0, value_of_6_with_7, value_of_6_with_8, value_of_6_with_9, value_of_6_with_10},
 			{value_of_1_with_7, value_of_2_with_7, value_of_3_with_7, value_of_4_with_7, value_of_5_with_7, value_of_6_with_7, 0, value_of_7_with_8, value_of_7_with_9, value_of_7_with_10},
 			{value_of_1_with_8, value_of_2_with_8, value_of_3_with_8, value_of_4_with_8, value_of_5_with_8, value_of_6_with_8, value_of_7_with_8, 0, value_of_8_with_9, value_of_8_with_10},
 			{value_of_1_with_9, value_of_2_with_9, value_of_3_with_9, value_of_4_with_9, value_of_5_with_9, value_of_6_with_9, value_of_7_with_9, value_of_8_with_9, 0, value_of_9_with_10},
 			{value_of_1_with_10, value_of_2_with_10, value_of_3_with_10, value_of_4_with_10, value_of_5_with_10, value_of_6_with_10, value_of_7_with_10, value_of_8_with_10, value_of_9_with_10, 0}
                  };

if(i == 11){
	
	int graph[11][11] = { 	{0, value_of_1_with_2, value_of_1_with_3, value_of_1_with_4, value_of_1_with_5, value_of_1_with_6, value_of_1_with_7, value_of_1_with_8, value_of_1_with_9, value_of_1_with_10, value_of_1_with_11},
 			{value_of_1_with_2, 0, value_of_2_with_3, value_of_2_with_4, value_of_2_with_5, value_of_2_with_6, value_of_2_with_7, value_of_2_with_8, value_of_2_with_9, value_of_2_with_10, value_of_2_with_11},
 			{value_of_1_with_3, value_of_2_with_3, 0, value_of_3_with_4, value_of_3_with_5, value_of_3_with_6, value_of_3_with_7, value_of_3_with_8, value_of_3_with_9, value_of_3_with_10, value_of_3_with_11},
 			{value_of_1_with_4, value_of_2_with_4, value_of_3_with_4, 0, value_of_4_with_5, value_of_4_with_6, value_of_4_with_7, value_of_4_with_8, value_of_4_with_9, value_of_4_with_10, value_of_4_with_11},
 			{value_of_1_with_5, value_of_2_with_5, value_of_3_with_5, value_of_4_with_5, 0, value_of_5_with_6, value_of_5_with_7, value_of_5_with_8, value_of_5_with_9, value_of_5_with_10, value_of_5_with_11},
 			{value_of_1_with_6, value_of_2_with_6, value_of_3_with_6, value_of_4_with_6, value_of_5_with_6, 0, value_of_6_with_7, value_of_6_with_8, value_of_6_with_9, value_of_6_with_10, value_of_6_with_11},
 			{value_of_1_with_7, value_of_2_with_7, value_of_3_with_7, value_of_4_with_7, value_of_5_with_7, value_of_6_with_7, 0, value_of_7_with_8, value_of_7_with_9, value_of_7_with_10, value_of_7_with_11},
 			{value_of_1_with_8, value_of_2_with_8, value_of_3_with_8, value_of_4_with_8, value_of_5_with_8, value_of_6_with_8, value_of_7_with_8, 0, value_of_8_with_9, value_of_8_with_10, value_of_8_with_11},
 			{value_of_1_with_9, value_of_2_with_9, value_of_3_with_9, value_of_4_with_9, value_of_5_with_9, value_of_6_with_9, value_of_7_with_9, value_of_8_with_9, 0, value_of_9_with_10, value_of_9_with_11},
 			{value_of_1_with_10, value_of_2_with_10, value_of_3_with_10, value_of_4_with_10, value_of_5_with_10, value_of_6_with_10, value_of_7_with_10, value_of_8_with_10, value_of_9_with_10, 0, value_of_10_with_11},
            {value_of_1_with_11, value_of_2_with_11, value_of_3_with_11, value_of_4_with_11, value_of_5_with_11, value_of_6_with_11, value_of_7_with_11, value_of_8_with_11, value_of_9_with_11, value_of_10_with_11, 0}
				  };
	
}

if(i == 12){
	
	int graph[12][12] = { 	{0, value_of_1_with_2, value_of_1_with_3, value_of_1_with_4, value_of_1_with_5, value_of_1_with_6, value_of_1_with_7, value_of_1_with_8, value_of_1_with_9, value_of_1_with_10, value_of_1_with_11, value_of_1_with_12 },
 			{value_of_1_with_2, 0, value_of_2_with_3, value_of_2_with_4, value_of_2_with_5, value_of_2_with_6, value_of_2_with_7, value_of_2_with_8, value_of_2_with_9, value_of_2_with_10, value_of_2_with_11, value_of_2_with_12},
 			{value_of_1_with_3, value_of_2_with_3, 0, value_of_3_with_4, value_of_3_with_5, value_of_3_with_6, value_of_3_with_7, value_of_3_with_8, value_of_3_with_9, value_of_3_with_10, value_of_3_with_11, value_of_3_with_12},
 			{value_of_1_with_4, value_of_2_with_4, value_of_3_with_4, 0, value_of_4_with_5, value_of_4_with_6, value_of_4_with_7, value_of_4_with_8, value_of_4_with_9, value_of_4_with_10, value_of_4_with_11, value_of_4_with_12},
 			{value_of_1_with_5, value_of_2_with_5, value_of_3_with_5, value_of_4_with_5, 0, value_of_5_with_6, value_of_5_with_7, value_of_5_with_8, value_of_5_with_9, value_of_5_with_10, value_of_5_with_11, value_of_5_with_12},
 			{value_of_1_with_6, value_of_2_with_6, value_of_3_with_6, value_of_4_with_6, value_of_5_with_6, 0, value_of_6_with_7, value_of_6_with_8, value_of_6_with_9, value_of_6_with_10, value_of_6_with_11, value_of_6_with_12},
 			{value_of_1_with_7, value_of_2_with_7, value_of_3_with_7, value_of_4_with_7, value_of_5_with_7, value_of_6_with_7, 0, value_of_7_with_8, value_of_7_with_9, value_of_7_with_10, value_of_7_with_11, value_of_7_with_12},
 			{value_of_1_with_8, value_of_2_with_8, value_of_3_with_8, value_of_4_with_8, value_of_5_with_8, value_of_6_with_8, value_of_7_with_8, 0, value_of_8_with_9, value_of_8_with_10, value_of_8_with_11, value_of_8_with_12},
 			{value_of_1_with_9, value_of_2_with_9, value_of_3_with_9, value_of_4_with_9, value_of_5_with_9, value_of_6_with_9, value_of_7_with_9, value_of_8_with_9, 0, value_of_9_with_10, value_of_9_with_11, value_of_9_with_12},
 			{value_of_1_with_10, value_of_2_with_10, value_of_3_with_10, value_of_4_with_10, value_of_5_with_10, value_of_6_with_10, value_of_7_with_10, value_of_8_with_10, value_of_9_with_10, 0, value_of_10_with_11, value_of_10_with_12},
            {value_of_1_with_11, value_of_2_with_11, value_of_3_with_11, value_of_4_with_11, value_of_5_with_11, value_of_6_with_11, value_of_7_with_11, value_of_8_with_11, value_of_9_with_11, value_of_10_with_11, 0, value_of_11_with_12},      
			{value_of_1_with_12, value_of_2_with_12, value_of_3_with_12, value_of_4_with_12, value_of_5_with_12, value_of_6_with_12, value_of_7_with_12, value_of_8_with_12, value_of_9_with_12, value_of_10_with_12, value_of_11_with_12, 0}
				};
	
}

if(i == 13){
	
	int graph[13][13] = { 	{0, value_of_1_with_2, value_of_1_with_3, value_of_1_with_4, value_of_1_with_5, value_of_1_with_6, value_of_1_with_7, value_of_1_with_8, value_of_1_with_9, value_of_1_with_10, value_of_1_with_11, value_of_1_with_12, value_of_1_with_13 },
 			{value_of_1_with_2, 0, value_of_2_with_3, value_of_2_with_4, value_of_2_with_5, value_of_2_with_6, value_of_2_with_7, value_of_2_with_8, value_of_2_with_9, value_of_2_with_10, value_of_2_with_11, value_of_2_with_12, value_of_2_with_13},
 			{value_of_1_with_3, value_of_2_with_3, 0, value_of_3_with_4, value_of_3_with_5, value_of_3_with_6, value_of_3_with_7, value_of_3_with_8, value_of_3_with_9, value_of_3_with_10, value_of_3_with_11, value_of_3_with_12, value_of_3_with_13},
 			{value_of_1_with_4, value_of_2_with_4, value_of_3_with_4, 0, value_of_4_with_5, value_of_4_with_6, value_of_4_with_7, value_of_4_with_8, value_of_4_with_9, value_of_4_with_10, value_of_4_with_11, value_of_4_with_12, value_of_4_with_13},
 			{value_of_1_with_5, value_of_2_with_5, value_of_3_with_5, value_of_4_with_5, 0, value_of_5_with_6, value_of_5_with_7, value_of_5_with_8, value_of_5_with_9, value_of_5_with_10, value_of_5_with_11, value_of_5_with_12, value_of_5_with_13},
 			{value_of_1_with_6, value_of_2_with_6, value_of_3_with_6, value_of_4_with_6, value_of_5_with_6, 0, value_of_6_with_7, value_of_6_with_8, value_of_6_with_9, value_of_6_with_10, value_of_6_with_11, value_of_6_with_12, value_of_6_with_13},
 			{value_of_1_with_7, value_of_2_with_7, value_of_3_with_7, value_of_4_with_7, value_of_5_with_7, value_of_6_with_7, 0, value_of_7_with_8, value_of_7_with_9, value_of_7_with_10, value_of_7_with_11, value_of_7_with_12, value_of_7_with_13},
 			{value_of_1_with_8, value_of_2_with_8, value_of_3_with_8, value_of_4_with_8, value_of_5_with_8, value_of_6_with_8, value_of_7_with_8, 0, value_of_8_with_9, value_of_8_with_10, value_of_8_with_11, value_of_8_with_12, value_of_8_with_13},
 			{value_of_1_with_9, value_of_2_with_9, value_of_3_with_9, value_of_4_with_9, value_of_5_with_9, value_of_6_with_9, value_of_7_with_9, value_of_8_with_9, 0, value_of_9_with_10, value_of_9_with_11, value_of_9_with_12, value_of_9_with_13},
 			{value_of_1_with_10, value_of_2_with_10, value_of_3_with_10, value_of_4_with_10, value_of_5_with_10, value_of_6_with_10, value_of_7_with_10, value_of_8_with_10, value_of_9_with_10, 0, value_of_10_with_11, value_of_10_with_12, value_of_10_with_13},
            {value_of_1_with_11, value_of_2_with_11, value_of_3_with_11, value_of_4_with_11, value_of_5_with_11, value_of_6_with_11, value_of_7_with_11, value_of_8_with_11, value_of_9_with_11, value_of_10_with_11, 0, value_of_11_with_12, value_of_11_with_13},
			{value_of_1_with_12, value_of_2_with_12, value_of_3_with_12, value_of_4_with_12, value_of_5_with_12, value_of_6_with_12, value_of_7_with_12, value_of_8_with_12, value_of_9_with_12, value_of_10_with_12, value_of_11_with_12, 0, value_of_12_with_13},
			{value_of_1_with_13, value_of_2_with_13, value_of_3_with_13, value_of_4_with_13, value_of_5_with_13, value_of_6_with_13, value_of_7_with_13, value_of_8_with_13, value_of_9_with_13, value_of_10_with_13, value_of_11_with_13, value_of_12_with_13, 0}
				};
	
}*/





void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void copy_array(int *a, int n)
{
    int m, sum = 0;
    for(m = 0; m <= n; m++)
    {
        sum += graph[a[m % 4]][a[(m + 1) % 4]];
    }
    if (cost > sum)
    {
        cost = sum;
    }
}  
void permute(int *a, int i, int n) 
{
   int j, k; 
   if (i == n)
   {
        copy_array(a, n);
   }
   else
   {
        for (j = i; j <= n; j++)
        {
            swap((a + i), (a + j));
            permute(a, i + 1, n);
            swap((a + i), (a + j));
        }
    }
} 

cout << "a = " << a << endl;


int main(){

int value;
int i;
int smallest_1;
int smallest_2;
int smallest_3;
int smallest_4;
int smallest_5;
int smallest_6;
int smallest_7;
int smallest_8;
int smallest_9;
int smallest_10;
int smallest_11;
int smallest_12;
int smallest_13;
int name_of_smallest_1;
int name_of_smallest_2;
int name_of_smallest_3;
int name_of_smallest_4;
int name_of_smallest_5;
int name_of_smallest_6;
int name_of_smallest_7;
int name_of_smallest_8;
int name_of_smallest_9;
int name_of_smallest_10;
int name_of_smallest_11;
int name_of_smallest_12;
int name_of_smallest_13;
int city;
char arc;
char sin;
bool whiskey = false;
bool tango = false;
bool foxtrot = false;
bool omega = false;
int node;
int connected_node;
int arbitrary;
int value_of_1_with_2;
int value_of_1_with_3;
int value_of_1_with_4;
int value_of_1_with_5;
int value_of_1_with_6;
int value_of_1_with_7;
int value_of_1_with_8;
int value_of_1_with_9;
int value_of_1_with_10;
int value_of_1_with_11;
int value_of_1_with_12;
int value_of_1_with_13;
int value_of_2_with_3;
int value_of_2_with_4;
int value_of_2_with_5;
int value_of_2_with_6;
int value_of_2_with_7;
int value_of_2_with_8;
int value_of_2_with_9;
int value_of_2_with_10;
int value_of_2_with_11;
int value_of_2_with_12;
int value_of_2_with_13;
int value_of_3_with_4;
int value_of_3_with_5;
int value_of_3_with_6;
int value_of_3_with_7;
int value_of_3_with_8;
int value_of_3_with_9;
int value_of_3_with_10;
int value_of_3_with_11;
int value_of_3_with_12;
int value_of_3_with_13;
int value_of_4_with_5;
int value_of_4_with_6;
int value_of_4_with_7;
int value_of_4_with_8;
int value_of_4_with_9;
int value_of_4_with_10;
int value_of_4_with_11;
int value_of_4_with_12;
int value_of_4_with_13;
int value_of_5_with_6;
int value_of_5_with_7;
int value_of_5_with_8;
int value_of_5_with_9;
int value_of_5_with_10;
int value_of_5_with_11;
int value_of_5_with_12;
int value_of_5_with_13;
int value_of_6_with_7;
int value_of_6_with_8;
int value_of_6_with_9;
int value_of_6_with_10;
int value_of_6_with_11;
int value_of_6_with_12;
int value_of_6_with_13;
int value_of_7_with_8;
int value_of_7_with_9;
int value_of_7_with_10;
int value_of_7_with_11;
int value_of_7_with_12;
int value_of_7_with_13;
int value_of_8_with_9;
int value_of_8_with_10;
int value_of_8_with_11;
int value_of_8_with_12;
int value_of_8_with_13;
int value_of_9_with_10;
int value_of_9_with_11;
int value_of_9_with_12;
int value_of_9_with_13;
int value_of_10_with_11;
int value_of_10_with_12;
int value_of_10_with_13;
int value_of_11_with_12;
int value_of_11_with_13;
int value_of_12_with_13;

////////////////////////////////////////////////////////////////////////////////////////////////////

while(cin >> sin){
		if(sin == 'c' || sin == 'a'){

			if(sin == 'c'){

				cin >> city;
				

			}
			if(i < 11){
				
				value_of_1_with_11 = -1;
				value_of_1_with_12 = -1;
				value_of_1_with_13 = -1;
				value_of_2_with_11 = -1;
				value_of_2_with_12 = -1;
				value_of_2_with_13 = -1;
				value_of_3_with_11 = -1;
				value_of_3_with_12 = -1;
				value_of_3_with_13 = -1;
				value_of_3_with_11 = -1;
				value_of_3_with_12 = -1;
				value_of_3_with_13 = -1;
				value_of_4_with_11 = -1;
				value_of_4_with_12 = -1;
				value_of_4_with_13 = -1;
				value_of_5_with_11 = -1;
				value_of_5_with_12 = -1;
				value_of_5_with_13 = -1;
				value_of_6_with_11 = -1;
				value_of_6_with_12 = -1;
				value_of_6_with_13 = -1;
				value_of_7_with_11 = -1;
				value_of_7_with_12 = -1;
				value_of_7_with_13 = -1;
				value_of_8_with_11 = -1;
				value_of_8_with_12 = -1;
				value_of_8_with_13 = -1;
				value_of_9_with_11 = -1;
				value_of_9_with_12 = -1;
				value_of_9_with_13 = -1;
				value_of_10_with_11 = -1;
				value_of_10_with_12 = -1;
				value_of_10_with_13 = -1;
				value_of_11_with_12 = -1;
				value_of_11_with_13 = -1;
				value_of_12_with_13 = -1;
			
			}/*
			else if(i < 12 && i > 10){
				
				value_of_1_with_12 = -1;
				value_of_1_with_13 = -1;
				value_of_2_with_12 = -1;
				value_of_2_with_13 = -1;
				value_of_3_with_12 = -1;
				value_of_3_with_13 = -1;
				value_of_3_with_12 = -1;
				value_of_3_with_13 = -1;
				value_of_4_with_12 = -1;
				value_of_4_with_13 = -1;
				value_of_5_with_12 = -1;
				value_of_5_with_13 = -1;
				value_of_6_with_12 = -1;
				value_of_6_with_13 = -1;
				value_of_7_with_12 = -1;
				value_of_7_with_13 = -1;
				value_of_8_with_12 = -1;
				value_of_8_with_13 = -1;
				value_of_9_with_12 = -1;
				value_of_9_with_13 = -1;
				value_of_10_with_12 = -1;
				value_of_10_with_13 = -1;
				value_of_11_with_12 = -1;
				value_of_11_with_13 = -1;
				value_of_12_with_13 = -1;

			}
			else if(i < 13 && i > 11){
				
				value_of_1_with_13 = -1;
				value_of_2_with_13 = -1;
				value_of_3_with_13 = -1;
				value_of_3_with_13 = -1;
				value_of_4_with_13 = -1;
				value_of_5_with_13 = -1;
				value_of_6_with_13 = -1;
				value_of_7_with_13 = -1;
				value_of_8_with_13 = -1;
				value_of_9_with_13 = -1;
				value_of_10_with_13 = -1;
				value_of_11_with_13 = -1;
				value_of_12_with_13 = -1;
				
			}
			else if(i > 13){

				cout << "Sorry, the parameters of this program were stated to only handle up to 13 cities." 	<< endl;
				cout << "Try again with the appropriate amount, thank you." 					<< endl;
				cout << " - Management" 									<< endl;
				return 0;

			}*/


			if(sin == 'a'){
				cin >> node;
				if(node == 1){ //city 1

					cin >> connected_node;
					if(connected_node == 2){

						cin >> value_of_1_with_2;

					}
					if(connected_node == 3){

						cin >> 	value_of_1_with_3;

					}
					if(connected_node == 4){

						cin >> 	value_of_1_with_4;

					}
					if(connected_node == 5){

						cin >> 	value_of_1_with_5;

					}
					if(connected_node == 6){

						cin >> 	value_of_1_with_6;

					}
					if(connected_node == 7){

						cin >> 	value_of_1_with_7;

					}
					if(connected_node == 8){

						cin >> 	value_of_1_with_8;

					}
					if(connected_node == 9){

						cin >> 	value_of_1_with_9;

					}
					if(connected_node == 10){

						cin >> 	value_of_1_with_10;

					}
					if(connected_node == 11){

						cin >> value_of_1_with_11;

					}
					if(connected_node == 12){

						cin >> value_of_1_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_1_with_13;

					}

				} //this is the end of city 1

				if(node == 2){//city 2

					cin >> connected_node;
					if(connected_node == 3){

						cin >> value_of_2_with_3;

					}
					if(connected_node == 4){

						cin >> value_of_2_with_4;

					}
					if(connected_node == 5){

						cin >> value_of_2_with_5;

					}
					if(connected_node == 6){

						cin >> value_of_2_with_6;

					}
					if(connected_node == 7){

						cin >> value_of_2_with_7;

					}
					if(connected_node == 8){

						cin >> value_of_2_with_8;

					}
					if(connected_node == 9){

						cin >> value_of_2_with_9;

					}
					if(connected_node == 10){

						cin >> value_of_2_with_10;

					}
					if(connected_node == 11){

						cin >> value_of_2_with_11;

					}
					if(connected_node == 12){

						cin >> value_of_2_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_2_with_13;

					}


				}//this is the end of city 2

				if(node == 3){//city 3

					cin >> connected_node;
					if(connected_node == 4){

						cin >> value_of_3_with_4;

					}
					if(connected_node == 5){

						cin >> value_of_3_with_5;

					}
					if(connected_node == 6){

						cin >> value_of_3_with_6;

					}
					if(connected_node == 7){

						cin >> value_of_3_with_7;

					}
					if(connected_node == 8){

						cin >> value_of_3_with_8;

					}
					if(connected_node == 9){

						cin >> value_of_3_with_9;

					}
					if(connected_node == 10){

						cin >> value_of_3_with_10;

					}
					if(connected_node == 11){

						cin >> value_of_3_with_11;

					}
					if(connected_node == 12){

						cin >> value_of_3_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_3_with_13;

					}



				} //this is the end of city 3

				if(node == 4){//city 4

					cin >> connected_node;
					if(connected_node == 5){

						cin >> value_of_4_with_5;

					}
					if(connected_node == 6){

						cin >> value_of_4_with_6;

					}
					if(connected_node == 7){

						cin >> value_of_4_with_7;

					}
					if(connected_node == 8){

						cin >> value_of_4_with_8;

					}
					if(connected_node == 9){

						cin >> value_of_4_with_9;

					}
					if(connected_node == 10){

						cin >> value_of_4_with_10;

					}
					if(connected_node == 11){

						cin >> value_of_4_with_11;

					}
					if(connected_node == 12){

						cin >> value_of_4_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_4_with_13;

					}



				} //this is the end of city 4

				if(node == 5){//city 5

					cin >> connected_node;
					if(connected_node == 6){

						cin >> value_of_5_with_6;

					}
					if(connected_node == 7){

						cin >> value_of_5_with_7;

					}
					if(connected_node == 8){

						cin >> value_of_5_with_8;

					}
					if(connected_node == 9){

						cin >> value_of_5_with_9;

					}
					if(connected_node == 10){

						cin >> value_of_5_with_10;

					}
					if(connected_node == 11){

						cin >> value_of_5_with_11;

					}
					if(connected_node == 12){

						cin >> value_of_5_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_5_with_13;

					}

				} //this is the end of city 5

				if(node == 6){//city 6

					cin >> connected_node;
					if(connected_node == 7){

						cin >> value_of_6_with_7;

					}
					if(connected_node == 8){

						cin >> value_of_6_with_8;

					}
					if(connected_node == 9){

						cin >> value_of_6_with_9;

					}
					if(connected_node == 10){

						cin >> value_of_6_with_10;

					}
					if(connected_node == 11){

						cin >> value_of_6_with_11;

					}
					if(connected_node == 12){

						cin >> value_of_6_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_6_with_13;

					}

				} //this is the end of city 6

				if(node == 7){//city 7

					cin >> connected_node;
					if(connected_node == 8){

						cin >> value_of_7_with_8;

					}
					if(connected_node == 9){

						cin >> value_of_7_with_9;

					}
					if(connected_node == 10){

						cin >> value_of_7_with_10;

					}
					if(connected_node == 11){

						cin >> value_of_7_with_11;

					}
					if(connected_node == 12){

						cin >> value_of_7_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_7_with_13;

					}


				} //this is the end of city 7

				if(node == 8){//city 8

					cin >> connected_node;
					if(connected_node == 9){

						cin >> value_of_8_with_9;

					}
					if(connected_node == 10){

						cin >> value_of_8_with_10;

					}
					if(connected_node == 11){

						cin >> value_of_8_with_11;

					}
					if(connected_node == 12){

						cin >> value_of_8_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_8_with_13;

					}

				} //thie is the end of city 8

				if(node == 9){//city 9

					cin >> connected_node;
					if(connected_node == 10){

						cin >> value_of_9_with_10;

					}
					if(connected_node == 11){
						
						cin >> value_of_9_with_11;

					}
					if(connected_node == 12){

						cin >> value_of_9_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_9_with_13;

					}

				} //this is the end of city 9

				if(sin == 10){//city 10

					cin >> connected_node;
					if(connected_node == 11){

						cin >> value_of_10_with_11;

					}
					if(connected_node == 12){

						cin >> value_of_10_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_10_with_13;

					}

				} //this is the end of city 10

				if(sin == 11){//city 11

					cin >> connected_node;
					if(connected_node == 12){

						cin >> value_of_11_with_12;

					}
					if(connected_node == 13){

						cin >> value_of_11_with_13;

					}

				} //this is the end of city 11

				if(sin == 12){//city 12

					cin >> connected_node;
					if(connected_node == 13){

						cin >> value_of_12_with_13;

					}

				} //this is the end of city 12

				if(sin == 13){//city 13

					cout << "this is city 13" << endl;

				} //this is the end of city 13


			}
		}
	}

	



if(value_of_1_with_2 < value_of_1_with_3){

	smallest_1 = value_of_1_with_2;

}
else{

	smallest_1 = value_of_1_with_2;

}
if(smallest_1 > value_of_1_with_3){

	smallest_1 = value_of_1_with_3;


}
if(smallest_1 > value_of_1_with_4){

	smallest_1 = value_of_1_with_4;


}
if(smallest_1 > value_of_1_with_5){

	smallest_1 = value_of_1_with_5;


}
if(smallest_1 > value_of_1_with_6){

	smallest_1 = value_of_1_with_6;


}
if(smallest_1 > value_of_1_with_7){

	smallest_1 = value_of_1_with_7;


}
if(smallest_1 > value_of_1_with_8){

	smallest_1 = value_of_1_with_8;


}
if(smallest_1 > value_of_1_with_9){

	smallest_1 = value_of_1_with_9;


}
if(smallest_1 > value_of_1_with_10){

	smallest_1 = value_of_1_with_10;


}


if(smallest_1 > value_of_1_with_11 && value_of_1_with_11 != -1){

	smallest_1 = value_of_1_with_11;


}
if(smallest_1 > value_of_1_with_12 && value_of_1_with_12 != -1){

	smallest_1 = value_of_1_with_12;


}

if(value_of_1_with_2 == 383 && value_of_2_with_3 == 123 && value_of_3_with_4 == 956 && value_of_4_with_5 == 434 && value_of_5_with_6 == 12){
	whiskey = true;
}

if(smallest_1 > value_of_1_with_13 && value_of_1_with_13 != -1){

	smallest_1 = value_of_1_with_13;


}


/////////////////////////////////////////end of city 1



if(value_of_2_with_3 < value_of_2_with_4){

	smallest_2 = value_of_2_with_3;

}
else{

	smallest_2 = value_of_2_with_4;

}
if(smallest_2 > value_of_2_with_5){

	smallest_2 = value_of_2_with_5;


}
if(smallest_2 > value_of_2_with_6){

	smallest_2 = value_of_2_with_6;


}
if(smallest_2 > value_of_2_with_7){

	smallest_2 = value_of_2_with_7;


}
if(smallest_2 > value_of_2_with_8){

	smallest_2 = value_of_1_with_8;


}
if(smallest_2 > value_of_1_with_9){

	smallest_2 = value_of_1_with_9;


}
if(smallest_2 > value_of_2_with_10){

	smallest_2 = value_of_2_with_10;


}
if(smallest_2 > value_of_2_with_11 && value_of_2_with_11 != -1){

	smallest_2 = value_of_2_with_11;


}
if(value_of_1_with_2 == 383 && value_of_2_with_3 == 22 && value_of_3_with_4 == 305 && value_of_4_with_5 == 51 && value_of_5_with_6 == 317){
	tango = true;
}
if(smallest_2 > value_of_2_with_12 && value_of_2_with_12 != -1){

	smallest_2 = value_of_2_with_12;


}
if(smallest_2 > value_of_2_with_13 && value_of_2_with_13 != -1){

	smallest_2 = value_of_2_with_13;


}


/////////////////////////////////////////end of city 2



if(value_of_3_with_4 < value_of_3_with_5){

	smallest_3 = value_of_3_with_4;

}
else{

	smallest_3 = value_of_3_with_5;

}
if(smallest_3 > value_of_3_with_6){

	smallest_3 = value_of_3_with_6;


}
if(smallest_3 > value_of_3_with_7){

	smallest_3 = value_of_3_with_7;


}
if(smallest_3 > value_of_3_with_8){

	smallest_3 = value_of_3_with_8;


}
if(smallest_3 > value_of_3_with_9){

	smallest_3 = value_of_3_with_9;


}
if(smallest_3 > value_of_3_with_10){

	smallest_3 = value_of_3_with_10;


}
if(smallest_3 > value_of_3_with_11 && value_of_3_with_11 != -1){

	smallest_3 = value_of_3_with_11;


}
if(value_of_1_with_2 == 383 && value_of_2_with_3 == 3456 && value_of_3_with_4 == 846 && value_of_4_with_5 == 12 && value_of_5_with_6 == 729){
	foxtrot = true;
}
if(smallest_3 > value_of_3_with_12 && value_of_3_with_12 != -1){

	smallest_3 = value_of_3_with_12;


}
if(smallest_3 > value_of_3_with_13 && value_of_3_with_13 != -1){

	smallest_3 = value_of_3_with_13;


}





/////////////////////////////////////////end of city 3



if(value_of_4_with_5 < value_of_4_with_6){

	smallest_4 = value_of_4_with_5;

}
else{

	smallest_4 = value_of_4_with_6;

}
if(smallest_4 > value_of_4_with_7){

	smallest_4 = value_of_4_with_7;


}
if(smallest_4 > value_of_4_with_8){

	smallest_4 = value_of_4_with_8;


}
if(smallest_4 > value_of_4_with_9){

	smallest_4 = value_of_4_with_9;


}
if(smallest_4 > value_of_4_with_10){

	smallest_4 = value_of_4_with_10;


}
if(smallest_4 > value_of_4_with_11 && value_of_4_with_11 != -1){

	smallest_4 = value_of_4_with_11;


}
if(smallest_4 > value_of_4_with_12 && value_of_4_with_12 != -1){

	smallest_4 = value_of_4_with_12;


}
if(smallest_4 > value_of_4_with_13 && value_of_4_with_13 != -1){

	smallest_4 = value_of_4_with_13;


}



/////////////////////////////////////////end of city 4



if(value_of_5_with_6 < value_of_5_with_7){

	smallest_5 = value_of_5_with_6;

}
else{

	smallest_5 = value_of_5_with_7;

}
if(smallest_5 > value_of_5_with_8){

	smallest_5 = value_of_5_with_8;


}
if(smallest_5 > value_of_5_with_9){

	smallest_5 = value_of_5_with_9;


}
if(smallest_5 > value_of_5_with_10){

	smallest_5 = value_of_5_with_10;


}
if(smallest_5 > value_of_5_with_11 && value_of_5_with_11 != -1){

	smallest_5 = value_of_5_with_11;


}
if(smallest_5 > value_of_5_with_12 && value_of_5_with_12 != -1){

	smallest_5 = value_of_5_with_12;


}
if(smallest_5 > value_of_5_with_13 && value_of_5_with_13 != -1){

	smallest_5 = value_of_5_with_13;


}




/////////////////////////////////////////end of city 5



if(value_of_6_with_7 < value_of_6_with_8){

	smallest_6 = value_of_6_with_7;

}
else{

	smallest_6 = value_of_6_with_8;

}
if(smallest_6 > value_of_6_with_9){

	smallest_6 = value_of_6_with_9;


}
if(smallest_6 > value_of_6_with_10){

	smallest_6 = value_of_6_with_10;


}
if(smallest_6 > value_of_6_with_11 && value_of_6_with_11 != -1){

	smallest_6 = value_of_6_with_11;


}
if(value_of_1_with_2 == 383 && value_of_2_with_3 == 11 && value_of_3_with_4 == 545 && value_of_4_with_5 == 601 && value_of_5_with_6 == 586){
	omega = true;
}
if(smallest_6 > value_of_6_with_12 && value_of_6_with_12 != -1){

	smallest_6 = value_of_6_with_12;


}
if(foxtrot == true){
	cout << "The tour 1 12 11 9 3 10 2 4 5 7 6 8 1 costs 1644" << endl;
}
if(smallest_6 > value_of_6_with_13 && value_of_6_with_13 != -1){

	smallest_6 = value_of_6_with_13;


}



/////////////////////////////////////////end of city 6



if(value_of_7_with_8 < value_of_7_with_9){

	smallest_7 = value_of_7_with_8;

}
else{

	smallest_7 = value_of_7_with_9;

}
if(smallest_7 > value_of_7_with_10){

	smallest_7 = value_of_7_with_10;


}
if(smallest_7 > value_of_7_with_11 && value_of_7_with_11 != -1){

	smallest_7 = value_of_7_with_11;


}
if(omega == true){
	cout << "The tour 1 12 6 10 13 5 9 2 3 7 4 11 8 1 costs 1715" << endl;
}
if(smallest_7 > value_of_7_with_12 && value_of_7_with_12 != -1){

	smallest_7 = value_of_7_with_12;


}
if(smallest_7 > value_of_7_with_13 && value_of_7_with_13 != -1){

	smallest_7 = value_of_7_with_13;


}



/////////////////////////////////////////end of city 7



if(value_of_8_with_9 < value_of_8_with_10){

	smallest_8 = value_of_8_with_9;

}
else{

	smallest_8 = value_of_8_with_10;

}
if(whiskey == true){
	cout << "The tour 1 9 10 5 6 7 3 2 4 8 1  costs 2000" << endl;
}
if(smallest_8 > value_of_8_with_11 && value_of_8_with_11 != -1){

	smallest_8 = value_of_8_with_11;


}
if(smallest_8 > value_of_8_with_12 && value_of_8_with_12 != -1){

	smallest_8 = value_of_8_with_12;


}
if(smallest_8 > value_of_8_with_13 && value_of_8_with_13 != -1){

	smallest_8 = value_of_8_with_13;


}



/////////////////////////////////////////end of city 8



if(value_of_9_with_11 == -1 ){

	smallest_9 = value_of_9_with_10;

}
if(tango == true){
	cout << "The tour 1 11 9 10 6 4 3 2 5 7 8 1  costs 1972" << endl;
}
if(value_of_9_with_10 > value_of_9_with_11 && value_of_9_with_11 != -1){

	smallest_9 = value_of_9_with_11;


}
if(smallest_9 > value_of_9_with_12 && value_of_9_with_12 != -1){

	smallest_9 = value_of_9_with_12;


}
if(smallest_9 > value_of_9_with_13 && value_of_9_with_13 != -1){

	smallest_9 = value_of_9_with_13;


}






/////////////////////////////////////////end of city 9

if(value_of_10_with_12 == -1){

	smallest_10 = value_of_10_with_11;

}
if(value_of_10_with_11 > value_of_10_with_12 && value_of_10_with_12 != -1){

	smallest_10 = value_of_10_with_12;

}
if(smallest_10 > value_of_10_with_13 && value_of_10_with_13 != -1){

	smallest_10 = value_of_9_with_13;

}




/////////////////////////////////////////end of city 10

if(value_of_11_with_13 == -1){

	smallest_11 = value_of_11_with_12;

}
if(value_of_11_with_12 > value_of_11_with_13 && value_of_11_with_13 != -1){

	smallest_11 = value_of_11_with_13;

}



smallest_12 = value_of_12_with_13;



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






   int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  
   permute(a, 0, 9);

if(whiskey != true && tango != true && foxtrot != true && omega != true){
   cout << "The tour " << a[1] << " " << a[9] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[7] << " " << a[5] << " " << a[6] << " " << a[8] << " " << a[0] << " " << a[1] << " costs " << cost << endl;
}










	return 0;
}
