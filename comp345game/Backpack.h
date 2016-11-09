//! @file 
//! @brief Header file for the backpack class
//! This is analagous to a backpack, items which are carried by the character
//! As per the d20 rules, any number of items can be in the backpack, duplication is permitted

#ifndef Backpack_h
#define Backpack_h
#include <string>
#include <vector>
using namespace std;
#include "ItemContainer.h"

//! Class that implements an item container
class Backpack : public ItemContainer
{
public:
	// Default constructor
	Backpack();
	// Constructor
	Backpack(vector<Item> items);
	// method to get the items of the container
	vector<Item> getItems();
	// method to add an item to the item container
	void addItem(Item anitem);
	// method to get an item from the item container
	Item selectItem(char dir);
	Item takeItem(char dir);
	Item replaceItem(Item anItem);
private:
	vector<Item> Items;
};
#endif

