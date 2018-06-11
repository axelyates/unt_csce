#include "Link.h"    

    Link::Link() // constructor
    {
    }

    Link::~Link() // destructor
    {
    }
       
    Link* Link::getNextLink(Link *link)
    {
        next = link->next;
    }
    
    void Link::setNext(Link *link)
    {
        next = link;
    }
