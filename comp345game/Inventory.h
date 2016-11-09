//! @file 
//! @brief Header file for the Inventory class
//! This is analagous to "worn items", items which are currently equipped
//! As per the d20 rules, only one item of each type may be worn.

#ifndef Inventory_h
#define Inventory_h
#include <string>
#include <vector>
using namespace std;
#include "ItemContainer.h"

//! Class that implements an item container
class Inventory : public ItemContainer
{
public:
	// Default constructor
	Inventory();
	// Constructor
	Inventory(vector<Item> items);
	// method to get the items of the container
	vector<Item> getItems();
	// method to add an item to the item container
	void addItem(Item anitem);
	// method to get an item from the item container
	Item getItem(string itemType);
	vector<Enhancement> getBonuses();
	Item replaceItem(Item anItem);
private:
	Item helmet, armor, shield, ring, belt, boots, weapon;
	vector<Item> Items;
};
#endif

