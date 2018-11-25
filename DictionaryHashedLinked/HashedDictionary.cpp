#include "pch.h"
#include "HashedDictionary.h"
#include <string>
#include <math.h>





template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
{
	hashTable = new HashedEntry<KeyType, ItemType>*[DEFAULT_SIZE];
	for (int i = 0 ;i < DEFAULT_SIZE;i++)
	{
		hashTable[i] = nullptr;
	}
}

template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear()
{
	delete[]hashTable;
	hashTable = nullptr;
	hashTable = new HashedEntry<KeyType, ItemType>*[DEFAULT_SIZE];
	for (int i = 0;i < DEFAULT_SIZE;i++)
	{
		hashTable[i] = nullptr;
	}
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::ifEntryExists(HashedEntry<KeyType, ItemType>* checkPtr,int hashIndex)
{
	

	bool found = false;
	HashedEntry<KeyType, ItemType>* curPtr = hashTable[hashIndex];
	HashedEntry<KeyType, ItemType>* tempPtr = checkPtr;
	if (curPtr->getKey() ==  tempPtr->getKey()) //first entry on chain matches entry to be added
	{
		found = true;
		
	}
	else
	{
		
		while ((curPtr->getNext() != nullptr)&& (!found))
		{
			curPtr = curPtr->getNext();
			if (curPtr == tempPtr)
				found = true;

		}
	}
	
	if(found)
		cout << endl << " item with key = " << tempPtr->getKey() << " not added, it allready exists.";
	return found;
}

template<class KeyType,class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& key)const
{
	int stringLength = key.length();
	int searchKey = 0;
	for (int letters = 0; letters < stringLength;letters++)
	{
		for (int powers = stringLength;powers > 0;powers--)
		{
			int letterNumber = key[letters];
			int numberToMultiply = pow(32, powers);
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
		itemCount++;
	}
	else 
	{
		//item only added to hashTable if it is unique, no duplicates
		if (!ifEntryExists(entryToAddPtr, itemHashIndex))
		{
			entryToAddPtr->setNext(hashTable[itemHashIndex]);
			hashTable[itemHashIndex] = entryToAddPtr;
			itemCount++;
		}
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
	if (itemFound)
		itemCount--;
	return itemFound;
}
template<class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType & searchKey)const throw(NotFoundException)
{
	int hashedIndex = getHashIndex(searchKey);
	ItemType foundItem;
	bool found = false;
	 
	HashedEntry<KeyType, ItemType>* curPtr = hashTable[hashedIndex];
	if (curPtr == nullptr) //chain is empty
	{
		throw new NotFoundException(" ");
	}
	else
	{
		if (curPtr->getKey() == searchKey) //first node in the chain matches the search key
		{
			foundItem = curPtr->getItem();
			found = true;
		}
		else
		{
			while ((curPtr != nullptr) && (!found))
			{
				curPtr = curPtr->getNext();
				if (curPtr->getKey() == searchKey)
				{
					found = true;
					foundItem = curPtr->getItem();
				}
				
			}

		}
		if (!found)
		{
			throw new NotFoundException(" ");
			foundItem = -1;
		}
	}
	return foundItem;
}
template<class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType & searchKey) const
{
	bool found = false;
	HashedEntry<KeyType, ItemType>* curPtr = hashTable[0];
	for (int i = 0; i < DEFAULT_SIZE;i++)
	{
		curPtr = hashTable[i];
		if (curPtr->getKey() == searchKey)
		{
			found = true;
		}

	}
	return found;
}
template<class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::traverse(void visit(ItemType&)) const
{
	for (int i = 0; i < DEFAULT_SIZE;i++)
	{
		
		HashedEntry<KeyType, ItemType>* curPtr = hashTable[i];
		if (curPtr != nullptr)
		{
			ItemType item = curPtr->getItem();
			visit(item);
		}
	}
}
//end remove


template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::~HashedDictionary()
{
	delete[] hashTable;
	hashTable = nullptr;
}

template<class KeyType,class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems()const
{
	return itemCount;
}

