#include "Link.h"

class HashTable : public Link
{
   public :
    // functions
    HashTable();         // constructor
    HashTable(int size); // alternate constructor
    ~HashTable();        // destructor

    int search(int key);    
    void insert(int key);    

    int hash (int key);
    
   private :
    // data

    int *theTable;
    int count;
};
