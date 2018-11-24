#include "pch.h"
#include "HashedEntry.h"


template<class KeyType,class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry() :nextPtr(nullptr)
{

}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(KeyType newSearchKey, ItemType newEntry)
{
	item = newEntry;
	searchKey = newSearchKey;

}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(KeyType searchKey, ItemType newEntry, HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
	searchKey = searchKey;
	item = newEntry;
	nextPtr = nextEntryPtr;

}

template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr)
{
	nextPtr = nextEntryPtr;
}

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType> HashedEntry<KeyType, ItemType>::getNext()
{
	return nextPtr;
}
