#include <stdio.h>

int main()
{
    int i,j,sum;

    i = 1;
    while( i <= 199998 )
    {
	sum = 0;
	j = i;
        while( sum < 1000000 )
        {
	    sum += j;
            j++;
        }
	if( sum == 1000000 )
	{
	    printf("The numbers from %d to %d fit the criteria\n",i,j-1);
	}
	++i;
    }
    return 0;
}
