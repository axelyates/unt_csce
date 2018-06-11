#include <stdio.h>

int fib(int n)
{
   if( n == 0 ) return 0;
   if( n == 1 ) return 1;

   return (fib(n-1) + fib(n-2));
}

int main()
{
   int i;

   for(i = 2; i < 50; i++)
       printf("Fib(%d) = %8d\n",i,fib(i));
}
