/**A class of entry objects for an implementation of the ADT dictionary
@file Entry.h*/
#pragma once
#include"pch.h"

template<class KeyType,class ItemType>
class Entry
{
private:
	ItemType item;
	KeyType searchKey;

protected:
	void setKey(const KeyType& searchKey);
public:
	Entry();
	Entry(KeyType& searchKey, ItemType& newEntry);
	ItemType getItem()const;
	KeyType getKey() const;
	void setItem(const ItemType& newEntry);

	bool operator == (const Entry<KeyType, ItemType>& rightHandItem)const;
	bool operator > (const Entry<KeyType, ItemType>& rightHandItem)const;


};
#include "Entry.cpp"
