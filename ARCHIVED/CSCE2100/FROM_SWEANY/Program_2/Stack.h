#include "Link.h"
#include "HashTable.h"

class Stack
{
    Stack();
    ~Stack();

    void push(HashTable& ht);   
           // Hash Tables are the "elements" of the stack

    HashTable& pop ();    // removes the top of the stack

    HashTable& top ();    // merely returns a reference to the
                          // top of the stack.  Doesn't really
			  // remove it.
};
