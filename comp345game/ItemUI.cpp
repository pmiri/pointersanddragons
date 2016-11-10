#include "ItemUI.h"
#include <iostream>
#include <sstream>

ItemUI::ItemUI(Inventory * i, Backpack * b)
{
	inv = i;
	back = b;
}

void ItemUI::PrintInventory()
{
	system("cls");
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
