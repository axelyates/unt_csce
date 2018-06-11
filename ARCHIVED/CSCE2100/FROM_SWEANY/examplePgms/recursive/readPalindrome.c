#include <stdio.h>

int isPal(char [], int, int);

int main()
{
    char word[80];
    scanf("%s",word);
    printf("%s\n",word);
    if( isPal(word, 0, strlen(word)-1) )
       printf("Yes, %s is a palindrome!\n",word);
    else
       printf("No, %s is not a palindrome.\n",word);
}

int isPal(char buffer[], int first, int last)
{
    if( first >= last ) return 1;  // TRUE
    if( buffer[first] != buffer[last] )
	return 0;	// FALSE
    else
	return isPal(buffer, first+1, last -1);
}
