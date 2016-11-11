#include "ItemUI.h"
#include <iostream>
#include <sstream>

ItemUI::ItemUI()
{
	inv = &Inventory();
	back = &Backpack();
}

ItemUI::ItemUI(Inventory * i, Backpack * b)
{
	inv = i;
	back = b;
}

void ItemUI::PrintInventory()
{
	std::cout << getInventoryString();
	std::cout << getBackpackString();
}

string ItemUI::getInventoryString()
{
	invString = "WORN:\n";
	invString.append("Helmet: " + inv->getItem("Helmet").getName() + "\n");
	invString.append("Armor: " + inv->getItem("Armor").getName() + "\n");
	invString.append("Shield: " + inv->getItem("Shield").getName() + "\n");
	invString.append("Ring: " + inv->getItem("Ring").getName() + "\n");
	invString.append("Belt: " + inv->getItem("Belt").getName() + "\n");
	invString.append("Boots: " + inv->getItem("Boots").getName() + "\n");
	invString.append("Weapon: " + inv->getItem("Weapon").getName() + "\n");
	return invString;
}

string ItemUI::getBackpackString()
{
	int numberOfItems = back->getItems().size();
	if (numberOfItems > 0)
	{
		std::ostringstream oss;
		oss << "CARRIED:\n";
		for (int i = 0; i < numberOfItems; i++)
		{
			oss << "Item #" << i << ": " << back->selectItem(i).getName() << "\n";
		}
		backString = oss.str();
	}
	else
		backString = "No items in backpack!\n";
	return backString;
}

bool ItemUI::organizeItems(char dir)
{
	int index = (int)dir - '0';
	if (index >= 0 && index < 10)
	{
		return equipFromBackpack(dir);
	}
	else
	{
		return unequip(dir);
	}
}

bool ItemUI::unequip(char dir)
{
	string itemType = "";
	switch (dir)
	{
	case 'h': itemType = "Helmet";
		break;
	case 'a': itemType = "Armor";
		break;
	case 's': itemType = "Shield";
		break;
	case 'r': itemType = "Ring";
		break;
	case 'b': itemType = "Belt";
		break;
	case 'o': itemType = "Boots";
		break;
	case 'w': itemType = "Weapon";
		break;
	}
	Item temp = inv->unequip(itemType);
	if (temp.validateItem())
	{
		bool goodAdd = addToPack(temp);
		if (goodAdd)
		{
			return true;
		}
		else
		{
			inv->replaceItem(temp);
			return false;
		}
	}
	else
		return false;
}

bool ItemUI::equipFromBackpack(char dir)
{
	int index = (int)dir - '0';
	if (index > back->getItems().size() || index < 0)
	{
		std::cout << "No item in slot " << dir << "\n";
		return false;
	}
	else
	{
		Item temp = back->takeItem(index);
		temp = inv->replaceItem(temp);
		if (temp.validateItem())
			back->replaceItem(temp);
		return true;
	}
}

void ItemUI::printChestInventory(std::vector<Item> chest)
{
	int numberOfItems = chest.size();
	if (numberOfItems > 0)
	{
		std::ostringstream oss;
		oss << "Items in Chest:\n";
		for (int i = 0; i < numberOfItems; i++)
		{
			oss << "Item #" << i << ": " << chest.at(i).getName() << "\n";
		}
		backString = oss.str();
	}
	else
		backString = "No items in chest!\n";
	std::cout << backString;
}

void ItemUI::grabFromChest(std::vector<Item> chest, char dir)
{
	int index = (int)dir - '0';
	if (index > chest.size() || index < 0)
		std::cout << "No item in slot " << dir << "\n";
	else
	{
		Item temp = chest.at(index);
		chest.erase(chest.begin() + index);
		bool goodAdd = addToPack(temp);
		if(!goodAdd)
			if (temp.validateItem())
				chest.push_back(temp);
	}
}

bool ItemUI::addToPack(Item i)
{
	if (back->getItems().size() > 9)
	{
		std::cout << "Backpack is full!";
		return false;
	}
	else if (!i.validateItem())
	{
		return false;
	}
	else
	{
		back->replaceItem(i);
	}
}
