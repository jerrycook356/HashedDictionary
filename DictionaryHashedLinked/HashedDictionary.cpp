#include "pch.h"
#include "HashedDictionary.h"
#include <list>


template<class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary()
{
	hashTable = new list<KeyType, ItemType>*[DEFAULT_SIZE];
}

template<class KeyType,class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& key)const
{
	
}