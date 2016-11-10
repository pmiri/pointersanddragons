//! @file 
//! @brief Declaration file for the ItemUI class  
//!
#pragma once
#include "Inventory.h"
#include "Backpack.h"

class ItemUI
{
public:
	ItemUI();
	ItemUI(Inventory* i, Backpack* b);
	void PrintInventory();
	std::string getInventoryString();
	std::string getBackpackString();
	void equipFromBackpack(char dir);
	void printChestInventory(std::vector<Item> chest);
	void grabFromChest(std::vector<Item> chest, char dir);
private:
	Inventory *inv;
	Backpack *back;
	std::string invString;
	std::string backString;
};