#include "HashTable.h"

    HashTable::HashTable()
    {
        int i;
        theTable = new int[100]; 
        for( i = 0; i < 100; i++ )
            theTable[i] = -1;       
    }
        
    HashTable::HashTable(int size)
    {
        int i;
        theTable = new int[size]; 
        for( i = 0; i < size; i++ )
            theTable[i] = -1;       
    }

    HashTable::~HashTable()
    {
	// nothing to do -- or is there?
    }


    int HashTable::search(int key)
    {
		// you figure it out
		return -1;   // failure
    } 

    void HashTable::insert(int key)
    {
		// you figure it out
    }
    

    int HashTable::hash(int key)
    {
        return key % count;    // change if you want.
    }
