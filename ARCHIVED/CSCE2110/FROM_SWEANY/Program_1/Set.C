/*****************************************************************************/
//
//  Set.C --- supplied by Phil Sweany, 1/23/2017
//
//  No rights reserved                           
//
/*****************************************************************************/

#include "Set.h"

	Set::Set()
        {
		int i;
                for(i = 0; i < NUM_WORDS; i++)
			bitString[i] = 0;
        }


	Set::Set(const Set& s)
        {
		int i;
                for(i = 0; i < NUM_WORDS; i++)
			bitString[i] = s.bitString[i];
        }

	
	Set::~Set()
        {
		int i;
                for(i = 0; i < NUM_WORDS; i++)
			bitString[i] = 0;
        }

	void Set::clear()
        {
		int i;
                for(i = 0; i < NUM_WORDS; i++)
			bitString[i] = 0;
        }

	void Set::addToSet(int i)
        {
		unsigned int mask = 0;
                int word;
                int bit;

                if( i == 0)
                {
		     word = 0; 
                     bit = 0;
                     mask = 1;
                }
                else
                {
			word = i / 32;	// word of bit we're going to access?
			bit = i % 32;   // bit in word we are going to set?
			mask = 1 << bit;
                }
                bitString[word] = bitString[word] | mask; 
        }


	void Set::removeFromSet(int i)
        {
	    if( is_member(i) )
            {
		int word = i / 32;
		int bit = i % 32;
		unsigned mask = 1 << bit;
		bitString[word] = bitString[word] ^ mask;
            }
        }


	int Set::cardinality()
        {
		int i;
                int ones = 0;
                for( i = 0; i < NUM_WORDS * 32; i++)
                {
                 	if( is_member(i) )
                        {
				ones++;
                	}
                }

		return ones; 
        }


	int Set::is_member(int i)
        {
		int bit, word;
                unsigned int mask;

                if( i == 0)
                {
		     word = bit = 0;
		     mask = 1 ;
                }
                else
                {
			word = i / 32;	// word of bit we're going to access?
			bit = i % 32;  // bit in word we are going to set?
			mask = 1 << bit;
                }
		if( bitString[word] & mask )
			return 1;
		else 
			return 0;
        }


	void Set::operator=(const Set& s)
        {
		int i;
                for(i = 0; i < NUM_WORDS; i++)
			bitString[i] = s.bitString[i];
        }

   
	Set Set::operator&(const Set& s)
        {
		Set result;
		int i;
                for(i = 0; i < NUM_WORDS; i++)
			result.bitString[i] = bitString[i] & s.bitString[i];
		return result;
        }

	
	Set Set::operator|(const Set& s)
        {
		Set result;
		int i;
                for(i = 0; i < NUM_WORDS; i++)
			result.bitString[i] = bitString[i] | s.bitString[i];
		return result;
        }

	
	Set Set::operator^(const Set& s)
        {
		Set result;
		int i;
                for(i = 0; i < NUM_WORDS; i++)
			result.bitString[i] = bitString[i] ^ s.bitString[i];
		return result;
        }

	
	Set Set::operator-(const Set& s)
        {
                Set result;
		int i;

                for(i = 0; i < 5; i++)
			result.bitString[i] = bitString[i] - s.bitString[i];
	
		return result;	
        }

	void Set::printSet()
        {
		int i;
                int First = 1;	// set for First element in set
                cout << "{";
                for(i = 0; i < NUM_WORDS * 32; i++)
		{
			if( First && is_member(i) )
                        {
				cout << i ;
                                First = 0;
                        }
                        else if( is_member(i) )
				cout << "," <<  " " << i ;
		}
                cout << "}" << endl;
	
		

        }


	void Set::debug()
        {
		printf("Word 0 = %X\n",bitString[0]);
		printf("Word 1 = %X\n",bitString[1]);
		printf("Word 2 = %X\n",bitString[2]);
		printf("Word 3 = %X\n",bitString[3]);
		printf("Word 4 = %X\n",bitString[4]);

        }
