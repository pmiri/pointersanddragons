#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::Inventory(vector<Item> items)
{
	for (int i = 0; i < items.size(); i++)
	{
		this->replaceItem(items.at(i)); //ensures no duplicates, right from the start.
	}
}

vector<Item> Inventory::getItems()
{
	return Items;
}

void Inventory::addItem(Item anitem)
{
	//intentionally left blank: do not use addItem for inventories.
}

Item Inventory::getItem(string itemType)
{
	return ItemContainer::getItem(itemType);
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
			for (int k = 0; k < Items.size(); k++)
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
	for (int i = 0; i < Items.size(); i++)
	{
		if (Items.at(i).getType() == anItem.getType())
		{
			Item temp = Items.at(i);
			Items.erase(Items.begin() + i);
			Items.insert(Items.begin() + i, anItem);
			return temp;
		}
	}
	Items.push_back(anItem);
	return Item();
}
