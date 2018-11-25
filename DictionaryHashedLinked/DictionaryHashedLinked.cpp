// DictionaryHashedLinked.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "HashedDictionary.h"

void visit(string& item)
{
	cout << endl << endl << " the item is = " << item;
}

using namespace std;
int main()
{
	HashedDictionary<string, string>* symbols = new HashedDictionary<string, string>();

	
}

/**Because you add an item to the dictionary only if its search key is not already present, does the time required
for an insertion increase?  
The time required does not increase, because you only add if the item does not exist. This way
the item is adde in the first position in the index. No searching or iterating through the 
lists would be needed. */


