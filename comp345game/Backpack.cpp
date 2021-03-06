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

Item Backpack::selectItem(int dir)
{
	if (dir > 9 || dir < 0)
		return Item();
	else
		return Items.at(dir);
}

Item Backpack::takeItem(int dir)
{
	if (dir > 9 || dir < 0)
		return Item();
	else
	{
		Item temp = Items.at(dir);
		Items.erase(Items.begin() + dir);
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
