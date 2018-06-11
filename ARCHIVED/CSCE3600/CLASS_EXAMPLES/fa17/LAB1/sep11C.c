// memset example
#include <string.h>
#include <stdio.h>
//#include <mem.h>

int main()
{
  char buffer[ ] = "Hello world\n";

  printf("Buffer before memset: %s\n", buffer);
  memset(buffer, '*', strlen(buffer) - 1);
  printf("Buffer after memset:  %s\n", buffer);
	return 0;
}

