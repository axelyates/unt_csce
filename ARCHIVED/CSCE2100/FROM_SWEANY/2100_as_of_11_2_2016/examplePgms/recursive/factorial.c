#include <stdio.h>

int fact(int n)
{
   if( n == 1 ) return 1;

   return (n * fact(n-1));
}

int main()
{
    int i;

    for( i = 1; i <= 10; i++ )
    {
	printf("%2d factorial = %8d\n",i,fact(i));
    }
}
