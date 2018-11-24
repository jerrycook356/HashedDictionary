/**@file Entry.cpp*/
#include"pch.h"
#include "Entry.h"

template<class KeyType,class ItemType>
Entry<KeyType, ItemType>::Entry()
{

}

template<class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(KeyType& newKey, ItemType & newEntry)
{
	searchKey = newKey;
	item = newEntry;
}

template<class KeyType, class ItemType>
ItemType  Entry<KeyType, ItemType>::getItem() const
{
	return item;
}

template<class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey()const
{
	return searchKey;
}

template<class KeyType,class ItemType>
void Entry<KeyType,ItemType>:: setItem(const ItemType& newItem)
{
	item = newItem;
}

template<class KeyType,class ItemType>
bool Entry<KeyType,ItemType>::operator == (const Entry<KeyType, ItemType>& rightHandItem)const
{
	return searchKey == rightHandItem.getKey();
}

template<class KeyType,class ItemType>
bool Entry<KeyType, ItemType>::operator  > (const Entry<KeyType, ItemType>& rightHandItem)const
{
	return searchKey > rightHandItem.getKey();
}