#include "Backpack.h"

Backpack::Backpack()
{
}

Backpack::Backpack(vector<Item> items)
{
	for (int i = 0; i < items.size(); i++)
	{
		this->replaceItem(items.at(i)); //ensures the number of items does not exceed 9
	}
}

vector<Item> Backpack::getItems()
{
	return Items;
}

void Backpack::addItem(Item anitem)
{
	//intentionally left blank to prevent over-encumbrance
}

Item Backpack::selectItem(char dir)
{
	int index = (int)dir - '0';
	if (index > 9 || index < 0)
		return Item();
	else
		return Items.at(index);
}

Item Backpack::takeItem(char dir)
{
	int index = (int)dir - '0';
	if (index > 9 || index < 0)
		return Item();
	else
	{
		Item temp = Items.at(index);
		Items.erase(Items.begin() + index);
		return temp;
	}
}

Item Backpack::replaceItem(Item anItem)
{
	Item temp = Item();
	if (Items.size() >= 9)
	{
		temp = Items.back();
		Items.pop_back();		
	}
	Items.push_back(anItem);
	return temp;
}
