#pragma once
#include "pch.h"
#include "HashedEntry.h"
#include "NotFoundException.h"
#include "DictionaryInterface.h"


template<class KeyType,class ItemType>

class HashedDictionary :public DictionaryInterface<KeyType,ItemType> 
{

private:
	
	HashedEntry<KeyType, ItemType>** hashTable; //array of pointers to entries
	int itemCount;   // count of dictionary entries
	int hashTableSize; //table size must be prime
	static const int DEFAULT_SIZE = 101;
	bool ifEntryExists(HashedEntry<KeyType, ItemType>* checkPtr,int hashIndex);

public :
	HashedDictionary();
	void clear();
	bool isEmpty()const;
	int getNumberOfItems()const;
	int getHashIndex(const KeyType& key)const;
	bool add(const ItemType& newItem, const KeyType& searchKey);
	bool remove(const KeyType& searchKey);
	ItemType getItem(const KeyType& searchKey)const throw(NotFoundException);
	bool contains(const KeyType& searchKey) const;
	void traverse(void visit(ItemType&)) const;
	
	~HashedDictionary();



};
#include "HashedDictionary.cpp"