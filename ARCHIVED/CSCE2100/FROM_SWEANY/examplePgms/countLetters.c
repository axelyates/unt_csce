#include <stdio.h>
#define LINES 65

int main()
{
    char lines[LINES][81];
    int letters[26];
    int i,j;
    for(i = 0; i < 26; i++)
	letters[i] = 0;
    for(i = 0; i < LINES; i++)
    {
        for(j = 0; j < 80; j++)
        {
	    scanf("%c",&lines[i][j]);
            if ( lines[i][j] >= 'a' && lines[i][j] <= 'z' )
		letters[lines[i][j]-'a']++;
            if ( lines[i][j] == '\n' )
	        break;
        }
	lines[i][j+1] = '\0';
    }
    for(i = 0; i < 26; i++)
    {
	printf("We found %4d instances of \t %c\n",letters[i], 'a' + i);
    }
    return 0;
}
