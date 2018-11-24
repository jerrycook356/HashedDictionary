#include "pch.h"
#include "HashList.h"
#include "HashedEntry.h"

template<class KeyType,class ItemType>
HashList<KeyType, ItemType>::HashList() :itemCount(0), headPtr(nullptr)
{

}

template<class KeyType,class ItemType>
bool HashList<KeyType, ItemType>::insert(HashedEntry<KeyType, ItemType>* newEntryPtr)
{
	if (headPtr == nullptr)
	{
		headPtr = newEntryPtr;
	}
	else
	{
		HashedEntry<KeyType, ItemType>* tempPtr = headPtr;
		headPtr = newEntryPtr;
		headPtr->setNext(tempPtr);
	}

}

template<class KeyType, class ItemType>
bool HashList<KeyType, ItemType>::remove()
{
	return false;
}

template<class KeyType, class ItemType>
bool HashList<KeyType, ItemType>::clear()
{
	return false;
}

template<class KeyType, class ItemType>
HashList<KeyType, ItemType>::~HashList()
{
}
