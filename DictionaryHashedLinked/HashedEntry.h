/**A class of entry objects for a hashing implemntation of the ADT dictionary
*@file HashedEntry.h*/

#pragma once
#include "pch.h"
#include "Entry.h"


template<class KeyType,class ItemType>
class HashedEntry :public Entry<KeyType, ItemType>
{
private:
	HashedEntry<KeyType, ItemType>* nextPtr;
public:
	HashedEntry();
	HashedEntry(KeyType searchKey, ItemType newEntry);
	HashedEntry(KeyType  searchKey, ItemType newEntry, HashedEntry<KeyType, ItemType>* nextEntryPtr);
	void setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr);
	HashedEntry<KeyType, ItemType> getNext();
};
#include "HashedEntry.cpp"
