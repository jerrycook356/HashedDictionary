#pragma once
#include"pch.h"
#include "HashedEntry.h"

template<class KeyType,class ItemType>
class HashList
{
private:
	HashedEntry<KeyType, ItemType>* headPtr;
	int itemCount;

public:
	HashList();
	bool insert(HashedEntry<KeyType,ItemType>* newEntryPtr);
	HashedEntry<KeyType, ItemType> getNext();
	bool remove();
	bool clear();
	~HashList();

};
#include "HashList.cpp"