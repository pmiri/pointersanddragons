//! @file 
//! @brief Implementation file for the Item class  
//! Items have a type and a vector of influences, 
//! which determines what they are and what bonuses they grant.
//! Only one item of each time can be added to a slot, as in D20

#include "Item.h"

//! default constructor
Item::Item()
{
	type = "";
	name = "";
	influence = vector<Enhancement>();
	valid = true;
}

//! constructor that receives an item type as a string and a vector containing the enhancements that this item gives
//! @param type_name : string representing the type of item
//! @param influences : vector containing all the characteristics influenced by the item
Item::Item(string type_name, vector<Enhancement> influences)
{
	// ***todo***: this constructor should verify that an new item of a certain type only 
	// enhances a character statistic valid for this item type
	type = type_name;
	name = "Normal " + type;
	influence = influences;
	if (validateItem())
		valid = true;
	else
		valid = false;
}

Item::Item(string type_name, vector<Enhancement> influences, string itemName)
{
	type = type_name;
	name = itemName;
	influence = influences;
	if (validateItem())
		valid = true;
	else
		valid = false;
}

//! method to get the type of the item
//! @return : type of the item
string Item::getType()
{
	return type;
}

//! method to get the influences of the item
//! @return : vector containg the list of stats that the item enhances
vector<Enhancement> Item::getInfluences()
{
	return influence;
}

void Item::setInfluences(vector<Enhancement> newInfluences)
{
	influence = newInfluences;
}

//! method to validate an item, e.g. verify that an new item of a certain type only enhances a character statistic valid for this item type
//! @return : true if the enhancement list is valid according to the rules, false if not
//! Specific item types can only have enhancements of specific kinds, and never below 0 or above 5
bool Item::validateItem()
{
	if (type == "Helmet")
	{
		for each (Enhancement effect in influence)
		{
			if ((effect.getType() != "Intelligence") && (effect.getType() != "Wisdom") && (effect.getType() != "Armor Class") || (effect.getBonus() > 5) || (effect.getBonus() < 0))
				return false;
		}
	}
	else if (type == "Armor")
	{
		for each (Enhancement effect in influence)
		{
			if (effect.getType() != "Armor Class" || (effect.getBonus() > 5) || (effect.getBonus() < 0))
				return false;
		}
	}
	else if (type == "Shield")
	{
		for each (Enhancement effect in influence)
		{
			if (effect.getType() != "Armor Class" || (effect.getBonus() > 5) || (effect.getBonus() < 0))
				return false;
		}
	}
	else if (type == "Ring")
	{
		for each (Enhancement effect in influence)
		{
			if (effect.getType() != "Strength" && effect.getType() != "Wisdom" && effect.getType() != "Charisma"  && effect.getType() != "Constitution" && effect.getType() != "Armor Class" || (effect.getBonus() > 5) || (effect.getBonus() < 0))
				return false;
		}
	}
	else if (type == "Belt")
	{
		for each (Enhancement effect in influence)
		{
			if (effect.getType() != "Constitution" && effect.getType() != "Strength" || (effect.getBonus() > 5) || (effect.getBonus() < 0))
				return false;
		}
	}
	else if (type == "Boots")
	{
		for each (Enhancement effect in influence)
		{
			if (effect.getType() != "Dexterity" && effect.getType() != "Armor Class" || (effect.getBonus() > 5) || (effect.getBonus() < 0))
				return false;
		}
	}
	else if (type == "Weapon")
	{
		for each (Enhancement effect in influence)
		{
			if (effect.getType() != "Attack" && effect.getType() != "Damage" || (effect.getBonus() > 5) || (effect.getBonus() < 0))
				return false;
		}
	}
	else
		return false;
	return true;
}

Item::Item(string type_name, string itemName, int characterLvl)//generates an item with enhancements that match the player's level
{
	type = type_name;
	name = itemName;
	vector<Enhancement> monsterItemEnhancements = vector<Enhancement>();
	int bonus;

	if (type_name == "Helmet") {
		monsterItemEnhancements.push_back(Enhancement("Intelligence", randomIntRange(0, 5)));
		monsterItemEnhancements.push_back(Enhancement("Wisdom", randomIntRange(0, 5)));
		monsterItemEnhancements.push_back(Enhancement("Armor Class", randomIntRange(0, 5)));
		int totalBonus = 0;
		//setBonuses(characterLvl, &monsterItemEnhancements);
	}
	else if (type_name == "Armor") {
		monsterItemEnhancements.push_back(Enhancement("Armor Class", randomIntRange(0, 5)));
		int totalBonus = 0;
		//setBonuses(characterLvl, &monsterItemEnhancements);
	}
	else if (type_name == "Shield") {
		monsterItemEnhancements.push_back(Enhancement("Armor Class", randomIntRange(0, 5)));
		int totalBonus = 0;
		//setBonuses(characterLvl, &monsterItemEnhancements);
	}
	else if (type_name == "Ring") {
		monsterItemEnhancements.push_back(Enhancement("Strength", randomIntRange(0, 5)));
		monsterItemEnhancements.push_back(Enhancement("Wisdom", randomIntRange(0, 5)));
		monsterItemEnhancements.push_back(Enhancement("Charisma", randomIntRange(0, 5)));
		monsterItemEnhancements.push_back(Enhancement("Constitution", randomIntRange(0, 5)));
		monsterItemEnhancements.push_back(Enhancement("Armor Class", randomIntRange(0, 5)));
		int totalBonus = 0;
		//setBonuses(characterLvl, &monsterItemEnhancements);
	}
	else if (type_name == "Belt") {
		monsterItemEnhancements.push_back(Enhancement("Strength", randomIntRange(0, 5)));
		monsterItemEnhancements.push_back(Enhancement("Constitution", randomIntRange(0, 5)));
		int totalBonus = 0;
		//setBonuses(characterLvl, &monsterItemEnhancements);
	}
	else if (type_name == "Boots") {
		monsterItemEnhancements.push_back(Enhancement("Dexterity", randomIntRange(0, 5)));
		monsterItemEnhancements.push_back(Enhancement("Armor Class", randomIntRange(0, 5)));
		int totalBonus = 0;
		//setBonuses(characterLvl, &monsterItemEnhancements);
	}
	else if (type_name == "Weapon") {
		monsterItemEnhancements.push_back(Enhancement("Attack", randomIntRange(0, 5)));
		monsterItemEnhancements.push_back(Enhancement("Damage", randomIntRange(0, 5)));
		int totalBonus = 0;
		//setBonuses(characterLvl, &monsterItemEnhancements);
	}
	influence = monsterItemEnhancements;
}

int Item::randomIntRange(int min, int max) {
	int random = (rand() % (int)(max - min + 1));
	int randomInt = min + random;
	return randomInt;
}

void Item::setBonuses(int charLvl, vector<Enhancement>* vecEn) {
	int totalBonus = 0;
	while (totalBonus < charLvl) {
		int totalBonus = 0;
		for each (Enhancement enc in *vecEn)
		{
			totalBonus += enc.getBonus();
		}
		if (totalBonus >= charLvl)
			break;
		else {
			for each (Enhancement enc in *vecEn)
			{
				if (enc.getBonus() >= 5)
					return;//if any of their equipment is maxed out, stop leveling up enhancements
				enc.setBonus(enc.getBonus() + 1);
			}
		}
	}
}

void Item::Copy(Item otherItem) {
	name = otherItem.getName();
	type = otherItem.getType();
	influence = otherItem.getInfluences();
	valid = true;
}

Item::Item(Item* otherItem) {
	name = otherItem->getName();
	type = otherItem->getType();
	influence = otherItem->getInfluences();
	valid = true;
}

string Item::getName()
{
	return name;
}

void Item::setName(string newName)
{
	name = newName;
}

bool Item::validateType(string itemType)
{
	if (itemType == "Helmet" || itemType == "Armor" || itemType == "Shield" || itemType == "Ring" || itemType == "Belt" || itemType == "Boots" || itemType == "Weapon")
	{
		return true;
	}
	else
		return false;
}

bool Item::validateEnhancementType(string itemType, string enhanceType)
{
	if (itemType == "Helmet")
	{
		if ((enhanceType != "Intelligence") && (enhanceType != "Wisdom") && (enhanceType != "Armor Class"))
			return false;
	}
	else if (itemType == "Armor")
	{
		if (enhanceType != "Armor Class")
			return false;
	}
	else if (itemType == "Shield")
	{
		if (enhanceType != "Armor Class")
			return false;
	}
	else if (itemType == "Ring")
	{
		if (enhanceType != "Strength" && enhanceType != "Wisdom" && enhanceType != "Charisma"  && enhanceType != "Constitution" && enhanceType != "Armor Class")
			return false;
	}
	else if (itemType == "Belt")
	{
		if (enhanceType != "Constitution" && enhanceType != "Strength")
			return false;
	}
	else if (itemType == "Boots")
	{
		if (enhanceType != "Dexterity" && enhanceType != "Armor Class")
			return false;
	}
	else if (itemType == "Weapon")
	{
		if (enhanceType != "Attack" && enhanceType != "Damage")
			return false;
	}
	else
		return false;
	return true;
}
