#include <stdio.h>

int fib(int n)
{
   int i, last, this, next;

   last = 0;
   this = 1;
   for(i = 2; i < n; i++)
   {
      next =  last + this;
      this = last;
      last = next;
   }
   return next;
}

int main()
{
   int i;

   for(i = 2; i < 50; i++)
       printf("Fib(%d) = %8d\n",i,fib(i));
}
