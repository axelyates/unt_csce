/*****************************************************************************/
//
//  Set.h --- supplied by Phil Sweany, 1/21/2017
//
//  No rights reserved                           
//
/*****************************************************************************/

//#pragma once
using namespace std;
#include <iostream>
#include <assert.h>
#include <stdio.h>

#define NUM_WORDS 5

class Set 
{
	public :

	Set();
	Set(const Set& s);	// copy constructor
	~Set();
	void clear();
	void addToSet(int i);
	void removeFromSet(int i);
	int cardinality();
	int is_member(int i);
	void operator=(const Set& s);   // copy a set
	Set operator&(const Set& s);	// intersection
	Set operator|(const Set& s);	// union
	Set operator^(const Set& s);	// exclusive OR
	Set operator-(const Set& s);	// set difference

	void printSet();
	void debug();

    private:   
               unsigned int bitString[NUM_WORDS];
};

