// memcpy example
#include <stdio.h>
#include <string.h>

int main()
{
   char src[ ] = "*************************";
   char dest[ ] = "abcdefghijlkmnopqrstuvwxyz01234";
   char *ptr;
   printf("destination before memcpy: %s\n", dest);
   ptr = (char *) memcpy(dest, src, strlen(src));
   if (ptr)
      printf("destination after memcpy: %s\n", dest);
   else
      printf("memcpy failed\n");
   return 0;
}

