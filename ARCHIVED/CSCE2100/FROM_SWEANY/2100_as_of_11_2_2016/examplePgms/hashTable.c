#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 100

int h1(int k)
{
    return k % TABLESIZE;
}

int h2(int k)
{
    return 1;
}

int search(int htable[TABLESIZE], int key)
{
    int index;
    int inc;

    index = h1(key);  
    inc = h2(key); 

    while (1) 
    {
	if ( htable[index] == key )
	      return index;
        else if (htable[index] == -1 ) // search failure
	      return index;
        else
	      index = (index + inc) % TABLESIZE;
    }
}


void insert(int htable[TABLESIZE], int key)
{
    int index;
    index = search(htable,key);
    
    if (htable[index] == -1) 
        htable[index] = key;
    else
    {
	printf("Key %d already in the table\n",key);
    }
}

int main()
{
    int A[TABLESIZE];
    int i, inputSize, key;
    int numSearches = 0;

    scanf("%d",&inputSize);
    
    for(i = 0; i < TABLESIZE; i++)
	A[i] = -1;

// First, insert 
    while( scanf("%d",&key) != EOF )
    {
        if( key == -1 ) 
            break;  // stop inserting and start searching from here
        insert(A,key);
    }

// Now search for data repeatedly

    while( scanf("%d",&key) != EOF )
    {
        i = search(A,key);
        numSearches++;
    }
    printf("We completed %d searches of the hash table\n",numSearches);

}
