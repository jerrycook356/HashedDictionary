#pragma once
#include "pch.h"
#include"DictionaryInterface.h"
#include "HashedEntry.h"


template<class KeyType,class ItemType>

class HashedDictionary : public DictionaryInterface<KeyType, ItemType>
{

private:
	
	HashedEntry<KeyType, ItemType>** hashTable; //array of pointers to entries
	int itemCount;   // count of dictionary entries
	int hashTableSize; //table size must be prime
	static const int DEFAULT_SIZE = 101;

public :
	HashedDictionary();
	int getHashIndex(const KeyType& key)const;


};