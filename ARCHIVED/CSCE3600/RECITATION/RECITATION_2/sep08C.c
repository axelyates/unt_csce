#include <stdio.h>
int main()
{
  FILE* fp;
  fp = fopen("example.txt", "w");
  fputs("This is an apple.", fp);
  fseek(fp, 9, SEEK_SET);
  fputs(" sam", fp);
  fclose(fp);
  return 0;
}

