#include "ItemUI.h"

ItemUI::ItemUI(Inventory * i, Backpack * b)
{
	inv = i;
}

void ItemUI::PrintInventory()
{
}

string ItemUI::getInventoryString()
{
	invString = "WORN:";
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
	return string();
}
