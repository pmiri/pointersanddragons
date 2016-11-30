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

ItemContainer::ItemContainer(int lvl, string desc) {
	int chance = 0, bonus = 0;

	//Helmet
	chance = randomIntRange(0, 10);
	if (chance < 4) {
		Item treasureitem = Item("Helmet", desc + " Helm", lvl);
		Items.push_back(treasureitem);
	}

	//Armor
	chance = randomIntRange(0, 10);
	if (chance < 4) {
		Item treasureitem = Item("Armor", desc + " Armor", lvl);
		Items.push_back(treasureitem);
	}

	//Shield
	chance = randomIntRange(0, 10);
	if (chance < 4) {
		Item treasureitem = Item("Shield", desc + " Shield", lvl);
		Items.push_back(treasureitem);
	}

	//Ring
	chance = randomIntRange(0, 10);
	if (chance < 4) {
		Item treasureitem = Item("Ring", desc + " Wedding Ring", lvl);
		Items.push_back(treasureitem);
	}

	//Belt
	chance = randomIntRange(0, 10);
	if (chance < 4) {
		Item treasureitem = Item("Belt", desc + " Belt", lvl);
		Items.push_back(treasureitem);
	}

	//Boots
	chance = randomIntRange(0, 10);
	if (chance < 4) {
		Item monsterHelm = Item("Boots", desc + " Footwear", lvl);
		Items.push_back(monsterHelm);
	}

	//Weapon
	chance = randomIntRange(0, 10);
	if (chance < 6) {
		Item treasureitem = Item("Weapon", desc + " Sword", lvl);
		Items.push_back(treasureitem);
	}
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

int ItemContainer::randomIntRange(int min, int max) {
	int random = (rand() % (int)(max - min + 1));
	int randomInt = min + random;
	return randomInt;
}