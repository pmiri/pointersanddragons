//! @file 
//! @brief Header file for the ItemContainer class  
//! Item containers are little more than specialized vectors
//! Containers can give you items, but only based off the type of item
//! Not well-suited to holding multiple items!
//! Note that items have no weight, unlike the official D20 rules.

#ifndef ItemContainer_h
#define ItemContainer_h
#include <string>
#include<vector>
using namespace std;
#include "Item.h"

//! Class that implements an item container
class ItemContainer
{
public:
	// Default constructor
	ItemContainer();
	// Constructor
	ItemContainer(vector<Item> items);
	// method to get the items of the container
	vector<Item> getItems();
	// method to add an item to the item container
	void addItem(Item anitem);
	// method to get an item from the item container
	Item getItem(string itemType);
protected:
	vector<Item> Items;
};
#endif

