#include "ItemUI.h"
#include <iostream>

ItemUI::ItemUI(Inventory * i, Backpack * b)
{
	inv = i;
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
	invString.append("Helmet: " + inv->getItem("helmet").getName() + "\n");
	invString.append("Armor: " + inv->getItem("armor").getName() + "\n");
	invString.append("Shield: " + inv->getItem("shield").getName() + "\n");
	invString.append("Ring: " + inv->getItem("ring").getName() + "\n");
	invString.append("Belt: " + inv->getItem("belt").getName() + "\n");
	invString.append("Boots: " + inv->getItem("boots").getName() + "\n");
	invString.append("Weapon: " + inv->getItem("weapon").getName() + "\n");
	return invString;
}

string ItemUI::getBackpackString()
{
	int numberOfItems = back->getItems().size();
	if (numberOfItems > 0)
	{
		backString = "CARRIED:\n";
		for (int i = 0; i < numberOfItems; i++)
		{
			backString.append("Item #" + i);
			backString.append(": " + back->selectItem(i).getName() + "\n");
		}
	}
	else
		backString = "No items in backpack!";
	return backString;
}
