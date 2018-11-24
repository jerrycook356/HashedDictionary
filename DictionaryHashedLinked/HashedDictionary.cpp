#include "pch.h"
#include "HashedDictionary.h"
#include <string>
#include <math.h>




template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
{
	hashTable = new HashedEntry<KeyType, ItemType>*[DEFAULT_SIZE];
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::ifEntryExists(HashedEntry<KeyType, ItemType>* checkPtr,int hashIndex)
{
	

	bool found = false;
	HashedEntry<KeyType, ItemType>* tempPtr = checkPtr;
	if ((hashTable[hashIndex] == tempPtr) //first entry on chain matches entry to be added
	{
		found = true;
	}
	else
	{
		while ((tempPtr != nullptr)&& (!found))
		{
			tempPtr = tempPtr->getNext();

		}
	}
	
	
	return false;
}

template<class KeyType,class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& key)const
{
	int stringLength = key.length();
	int searchKey;
	for (int letters = 0; letters < stringLength;letters++)
	{
		for (int powers = stringLength;powers > 0;powers--)
		{
			int letterNumber = key[letters];
			int numberToMultiply = pow(15, powers);
			searchKey += letterNumber * numberToMultiply;
		}
	}

	return searchKey % DEFAULT_SIZE;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const ItemType & newItem, const KeyType & searchKey)
{
	//create entry to add to dictionary
	HashedEntry<KeyType, ItemType>* entryToAddPtr = new HashedEntry<KeyType, ItemType>(newItem, searchKey);

	int itemHashIndex = getHashIndex(searchKey);

	//add entry to chain at itemHashIndex;
	if (hashTable[itemHashIndex] == nullptr)
	{
		hashTable[itemHashIndex] = entryToAddPtr;
	}
	else
	{
		//item only added to hashTable if it is unique, no duplicates
		if(!entryAlreadyExists(entryToAddPtr,itemHashIndex))
		entryToAddPtr->setNext(hashTable[itemHashIndex]);
		hashTable[itemHashIndex] = entryToAddPtr;
	}
	return true;
}//end add

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType & searchKey)
{
	bool itemFound = false;
	//computer the hash index of the array
	int itemHashIndex = getHashIndex(searchKey);
	if (hashTable[itemHashIndex] != nullptr)
	{
		//special case firstnode has target
		if (searchKey == hashTable[itemHashIndex]->getKey())
		{
			HashedEntry<KeyType, ItemType>* entryToRemovePtr =
				hashTable[itemHashIndex];
			hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
			delete entryToRemovePtr;
			entryToRemovePtr = nullptr;
			itemFound = true;
		}
		else //search rest of the chain
		{
			HashedEntry<KeyType, ItemType>* prevPtr = hashTable[itemHashIndex];
			HashedEntry<KeyType, ItemType>*curPtr = prevPtr->getNext();
			while ((curPtr != nullptr) && (!itemFound))
			{
				//found item in the chain, remove the entry
				if (searchKey == curPtr->getKey())
				{
					prevPtr->setNext(curPtr->getNext());
					delete curPtr;
					curPtr = nullptr;
					itemFound = true;
				}
				else // look at next entry in the chain
				{
					prevPtr = curPtr;
					curPtr = curPtr->getNext();
				}//end if
			}//end while
		}//end if


	}//end if
}//end remove

template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary()
{
	delete hashTable[];
	hashTable = nullptr;
}

