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
