// **********************************************************
//
//  reverse.c --- takes an non-negative integer and reverses
//
// **********************************************************

#include <stdio.h>
#include <stdlib.h>

int reverseDigits(int);
int main()
{
    int num, seedValue;

    printf("Please enter integer value to seed random()\n");
    scanf("%d",&seedValue);
    srand(seedValue);
    
    num = random() % 1000000000 + 1;	// 1 .. one billion
    printf("%d reversed is, while the reverse number is %d",
	    num, reverseDigits(num));
    printf("\n");
}


int reverseDigits(int n)
{
}
