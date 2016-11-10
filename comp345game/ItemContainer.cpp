//! @file 
//! @brief Implementation file for the ItemContainer class  
//! Item containers are basically vectors for items, but have a few unique methods
//! The main thing about item containers is that they are only ever supposed to contain 
//! one of each kind of item, unlike the D20 rules, where this is managed by equipment weight

#include "ItemContainer.h"

//! default constructor
ItemContainer::ItemContainer()
{
	Items = vector<Item>();
}

//! constructor that takes a vector of items as input to create an ItemContainer
//! @param containeritems: vector of items to put in the new container
ItemContainer::ItemContainer(vector<Item> containeritems)
{
	Items = containeritems;
}

//! method to get the items of the container
//! @return : return the vector of items contained in the ItemContainer
vector<Item> ItemContainer::getItems()
{
	return Items;
}

//! method to add an item to the item container
//! @param anitem : new item to put in the ItemContainer
void ItemContainer::addItem(Item anitem)
{
	Items.push_back(anitem);
}

//! method to return the item of a certain type contained in the ItemContainer
//! assumption: the container can only contain one element of each type
//! @param itemType : type of item to extract from the container
//! @return : item of the specified kind provided in input
Item ItemContainer::getItem(string itemType)
{
	for (int i = 0; i < Items.size(); i++)
		if (Items[i].getType() == itemType)
			return Items[i];
	return Item();
}