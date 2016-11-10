#include "Inventory.h"

Inventory::Inventory()
{
	helmet = Item();
	Items.push_back(helmet);
	armor = Item();
	Items.push_back(armor);
	shield = Item();
	Items.push_back(shield);
	ring = Item();
	Items.push_back(ring);
	belt = Item();
	Items.push_back(belt);
	boots = Item();
	Items.push_back(boots);
	weapon = Item();
	Items.push_back(weapon);
}

Inventory::Inventory(vector<Item> items)
{
	helmet = Item();
	Items.push_back(helmet);
	armor = Item();
	Items.push_back(armor);
	shield = Item();
	Items.push_back(shield);
	ring = Item();
	Items.push_back(ring);
	belt = Item();
	Items.push_back(belt);
	boots = Item();
	Items.push_back(boots);
	weapon = Item();
	Items.push_back(weapon);
	for (int i = 0; i < items.size(); i++)
	{
		this->replaceItem(items.at(i)); //ensures no duplicates, right from the start.
	}
}

void Inventory::addItem(Item anitem)
{
	//intentionally left blank: do not use addItem for inventories.
}

vector<Enhancement> Inventory::getBonuses()
{
	vector<Enhancement> totalEnhancements;
	for (int i = 0; i < Items.size(); i++)
	{
		vector<Enhancement> tempEnhancements = Items.at(i).getInfluences();
		for (int j = 0; j < tempEnhancements.size(); j++)
		{
			bool unique = true;
			for (int k = 0; k < totalEnhancements.size(); k++)
			{
				if (totalEnhancements.at(k).getType() == tempEnhancements.at(j).getType())
				{
					unique = false;
					int totalBonus = totalEnhancements.at(k).getBonus() + tempEnhancements.at(j).getBonus();
					Enhancement mergedEnhancement = Enhancement(totalEnhancements.at(k).getType(), totalBonus);
					totalEnhancements.erase(totalEnhancements.begin() + k);
					totalEnhancements.push_back(mergedEnhancement);
					break;
				}
			}
			if(unique)
				totalEnhancements.push_back(tempEnhancements.at(j));
		}
	}
	return vector<Enhancement>();
}

Item Inventory::replaceItem(Item anItem)
{
	string itemType = anItem.getType();
	if (itemType == "Helmet")
	{
		Item temp = helmet;
		helmet = anItem;
		Items.erase(Items.begin() + 0);
		Items.insert(Items.begin() + 0, helmet);
		return temp;
	}
	else if (itemType == "Armor")
	{
		Item temp = armor;
		armor = anItem;
		Items.erase(Items.begin() + 1);
		Items.insert(Items.begin() + 1, armor);
		return temp;
	}
	else if (itemType == "Shield")
	{
		Item temp = shield;
		shield = anItem;
		Items.erase(Items.begin() + 2);
		Items.insert(Items.begin() + 2, shield);
		return temp;
	}
	else if (itemType == "Ring")
	{
		Item temp = ring;
		ring = anItem;
		Items.erase(Items.begin() + 3);
		Items.insert(Items.begin() + 3, ring);
		return temp;
	}
	else if (itemType == "Belt")
	{
		Item temp = belt;
		belt = anItem;
		Items.erase(Items.begin() + 4);
		Items.insert(Items.begin() + 4, belt);
		return temp;
	}
	else if (itemType == "Boots")
	{
		Item temp = boots;
		boots = anItem;
		Items.erase(Items.begin() + 5);
		Items.insert(Items.begin() + 5, boots);
		return temp;
	}
	else if (itemType == "Weapon")
	{
		Item temp = weapon;
		weapon = anItem;
		Items.erase(Items.begin() + 6);
		Items.insert(Items.begin() + 6, weapon);
		return temp;
	}
	else
		return anItem;
}

Item Inventory::unequip(std::string itemType)
{
	if (itemType == "Helmet")
	{
		Item temp = helmet;
		helmet = Item();
		Items.erase(Items.begin() + 0);
		Items.insert(Items.begin() + 0, helmet);
		return temp;
	}
	else if (itemType == "Armor")
	{
		Item temp = armor;
		armor = Item();
		Items.erase(Items.begin() + 1);
		Items.insert(Items.begin() + 1, armor);
		return temp;
	}
	else if (itemType == "Shield")
	{
		Item temp = shield;
		shield = Item();
		Items.erase(Items.begin() + 2);
		Items.insert(Items.begin() + 2, shield);
		return temp;
	}
	else if (itemType == "Ring")
	{
		Item temp = ring;
		ring = Item();
		Items.erase(Items.begin() + 3);
		Items.insert(Items.begin() + 3, ring);
		return temp;
	}
	else if (itemType == "Belt")
	{
		Item temp = belt;
		belt = Item();
		Items.erase(Items.begin() + 4);
		Items.insert(Items.begin() + 4, belt);
		return temp;
	}
	else if (itemType == "Boots")
	{
		Item temp = boots;
		boots = Item();
		Items.erase(Items.begin() + 5);
		Items.insert(Items.begin() + 5, boots);
		return temp;
	}
	else if (itemType == "Weapon")
	{
		Item temp = weapon;
		weapon = Item();
		Items.erase(Items.begin() + 6);
		Items.insert(Items.begin() + 6, weapon);
		return temp;
	}
	else
		return Item();
}
