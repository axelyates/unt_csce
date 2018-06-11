#include <stdio.h>	//necessary includes
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


#ifndef HASH_H
#define HASH_H

class hash{

	private:

		struct item{

			string name;
			item* next;

		};

		item* Hash_Table[10];

	public:

		hash();				//hash constructor
		~hash();			//hash destructor
		string input;			//string variable to hold data read in
		int Hash(string key);		//hash function
		void Insert(string number);	//insert function
		void Print_Table();		//print function
		void Search(string name);	//search function
		void Find();			//find function
		void Remove_Item(string name);	//remove function
		void Push(int count);		//push function
		void Pop(int count);		//pop function

};


#endif /* HASH_H */
