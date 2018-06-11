#include <stdio.h>
#include <stdlib.h>

int main()
{	FILE *fp;
	char c;
	fp = fopen("INPUT", "a"); 	/* open file for writing */
	if (fp == NULL)
	{
		printf("Error: Unable to open file INPUT\n");
		exit(EXIT_FAILURE);
	}
	
	while((c=getchar()) != EOF) 	/*get char from keyboard 												until CTL-D*/
		putc(c,fp); 			/*write a character to INPUT */
	
	fclose(fp); 	 				/* close INPUT */
	fp = fopen("INPUT", "r"); 	/* reopen file */
	
	while((c =getc(fp))!=EOF) 	/* read character from file 											INPUT */
		printf("%c", c);		/* print character to screen */
	
	fclose(fp);
} /* end main */

