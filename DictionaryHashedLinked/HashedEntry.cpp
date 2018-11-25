#include "pch.h"
#include "HashedEntry.h"



template<class KeyType,class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry() :nextPtr(nullptr)
{

}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry,KeyType newSearchKey)
{
	item = newEntry;
	searchKey = newSearchKey;

}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry,KeyType newSearchKey, HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
	searchKey = newSearchKey;
	item = newEntry;
	nextPtr = nextEntryPtr;

}

template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
	nextPtr = nextEntryPtr;
}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>* HashedEntry<KeyType, ItemType>::getNext()
{
	return nextPtr;
}

template<class KeyType, class ItemType>
KeyType HashedEntry<KeyType, ItemType>::getKey()
{
	return searchKey;
}


template <class KeyType,class ItemType>
ItemType HashedEntry<KeyType, ItemType>::getItem()
{
	return item;
}

