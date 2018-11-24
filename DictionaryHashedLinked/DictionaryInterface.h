/**An interface for the ADT dictionary
@file DictionaryInterface.h*/
#pragma once
#include"pch.h"
#include "NotFoundException.h"


template<class KeyType,class Itemtype>
class DictionaryInterface
{
public:
	/**Sees whether this dictionary is empty
	@returns true if the dictionary is empty false otherwise*/
	virtual bool isEmpty()const = 0;

	/**Gets the number of items in this dictionary 
	@return the number of items in the dictionary*/
	virtual int getNumberOfItems() const = 0;

	/**Inserts an item int this dictionary according to the items search key
	@pre the search key of the new item didfes from all search keys presently in the dictionary
	@post if the insertion is successful, new Item is in its proper position within the dictionary
	@param searchKey the search key associated wit the item to be inserted
	@param newItem teh item to add to the dictionary
	@return true if th item was successfully added or false otherwise*/
	virtual bool add(const KeyType& searchKey, const ItemType& newItem) = 0;

	/**Removes an item with the given search key form this dictionary
	@post if the item whose search key equals searcKey existed in
	the dictionary, the item was removed.
	@pararm searchKey teh search key of the time to be removed.
	@ return true if the operation is successfull false otherwise*/
	virtual bool  remove(const KeyType& searchKey)  = 0;

	/**Remove all entries from the dictionary*/
	virtual void clear() = 0;

	/**Retrieves an item with the given search key from a dictionary.
	@post if the retrieval is successful, the item is returned
	@param searchKey the search key of the item to be retrieved
	@return the item associated with the search key
	@throw NotFoundException if the item does not exist.*/
	virtual ItemType getItem(const KeyType& searchKey) const throw(NotFoundException) = 0;

	/**sees whether this dictionary contains an item with a given search key
	@post the dictionary is unchanged
	@param searchKey the search key of the item to be retrieved.
	@return true if an item with the given search key exists in the dictionary.*/
	virtual bool contains(const KeyType& searchKey) const = 0;

	/**Traverses this dictionary and calls a given client function once for each item
	@post the given function's action occurs once for each item in the dictionary
	and possible alters the item
	@param visit a client function*/
	virtual void traverse(void visit(ItemType&)) const = 0;
};
