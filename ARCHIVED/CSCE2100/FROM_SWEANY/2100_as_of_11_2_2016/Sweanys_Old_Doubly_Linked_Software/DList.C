// ***********************************************************************
//
//   DList.C --- defines the base classes DLink and DList, used together 
//              to build all the derived list classes.
//
// Classes included: DLink, DList, DList_iterator.
//
// History --- initial coding 3/14/97 by Philip Sweany
//
// No rights reserved.
//
// ***********************************************************************

#include "DList.h"

// ***********************************************************************
// 
//   Class DLink --- the element of a doubly linked list.
// 
// ***********************************************************************

// -----------------------------------------------------------------------
// 
//   DLink --- the constructor
// 
// -----------------------------------------------------------------------
   DLink::DLink()
   {
      next = NULL;
      previous = NULL;
   }


// -----------------------------------------------------------------------
// 
//   ~DLink --- the destructor
// 
// -----------------------------------------------------------------------
   DLink::~DLink()
   {
      previous = next = NULL;
   }


// -----------------------------------------------------------------------
// 
//   Insert --- inserts a new element, in front of this one.
// 
// -----------------------------------------------------------------------
   void DLink::insert(DLink* element)
   {
      // WARNING!!! If "this" is already the start of a list
      //            this method will DESTROY the list's consistency
      //            because we have no way to update the list's head

      element->previous = previous;
      element->next = this;
      if( previous )
      {
	 previous->next = element;
      }
      else
      {
	 cout << "Warning:  DLink::insert is adding an element to the start "
	      << "of the list but NOT updating the list's head ptr.\n";
      }
      previous = element;
   }


// -----------------------------------------------------------------------
// 
//   Append --- appends a new element, after this one.
// 
// -----------------------------------------------------------------------
   void DLink::append(DLink* element)
   {
      // WARNING!!! If "this" is already the end of a list
      //            this method will DESTROY the list's consistency
      //            because we have no way to update the list's tail

      element->next = next;
      element->previous = this;
      if( next )
      {
	 next->previous = element;
      }	
      else
      {
	 cout << "Warning:  DLink::append is adding an element to the end "
	      << "of the list but NOT updating the list's tail ptr.\n";
      }
      next = element;
   }


// -----------------------------------------------------------------------
// 
//   Duplicate --- make a duplicate of this link.  This is a virtual routine.
// 
// -----------------------------------------------------------------------
   DLink* DLink::duplicate()
   {
      // nothing to do
   }


// -----------------------------------------------------------------------
// 
//   Equal --- a Boolean method which returns true iff this "matches"
//        the parameter link.
// 
// -----------------------------------------------------------------------
   Boolean DLink::equal(DLink* link)
   {
      return FALSE;
   }


// -----------------------------------------------------------------------
// 
//   Remove --- removes this element from the list to which it belongs.
// 
// -----------------------------------------------------------------------
   DLink* DLink::remove()
   {
      // WARNING!!! If "this" is already the start or tail of a list
      //            this method will DESTROY the list's consistency
      //            because we have no way to update the list's head or tail

      if( previous )
      {
         previous->next = next;
      }
      else
      {
	 cout << "Warning:  DLink::remove is removing element from the start "
	      << "of the list but NOT updating the list's head ptr.\n";
      }
      if( next )
      {
         next->previous = previous;
      }
      else
      {
	 cout << "Warning:  DLink::remove is removing an element from the end "
	      << "of the list but NOT updating the list's tail ptr.\n";
      }
      return this;
   }


// -----------------------------------------------------------------------
// 
//   Print --- "print" the link.
// 
// -----------------------------------------------------------------------
   void DLink::print()
   {
	// nothing to do
   }



// ***********************************************************************
// 
//   Class DList --- the base class for doubly linked lists
// 
// ***********************************************************************

// -----------------------------------------------------------------------
// 
//   DList --- the constructor
// 
// -----------------------------------------------------------------------
   DList::DList()
   {
      head = tail = NULL;
   }


// -----------------------------------------------------------------------
// 
//   DList --- the constructor which returns DLists, passes DLists as args, etc.
// 
// -----------------------------------------------------------------------
   DList::DList(DList& l)
   {
      operator=(l);
   }


// -----------------------------------------------------------------------
// 
//   ~DList --- the destructor
// 
// -----------------------------------------------------------------------
   DList::~DList()
   {
      head = tail = NULL;
   }


// -----------------------------------------------------------------------
// 
//   Insert --- inserts a new element, at front of the list.
// 
// -----------------------------------------------------------------------
   void DList::insert(DLink* element)
   {
      if( head == NULL )
      {
	 head = tail = element;
      }
      else
      {
         element->next = head;
	 head->previous = element;
	 head = element;
      }
   }


// -----------------------------------------------------------------------
// 
//   Append --- appends a new element, at the back of the list.
// 
// -----------------------------------------------------------------------
   void DList::append(DLink* element)
   {
      if( head == NULL )
      {
	 head = tail = element;
      }
      else
      {
         element->previous = tail;
	 tail->next = element;
	 tail = element;
      }
   }


// -----------------------------------------------------------------------
// 
//   Find --- searches the list for an element equal to the incoming
//            DLink and returns a pointer to the element if one is
//            found.  
// 
// -----------------------------------------------------------------------
   DLink* DList::find(DLink* link, Boolean reverse)
   {
      DList_iterator it(*this,reverse);
      DLink* element;
      while(element = ++it)
      {
	 if( link->equal(element) )
	    return element;
      }
      return NULL;
   }


// -----------------------------------------------------------------------
// 
//   Size --- returns the size of the list
// 
// -----------------------------------------------------------------------
   int DList::size()
   {
      int length = 0;
      DList_iterator it(*this);
      DLink* element;
      while(element = ++it)
      {
	 length++;
      }
      return length;
   }


// -----------------------------------------------------------------------
// 
//   Is_empty --- returns True iff this is the empty list.
// 
// -----------------------------------------------------------------------
   Boolean DList::is_empty()
   {
      return (head == NULL);
   }


// -----------------------------------------------------------------------
//
//   Front --- return the first element on the list but don't remove it.
//
// -----------------------------------------------------------------------
   DLink* DList::front()
   {
      return head;
   }
 
 
// -----------------------------------------------------------------------
//
//   Rear --- return the last element on the list but don't remove it.
//
// -----------------------------------------------------------------------
   DLink* DList::rear()
   {
      return tail;
   }
 
// -----------------------------------------------------------------------
//
//   Remove_rear --- remove the last element on the list and return it.
//
// -----------------------------------------------------------------------
   DLink* DList::remove_rear()
   {
      DLink* temp = tail;
      if( ! tail )
         return tail;
      if( head == tail )
      {
	 head = tail = NULL;
	 return temp;
      }
      tail = tail->previous;
      tail->next = NULL;
      temp->previous = NULL;
      return temp;
   }
 
 
// -----------------------------------------------------------------------
//
//   Remove_front --- remove the first element on the list and return it.
//
// -----------------------------------------------------------------------
   DLink* DList::remove_front()
   {
      DLink* temp = head;
      if( ! tail )
         return tail;
      if( head == tail )
      {
	 head = tail = NULL;
	 return temp;
      }
      head = head->next;
      head->previous = NULL;
      temp->next = NULL;
      return temp;
   }
 
 
// -----------------------------------------------------------------------
// 
//   Remove --- removes this element from the list to which it belongs.
// 
// -----------------------------------------------------------------------
   DLink* DList::remove(DLink* link)
   {
      if( link == head )
	 return remove_front();

      if( link == tail )
	 return remove_rear();

      return link->DLink::remove();
   }


// -----------------------------------------------------------------------
//
//  Clear --- clears the list, deleting each element of the list.
//
// -----------------------------------------------------------------------
   void DList::clear()
   {
      while( head )
	 delete remove_front();
   }
 
 
// -----------------------------------------------------------------------
// 
//   = --- copies a list.
// 
// -----------------------------------------------------------------------
   DList& DList::operator=(DList& l)
   {
      DList_iterator it(l);
      DLink* element;
      while(element = ++it)
      {
	 append(element->duplicate());
      }
      return *this;
   }


// -----------------------------------------------------------------------
// 
//   Print --- "print" the list.
// 
// -----------------------------------------------------------------------
   void DList::print()
   {
      DList_iterator it(*this);
      DLink* element;
      while(element = ++it)
      {
	 element->print();
      }
      cout << endl;
   }



// ***********************************************************************
// 
//   Class DList_iterator --- a class to move through a list, forwards
//                           or backwards.
// 
// ***********************************************************************


// -----------------------------------------------------------------------
// 
//   DList_iterator --- the constructor
// 
// -----------------------------------------------------------------------
   DList_iterator::DList_iterator
   (
      DList& list,
      Boolean reverse
   )
   {
      if(reverse)
	current = list.rear();
      else
	current = list.front();
   }


// -----------------------------------------------------------------------
// 
//   Next_element(overloaded to ++) --- returns the next element in the list.
// 
// -----------------------------------------------------------------------
   DLink* DList_iterator::operator++()
   {
      if( current )
      {
         DLink* temp = current;
         current = current->next;
         return temp;
      }
      return current;
   }


// -----------------------------------------------------------------------
// 
//   Previous_element(overloaded to ++) --- returns previous element in list.
// 
// -----------------------------------------------------------------------
   DLink* DList_iterator::operator--()
   {
      if( current )
      {
         DLink* temp = current;
         current = current->previous;
         return temp;
      }
      return current;
   }
