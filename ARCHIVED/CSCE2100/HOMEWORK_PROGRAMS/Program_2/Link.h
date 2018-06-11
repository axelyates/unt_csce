#pragma once

class Link
{
   public :
    // functions
    Link();        // constructor
    ~Link();       // destructor
    Link* getNextLink(Link *link);
    void setNext(Link *link);

   private :
    // data

    Link * next;
};
